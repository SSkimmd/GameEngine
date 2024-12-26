#include "input.hpp"
#include <iostream>

void InputManager::Start(GLFWwindow* window) {
	this->window = window;

	for(int i = 32; i < 349; i++) {
		keys.emplace(i, false);
	}
}

void InputManager::Update() {
	for (int i = 32; i < 349; i++) {
		if(glfwGetKey(window, i) == GLFW_PRESS) {
			keys[i] = true;
		} else {
			keys[i] = false;
		}
	}
}

bool InputManager::GetKeyDown(int key) {
	return keys[key];
}