#include "ShaderLoader.h"
#include "ShaderLoader.h"

string ShaderLoader::load_file(const char* fname)
{
	ifstream file(fname);
	if (!file.is_open())
	{
		cout << "Unable to open file " << fname << endl;
		//exit(1);
	}
	std::stringstream fileData;
	fileData << file.rdbuf();
	file.close();
	return fileData.str();
}

GLuint ShaderLoader::load_shader(const char* vertexFile, const char* fragmentFile) {
	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string vertexShaderString = load_file(vertexFile);
	string fragmentShaderString = load_file(fragmentFile);
	int vlen = vertexShaderString.length();
	int flen = fragmentShaderString.length();

	if (vertexShaderString.empty()) printf("Empty Vertex Shader\n");
	if (fragmentShaderString.empty()) printf("Empty Fragment Shader\n");

	const char* vertexShaderCStr = vertexShaderString.c_str();
	const char* fragmentShaderCStr = fragmentShaderString.c_str();

	vertex_id = glCreateShader(GL_VERTEX_SHADER);    //Vertex Shader
	glShaderSource(vertex_id, 1, (const GLchar**)&vertexShaderCStr, &vlen);
	glCompileShader(vertex_id);
	GLint status;
	glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(vertex_id, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(vertex_id, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Vertex shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}

	fragment_id = glCreateShader(GL_FRAGMENT_SHADER); //Fragment Shader
	glShaderSource(fragment_id, 1, (const GLchar**)&fragmentShaderCStr, &flen);
	glCompileShader(fragment_id);

	glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(fragment_id, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(fragment_id, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Fragment shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}

	shader_program_id = glCreateProgram();
	glAttachShader(shader_program_id, vertex_id);
	glAttachShader(shader_program_id, fragment_id);
	glLinkProgram(shader_program_id);

	glGetProgramiv(shader_program_id, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shader_program_id, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shader_program_id, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
	else printf(" Shader:Load OK \n");

	return shader_program_id;
}
void ShaderLoader::delete_shader() {
	printf("ShaderLoader::deleteShader()\n");
	glDetachShader(shader_program_id, vertex_id);
	glDetachShader(shader_program_id, fragment_id);
	glDeleteShader(vertex_id);
	glDeleteShader(fragment_id);
	glUseProgram(0);
	glDeleteProgram(this->shader_program_id);
}


ShaderLoader::ShaderLoader()
{
}

ShaderLoader::ShaderLoader(const char* vertexFile, const char* fragmentFile)
{
	this->shader_program_id = load_shader(vertexFile, fragmentFile);
}


ShaderLoader::~ShaderLoader()
{
}
