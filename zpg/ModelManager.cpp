#include "ModelManager.h"
#include "Model.h"
#include "TangentModel.h"
#include "TextureModel.h"

ModelManager::ModelManager()
{
}

ModelManager* ModelManager::get_instance()
{
	if (!instance)
		instance = new ModelManager();
	return instance;
}

Model* ModelManager::get_texture_model(std::string path)
{
	auto it = texture_model_map.find(path);

	if (it == texture_model_map.end())
	{
		TextureModel* model = new TextureModel(path.c_str());
		texture_model_map.insert({ path, model });

		return model;
	}
	return it->second;
}

Model* ModelManager::get_tangent_model(std::string path)
{
	auto it = tangent_model_map.find(path);

	if (it == tangent_model_map.end())
	{
		TangentModel* model = new TangentModel(path.c_str());
		tangent_model_map.insert({ path, model });

		return model;
	}
	return it->second;
}

ModelManager* ModelManager::instance = 0;