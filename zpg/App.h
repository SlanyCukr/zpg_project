#ifndef APP_H
#define APP_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "DrawableObject.h"
#include "Controller.h"
#include <glm/ext/quaternion_trigonometric.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <vector>
#include "ShaderProgram.h"
#include "Scene.h"
#include "Renderer.h"
#include "Camera.h"
#include "DrawableObjectFactory.h"
#include "ShaderManager.h"
#include "Light.h"

class Window;
class App
{
private:
	App();
	Window* window;
	Controller* controller;
	static App* instance;
public:
	void init();
	void startRendering();
	static App* get_instance();
	Controller* get_controller();
};

#endif