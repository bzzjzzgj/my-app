#pragma once

#include <cstdint>
#include <string>

namespace MyWindowing::Settings {
    /**
     * @brief 窗口设置
     * @details 该结构体用于存储窗口的设置参数
     */
    struct WindowSettings {
            std::string title      = "我的窗口"; // 窗口标题
            uint16_t    width      = 800;        // 窗口宽度
            uint16_t    height     = 600;        // 窗口高度
            bool        fullscreen = false;      // 是否全屏
            uint32_t    samples    = 4;          // 抗锯齿级别
            int16_t     x          = 0;          // 窗口位置 X 坐标
            int16_t     y          = 0;          // 窗口位置 Y 坐标
    };
} // namespace MyWindowing::Settings