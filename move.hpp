#pragma once
#include "component.hpp"
#include "scenes.hpp"



class Move : public Component {
public:
	Move(GameObject* object) {
		this->object = object;
	}
	~Move() = default;
	void Start() override { }
	void Update(float deltaTime) override {
		if (InputManager::get().GetKeyPressed(GLFW_KEY_P)) {
			paused = !paused;
		}

		if (!paused) {
			glm::vec3 currentPos = object->GetPosition();
			if (right) {
				if (currentPos.x < 5) {
					currentPos.x += speed * deltaTime;
					object->SetPosition(currentPos);
				}
				else {
					right = false;
				}
			}
			else {
				if (currentPos.x > -5) {
					currentPos.x -= speed * deltaTime;
					object->SetPosition(currentPos);
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
	bool paused = false;
	GameObject* object;
};