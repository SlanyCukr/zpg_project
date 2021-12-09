#include "DrawableObjectFactory.h"
#include "ModelManager.h"
#include "MaterialManager.h"

DrawableObjectFactory::DrawableObjectFactory(ShaderProgram* shader_program)
{
	this->shader_program = shader_program;
}

DrawableObject* DrawableObjectFactory::create_object(ObjectType object_type)
{
	std::string name = names[object_type];

	std::string model_name = std::string(name) + std::string(".obj");
	std::string texture_name = std::string(name) + std::string(".png");

	Model* model = ModelManager::get_instance()->get_texture_model(model_name);
	Texture* texture = TextureManager::get_instance()->get_texture(texture_name, "textureUnitID");
	Material* material = MaterialManager::get_instance()->get_material(name);

	DrawableObject* drawable_object = new DrawableObject(model, shader_program, std::vector<Texture*>{texture}, material);
	return drawable_object;
}

DrawableObject* DrawableObjectFactory::create_sphere()
{
	std::vector<int> sizes = {3, 3};
	Model* model = new Model(sphere, 17280, sizes);
	return nullptr;
	//return new DrawableObject(model, shader_program, TextureManager::get_instance()->get_texture("test.png"), nullptr);
}

DrawableObject* DrawableObjectFactory::create_tangent_sphere()
{
	Model* model = ModelManager::get_instance()->get_tangent_model("tangent_sphere.obj");
	//Model* model = ModelManager::get_instance()->get_tangent_model("tangent_box.obj");
	Texture* texture_albedo = TextureManager::get_instance()->get_texture("sphere_albedo.png", "UIAlbedo");
	Texture* texture_normal = TextureManager::get_instance()->get_texture("sphere_normal.png", "UINormal");
	Material* material = MaterialManager::get_instance()->get_material("tangent_box");

	DrawableObject* drawable_object = new DrawableObject(model, shader_program, std::vector<Texture*>{texture_albedo, texture_normal}, material);
	return drawable_object;
}

//DrawableObject* DrawableObjectFactory::create_suzi()
//{
//	Model* model = new Model(suzi_flat, 17424, 2904, 3, attribs_count);
//	return new DrawableObject(model, shader_program);
//}
//
//
//DrawableObject* DrawableObjectFactory::create_bush()
//{
//	Model* model = new Model(bush, 8730, 2904, 3, attribs_count);
//	return new DrawableObject(model, shader_program);
//}
//
//DrawableObject* DrawableObjectFactory::create_gift()
//{
//	Model* model = new Model(gift, 66624, 2904, 3, attribs_count);
//	return new DrawableObject(model, shader_program);
//}
//