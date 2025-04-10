#pragma once

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
            MyWindowing::Settings::WindowSettings         windowSettings;

        private:
            const std::string projectPath;
    };
} // namespace MyApp::Core