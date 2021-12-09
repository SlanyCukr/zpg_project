#include "DrawableObject.h"

int DrawableObject::last_id = -1;

DrawableObject::DrawableObject(Model* model, ShaderProgram* shader_program, std::vector<Texture*> textures, Material* material)
{
    this->model = model;
    this->shader_program = shader_program;
    this->transformation = new Transformation();
    this->textures = textures;
    this->material = material;

    DrawableObject::last_id++;
    this->id = DrawableObject::last_id;
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

    // model matrix from transformation
    shader_program->set_var("modelMatrix", transformation->get_matrix());
    
    // set textures
    for (int i = 0; i < textures.size(); i++)
    {
        Texture* texture = this->textures[i];
        shader_program->set_active_texture(texture->get_type_name(), texture->get_index());
    }
    
    // material values
    shader_program->set_var("ambient_coef", material->get_ambient());
    shader_program->set_var("diffuse_coef", material->get_diffuse());
    shader_program->set_var("specular_coef", material->get_specular());
    shader_program->set_var("shininess", material->get_shininess());

    // could be handled better
    if(material->get_intensity() != -1.f)
        shader_program->set_var("normal_intensity", material->get_intensity());
    
    this->model->render();
}

Transformation* DrawableObject::get_transformation()
{
    return this->transformation;
}

int DrawableObject::get_id()
{
    return this->id;
}
