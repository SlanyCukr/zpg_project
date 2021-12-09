#include "Renderer.h"
#include "MovingObject.h"

Renderer::Renderer(Scene* scene, Window* window)
{
	this->scene = scene;
    this->window = window;
}

void Renderer::render_loop()
{
    // zapnutí z-bufferu
    glEnable(GL_DEPTH_TEST);

    // stencil buffer
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    while (!window->get_close_flag()) {
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        std::vector<DrawableObject*> drawable_objects = this->scene->get_drawable_objects();
        for (int i = 0; i < drawable_objects.size(); i++)
        {
            DrawableObject* drawable_object = drawable_objects[i];
            glStencilFunc(GL_ALWAYS, drawable_object->get_id(), 0xFF);
            drawable_object->render();
        }

        std::vector<MovingObject*> moving_objects = this->scene->get_moving_objects();
        for (int i = 0; i < moving_objects.size(); i++)
        {
            MovingObject* moving_object = moving_objects[i];
            moving_object->move();
            glStencilFunc(GL_ALWAYS, moving_object->get_id(), 0xFF);
            moving_object->render();
        }

        // draw skybox last
        this->scene->get_skybox()->render();

        // update other events like input handling
        glfwPollEvents();

        // put the stuff we’ve been drawing onto the display
        window->swap_buffers();
    }

    window->destroy_window();
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
