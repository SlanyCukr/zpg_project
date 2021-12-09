#include "ConstantShader.h"

ConstantShader::ConstantShader(const char* vertex_file, const char* fragment_file) : ShaderProgram(vertex_file, fragment_file)
{
}

void ConstantShader::update_by_camera(Camera* camera)
{
	this->use();
	this->set_var("viewMatrix", camera->get_view_mat());
	this->set_var("projectionMatrix", camera->get_proj_mat());
}

void ConstantShader::update_by_light(Light* light)
{
}
