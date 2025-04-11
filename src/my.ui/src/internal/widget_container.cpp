#include "internal/widget_container.h"
#include "internal/e_memory_mode.h"
#include <algorithm>
#include <iterator>
#include <ranges>
#include <span>

// void MyUI::Internal::WidgetContainer::ConsiderWidget (Widgets::AWidget &p_widget, bool p_manageMemory) {
//     m_widgets.emplace_back (std::make_pair (&p_widget, p_manageMemory ? EMemoryMode::INTERNAL_MANAGMENT : EMemoryMode::EXTERNAL_MANAGMENT));
//     p_widget.SetParent (this);
// }

// void MyUI::Internal::WidgetContainer::CollectGarbages () {
//     m_widgets.erase (std::remove_if (m_widgets.begin (), m_widgets.end (),
//                          [] (const std::pair<Widgets::AWidget *, Internal::EMemoryMode> &p_item) {
//                              bool toDestroy = p_item.first && p_item.first->IsDestroyed ();
//                              if (toDestroy && p_item.second == EMemoryMode::INTERNAL_MANAGMENT) {
//                                  delete p_item.first;
//                              }
//                              return toDestroy;
//                          }),
//         m_widgets.end ());
// }

// void MyUI::Internal::WidgetContainer::DrawWidgets () {
//     CollectGarbages ();

//     using WidgetType = decltype (m_widgets)::value_type::first_type;

//     std::vector<WidgetType> widgetsToDraw;
//     widgetsToDraw.reserve (m_widgets.size ());
//     // std::transform (m_widgets.begin (), m_widgets.end (), std::back_inserter (widgetsToDraw), [] (const auto &pair) { return pair.first; });
//     std::ranges::copy (m_widgets | std::views::keys, std::back_inserter (widgetsToDraw));
//     // if (m_reversedDrawOrder) [[unlikely]] {
//     //     for (WidgetType widget : widgetsToDraw | std::views::reverse) {
//     //         widget->Draw ();
//     //     }
//     // } else {
//     //     for (WidgetType widget : widgetsToDraw) {
//     //         widget->Draw ();
//     //     }
//     // }
// }
