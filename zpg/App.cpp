#include "App.h"

App::App()
{
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    window = new Window(800, 600, "ZPG");
    controller = new Controller();
        
    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // get version info
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("Vendor %s\n", glGetString(GL_VENDOR));
    printf("Renderer %s\n", glGetString(GL_RENDERER));
    printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Using GLFW %i.%i.%i\n", major, minor, revision);

    int width, height;
    window->getFrameBufferSize(&width, &height);
    float ratio = width / (float)height;
    glViewport(0, 0, width, height);
}

void App::startRendering()
{
    ShaderManager* shader_manager = new ShaderManager();
    ShaderProgram* shader_program = shader_manager->get_phong_shader();

    DrawableObjectFactory* drawable_object_factory = new DrawableObjectFactory(shader_program, 2);
    DrawableObject* sphere = drawable_object_factory->create_sphere();

    std::vector<DrawableObject*> drawable_objects = std::vector<DrawableObject*>{ sphere };

    int width, height;
    window->getFrameBufferSize(&width, &height);
    window->bind_callbacks();
    Camera* camera = new Camera(width, height, glm::vec3(0.0f, 0.0f, 10.0f));
    camera->attach(shader_program);

    Light* light = new Light(glm::vec3(0.0f, 0.0f, 1.0f));
    light->add_shader_to_notify(shader_program);
    da
    this->controller->add_camera(camera);

    Scene* scene = new Scene(camera, drawable_objects);

    Renderer* renderer = new Renderer(scene, window);
    renderer->render_loop();
}

App* App::get_instance()
{
    if (!instance)
        instance = new App();
    return instance;
}

Controller* App::get_controller()
{
    return controller;
}

App* App::instance = 0;