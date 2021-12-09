#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertex_file, const char* fragment_file) : ShaderLoader(vertex_file, fragment_file)
{
}


void ShaderProgram::set_var(const char* name, glm::mat4 matrix)
{
	GLuint uniform_id = glGetUniformLocation(shader_program_id, name);

	if (uniform_id == -1)
		printf("Can't set %s.", name);
	//if (uniform_id == -1)
	//	exit(1);

	glUniformMatrix4fv(uniform_id, 1, GL_FALSE, &matrix[0][0]);
}

void ShaderProgram::set_var(const char* name, glm::vec3 vec)
{
	GLuint uniform_id = glGetUniformLocation(shader_program_id, name);

	if (uniform_id == -1)
		printf("Can't set %s.", name);
	//if (uniform_id == -1)
	//	exit(1);

	glUniform3fv(uniform_id, 1, &vec[0]);
}

void ShaderProgram::set_var(const char* name, glm::vec4 vec)
{
	GLuint uniform_id = glGetUniformLocation(shader_program_id, name);

	if (uniform_id == -1)
		printf("Can't set %s.", name);
	//if (uniform_id == -1)
	//	exit(1);

	glUniform4fv(uniform_id, 1, &vec[0]);
}

void ShaderProgram::set_var(const char* name, int val)
{
	GLint uniform_id = glGetUniformLocation(shader_program_id, name);

	if (uniform_id == -1)
		printf("Can't set %s.", name);
	//if (uniform_id == -1)
		//exit(1);
	glUniform1i(uniform_id, val);
}

void ShaderProgram::set_var(const char* name, float val)
{
	GLint uniform_id = glGetUniformLocation(shader_program_id, name);
	
	if(uniform_id == -1)
		printf("Can't set %s.", name);
	/*if (uniform_id == -1)
		exit(1);*/

	glUniform1f(uniform_id, val);
}

void ShaderProgram::use()
{
	glUseProgram(shader_program_id);
}

void ShaderProgram::update_by_camera(Camera* camera)
{
	this->use();
	this->set_var("viewMatrix", camera->get_view_mat());
	this->set_var("projectionMatrix", camera->get_proj_mat());
	this->set_var("cameraPosition", camera->get_position());
}

void ShaderProgram::update_by_light(Light* light)
{
	this->use();
	this->set_var("lightPosition", light->get_position());
}

void ShaderProgram::set_active_texture(const char* name, int index)
{
	this->use();
	set_var(name, index);
}
