#include "PointLight.h"

PointLight::PointLight(glm::vec3 position) : Light(position)
{
	constant = 1.0f;
	linear = 0.1f;
	quadratic = 0.0f;

	type = LightType::POINT_LIGHT;
}

float PointLight::get_constant()
{
	return constant;
}

float PointLight::get_linear()
{
	return linear;
}

float PointLight::get_quadratic()
{
	return quadratic;
}
