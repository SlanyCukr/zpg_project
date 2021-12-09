#pragma once
#include "Light.h"
class DirectionalLight :public Light
{
public:
	DirectionalLight(glm::vec3 position, glm::vec3 direction);
	glm::vec3 get_direction();
private:
	glm::vec3 direction;
};

