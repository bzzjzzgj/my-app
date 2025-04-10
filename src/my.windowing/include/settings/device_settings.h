#pragma once

#include <cstdint>

namespace MyWindowing::Settings {
    /**
     * @brief 设备设置
     * @details 该结构体用于存储设备的设置参数
     */
    struct DeviceSettings {
            bool    debugProfile         = false; // 是否启用调试模式
            bool    forwardCompatibility = false; // 是否启用向前兼容性
            uint8_t contextMajorVersion  = 3;     // 主版本号
            uint8_t contextMinorVersion  = 2;     // 次版本号
            uint8_t samples              = 4;     // 抗锯齿级别
    };
} // namespace MyWindowing::Settings