#pragma once

#include "context/device.h"
#include "settings/window_settings.h"
#include <GLFW/glfw3.h>

namespace MyWindowing {
    class Window {
        public:
            Window (const Context::Device &p_device, const Settings::WindowSettings &p_windowSettings);
            ~Window ();

            void        MakeCurrentContext () const; // 设置当前上下文
            GLFWwindow *GetGlfwWindow () const;      // 获取 Glfw 窗口 返回： GLFWwindow* 窗口指针
            bool        ShouldClose () const;        // 检查窗口是否关闭 返回： true 窗口已关闭，false 窗口未关闭

        private:
            void CreateGlfwWindow (const Settings::WindowSettings &p_settings); // 创建 Glfw 窗口

        private:
            const Context::Device        &m_device;
            GLFWwindow                   *m_glfwWindow;
            std::string                   m_title;
            std::pair<uint16_t, uint16_t> m_size;
    };
} // namespace MyWindowing