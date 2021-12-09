#include "SkyboxShader.h"

SkyboxShader::SkyboxShader(const char* vertex_file, const char* fragment_file) : ShaderProgram(vertex_file, fragment_file)
{
}

void SkyboxShader::update_by_camera(Camera* camera)
{
	this->use();
	this->set_var("viewMatrix", glm::mat4(glm::mat3(camera->get_view_mat())));
	this->set_var("projectionMatrix", camera->get_proj_mat());

	this->view_mat = glm::mat4(glm::mat3(camera->get_view_mat()));
	this->proj_mat = camera->get_proj_mat();
}

void SkyboxShader::update_by_light(Light* light)
{
}

void SkyboxShader::set_variables()
{
	this->use();
	this->set_var("viewMatrix", glm::mat4(glm::mat3(view_mat)));
	this->set_var("projectionMatrix", proj_mat);
}
