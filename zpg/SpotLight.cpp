#include "SpotLight.h"

SpotLight::SpotLight(glm::vec3 position, glm::vec3 direction, float cone_angle, float cone_cosine) : PointLight(position)
{
	this->direction = direction;

	this->cone_angle = glm::cos(glm::radians(cone_angle));
	this->cone_cosine = glm::cos(glm::radians(cone_angle));

	this->type = LightType::SPOT_LIGHT;
}

float SpotLight::get_cone_angle()
{
	return cone_angle;
}

float SpotLight::get_cone_cosine()
{
	return cone_cosine;
}

glm::vec3 SpotLight::get_direction()
{
	return direction;
}

void SpotLight::update_by_camera(Camera* camera)
{
	this->light_position = camera->get_position();
	this->direction = camera->get_orientation();

	notify_shaders();
}
