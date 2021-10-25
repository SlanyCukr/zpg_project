#include "Controller.h"

Controller::Controller()
{
	this->previous_mouse_x = 0;
	this->previous_mouse_y = 0;
}

void Controller::key_callback(int key, int scancode, int action, int mods)
{
	Camera_movement movement = CAM_INVALID;
	switch (key) 
	{
	case 'W':
		movement = CAM_FORWARD;
		break;
	case 'S':
		movement = CAM_BACKWARD;
		break;
	case 'A':
		movement = CAM_LEFT;
		break;
	case 'D':
		movement = CAM_RIGHT;
		break;
	default:
		break;
	}

	if(movement != CAM_INVALID)
		this->camera->move(movement);
	// printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Controller::window_focus_callback(int focused)
{
	printf("window_focus_callback \n");
}

void Controller::window_iconify_callback(int iconified)
{
	printf("window_iconify_callback \n");
}

void Controller::window_size_callback(int width, int height)
{
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Controller::cursor_callback(GLFWwindow* window, double x, double y)
{
	if (previous_mouse_x == 0 || previous_mouse_y == 0)
	{
		previous_mouse_x = 0;
		previous_mouse_y = 0;
	}
	else
	{
		camera->rotate(previous_mouse_x - x, previous_mouse_y - y, true);
	}
	previous_mouse_x = x;
	previous_mouse_y = y;
	//printf("cursor_callback x:%f y:%f\n", x, y);
}

void Controller::button_callback(int button, int action, int mode)
{
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void Controller::add_camera(Camera* camera)
{
	this->camera = camera;
}
