#pragma once
#include "PointLight.h"

class UpdatableByCamera;
class SpotLight : public PointLight, public UpdatableByCamera
{
public:
	SpotLight(glm::vec3 position, glm::vec3 direction, float cone_angle, float cone_cosine);
	float get_cone_angle();
	float get_cone_cosine();
	glm::vec3 get_direction();
	void update_by_camera(Camera* camera);
private:
	float cone_angle;
	float cone_cosine;
	glm::vec3 direction;
};

