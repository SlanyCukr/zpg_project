#pragma once
#include <string>
#include <map>
#include "Material.h"

class MaterialManager
{
private:
	static MaterialManager* instance;
	MaterialManager();
	std::map<std::string, Material*> materials_map;
	Material* default_material;
public:
	static MaterialManager* get_instance();
	Material* get_material(std::string name);
};

