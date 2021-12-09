#version 330
in vec4 ex_worldPosition;
in vec3 ex_worldNormal;

uniform vec3 lightPosition;
uniform vec3 cameraPosition;

out vec4 frag_colour;
void main(void) {
    vec3 worldPosition = vec3(ex_worldPosition.xyz / ex_worldPosition.w);

    vec3 lightVector = lightPosition - worldPosition;
    vec3 viewVector = cameraPosition - worldPosition;

    vec3 lightReflectionVector = reflect(-lightVector, normalize(ex_worldNormal));
    
    float dot_product_diffuse = max(dot(normalize(lightVector), normalize(ex_worldNormal)), 0.0f);
    
    float dot_product_reflection = 0.0f;
    if (dot_product_diffuse != 0.0f)
        dot_product_reflection = max(dot(normalize(viewVector), normalize(lightReflectionVector)), 0.0f);
    
    vec4 diffuse = dot_product_diffuse * vec4(0.5, 0, 0.8, 1.0); // difùzní složka - intenzita svìtla daná jako skalární souèin vektoru svìtla a normály fragmentu
    vec4 ambient = vec4(0.2, 0.2, 0.2, 1.0); // ambientní složka
    
    vec4 reflection = pow(dot_product_reflection, 16) * vec4(1.0f, 1.0f, 1.0f, 1.0); // odrazová složka; vec4 = barva svìtla

    frag_colour = ambient + diffuse + reflection;
}