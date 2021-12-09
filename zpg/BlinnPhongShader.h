#ifndef BLINN_PHONG_SHADER_H
#define BLINN_PHONG_SHADER_H
#include "ShaderProgram.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

class Light;
class BlinnPhongShader : public ShaderProgram
{
public:
	BlinnPhongShader(const char* vertex_file, const char* fragment_file);
	void update_by_camera(Camera* camera);
	void update_by_light(Light* light);
};

#endif