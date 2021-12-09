#version 330 core
out vec4 frag_colour;

in vec3 ex_TexCoords;

uniform samplerCube skybox;

void main()
{
    frag_colour = texture(skybox, ex_TexCoords);
}