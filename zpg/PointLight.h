#pragma once
#include "Light.h"
class PointLight : public Light
{
public:
	PointLight(glm::vec3 position);
	float get_constant();
	float get_linear();
	float get_quadratic();
private:
	float constant;
	float linear;
	float quadratic;
};

