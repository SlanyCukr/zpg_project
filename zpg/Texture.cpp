#include "Texture.h"
#include <stdio.h>

Texture::Texture(const char* path, int index, std::string type_name)
{
	this->index = index;
	this->type_name = type_name;

	glActiveTexture(GL_TEXTURE0 + index);
	texture_id = SOIL_load_OGL_texture(path, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	printf("Succesfully loaded texture %s with ID %d\n", path, texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

int Texture::get_index()
{
	return index;
}

const char* Texture::get_type_name()
{
	return type_name.c_str();
}
