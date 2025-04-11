#pragma once

#include "api/idrawable.h"

namespace MyUI::Modules {
    class Canvas : public MyUI::API::IDrawable {
        public:
            void Draw () override;

        private:
            // Add any private members or methods here
    };
} // namespace MyUI::Modules