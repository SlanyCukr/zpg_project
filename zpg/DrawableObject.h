#pragma once
#include <vector>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include "ShaderProgram.h"
#include "Transformation.h"
#include "Model.h"

// tahle t��da bude abstraktn�, budou vytvo�en� dal�� objekty - Kole�ko, �tverec
class DrawableObject
{
private:
	ShaderProgram* shader_program;
	Transformation* transformation;
	Model* model;

public:
	DrawableObject(Model* model, ShaderProgram* shader_program);
	~DrawableObject();
	void render();
	Transformation* get_transformation();
};

