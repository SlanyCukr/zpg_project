#include "MaterialManager.h"

MaterialManager::MaterialManager()
{
	default_material = new Material(0.2, 1, 1, 128);

	materials_map.insert({ "terrain", new Material(0.1, 1, 1, 4096) });
	materials_map.insert({ "tangent_box", new Material(0.2, 1, 1, 128, 1) });
}

MaterialManager* MaterialManager::get_instance()
{
	if (!instance)
		instance = new MaterialManager();
	return instance;
}

Material* MaterialManager::get_material(std::string name)
{
	auto it = materials_map.find(name);

	if (it == materials_map.end())
		return default_material;

	return it->second;
}

MaterialManager* MaterialManager::instance = 0;