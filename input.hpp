#pragma once
#include "GLFW/glfw3.h"
#include <map>

class InputManager {
public:
	static InputManager& get() {
		static InputManager manager;
		return manager;
	}

	void Start(GLFWwindow* window);
	void Update();
	bool GetKeyDown(int key);
	bool GetKeyPressed(int key);
private:
	std::map<int, bool> keysDown;
	std::map<int, bool> keysPressed;
	std::map<int, bool> keysDownLastFrame;
	GLFWwindow* window;
	InputManager() = default;
	~InputManager() = default;
};