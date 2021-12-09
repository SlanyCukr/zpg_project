#pragma once
#include "ShaderProgram.h"
class SkyboxShader : public ShaderProgram
{
public:
	SkyboxShader(const char* vertex_file, const char* fragment_file);
	void update_by_camera(Camera* camera);
	void update_by_light(Light* light);
	void set_variables();
private:
	glm::mat4 view_mat;
	glm::mat4 proj_mat;
};

