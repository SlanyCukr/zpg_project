#include "PhongShader.h"

PhongShader::PhongShader(const char* vertex_file, const char* fragment_file) : ShaderProgram(vertex_file, fragment_file)
{
}

void PhongShader::update_by_camera(Camera* camera)
{
	this->use();
	this->set_var("viewMatrix", camera->get_view_mat());
	this->set_var("projectionMatrix", camera->get_proj_mat());
	this->set_var("cameraPosition", camera->get_position());
}

void PhongShader::update_by_light(Light* light)
{
	this->use();
	this->set_var("lightPosition", light->get_position());
}
