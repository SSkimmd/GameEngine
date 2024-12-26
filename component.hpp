#pragma once
#include <iostream>

class Component {
public:
	virtual void Start() {
		std::cout << "start component" << std::endl;
	};
	virtual void Update(float deltaTime) {

	};
};