#include "core/application.h"

MyApp::Core::Application::Application ()
    : m_context ("test")
    , m_editor (m_context) {}

MyApp::Core::Application::~Application () {}

void MyApp::Core::Application::Run () {
    while (IsRunning ()) {
        m_editor.PreUpdate ();
        m_editor.Update (0.0f);
    }
}

bool MyApp::Core::Application::IsRunning () const {
    return !m_context.window->ShouldClose ();
}