#include "ShaderManager.h"
#include "ConstantShader.h"
#include "LambertShader.h"
#include "PhongShader.h"
#include "BlinnPhongShader.h"
#include "TextureShader.h"
#include "SkyboxShader.h"

ShaderProgram* ShaderManager::get_constant_shader()
{
	ConstantShader* constant_shader = new ConstantShader("constant_vertex.shader", "constant_fragment.shader");
	ShaderProgram* shader = constant_shader;
	return shader;
}

ShaderProgram* ShaderManager::get_lambert_shader()
{
	LambertShader* lambert_shader = new LambertShader("lambert_vertex.shader", "lambert_fragment.shader");
	ShaderProgram* shader = lambert_shader;
	return shader;
}

ShaderProgram* ShaderManager::get_phong_shader()
{
	PhongShader* phong_shader = new PhongShader("phong_vertex.shader", "phong_fragment.shader");
	ShaderProgram* shader = phong_shader;
	return shader;
}

ShaderProgram* ShaderManager::get_blinn_phong_shader()
{
	BlinnPhongShader* blinn_phong_shader = new BlinnPhongShader("phong_vertex.shader", "blinn_texture_fragment.shader");
	ShaderProgram* shader = blinn_phong_shader;
	return shader;
}

ShaderProgram* ShaderManager::get_blinn_normal()
{
	BlinnPhongShader* blinn_phong_shader = new BlinnPhongShader("blinn_normal_vertex.shader", "blinn_normal_fragment.shader");
	ShaderProgram* shader = blinn_phong_shader;
	return shader;
}

ShaderProgram* ShaderManager::get_texture_shader()
{
	TextureShader* texture_shader = new TextureShader("texture_vertex.shader", "texture_fragment.shader");
	ShaderProgram* shader = texture_shader;
	return shader;
}

ShaderProgram* ShaderManager::get_skybox_shader()
{
	SkyboxShader* skybox_shader = new SkyboxShader("skybox_vertex.shader", "skybox_fragment.shader");
	ShaderProgram* shader = skybox_shader;
	return shader;
}