#version 330
uniform sampler2D textureUnitID;

#define MAX_LIGHTS 5
struct Light
{
    // base light
    vec3 position;
    vec4 color;
    int type;

    // point light
    float constant;
    float linear;
    float quadratic;

    // directional light
    vec3 direction;

    // spotlight light
    float cone_angle;
    float cone_cosine;
};

in vec4 ex_worldPosition;
in vec3 ex_worldNormal;
in vec2 ex_Uv;

// camera
uniform vec3 cameraPosition;

// light
uniform Light lights[MAX_LIGHTS];
uniform int numberOfLights;

// material
uniform float ambient_coef; 
uniform float diffuse_coef;
uniform float specular_coef;
uniform int shininess;

out vec4 frag_colour;

vec4 calc_base_light(vec4 diffuse, vec4 ambient, vec4 reflection)
{
    vec4 current_color = ambient + diffuse + reflection;
    return current_color;
}

vec4 calc_point_light(Light light, vec4 diffuse, vec4 ambient, vec4 reflection, vec3 frag_pos)
{
    float distance = length(light.position - frag_pos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    return (ambient + diffuse + reflection) * attenuation;
}

vec4 calc_spot_light(Light light, vec4 diffuse, vec4 ambient, vec4 reflection, vec3 frag_pos, vec3 light_vector)
{
    // attenuation
    float distance = length(light.position - frag_pos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    // spotlight intensity
    float theta = dot(light_vector, normalize(-light.direction));
    float epsilon = light.cone_angle - light.cone_cosine;
    float intensity = clamp((theta - light.cone_cosine) / epsilon, 0.0, 1.0);

    if (intensity == 0.0)
        return ambient;

    return (diffuse + ambient + reflection) * attenuation * intensity;
}

void main(void) {
    vec3 worldPosition = vec3(ex_worldPosition.xyz / ex_worldPosition.w);

    vec4 resulting_color = vec4(0, 0, 0, 0);

    // iterate over all light sources
    for (int index = 0; index < numberOfLights; index++)
    {
        Light light = lights[index];

        // either calculate light vector as vector from light source to fragment
        // or if it is directional light, just use its direction
        vec3 lightVector = normalize(light.position - worldPosition);
        if (light.type == 2)
            lightVector = normalize(-light.direction);

        vec3 viewVector = normalize(cameraPosition - worldPosition);
        vec3 halfwayVector = normalize(lightVector + viewVector);

        float dot_product_diffuse = max(dot(lightVector, normalize(ex_worldNormal)), 0.0);

        float dot_product_reflection = 0.0f;
        if (dot_product_diffuse != 0.0f)
            dot_product_reflection = max(dot(normalize(ex_worldNormal), halfwayVector), 0.0);

        vec4 diffuse = diffuse_coef * dot_product_diffuse * texture(textureUnitID, ex_Uv); // difùzní složka

        vec4 ambient = ambient_coef * texture(textureUnitID, ex_Uv); // ambientní složka

        vec4 reflection = specular_coef * pow(dot_product_reflection, shininess) * light.color; // reflekèní složka

        if(light.type == 0)
            resulting_color += ambient + diffuse + reflection;
        else if(light.type == 1)
            resulting_color += calc_point_light(light, diffuse, ambient, reflection, worldPosition);
        else if(light.type == 2)
            resulting_color += diffuse + ambient + reflection;
        else if(light.type == 3)
            resulting_color += calc_spot_light(light, diffuse, ambient, reflection, worldPosition, lightVector);
    }
    frag_colour = resulting_color;
}