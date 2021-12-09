#ifndef WINDOW_H
#define WINDOW_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "App.h"

class App;
class Window
{
private:
	GLFWwindow* window;
public:
	Window(int width, int height, const char* title);
	Window() = default;
	int get_close_flag();
	void get_frame_buffer_size(int* width, int* height);
	void get_cursor_pos(double* x_pos, double* y_pos);
	void swap_buffers();
	void destroy_window();
	void bind_callbacks();
};

#endif