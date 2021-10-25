#ifndef SCENE_H
#define SCENE_H
#include "Camera.h"
#include "DrawableObject.h"

class Scene
{
private:
	Camera* camera;
	std::vector<DrawableObject*> drawable_objects;
public: 
	Scene(Camera* camera, std::vector<DrawableObject*> drawable_objects);
	std::vector<DrawableObject*> get_drawable_objects();
};
#endif
