#ifndef LIGHT_H
#define LIGHT_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext/vector_float4.hpp>
#include <glm/ext/vector_float3.hpp>
#include <vector>
#include "ShaderProgram.h"

enum class LightType
{
	BASIC,
	POINT_LIGHT,
	DIRECTIONAL_LIGHT,
	SPOT_LIGHT
};

class ShaderProgram;
class Light
{
protected:
	static int lights_count;
	int light_index;
	glm::vec3 light_position;
	glm::vec4 color;

	LightType type;

	std::vector<ShaderProgram*> shaders_to_notify;
	void notify_shaders();
public:
	Light(glm::vec3 light_position, glm::vec4 color);
	Light(glm::vec3 light_position);
	void move(glm::vec3 direction);
	void add_shader_to_notify(ShaderProgram* shader_program);
	glm::vec3 get_position();
	glm::vec4 get_color();
	int get_index();
	LightType get_type();
	static int get_lights_count();
};
#endif
