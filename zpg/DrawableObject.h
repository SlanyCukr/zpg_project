#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
#include <vector>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include "ShaderProgram.h"
#include "Transformation.h"
#include "Model.h"
#include "Texture.h"
#include "Material.h"

class DrawableObject
{
private:
	ShaderProgram* shader_program;
	Transformation* transformation;
	Model* model;
	std::vector<Texture*> textures;
	Material* material;
	static int last_id;
	int id;
public:
	DrawableObject(Model* model, ShaderProgram* shader_program, std::vector<Texture*> textures, Material* material);
	~DrawableObject();
	void render();
	Transformation* get_transformation();
	int get_id();
};

#endif