#pragma once
#include "component.hpp"
#include "scenes.hpp"

class Player : public Component {
public:
	Player() { }
	~Player() = default;

	void SetSpeed(float speed) {
		this->speed = speed;
	}

	void Start() override {

	}

	void Update(float deltaTime) override {
		glm::vec3 currentPos = SceneManager::get().GetObjectInScene("player")->GetPosition();

		if (InputManager::get().GetKeyDown(GLFW_KEY_D)) {
			SceneManager::get().GetObjectInScene("player")
				->SetPosition(glm::vec3(currentPos.x + speed * deltaTime, currentPos.y, currentPos.z));
		}
		if (InputManager::get().GetKeyDown(GLFW_KEY_A)) {
			SceneManager::get().GetObjectInScene("player")
				->SetPosition(glm::vec3(currentPos.x - speed * deltaTime, currentPos.y, currentPos.z));
		}
	}
private:
	int speed = 1;
};