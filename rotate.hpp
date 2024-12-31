#pragma once
#include "component.hpp"
#include "scenes.hpp"

class Rotate : public Component {
public:
	Rotate(GameObject* object) {
		this->object = object;
	}
	~Rotate() = default;
	void Start() override { }
	void Update(float deltaTime) override {
		if (InputManager::get().GetKeyPressed(GLFW_KEY_P)) {
			paused = !paused;
		}

		if(!paused) {
			glm::vec3 currentRot = object->GetRotation();
			currentRot.x += speed * deltaTime;
			currentRot.y += speed * deltaTime;
			object->SetRotation(currentRot);
		}
	}
private:
	int speed = 1;
	bool paused = false;
	GameObject* object;
};