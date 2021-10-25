#version 330
layout(location=0) in vec4 vp;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
out vec4 colour;
void main () {
	gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vp;
	colour = vec4(0.5, 0.0, 0.5, 1.0);
}