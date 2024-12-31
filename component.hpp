#pragma once
#include <iostream>

class Component {
public:
	virtual void Start() { };
	virtual void Update(float deltaTime) { };
	Component() {};
};