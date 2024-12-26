#pragma once
#include "scene.hpp"


class SceneManager {
public:
	static SceneManager& get() {
		static SceneManager manager;
		return manager;
	}

	void Start() {
		for (auto& object : currentScene->GetObjects()) {
			object.Start();
		}
	}

	void Update(float deltaTime) {
		for(auto& object : currentScene->GetObjects()) {
			object.Update(deltaTime);
		}
	}

	void SetScene(Scene* scene) {
		currentScene = scene;
		Start();
	}

	Scene* GetCurrentScene() {
		return currentScene;
	}

	~SceneManager() = default;
private:
	SceneManager() {};
	Scene* currentScene = new Scene();
};