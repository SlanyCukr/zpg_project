#version 330
uniform sampler2D textureUnitID;

in vec2 ex_Uv;

out vec4 frag_colour;
void main() {
    frag_colour = texture(textureUnitID, ex_Uv);
    //frag_colour = vec4(ex_Uv, 1.0, 1.0); 
    //frag_colour = vec4(0.2, 0.2, 0.2, 1.0);
}