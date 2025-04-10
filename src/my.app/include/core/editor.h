#pragma once

#include "context.h"

namespace MyApp::Core {
    class Editor {
        public:
            Editor (Context &p_context);
            ~Editor ();

            void PreUpdate ();
            void Update (float p_deltaTime);

        private:
            MyApp::Core::Context &m_context;
    };

} // namespace MyApp::Core