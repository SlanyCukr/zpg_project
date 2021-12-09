#pragma once
#include <map>
#include <string>

class Texture;
class TextureManager
{
private:
	TextureManager();
	static TextureManager* instance;

	int last_texture_id;
	std::map<std::string, Texture*> texture_map;
public:
	static TextureManager* get_instance();

	Texture* get_texture(std::string path, std::string type_name);
};

