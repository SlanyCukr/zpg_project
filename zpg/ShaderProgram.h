#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>
#include "Camera.h"
#include "ShaderLoader.h"
#include "Light.h"
#include "UpdatableByCamera.h"
#include <glm/ext/matrix_transform.hpp>

class Light;
class Camera;
class ShaderProgram : public ShaderLoader, public UpdatableByCamera
{
public:
	ShaderProgram(const char* vertex_file, const char* fragment_file);
	void set_var(const char* name, glm::mat4 matrix);
	void set_var(const char* name, glm::vec3 vec);
	void set_var(const char* name, glm::vec4 vec);
	void set_var(const char* name, int val);
	void set_var(const char* name, float val);
	void use();
	virtual void update_by_camera(Camera* camera) = 0;
	virtual void update_by_light(Light* light) = 0;
	void set_active_texture(const char* name, int index);
};

#endif