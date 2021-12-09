#include "Window.h"

static void error_callback(int error, const char* description) { fputs(description, stderr); }

Window::Window(int width, int height, const char* title)
{
	glfwSetErrorCallback(error_callback);
	
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	/* //inicializace konkretni verze
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);s
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,
	GLFW_OPENGL_CORE_PROFILE);  //*/
}

int Window::get_close_flag()
{
	return glfwWindowShouldClose(window);
}

void Window::get_frame_buffer_size(int* width, int* height)
{
	glfwGetFramebufferSize(window, width, height);
}

void Window::get_cursor_pos(double* x_pos, double* y_pos)
{
	glfwGetCursorPos(window, x_pos, y_pos);
}

void Window::swap_buffers()
{
	glfwSwapBuffers(window);
}

void Window::destroy_window()
{
	glfwDestroyWindow(window);
}

void Window::bind_callbacks()
{
	glfwSetErrorCallback([](int err, const char* description) -> void {
		throw std::runtime_error(description);
		});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
		App::get_instance()->get_controller()->mouse_button_callback(button, action, mods);
		});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y) {
		App::get_instance()->get_controller()->cursor_callback(window, x, y);
	});

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		App::get_instance()->get_controller()->key_callback(key, scancode, action, mods);
	});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		App::get_instance()->get_controller()->window_size_callback(width, height);
	});
}
