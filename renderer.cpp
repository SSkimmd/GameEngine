#include "renderer.hpp"

Renderer::Renderer(int screen_width, int screen_height) {
    SetSize(screen_width, screen_height);
    shader = Shader("C:/Users/jimmy/Desktop/GameEngine/GameEngine/shaders/sprite.vs", "C:/Users/jimmy/Desktop/GameEngine/GameEngine/shaders/sprite.fs");
}

void Renderer::Render(Scene* scene) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    shader.use();
    glm::mat4 projection = glm::perspective(glm::radians(80.0f), (float)screen_width / (float)screen_height, 0.1f, 100.0f);
    shader.setMat4("projection", projection);

    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    shader.setMat4("view", view);

    for(int i = 0; i < scene->GetObjects().size(); i++) {
        auto* obj = scene->GetObject(i);

        if(obj->IsHidden()) continue;

        obj->Render(shader);
    }
}
