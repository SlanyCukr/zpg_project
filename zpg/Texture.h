#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glew.h>
#include <SOIL.h>
#include <string>

class Texture
{
public:
	Texture(const char* path, int index, std::string type_name);
	int get_index();
	const char* get_type_name();

private:
	int texture_id;
	int index;
	std::string type_name;
};
#endif
