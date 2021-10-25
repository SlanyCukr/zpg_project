#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>
#include "Camera.h"
#include "ShaderLoader.h"
#include "Light.h"
#include <glm/ext/matrix_transform.hpp>

class Light;
class Camera;
class ShaderProgram : public ShaderLoader
{
public:
	ShaderProgram(const char* vertex_file, const char* fragment_file);
	void set_var(const char* name, glm::mat4 matrix);
	void set_var(const char* name, glm::vec4 vec);
	void use();
	void update(Camera* camera);
	void update_by_light(Light* light);
};

