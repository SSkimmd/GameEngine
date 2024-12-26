#include "interface.hpp"

UserInterface::UserInterface(GLFWwindow* window) {
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    io = &ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void UserInterface::Render() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();
    ImGui::Begin("Debug");

    ImGui::Text(SceneManager::get().GetCurrentScene()->GetName().c_str());
    Scene* scene = SceneManager::get().GetCurrentScene();
    int objects = std::size(scene->GetObjects());
    std::string object_text = "Objects: " + std::to_string(objects);
    ImGui::Text(object_text.c_str());
    ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);

    if(ImGui::CollapsingHeader("Objects")) {
        ImGui::Indent();

        for(int i = 0; i < SceneManager::get().GetAllObjectsInScene().size(); i++) {
            GameObject* object = scene->GetObject(i);
            if(!object) {
                i = 0;
            }

            if(ImGui::CollapsingHeader(object->GetName().c_str())) {
                ImGui::Indent();

                std::string id_text = "ID: " + std::to_string(object->GetID());
                ImGui::Text(id_text.c_str());
                bool isHidden = object->IsHidden();

                std::string components_text = "Components: " + std::to_string(object->GetAllComponents().size());
                ImGui::Text(components_text.c_str());

                std::string hide_text = "Hide: " + object->GetName();
                if(ImGui::Checkbox(hide_text.c_str(), &isHidden)) {
                    object->ToggleHidden();
                }

                std::string remove_text = "Remove: " + object->GetName();
                if (ImGui::Button(remove_text.c_str())) {
                    SceneManager::get().RemoveFromScene(object->GetID());
                }

                std::string position_text = "Position " + object->GetName();
                if(ImGui::CollapsingHeader(position_text.c_str())) {
                    ImGui::InputFloat("X Pos", &x_pos, 0.1f, 0.1f, "%.1f");
                    ImGui::InputFloat("Y Pos", &y_pos, 0.1f, 0.1f, "%.1f");
                    ImGui::InputFloat("Z Pos", &z_pos, 0.1f, 0.1f, "%.1f");

                    if(ImGui::Button("Move")) {
                        object->SetPosition(glm::vec3(x_pos, y_pos, z_pos));
                    }
                }
                std::string scale_text = "Scale " + object->GetName();
                if (ImGui::CollapsingHeader(scale_text.c_str())) {
                    ImGui::InputFloat("X Scale", &x_scale, 0.1f, 0.1f, "%.1f");
                    ImGui::InputFloat("Y Scale", &y_scale, 0.1f, 0.1f, "%.1f");
                    ImGui::InputFloat("Z Scale", &z_scale, 0.1f, 0.1f, "%.1f");

                    if (ImGui::Button("Scale")) {
                        object->SetScale(glm::vec3(x_scale, y_scale, z_scale));
                    }
                }
                ImGui::Spacing();
                ImGui::Unindent();
            }
        }
        ImGui::Unindent();
    }
    if(ImGui::CollapsingHeader("Scene")) {
        if(ImGui::Button("Create New Object")) {
            SceneManager::get().CreateObject();
        }
    }

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
