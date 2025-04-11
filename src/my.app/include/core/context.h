#pragma once

#include <core/ui_manager.h>
#include <memory>
#include <window.h>

namespace MyApp::Core {
    class Context {
        public:
            Context (const std::string &p_projectPath);
            ~Context ();

        public:
            std::unique_ptr<MyWindowing::Context::Device> device;
            std::unique_ptr<MyWindowing::Window>          window;
            std::unique_ptr<MyUI::Core::UIManager>        uiManager;
            MyWindowing::Settings::WindowSettings         windowSettings;

        private:
            const std::string projectPath;
    };
} // namespace MyApp::Core