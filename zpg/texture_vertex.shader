#version 330
layout(location = 0) in vec3 in_Position;
layout(location = 1) in vec3 in_Normal;
layout(location = 2) in vec2 in_Uv;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec2 ex_Uv;

void main() {
    gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(in_Position, 1.0);
	ex_Uv = in_Uv;
}