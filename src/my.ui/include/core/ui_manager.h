#pragma once

#include "styling/e_style.h"
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <string>

namespace MyUI::Core {
    /**
     * Class that manages the UI
     */
    class UIManager {
        public:
            UIManager (GLFWwindow *p_glfwWindow, Styling::EStyle p_style = Styling::EStyle::IM_DARK_STYLE, const std::string &p_glslVersion = "#version 150");
            ~UIManager ();

            void EnableDocking (bool p_value);

        private:
            // Add any private members or methods here
            bool        m_dockingState;
            std::string m_layoutSaveFilename = "imgui.ini";
    };
} // namespace MyUI::Core