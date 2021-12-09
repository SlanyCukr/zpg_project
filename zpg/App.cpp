#include "App.h"

App::App()
{
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    window = new Window(800, 600, "ZPG");
        
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
    window->get_frame_buffer_size(&width, &height);
    float ratio = width / (float)height;
    glViewport(0, 0, width, height);
}

void App::init()
{
}

void App::start_rendering()
{
    ShaderManager* shader_manager = new ShaderManager();
    ShaderProgram* blinn_phong_shader = shader_manager->get_blinn_phong_shader();
    ShaderProgram* texture_shader = shader_manager->get_texture_shader();
    ShaderProgram* skybox_shader = shader_manager->get_skybox_shader();
    ShaderProgram* tangent_shader = shader_manager->get_blinn_normal();
    
    DrawableObjectFactory* drawable_object_factory_blinn = new DrawableObjectFactory(blinn_phong_shader);
    DrawableObjectFactory* drawable_object_factory_texture = new DrawableObjectFactory(texture_shader);
    DrawableObjectFactory* drawable_object_factory_tangent = new DrawableObjectFactory(tangent_shader);
    MovingObjectFactory* moving_object_factory = new MovingObjectFactory(blinn_phong_shader);

    int width, height;
    window->get_frame_buffer_size(&width, &height);
    window->bind_callbacks();
   
    Skybox* skybox = new Skybox(skybox_shader);
    Camera* camera = new Camera(width, height, glm::vec3(0.0f, 4.0f, 18.0f));
    camera->attach(texture_shader);
    camera->attach(skybox_shader);
    camera->attach(blinn_phong_shader);
    camera->attach(tangent_shader);

    //Light* light1 = new Light(glm::vec3(0.0f, 10.0f, 15.0f), glm::vec4(1.0, 1.0, 1.0, 1.0));
    //DirectionalLight* light2 = new DirectionalLight(glm::vec3(0.0f, 5.0f, 10.0f), glm::vec3(0.0f, -3.0f, -10.0f));
    //PointLight* light1 = new PointLight(glm::vec3(5.0f, 10.0f, 0.0f));    
    SpotLight* light2 = new SpotLight(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 12.5f, 15.f);
    camera->attach(light2);

    Light* casted_light = (Light*)light2;
    //Light* casted_light1 = (Light*)light1;
    //Light* light2 = new Light(glm::vec3(0.0f, 15.0f, 10.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 1, 128);
    //light1->add_shader_to_notify(blinn_phong_shader);
    light2->add_shader_to_notify(blinn_phong_shader);
    light2->add_shader_to_notify(tangent_shader);
    //light1->add_shader_to_notify(blinn_phong_shader);
    
    Scene* scene = Scene::create_forest(camera, std::vector<Light*>{light2}, drawable_object_factory_tangent, drawable_object_factory_blinn, skybox, moving_object_factory);

    controller = new Controller(scene, drawable_object_factory_blinn);

    // controller will control camera
    this->controller->add_camera(camera);

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

Window* App::get_window()
{
    return this->window;
}

App* App::instance = 0;