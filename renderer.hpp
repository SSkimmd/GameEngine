#pragma once
#include "scenes.hpp"
#include "shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb/stb_image.h"
#include <GLFW/glfw3.h>

class Renderer {
public:    
    Renderer(int width, int height);
    ~Renderer() = default;
    void Render(Scene* scene);
    void SetSize(float width, float height) {
        screen_width = width;
        screen_height = height;
    }
private:
    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
    unsigned int screen_width, screen_height;
    Shader shader;
}; 