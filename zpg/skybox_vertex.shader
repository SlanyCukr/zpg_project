#version 330 core
layout(location = 0) in vec3 pos;

out vec3 ex_TexCoords;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main()
{
    ex_TexCoords = pos;
    vec4 pos = projectionMatrix * viewMatrix * vec4(pos, 1.0);
    gl_Position = pos.xyww;
}