#version 330
in vec4 ex_worldPosition;
in vec4 ex_worldNormal;

uniform vec4 lightPosition;

out vec4 frag_colour;   
void main(void) {
    vec4 lightVector = ex_worldNormal * lightPosition;
    float dot_product = max(dot(normalize(lightVector), normalize(ex_worldNormal)), 0.0);
    vec4 diffuse = dot_product * vec4(0.385, 0.647, 0.812, 1.0); // dif�zn� slo�ka - intenzita sv�tla dan� jako skal�rn� sou�in vektoru sv�tla a norm�ly fragmentu
    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);
    frag_colour = ambient + diffuse;
}