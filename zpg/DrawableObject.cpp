#include "DrawableObject.h"

DrawableObject::DrawableObject(Model* model, ShaderProgram* shader_program)
{
    this->model = model;
    this->shader_program = shader_program;
    this->transformation = new Transformation();
}

DrawableObject::~DrawableObject()
{
    delete this->transformation;
    delete this->model;
    delete this->shader_program;
}

void DrawableObject::render()
{
    shader_program->use(); 
    shader_program->set_var("modelMatrix", transformation->get_matrix());
    this->model->render();
}

Transformation* DrawableObject::get_transformation()
{
    return this->transformation;
}
