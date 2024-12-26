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

    GameObject &GetObject(int i) {
        return objects[i];
    }

    std::vector<GameObject> &GetObjects() {
        return objects;
    }
private:
    std::vector<GameObject> objects {};
    std::string name = "";
};