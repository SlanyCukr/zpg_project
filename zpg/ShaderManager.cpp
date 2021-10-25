#include "ShaderManager.h"

ShaderProgram* ShaderManager::get_constant_shader()
{
	return new ShaderProgram("constant_vertex.shader", "constant_fragment.shader");
}

ShaderProgram* ShaderManager::get_lambert_shader()
{
	return new ShaderProgram("lambert_vertex.shader", "lambert_fragment.shader");
}

ShaderProgram* ShaderManager::get_phong_shader()
{
	return new ShaderProgram("phong_vertex.shader", "phong_fragment.shader");
}