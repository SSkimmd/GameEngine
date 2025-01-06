#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}


void Game::Start() {    
    GameObject* player = new GameObject("textures/test_one.jpg");
    player->AddComponent(new Player());
    player->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    player->SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
    player->SetName("player");
    SceneManager::get().AddObjectToScene(player);


    GameObject* cube = new GameObject("textures/test_two.jpg");
    cube->AddComponent(new Rotate(cube));
    cube->AddComponent(new Move(cube));

    cube->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    cube->SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
    cube->SetName("cube");
    SceneManager::get().AddObjectToScene(cube);
}