#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H
#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

class ShaderLoader
{
	GLuint vertex_id = 0;
	GLuint fragment_id = 0;
	string load_file(const char* fname);
protected:
	GLuint shader_program_id = 0;
public:
	GLuint load_shader(const char* vertex_file, const char* fragment_file);
	void delete_shader();
	ShaderLoader();
	ShaderLoader(const char* vertex_file, const char* fragment_file);
	~ShaderLoader();
};
#endif