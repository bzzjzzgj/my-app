#include "widgets/awidget.h"
#include <imgui/imgui.h>

uint64_t MyUI::Widgets::AWidget::__WIDGET_ID_INCREMENT = 0;

MyUI::Widgets::AWidget::AWidget () {
    m_widgetID = "##" + std::to_string (__WIDGET_ID_INCREMENT++);
}

void MyUI::Widgets::AWidget::Draw () {
    if (enabled) {
        _Draw_Impl ();

        if (!lineBreak) {
            ImGui::SameLine ();
        }
    }
}

MyUI::Internal::WidgetContainer *MyUI::Widgets::AWidget::GetParent () {
    return m_parent;
}

void MyUI::Widgets::AWidget::SetParent (MyUI::Internal::WidgetContainer *p_parent) {
    m_parent = p_parent;
}
bool MyUI::Widgets::AWidget::IsDestroyed () const {
    return m_destroyed;
}

void MyUI::Widgets::AWidget::Destroy () {
    m_destroyed = true;
}
