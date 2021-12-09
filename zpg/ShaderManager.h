#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H
#include "ShaderProgram.h"

class ShaderProgram;
class ShaderManager
{
public:
	ShaderManager() = default;
	ShaderProgram* get_constant_shader();
	ShaderProgram* get_lambert_shader();
	ShaderProgram* get_phong_shader();
	ShaderProgram* get_blinn_phong_shader();
	ShaderProgram* get_blinn_normal();
	ShaderProgram* get_texture_shader();
	ShaderProgram* get_skybox_shader();
};
#endif