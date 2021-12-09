#pragma once
#include "DrawableObject.h"
class MovingObject : public DrawableObject
{
public:
	MovingObject(glm::mat4x3 points, Model* model, ShaderProgram* shader_program, std::vector<Texture*> textures, Material* material);
	MovingObject(Model* model, ShaderProgram* shader_program, std::vector<Texture*> textures, Material* material);
	void assign_movement(glm::mat4x3 points);
	void move();
private:
	glm::mat4x3 points;
	float t = 0.5f;
	float delta = 0.01f;
};

