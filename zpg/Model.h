#ifndef MODEL_H
#define MODEL_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <functional>
#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>

struct Vertex
{
	float Position[3];
	float Normal[3];
	float Texture[2];
	float Tangent[3];
};

class Model
{
protected:
	GLuint VAO;
	GLuint VBO;
	int length;

	int get_safe_previous_size(int index, std::vector<int> sizes);

	std::vector<float> data;
public:
	Model() = default;
	Model(const float points[], int length, std::vector<int> sizes);
	Model(const char* path);
	void render();
};
#endif
