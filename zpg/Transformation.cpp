#include "Transformation.h"
#include <glm/ext/matrix_transform.hpp>

Transformation::Transformation()
{
	this->matrix = glm::mat4(1.0f);
}

Transformation* Transformation::rotate(float angle, glm::vec3 axis)
{
	this->matrix = glm::rotate(this->matrix, angle, axis);
	return this;
}

Transformation* Transformation::move(glm::vec3 direction)
{
	this->matrix = glm::translate(this->matrix, direction);
	return this;
}

Transformation* Transformation::set_pos(glm::vec3 pos)
{
	this->matrix = glm::translate(glm::mat4(1.0f), pos);
	return this;
}

Transformation* Transformation::scale(glm::vec3 scale)
{
	this->matrix = glm::scale(this->matrix, scale);
	return this;
}

const glm::mat4 Transformation::get_matrix()
{
	return this->matrix;
}
