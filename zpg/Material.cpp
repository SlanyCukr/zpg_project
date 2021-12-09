#include "Material.h"

Material::Material(float ambient, float diffuse, float specular, int shininess)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
	this->intensity = -1.f;
}

Material::Material(float ambient, float diffuse, float specular, int shininess, float intensity) : Material(ambient, diffuse, specular, shininess)
{
	this->intensity = intensity;
}

float Material::get_ambient()
{
	return ambient;
}

float Material::get_diffuse()
{
	return diffuse;
}

float Material::get_specular()
{
	return specular;
}

int Material::get_shininess()
{
	return shininess;
}

float Material::get_intensity()
{
	return intensity;
}
