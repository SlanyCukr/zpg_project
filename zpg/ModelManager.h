#pragma once
#include <map>
#include <string>

class TextureModel;
class TangentModel;
class Model;
class ModelManager
{
private:
	ModelManager();
	static ModelManager* instance;

	std::map<std::string, Model*> model_map;
	std::map<std::string, TextureModel*> texture_model_map;
	std::map<std::string, TangentModel*> tangent_model_map;
public:
	static ModelManager* get_instance();
	Model* get_texture_model(std::string path);
	Model* get_tangent_model(std::string path);
};