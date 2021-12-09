#include "Controller.h"
#include <glm/ext/matrix_projection.hpp>

Controller::Controller(Scene* scene, DrawableObjectFactory* drawable_object_factory)
{
	this->previous_mouse_x = 0;
	this->previous_mouse_y = 0;
	this->receiving_position = false;

	this->scene = scene;
	this->drawable_object_factory = drawable_object_factory;
}

void Controller::key_callback(int key, int scancode, int action, int mods)
{
	Camera_movement movement = CAM_INVALID;
	switch (key) 
	{
	case 'W':
		movement = CAM_FORWARD;
		break;
	case 'S':
		movement = CAM_BACKWARD;
		break;
	case 'A':
		movement = CAM_LEFT;
		break;
	case 'D':
		movement = CAM_RIGHT;
		break;
	default:
		break;
	}

	if(movement != CAM_INVALID)
		this->camera->move(movement);
	// printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Controller::window_focus_callback(int focused)
{
	printf("window_focus_callback \n");
}

void Controller::window_iconify_callback(int iconified)
{
	printf("window_iconify_callback \n");
}

void Controller::window_size_callback(int width, int height)
{
	glViewport(0, 0, width, height);
	this->camera->new_size(width, height);
}

void Controller::mouse_button_callback(int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		GLbyte color[4];
		GLfloat depth;
		GLuint index;

		GLint x = (GLint)previous_mouse_x;
		GLint y = (GLint)previous_mouse_y;
		
		int newy = (GLint)camera->get_height() - y;

		glReadPixels(x, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
		glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
		glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

		printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth% f, stencil index % u\n", x, y, color[0], color[1], color[2], color[3], depth, index);

		//Mùžeme nastavit vybrané tìleso scena->setSelect(index-1);

		//Mùžeme vypoèíst pozici v globálním souøadném systému.  
		glm::vec3 screenX = glm::vec3(x, newy, depth);
		glm::vec4 viewPort = glm::vec4(0, 0, camera->get_width(), camera->get_height());
		glm::vec3 pos = glm::unProject(screenX, camera->get_view_mat(), camera->get_proj_mat(), viewPort);

		printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);

		DrawableObject* tree = drawable_object_factory->create_object(ObjectType::TREE);
		tree->get_transformation()->set_pos(pos)->scale(glm::vec3(0.1f, 0.1f, 0.1f));
		scene->add_drawable_object(tree);
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS)
			this->receiving_position = true;
		else if (action == GLFW_RELEASE)
			this->receiving_position = false;
	}
}

void Controller::cursor_callback(GLFWwindow* window, double x, double y)
{
	if (this->receiving_position == 0)
	{
		previous_mouse_x = x;
		previous_mouse_y = y;
		return;
	}

	if (previous_mouse_x == 0 || previous_mouse_y == 0)
		return;
	else
		camera->rotate(previous_mouse_x - x, previous_mouse_y - y, true);

	previous_mouse_x = x;
	previous_mouse_y = y;
}

void Controller::button_callback(int button, int action, int mode)
{
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void Controller::add_camera(Camera* camera)
{
	this->camera = camera;
}
