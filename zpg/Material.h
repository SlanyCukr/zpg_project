#pragma once
#include <glm/ext/vector_float4.hpp>

class Material
{
public:
	Material(float ambient, float diffuse, float specular, int shininess);
	Material(float ambient, float diffuse, float specular, int shininess, float intensity);
	float get_ambient();
	float get_diffuse();
	float get_specular();
	int get_shininess();
	float get_intensity();
private:
	float ambient;
	float diffuse;
	float specular;
	int shininess;
	float intensity;
};

