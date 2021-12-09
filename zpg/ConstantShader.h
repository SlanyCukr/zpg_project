#ifndef CONSTANT_SHADER_H
#define CONSTANT_SHADER_H
#include "ShaderProgram.h"
class ConstantShader : public ShaderProgram
{
public:
	ConstantShader(const char* vertex_file, const char* fragment_file);
	void update_by_camera(Camera* camera);
	void update_by_light(Light* light);
};

#endif