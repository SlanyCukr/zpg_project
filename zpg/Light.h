#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext/vector_float4.hpp>
#include <glm/ext/vector_float3.hpp>
#include <vector>
#include "ShaderProgram.h"

class ShaderProgram;
class Light
{
private:
	glm::vec4 light_position;
	std::vector<ShaderProgram*> shaders_to_notify;
	void notify_shaders();
public:
	Light(glm::vec3 light_position);
	void move(glm::vec3 direction);
	void add_shader_to_notify(ShaderProgram* shader_program);
	glm::vec4 get_light_position();
};

