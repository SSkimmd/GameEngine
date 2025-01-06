#pragma once
#include "scene.hpp"

class SceneManager {
public:
	static SceneManager& get() {
		static SceneManager manager;
		return manager;
	}

	void Start() {
		for(int i = 0; i < currentScene->GetObjects().size(); i++) {
			GameObject* object = currentScene->GetObjects()[i];

			if(object) {
				object->Start();
			}
		}
	}

	void Update(float deltaTime) {
		for(int i = 0; i < currentScene->GetObjects().size(); i++) {
			GameObject* object = currentScene->GetObjects()[i];

			if(object) {
				object->Update(deltaTime);
			}
		}
	}

	void SetScene(Scene* scene) {
		currentScene = scene;
		Start();
	}

	void AddObjectToScene(GameObject* newObject) {
		currentScene->AddObject(newObject);
		std::vector<Component*> components = newObject->GetAllComponents();
		for(int i = 0; i < components.size(); i++) {
			components[i]->Start();
		}
	}

	void CreateObject() {
		GameObject* newObject = new GameObject("textures/test_one.jpg");
		newObject->SetID(currentScene->GetObjects().size());
		newObject->SetName("Cube" + std::to_string(newObject->GetID()));
		currentScene->AddObject(newObject);
	}


	void RemoveFromScene(int id) {
		for(int i = 0; i < currentScene->GetObjects().size(); i++) {
			GameObject* object = currentScene->GetObjects()[i];

			if(object) {
				if (object->GetID() == id) {
					currentScene->RemoveObject(i);
					return;
				}
			}
		}
	}

	std::vector<GameObject*> GetAllObjectsInScene() {
		return currentScene->GetObjects();
	}

	GameObject* GetObjectInScene(int id) {
		for (int i = 0; i < currentScene->GetObjects().size(); i++) {
			GameObject* object = currentScene->GetObjects()[i];
			if(object) {
				if(object->GetID() == id) {
					return object;
				}
			}
		}

		return nullptr;
	}
	GameObject* GetObjectInScene(std::string name) {
		for (int i = 0; i < currentScene->GetObjects().size(); i++) {
			GameObject* object = currentScene->GetObjects()[i];
			if(object) {
				if(object->GetName() == name) {
					return object;
				}
			}
		}

		return nullptr;
	}

	Scene* GetCurrentScene() {
		return currentScene;
	}

	~SceneManager() = default;
	SceneManager() = default;
private:
	Scene* currentScene = new Scene();
};