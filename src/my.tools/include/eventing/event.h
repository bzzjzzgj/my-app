#pragma once

#include <functional>
#include <cstdint>

namespace MyTools::Eventing
{
    using ListenerID = uint64_t;

    template <class... ArgTypes>
    class Event
    {
    public:
        /**
         * @brief 通用函数的简单快捷方式，没有返回值
         */
        using Callback = std::function<void(ArgTypes...)>;

        /**
         * @brief 将一个函数回调添加到此事件,同时返回新监听器的ID（如果你想以后移除监听器，你应该存储返回的ID）。
         * @param p_callback 要添加的监听器函数
         * @return 监听器的ID
         */
        ListenerID AddListener(Callback p_callback);

        /**
         * @brief 为此事件添加一个函数回调,同时返回新监听器的ID（如果你想以后移除监听器，你应该存储返回的ID）
         */
        ListenerID operator+=(Callback p_callback);

        /**
         * @brief 从事件中移除一个监听器
         * @param p_listener_id 要移除的监听器的ID
         */
        bool RemoveListener(ListenerID p_listenerID);

        /**
         * @brief 从事件中移除一个监听器
         * @param p_listener_id 要移除的监听器的ID
         */
        bool operator-=(ListenerID p_listenerID);

        void RemoveAllListeners();

        uint64_t GetListenerCount();

        void Invoke(ArgTypes... p_args);

    private:
        std::unordered_map<ListenerID, Callback> m_callbacks;
        ListenerID m_availableListenerID = 0;
    };
}

#include "event.inl" // 包含实现文件，以确保模板类的定义在使用时可见。这是一个常见的做法，因为模板类的定义通常放在头文件中，而实现放在源文件中。这样可以确保在使用模板类时，编译器能够找到其定义。