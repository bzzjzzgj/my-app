#include "core/ui_manager.h"

MyUI::Core::UIManager::UIManager (GLFWwindow *p_glfwWindow, Styling::EStyle p_style, const std::string &p_glslVersion) {
    ImGui::CreateContext ();
    ImGuiIO &io                          = ImGui::GetIO ();
    io.ConfigWindowsMoveFromTitleBarOnly = true;

    EnableDocking (false);

    ImGui_ImplGlfw_InitForOpenGL (p_glfwWindow, true);
    ImGui_ImplOpenGL3_Init (p_glslVersion.data ());
}

MyUI::Core::UIManager::~UIManager () {}

void MyUI::Core::UIManager::EnableDocking (bool p_value) {
    m_dockingState = p_value;
    if (p_value)
        ImGui::GetIO ().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    else
        ImGui::GetIO ().ConfigFlags &= ~ImGuiConfigFlags_DockingEnable;
}
