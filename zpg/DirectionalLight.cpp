#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(glm::vec3 position, glm::vec3 direction) : Light(position)
{
	this->direction = direction;

	type = LightType::DIRECTIONAL_LIGHT;
}

glm::vec3 DirectionalLight::get_direction()
{
	return direction;
}
