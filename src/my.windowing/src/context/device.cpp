#include "context/device.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

MyWindowing::Context::Device::Device (const Settings::DeviceSettings &p_deviceSettings) {
    int initializationCode = glfwInit ();
    if (initializationCode == GLFW_FALSE) {
        throw std::runtime_error ("Failed to initialize GLFW!");
        glfwTerminate ();
    } else {
        if (p_deviceSettings.debugProfile) {
            glfwWindowHint (GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
        }

        glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, p_deviceSettings.contextMajorVersion);
        glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, p_deviceSettings.contextMinorVersion);
        glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 核心模式（Core Profile）
        glfwWindowHint (GLFW_SAMPLES, p_deviceSettings.samples);

        m_isAlive = true;
    }
}

MyWindowing::Context::Device::~Device () {
    if (m_isAlive) {
        glfwTerminate ();
        m_isAlive = false;
    }
}

void MyWindowing::Context::Device::PollEvents () const {
    glfwPollEvents ();
}

std::pair<int16_t, int16_t> MyWindowing::Context::Device::GetMonitorSize () const {
    const GLFWvidmode *mode = glfwGetVideoMode (glfwGetPrimaryMonitor ());
    return std::pair<int16_t, int16_t> (static_cast<int16_t> (mode->width), static_cast<int16_t> (mode->height));
}

std::array<int, 4> MyWindowing::Context::Device::GetWorkAreaSize () const {
    std::array<int, 4> workArea;
    glfwGetMonitorWorkarea (glfwGetPrimaryMonitor (), workArea.data (), workArea.data () + 1, workArea.data () + 2, workArea.data () + 3);
    return workArea;
}

void MyWindowing::Context::Device::SetVsync (bool p_value) {
    glfwSwapInterval (p_value ? 1 : 0);
    m_vsync = p_value;
}
