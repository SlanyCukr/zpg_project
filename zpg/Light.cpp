#include "Light.h"

void Light::notify_shaders()
{
	for (auto& shader : shaders_to_notify)
		shader->update_by_light(this);
}

Light::Light(glm::vec3 light_position)
{
	this->light_position = glm::vec4(light_position, 1.0f);
}

void Light::move(glm::vec3 direction)
{
	this->light_position + glm::vec4(direction, 0.0f);
}

void Light::add_shader_to_notify(ShaderProgram* shader_program)
{
	this->shaders_to_notify.push_back(shader_program);
	shader_program->update_by_light(this);
}

glm::vec4 Light::get_light_position()
{
	return this->light_position;
}
