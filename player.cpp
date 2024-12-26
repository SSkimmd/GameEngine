#include "player.hpp"
#include <iostream>

void Player::Start() {
	std::cout << "start player" << std::endl;
}

void Player::SetSpeed(float speed) {
	this->speed = speed;
}

void Player::Update(float deltaTime) {

	glm::vec3 currentPos = SceneManager::get().GetObjectInScene("player")->GetPosition();

	if(InputManager::get().GetKeyDown(GLFW_KEY_D)) {
		SceneManager::get().GetObjectInScene("player")
			->SetPosition(glm::vec3(currentPos.x + speed * deltaTime, currentPos.y, currentPos.z));
	}
	if(InputManager::get().GetKeyDown(GLFW_KEY_A)) {
		SceneManager::get().GetObjectInScene("player")
			->SetPosition(glm::vec3(currentPos.x - speed * deltaTime, currentPos.y, currentPos.z));
	}
}