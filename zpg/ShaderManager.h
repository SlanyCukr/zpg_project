#pragma once
#include "ShaderProgram.h"

class ShaderProgram;
class ShaderManager
{
public:
	ShaderManager() = default;
	ShaderProgram* get_constant_shader();
	ShaderProgram* get_lambert_shader();
	ShaderProgram* get_phong_shader();
	void get_blinn_shader();
};