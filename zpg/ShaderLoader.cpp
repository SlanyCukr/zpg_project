#include "ShaderLoader.h"
#include "ShaderLoader.h"

string ShaderLoader::loadFile(const char* fname)
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

GLuint ShaderLoader::loadShader(const char* vertexFile, const char* fragmentFile) {
	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string vertexShaderString = loadFile(vertexFile);
	string fragmentShaderString = loadFile(fragmentFile);
	int vlen = vertexShaderString.length();
	int flen = fragmentShaderString.length();

	if (vertexShaderString.empty()) printf("Empty Vertex Shader\n");
	if (fragmentShaderString.empty()) printf("Empty Fragment Shader\n");

	const char* vertexShaderCStr = vertexShaderString.c_str();
	const char* fragmentShaderCStr = fragmentShaderString.c_str();

	vertexID = glCreateShader(GL_VERTEX_SHADER);    //Vertex Shader
	glShaderSource(vertexID, 1, (const GLchar**)&vertexShaderCStr, &vlen);
	glCompileShader(vertexID);
	GLint status;
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(vertexID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Vertex shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}

	fragmentID = glCreateShader(GL_FRAGMENT_SHADER); //Fragment Shader
	glShaderSource(fragmentID, 1, (const GLchar**)&fragmentShaderCStr, &flen);
	glCompileShader(fragmentID);

	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(fragmentID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Fragment shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}

	shader_program_id = glCreateProgram();
	glAttachShader(shader_program_id, vertexID);
	glAttachShader(shader_program_id, fragmentID);
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
void ShaderLoader::deleteShader() {
	printf("ShaderLoader::deleteShader()\n");
	glDetachShader(shader_program_id, vertexID);
	glDetachShader(shader_program_id, fragmentID);
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
	glUseProgram(0);
	glDeleteProgram(this->shader_program_id);
}


ShaderLoader::ShaderLoader()
{
}

ShaderLoader::ShaderLoader(const char* vertexFile, const char* fragmentFile)
{
	this->shader_program_id = loadShader(vertexFile, fragmentFile);
}


ShaderLoader::~ShaderLoader()
{
}
