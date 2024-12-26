#pragma once
#include "component.hpp"
#include "scenes.hpp"



class Move : virtual public Component {
public:
	void SetID(int id) {
		this->id = id;
	}
	void Start() {

	}
	void Update(float deltaTime) {
		glm::vec3 currentPos = SceneManager::get().GetCurrentScene()->GetObject(id).GetPosition();
		if (right) {
			if (currentPos.x < 5) {
				currentPos.x += speed * deltaTime;
				SceneManager::get().GetCurrentScene()->GetObject(id).SetPosition(currentPos);
			}
			else {
				right = false;
			}
		}
		else {
			if (currentPos.x > -5) {
				currentPos.x -= speed * deltaTime;
				SceneManager::get().GetCurrentScene()->GetObject(id).SetPosition(currentPos);
			}
			else {
				right = true;
			}
		}
	}
private:
	int speed = 1;
	bool right = true;
	int id = -1;
};