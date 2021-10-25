#ifndef WINDOW_H
#define WINDOW_H
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "App.h"

// tady by se hodil observer
class App;
class Window
{
private:
	GLFWwindow* window;
public:
	Window(int width, int height, const char* title);
	Window() = default;
	int getCloseFlag();
	void getFrameBufferSize(int* width, int* height);
	void swapBuffers();
	void destroyWindow();
	void bind_callbacks();
};

#endif