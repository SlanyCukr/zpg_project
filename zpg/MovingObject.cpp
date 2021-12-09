#include "MovingObject.h"

MovingObject::MovingObject(glm::mat4x3 points, Model* model, ShaderProgram* shader_program, std::vector<Texture*> textures, Material* material) : DrawableObject(model, shader_program, textures, material)
{
	this->points = points;

    this->t = 0.5f;
    this->delta = 0.01f;
}

MovingObject::MovingObject(Model* model, ShaderProgram* shader_program, std::vector<Texture*> textures, Material* material) : DrawableObject(model, shader_program, textures, material)
{
    this->t = 0.5f;
    this->delta = 0.01f;
}

void MovingObject::assign_movement(glm::mat4x3 points)
{
    this->points = points;

    this->t = 0.5f;
    this->delta = 0.001f;
}

void MovingObject::move()
{
    glm::mat4 A = glm::mat4(glm::vec4(-1.0, 3.0, -3.0, 1.0),
        glm::vec4(3.0, -6.0, 3.0, 0),
        glm::vec4(-3.0, 3.0, 0, 0),
        glm::vec4(1, 0, 0, 0));

    glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
    glm::vec3 p = parameters * A * glm::transpose(points);
    this->get_transformation()->set_pos(glm::vec3(p.x, p.y, p.z));

    if (t >= 1.0f || t <= 0.0f)
        delta *= -1;
    t += delta;
}
