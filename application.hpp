#pragma once
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "renderer.hpp"
#include "interface.hpp"
#include "scenes.hpp"
#include "input.hpp"
#include "game.hpp"

class Application {
public:
    Application(int SCR_WIDTH, int SCR_HEIGHT);
    ~Application() = default;

    static void FrameBufferSizeChanged(GLFWwindow *window, int width, int height);

    float GetWidth() {
        return SCR_WIDTH;
    }
    float GetHeight() {
        return SCR_HEIGHT;
    }
private:
    float SCR_WIDTH, SCR_HEIGHT;
};