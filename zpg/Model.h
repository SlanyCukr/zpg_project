#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
class Model
{
private:
	GLuint VAO;
	GLuint VBO;
	int length;
	int row_len;

public:
	Model() = default;
	Model(const float points[], int length, int row_len, int dimensions, int attribs_count);
	void render();
};

