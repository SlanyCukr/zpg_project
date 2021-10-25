#include "Transformation.h"
#include <glm/ext/matrix_transform.hpp>

Transformation::Transformation()
{
	this->matrix = glm::mat4(1.0f);
}

void Transformation::rotate(float angle, glm::vec3 axis)
{
	this->matrix = glm::rotate(glm::mat4(1.0f), angle, axis);
}

const glm::mat4 Transformation::get_matrix()
{
	return this->matrix;
}
