#include "Camera.h"
#include "UpdatableByCamera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	this->width = width;
	this->height = height;

	yaw = -90.0f;
	pitch = 0.0f;
	movement_speed = 0.1f;
	this->position = position;
	viewMat = glm::lookAt(position, position + orientation, worldUp);
	projMat = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

	calculate_orientation();
}

void Camera::calculate_orientation()
{
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	true_orientation = front;
	orientation = glm::normalize(front);

	// also re-calculate the Right and Up vector
	right = glm::normalize(glm::cross(orientation, worldUp)); // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, orientation));

	notify();
}

void Camera::calculate_view()
{
	viewMat = glm::lookAt(position, position + orientation, worldUp);

	notify();
}

void Camera::move(Camera_movement direction)
{
	GLfloat velocity = movement_speed;
	switch (direction)
	{
	case CAM_FORWARD:
		position += orientation * velocity;
		break;
	case CAM_BACKWARD:
		position -= orientation * velocity;
		break;
	case CAM_LEFT:
		position -= right * velocity;
		break;
	case CAM_RIGHT:
		position += right * velocity;
		break;
	case CAM_UP:
		position += up * velocity;
		break;
	case CAM_DOWN:
		position -= up * velocity;
		break;
	}
	calculate_view();
}

void Camera::rotate(double xoffset, double yoffset, GLboolean constrainPitch)
{
	yaw += xoffset * sensitivity;
	pitch -= yoffset * sensitivity;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}
	calculate_orientation();
	calculate_view();
}

void Camera::attach(UpdatableByCamera* obj)
{
	this->notify_list.push_back(obj);
	obj->update_by_camera(this);
}

glm::vec3 Camera::get_position()
{
	return glm::vec3(position);
}

glm::vec3 Camera::get_orientation()
{
	return orientation;
}

void Camera::notify()
{
	for (auto& obj : notify_list)
		obj->update_by_camera(this);
}

glm::mat4 Camera::get_view_mat()
{
	return this->viewMat;
}

glm::mat4 Camera::get_proj_mat()
{
	return this->projMat;
}

void Camera::new_size(int width, int height)
{
	this->width = width;
	this->height = height;

	projMat = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
	notify();
}

int Camera::get_height()
{
	return this->height;
}

int Camera::get_width()
{
	return this->width;
}