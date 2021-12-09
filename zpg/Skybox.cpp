#include "Skybox.h"
#include "DrawableObject.h"
#include <glm/ext.hpp>
#include "stb_image.h"
#include "SkyboxVertices.h"

Skybox::Skybox(ShaderProgram* shader_program)
{
	this->shader_program = shader_program;

	// create cubemap
	glGenTextures(1, &cubemap_texture_id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap_texture_id);

	// supply textures
	int width, height, nrChannels;
	unsigned char* data;
	for (unsigned int i = 0; i < paths.size(); i++)
	{
		data = stbi_load(paths[i], &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
			);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap tex failed to load at path: " << paths[i] << std::endl;
			stbi_image_free(data);
		}
	}

	// wrapping and filtering methods
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	// this should be outside of this class maybe
	model = new Model(skybox_vertices, 108, std::vector<int>{3});
}

void Skybox::render()
{
	// change depth function so depth test passes when values are equal to depth buffer's content
	glDepthFunc(GL_LEQUAL);

	shader_program->use();

	// select correct texture unit, trigger rendering of model
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap_texture_id);
	model->render();

	glDepthFunc(GL_LESS); // set depth function back to default
}
