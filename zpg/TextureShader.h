#ifndef TEXTURE_SHADER_H
#define TEXTURE_SHADER_H
#include "ShaderProgram.h"
class TextureShader : public ShaderProgram
{
public:
	TextureShader(const char* vertex_file, const char* fragment_file);
	void update_by_camera(Camera* camera);
	void update_by_light(Light* light);
};

#endif