#pragma once

#include "settings/device_settings.h"
#include <array>
#include <utility>

namespace MyWindowing::Context {
    class Device {
        public:
            Device (const Settings::DeviceSettings &p_deviceSettings);
            ~Device ();

            void                        PollEvents () const;
            std::pair<int16_t, int16_t> GetMonitorSize () const;
            std::array<int, 4>          GetWorkAreaSize () const;
            void                        SetVsync (bool p_value);

        private:
            bool m_isAlive = false;
            bool m_vsync   = true;
    };

} // namespace MyWindowing::Context