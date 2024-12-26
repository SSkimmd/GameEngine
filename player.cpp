#include "player.hpp"
#include <iostream>

void Player::Start() {
	std::cout << "start player" << std::endl;
}

void Player::SetSpeed(float speed) {
	this->speed = speed;
}

void Player::Update(float deltaTime) {
	if(InputManager::get().GetKeyDown(GLFW_KEY_D)) {
		glm::vec3 currentPos = SceneManager::get().GetCurrentScene()->GetObject(0).GetPosition();
		SceneManager::get().GetCurrentScene()->GetObject(0)
			.SetPosition(glm::vec3(currentPos.x + speed * deltaTime, currentPos.y, currentPos.z));
	}
	if(InputManager::get().GetKeyDown(GLFW_KEY_A)) {
		glm::vec3 currentPos = SceneManager::get().GetCurrentScene()->GetObject(0).GetPosition();
		SceneManager::get().GetCurrentScene()->GetObject(0)
			.SetPosition(glm::vec3(currentPos.x - speed * deltaTime, currentPos.y, currentPos.z));
	}
}