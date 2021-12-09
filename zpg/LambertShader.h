#ifndef LAMBERT_SHADER_H
#define LAMBERT_SHADER_H
#include "ShaderProgram.h"
class LambertShader : public ShaderProgram
{
public:
	LambertShader(const char* vertex_file, const char* fragment_file);
	void update_by_camera(Camera* camera);
	void update_by_light(Light* light);
};

#endif