#include "DrawableObjectFactory.h"

DrawableObjectFactory::DrawableObjectFactory(ShaderProgram* shader_program, int attribs_count)
{
	this->shader_program = shader_program;
	this->attribs_count = attribs_count;
}

DrawableObject* DrawableObjectFactory::create_sphere()
{
	Model* model = new Model(sphere, 17280, 2880, 3, attribs_count);
	return new DrawableObject(model, shader_program);
}

DrawableObject* DrawableObjectFactory::create_suzi()
{
	Model* model = new Model(suzi_flat, 17424, 2904, 3, attribs_count);
	return new DrawableObject(model, shader_program);
}
