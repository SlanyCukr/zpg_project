#version 330
in vec4 ex_worldPosition;
in vec4 ex_worldNormal;

uniform vec4 lightPosition;
uniform vec4 cameraPosition;

out vec4 frag_colour;
void main(void) {
    vec4 lightVector = ex_worldNormal * lightPosition;
    vec4 viewVector = normalize(vec4(0.0, 0.0, 10.0, 1.0) - ex_worldPosition);
    vec4 lightReflectionVector = reflect(-lightVector, ex_worldNormal);
    //vec4 cameraVector = ex_worldNormal * vec4(0.0, 0.0, 10.0, 1.0); // camera position by tu m�l b�t m�sto t�hle pozice natvrdo
    //vec4 lightReflectionVector = lightVector - 2.0 * dot(ex_worldNormal, lightVector) * ex_worldNormal;
    float dot_product_diffuse = max(dot(normalize(lightVector), normalize(ex_worldNormal)), 0.0);
    float dot_product_reflection = max(dot(normalize(viewVector), normalize(lightReflectionVector)), 0.0);
    vec4 diffuse = dot_product_diffuse * vec4(0.5, 0.5, 0.5, 1.0); // dif�zn� slo�ka - intenzita sv�tla dan� jako skal�rn� sou�in vektoru sv�tla a norm�ly fragmentu
    
    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);
    
    float light_strength = 10000.0f;
    vec4 reflection = light_strength * pow(dot_product_reflection, 32) * vec4(1, 1, 1, 1.0); // odrazov� slo�ka
    
    frag_colour = ambient + diffuse + reflection;
}