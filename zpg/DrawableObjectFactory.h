#ifndef DRAWABLE_OBJECT_FACTORY_H
#define DRAWABLE_OBJECT_FACTORY_H
#include "Sphere.h"
#include "DrawableObject.h"
#include "Sphere.h"
#include "Suzi_flat.h"
#include "Tree.h"
#include "Bush.h"
#include "Gift.h"
#include "Plain.h"
#include "Texture.h"
#include "TextureManager.h"

enum ObjectType 
{
	PLAIN,
	HOUSE,
	ZOMBIE,
	TREE,
	TERRAIN
};

class MaterialManager;
class ModelManager;
class DrawableObjectFactory
{
public:
	DrawableObjectFactory(ShaderProgram* shader_program);
	DrawableObject* create_object(ObjectType object_type);
	DrawableObject* create_sphere();
	DrawableObject* create_tangent_sphere();
	DrawableObject* create_suzi();
	DrawableObject* create_bush();
	DrawableObject* create_gift();
protected:
	ShaderProgram* shader_program;
	std::map<ObjectType, const char*> names{ 
		{PLAIN, "plain"},
		{HOUSE, "house"},
		{ZOMBIE, "zombie"},
		{TREE, "tree"},
		{TERRAIN, "terrain"}
	};
};

#endif