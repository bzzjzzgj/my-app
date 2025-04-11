#pragma once

#include "widgets/awidget.h"
#include <vector>

namespace MyUI::Internal {
    class WidgetContainer {
        public:
            // WidgetContainer ();
            virtual ~WidgetContainer ();

            // void ConsiderWidget (MyUI::Widgets::AWidget &p_widget, bool p_manageMemory = true);
            // void CollectGarbages ();
            // void DrawWidgets ();

        protected:
            std::vector<std::pair<Widgets::AWidget *, bool>> m_widgets;

        private:
            // Add any private members or methods here
    };
} // namespace MyUI::Internal