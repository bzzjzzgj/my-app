#pragma once

#include "context.h"
#include "editor.h"

namespace MyApp::Core {
    class Application {
        public:
            Application ();
            ~Application ();

            void Run ();
            bool IsRunning () const;

        private:
            Context m_context;
            Editor  m_editor;
    };

} // namespace MyApp::Core