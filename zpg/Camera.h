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

class UpdatableByCamera;
class ShaderProgram;
class Camera
{
public:
	Camera(int width, int height, glm::vec3 position);
	void calculate_orientation();
	void calculate_view();
	void move(Camera_movement direction);
	void rotate(double xoffset, double yoffset, GLboolean constrain_pitch);
	void attach(UpdatableByCamera* shader_program);
	
	glm::vec3 get_position();
	glm::vec3 get_orientation();

	glm::mat4 get_view_mat();
	glm::mat4 get_proj_mat();

	void new_size(int width, int height);
	int get_height();
	int get_width();
private:
	std::vector<UpdatableByCamera*> notify_list;
	void notify();

	glm::vec3 position;
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 true_orientation;
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 right = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 viewMat;
	glm::mat4 projMat;

	GLfloat movement_speed;
	GLfloat sensitivity = 0.05f;
	GLfloat pitch;
	GLfloat yaw;

	int height;
	int width;
};

#endif
