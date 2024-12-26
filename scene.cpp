#include "scene.hpp"
#include "player.hpp"
#include "move.hpp"

Scene::Scene() {

}

bool Scene::Load(std::string name) {
    this->name = name;

    GameObject cube1 = GameObject("C:/Users/jimmy/Desktop/COMP3016/textures/test_one.jpg");
    cube1.AddComponent(new Player());

    cube1.SetID(0);
    cube1.SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    std::string cube1_name = "Cube" + std::to_string(cube1.GetID());
    cube1.SetName(cube1_name);
    objects.push_back(cube1);



    for (int i = 0; i < 2; i++) {
        GameObject cube = GameObject("C:/Users/jimmy/Desktop/COMP3016/textures/test_two.jpg");

        cube.AddComponent(new Move());
        Move* move = cube.GetComponent<Move>(0);
        move->SetID(i + 1);

        cube.SetID(i+1);
        cube.SetPosition(glm::vec3((float)i + 1, 0.0f, 0.0f));
        std::string cube_name = "Cube" + std::to_string(cube.GetID());
        cube.SetName(cube_name);
        objects.push_back(cube);
    }


    /*
    GameObject cube3 = GameObject("C:/Users/jimmy/Desktop/COMP3016/textures/test_three.jpg");
    cube3.SetID(2);
    cube3.SetPosition(glm::vec3(2.0f, 0.0f, 0.0f));
    std::string cube3_name = "Cube" + std::to_string(cube3.GetID());
    cube3.SetName(cube3_name);
    objects.push_back(cube3);
    */
    /*for (int i = 0; i < 10; i++) {
        GameObject cube = GameObject("C:/Users/jimmy/Desktop/COMP3016/textures/test_two.jpg");
        cube.SetPosition(glm::vec3((float)i, 0.0f, 0.0f));
        std::string name = "Cube" + std::to_string(i);
        cube.SetName(name);
        cube.SetID(i);
        objects.push_back(cube);
    }*/

    return true;
}