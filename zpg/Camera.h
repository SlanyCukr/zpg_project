#ifndef CAMERA_H
#define CAMERA_H
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <vector>
#include "ShaderProgram.h"

const glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

enum Camera_movement {
	CAM_FORWARD,
	CAM_BACKWARD,
	CAM_LEFT,
	CAM_RIGHT,
	CAM_UP,
	CAM_DOWN,
	CAM_INVALID
};

class ShaderProgram;
class Camera
{
public:
	Camera(int width, int height, glm::vec3 position);
	void calcOrientation();
	void calcView();
	void move(Camera_movement direction);
	void rotate(double xoffset, double yoffset, GLboolean constrainPitch);
	void attach(ShaderProgram* shader_program);
	
	glm::vec4 get_position();

	glm::mat4 get_view_mat();
	glm::mat4 get_proj_mat();
private:
	std::vector<ShaderProgram*> notify_list;
	void notify();

	glm::vec3 position;
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 right = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 viewMat;
	glm::mat4 projMat;

	GLfloat movementSpeed;
	GLfloat sensitivity = 0.05f;
	GLfloat pitch;
	GLfloat yaw;
};
#endif