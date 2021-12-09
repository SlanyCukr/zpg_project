#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include <glm/ext/matrix_float4x4.hpp>
class Transformation
{
private:
	glm::mat4 matrix;
public:
	Transformation();
	Transformation* rotate(float angle, glm::vec3 axis);
	Transformation* move(glm::vec3 direction);
	Transformation* set_pos(glm::vec3 pos);
	Transformation* scale(glm::vec3 scale);
	const glm::mat4 get_matrix();
};

#endif