#ifndef PHONG_SHADER_H
#define PHONG_SHADER_H
#include "ShaderProgram.h"
class PhongShader : public ShaderProgram
{
public:
	PhongShader(const char* vertex_file, const char* fragment_file);
	void update_by_camera(Camera* camera);
	void update_by_light(Light* light);
};
#endif
