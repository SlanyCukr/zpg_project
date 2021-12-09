#include "Light.h"

int Light::lights_count = -1;

void Light::notify_shaders()
{
	for (auto& shader : shaders_to_notify)
		shader->update_by_light(this);
}

Light::Light(glm::vec3 light_position, glm::vec4 color)
{
	Light::lights_count++;

	this->light_index = Light::lights_count;
	
	this->light_position = glm::vec4(light_position, 1.0f);
	this->color = color;

	this->type = LightType::BASIC;
}

void Light::move(glm::vec3 direction)
{
	this->light_position += direction;
	this->notify_shaders();
}

void Light::add_shader_to_notify(ShaderProgram* shader_program)
{
	this->shaders_to_notify.push_back(shader_program);
	shader_program->update_by_light(this);
}

glm::vec3 Light::get_position()
{
	return this->light_position;
}

glm::vec4 Light::get_color()
{
	return this->color;
}

int Light::get_index()
{
	return this->light_index;
}

Light::Light(glm::vec3 light_position) : Light(light_position, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f))
{
}

LightType Light::get_type()
{
	return this->type;
}

int Light::get_lights_count()
{
	return Light::lights_count + 1;
}
