#pragma once
#include "component.hpp"
#include "object.hpp"
#include "scenes.hpp"

class Player : virtual public Component {
public:
	Player() {

	}
	~Player() = default;
	void Start();
	void Update(float deltaTime);
	void SetSpeed(float speed);
private:
	int speed = 1;
};