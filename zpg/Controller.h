#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.h"

class Controller
{
public:
	Controller();
	void key_callback(int key, int scancode, int action, int mods);
	void window_focus_callback(int focused);
	void window_iconify_callback(int iconified);
	void window_size_callback(int width, int height);
	void cursor_callback(GLFWwindow* window, double x, double y);
	void button_callback(int button, int action, int mode);
	void add_camera(Camera* camera);
private:
	Camera* camera;
	double previous_mouse_x;
	double previous_mouse_y;
};
