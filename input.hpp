#pragma once
#include "GLFW/glfw3.h"
#include <map>

class InputManager {
public:
	static InputManager& get() {
		static InputManager manager;
		return manager;
	}
	~InputManager() = default;

	void Start(GLFWwindow* window);
	void Update();
	bool GetKeyDown(int key);
private:
	std::map<int, bool> keys;
	GLFWwindow* window;
	InputManager() {}
};