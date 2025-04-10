#include "core/editor.h"

MyApp::Core::Editor::Editor (Context &p_context)
    : m_context (p_context) {}

MyApp::Core::Editor::~Editor () {}

void MyApp::Core::Editor::PreUpdate () {
    m_context.device->PollEvents ();
}

void MyApp::Core::Editor::Update (float p_deltaTime) {}
