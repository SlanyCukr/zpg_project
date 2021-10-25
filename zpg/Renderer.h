#ifndef RENDERER_H
#define RENDERER_H
#include "Scene.h"
#include "Window.h"

class Window;
class Renderer
{
private:
	Scene* scene;
	Window* window;
public:
	Renderer(Scene* scene, Window* window);
	void render_loop();
};
#endif