#pragma once
#include "DrawableObjectFactory.h"

class MovingObject;
class MovingObjectFactory : public DrawableObjectFactory
{
public:
	MovingObjectFactory(ShaderProgram* shader_program);
	MovingObject* get_moving_zombie();
};

