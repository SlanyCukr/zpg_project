#include "MovingObjectFactory.h"
#include "MovingObject.h"
#include "ModelManager.h"
#include "MaterialManager.h"

MovingObjectFactory::MovingObjectFactory(ShaderProgram* shader_program) : DrawableObjectFactory(shader_program)
{
}

// this should be updated to allow zombies with multiple textures - needed for normal mapping
MovingObject* MovingObjectFactory::get_moving_zombie()
{
	Model* model = ModelManager::get_instance()->get_texture_model("zombie.obj");
	Texture* texture = TextureManager::get_instance()->get_texture("zombie.png", "textureUnitID");
	Material* material = MaterialManager::get_instance()->get_material("zombie");

	MovingObject* moving_object = new MovingObject(model, shader_program, std::vector<Texture*>{texture}, material);

	moving_object->assign_movement(glm::mat4x3(glm::vec3(-5, -1, 10),
		glm::vec3(-1, 1, 10),
		glm::vec3(3, -1, 10),
		glm::vec3(5, -1, 10)));
	
	return moving_object;
}
