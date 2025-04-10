#include "window.h"
#include <stdexcept>

MyWindowing::Window::Window (const Context::Device &p_device, const Settings::WindowSettings &p_windowSettings)
    : m_device (p_device)
    , m_size (p_windowSettings.width, p_windowSettings.height)
    , m_title (p_windowSettings.title) {
    CreateGlfwWindow (p_windowSettings);
}

MyWindowing::Window::~Window () {
    glfwDestroyWindow (m_glfwWindow);
    m_glfwWindow = nullptr;
}

void MyWindowing::Window::CreateGlfwWindow (const Settings::WindowSettings &p_windowSettings) {
    GLFWmonitor *selectedMonitor = nullptr;

    if (p_windowSettings.fullscreen) {
        selectedMonitor = glfwGetPrimaryMonitor ();
    }

    glfwWindowHint (GLFW_SAMPLES, p_windowSettings.samples);

    m_glfwWindow = glfwCreateWindow (static_cast<int> (m_size.first), static_cast<int> (m_size.second), m_title.c_str (), selectedMonitor, nullptr);

    if (!m_glfwWindow) {
        throw std::runtime_error ("Failed to create GLFW window!");
    }
}

void MyWindowing::Window::MakeCurrentContext () const {
    glfwMakeContextCurrent (m_glfwWindow);
}

GLFWwindow *MyWindowing::Window::GetGlfwWindow () const {
    return m_glfwWindow;
}

bool MyWindowing::Window::ShouldClose () const {
    return glfwWindowShouldClose (m_glfwWindow);
}
