#pragma once

#include "api/idrawable.h"
#include <cstdint>
#include <string>

namespace MyUI::Internal {
    class WidgetContainer;
}

namespace MyUI::Widgets {
    class AWidget : public MyUI::API::IDrawable {
        public:
            AWidget ();
            virtual void                     Draw () override;
            MyUI::Internal::WidgetContainer *GetParent ();
            void                             SetParent (MyUI::Internal::WidgetContainer *p_parent);
            bool                             IsDestroyed () const;
            void                             Destroy ();

        protected:
            virtual void _Draw_Impl () = 0;

        public:
            bool enabled   = true;
            bool lineBreak = true;

        protected:
            Internal::WidgetContainer *m_parent;
            std::string                m_widgetID = "?";

        private:
            static uint64_t __WIDGET_ID_INCREMENT;
            bool            m_destroyed = false;
    };
} // namespace MyUI::Widgets
