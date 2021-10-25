#pragma once
#include <glm/ext/matrix_float4x4.hpp>
class Transformation
{
private:
	glm::mat4 matrix;
public:
	Transformation();
	void rotate(float angle, glm::vec3 axis);
	const glm::mat4 get_matrix();
};

