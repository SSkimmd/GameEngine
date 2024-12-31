#include "scene.hpp"

Scene::Scene() {

}

bool Scene::Load(std::string name) {
    this->name = name;
    return true;
}