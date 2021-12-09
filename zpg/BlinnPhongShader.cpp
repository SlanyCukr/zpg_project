#include "BlinnPhongShader.h"
#include "Light.h"

BlinnPhongShader::BlinnPhongShader(const char* vertex_file, const char* fragment_file) : ShaderProgram(vertex_file, fragment_file)
{
}

void BlinnPhongShader::update_by_camera(Camera* camera)
{
	this->use();
	this->set_var("viewMatrix", camera->get_view_mat());
	this->set_var("projectionMatrix", camera->get_proj_mat());
	this->set_var("cameraPosition", camera->get_position());
}

void BlinnPhongShader::update_by_light(Light* light)
{
	this->use();

	std::ostringstream prefix;
	prefix << "lights[" << light->get_index() << "].";

	this->set_var((prefix.str() + std::string("position")).c_str(), light->get_position());
	this->set_var((prefix.str() + std::string("color")).c_str(), light->get_color());
	this->set_var((prefix.str() + std::string("type")).c_str(), (int)light->get_type());

	switch (light->get_type())
	{
	case LightType::POINT_LIGHT:
	{
		PointLight* point_light = (PointLight*)light;
		this->set_var((prefix.str() + std::string("constant")).c_str(), point_light->get_constant());
		this->set_var((prefix.str() + std::string("linear")).c_str(), point_light->get_linear());
		this->set_var((prefix.str() + std::string("quadratic")).c_str(), point_light->get_quadratic());
	}
	case LightType::DIRECTIONAL_LIGHT:
	{
		DirectionalLight* directional_light = (DirectionalLight*)light;
		this->set_var((prefix.str() + std::string("direction")).c_str(), directional_light->get_direction());
	}
	case LightType::SPOT_LIGHT:
	{
		SpotLight* spot_light = (SpotLight*)light;

		// set direction of spotlight
		this->set_var((prefix.str() + std::string("direction")).c_str(), spot_light->get_direction());

		// set attenuation parameters for spotlight
		this->set_var((prefix.str() + std::string("constant")).c_str(), spot_light->get_constant());
		this->set_var((prefix.str() + std::string("linear")).c_str(), spot_light->get_linear());
		this->set_var((prefix.str() + std::string("quadratic")).c_str(), spot_light->get_quadratic());

		// set cone parameters of spotlight
		this->set_var((prefix.str() + std::string("cone_angle")).c_str(), spot_light->get_cone_angle());
		this->set_var((prefix.str() + std::string("cone_cosine")).c_str(), spot_light->get_cone_cosine());
	}
	}


	this->set_var("numberOfLights", Light::get_lights_count());
}
