#ifndef SKYBOX_H
#define SKYBOX_H
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <vector>
#include "Model.h"

class ShaderProgram;
class Skybox
{
public:
	Skybox(ShaderProgram* shader_program);
	void render();
private:
	glm::mat4 view_mat;
	glm::mat4 proj_mat;
	Model* model;
	ShaderProgram* shader_program;
	unsigned int cubemap_texture_id;
	std::vector<const char*> paths = std::vector<const char*>{ "posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg" };
};
class DrawableObject;
class ShaderProgram;

#endif
