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
        for(int i = 0; i < objects; i++) {
            GameObject& object = scene->GetObject(i);

            if(ImGui::CollapsingHeader(object.GetName().c_str())) {
                ImGui::Indent();

                std::string id_text = "ID: " + std::to_string(object.GetID());
                ImGui::Text(id_text.c_str());
                bool isHidden = object.IsHidden();

                std::string components_text = "Components: " + std::to_string(object.GetAllComponents().size());
                ImGui::Text(components_text.c_str());

                if (ImGui::Checkbox("Hide", &isHidden)) {
                    object.ToggleHidden();
                }

                if(ImGui::CollapsingHeader("position")) {
                    ImGui::InputFloat("X Pos", &x_pos, 0.1f, 0.1f, "%.1f");
                    ImGui::InputFloat("Y Pos", &y_pos, 0.1f, 0.1f, "%.1f");
                    ImGui::InputFloat("Z Pos", &z_pos, 0.1f, 0.1f, "%.1f");

                    if(ImGui::Button("Move")) {
                        object.SetPosition(glm::vec3(x_pos, y_pos, z_pos));
                    }
                }
                ImGui::Spacing();
                ImGui::Unindent();
            }
        }
    }
    
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
