#pragma once
#include "Sphere.h"
#include "DrawableObject.h"
#include "Sphere.h"
#include "Suzi_flat.h"

class DrawableObjectFactory
{
public:
	DrawableObjectFactory(ShaderProgram* shader_program, int attribs_count);
	DrawableObject* create_sphere();
	DrawableObject* create_suzi();
private:
	ShaderProgram* shader_program;
	int attribs_count;
};

