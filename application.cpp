#include "application.hpp"
#include <iostream>

Application::Application(int SCR_WIDTH, int SCR_HEIGHT) {
    this->SCR_WIDTH = SCR_WIDTH;
    this->SCR_HEIGHT = SCR_HEIGHT;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Game", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, Application::FrameBufferSizeChanged);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glEnable(GL_DEPTH_TEST);

    Scene scene_test;
    if(!scene_test.Load("scene1")) return;
    SceneManager::get().SetScene(&scene_test);

    Renderer renderer = Renderer(SCR_WIDTH, SCR_HEIGHT);
    UserInterface userInterface = UserInterface(window);
    InputManager::get().Start(window);

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        InputManager::get().Update();
        SceneManager::get().Update(deltaTime);

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        renderer.Render(SceneManager::get().GetCurrentScene());
        userInterface.Render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}

void Application::FrameBufferSizeChanged(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}