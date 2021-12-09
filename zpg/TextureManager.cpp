#include "TextureManager.h"
#include "Texture.h"

TextureManager::TextureManager()
{
	last_texture_id = -1;
}

TextureManager* TextureManager::get_instance()
{
	if (!instance)
		instance = new TextureManager();
	return instance;
}

Texture* TextureManager::get_texture(std::string path, std::string type_name)
{
	auto it = texture_map.find(path);

	if (it == texture_map.end())
	{
		last_texture_id++;

		Texture* texture = new Texture(path.c_str(), last_texture_id, type_name);
		texture_map.insert({path, texture});

		return texture;
	}

	return it->second;
}

TextureManager* TextureManager::instance = 0;