#pragma once
#include "object.hpp"
#include <vector>


class Scene {
public:
    Scene();
    ~Scene() = default;
    bool Load(std::string name);
    std::string GetName() {
        return name;
    }

    void AddObject(GameObject* newObject) {
        newObject->SetID(objects.size());
        objects.push_back(newObject);
    }

    void RemoveObject(int id) {
        objects.erase(objects.begin() + id);
    }

    GameObject* GetObject(int i) {
        return objects[i];
    }

    std::vector<GameObject*> GetObjects() {
        return objects;
    }
private:
    std::vector<GameObject*> objects {};
    std::string name = "";
};