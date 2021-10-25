#include "Renderer.h"

Renderer::Renderer(Scene* scene, Window* window)
{
	this->scene = scene;
    this->window = window;
}

void Renderer::render_loop()
{
    // zapnutí z-bufferu
    glEnable(GL_DEPTH_TEST);

    float angle = 0.0f;

    // vytvorit novou tridu Renderer
    while (!window->getCloseFlag()) {
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        angle += 0.01f;

        std::vector<DrawableObject*> drawable_objects = this->scene->get_drawable_objects();
        for (int i = 0; i < drawable_objects.size(); i++)
        {
            DrawableObject* drawable_object = drawable_objects[i];
            drawable_object->get_transformation()->rotate(angle, glm::vec3(0, 1.0f, 0));
            drawable_object->render();
        }

        // update other events like input handling
        glfwPollEvents();

        // put the stuff we’ve been drawing onto the display
        window->swapBuffers();
    }

    window->destroyWindow();
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
