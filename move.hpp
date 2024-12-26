#pragma once
#include "component.hpp"
#include "scenes.hpp"



class Move : virtual public Component {
public:
	void SetID(int id) {
		this->id = id;
	}
	void Start() {
		std::cout << "start called in move component" << std::endl;
	}
	void Update(float deltaTime) {
		if (InputManager::get().GetKeyPressed(GLFW_KEY_P)) {
			paused = !paused;
		}

		if (!paused) {
			glm::vec3 currentPos = SceneManager::get().GetObjectInScene(id)->GetPosition();
			if (right) {
				if (currentPos.x < 5) {
					currentPos.x += speed * deltaTime;
					SceneManager::get().GetObjectInScene(id)->SetPosition(currentPos);
				}
				else {
					right = false;
				}
			}
			else {
				if (currentPos.x > -5) {
					currentPos.x -= speed * deltaTime;
					SceneManager::get().GetObjectInScene(id)->SetPosition(currentPos);
				}
				else {
					right = true;
				}
			}
		}
	}
private:
	int speed = 1;
	bool right = true;
	int id = -1;
	bool paused = false;
};