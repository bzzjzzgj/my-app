#include "core/context.h"
#include <array>

constexpr std::array<std::pair<int, int>, 13> kResolutions{
    std::make_pair (640, 360),   // nHD
    std::make_pair (854, 480),   // FWVGA
    std::make_pair (960, 540),   // qHD
    std::make_pair (1024, 576),  // WSVGA
    std::make_pair (1280, 720),  // HD
    std::make_pair (1366, 768),  // FWXGA
    std::make_pair (1600, 900),  // HD+
    std::make_pair (1920, 1080), // Full HD
    std::make_pair (2560, 1440), // QHD
    std::make_pair (3200, 1800), // QHD+
    std::make_pair (3840, 2160), // 4K UHD
    std::make_pair (5120, 2880), // 5K
    std::make_pair (7680, 4320), // 8K UHD
};

std::array<int, 4> FindBestFitWindowSizeAndPosition (std::array<int, 4> p_workAreaSize) {
    // Extract work area dimensions
    int workAreaX      = p_workAreaSize[0];
    int workAreaY      = p_workAreaSize[1];
    int workAreaWidth  = p_workAreaSize[2];
    int workAreaHeight = p_workAreaSize[3];

    // Iterate over available resolutions
    for (auto it = kResolutions.rbegin (); it != kResolutions.rend (); ++it) {
        int width  = it->first;
        int height = it->second;

        // Check if resolution fits within work area
        if (width <= workAreaWidth && height <= workAreaHeight) {
            // Center the resolution within the work area
            int posX = workAreaX + workAreaWidth / 2 - width / 2;
            int posY = workAreaY + workAreaHeight / 2 - height / 2;

            return {posX, posY, width, height};
        }
    }

    return {};
}

MyApp::Core::Context::Context (const std::string &p_projectPath)
    : projectPath (p_projectPath) {
    MyWindowing::Settings::DeviceSettings deviceSettings;
    deviceSettings.contextMajorVersion = 4;
    deviceSettings.contextMinorVersion = 3;

    device                                  = std::make_unique<MyWindowing::Context::Device> (deviceSettings);
    const auto workAreaSize                 = device->GetWorkAreaSize ();
    const auto bestFitWindowSizeAndPosition = FindBestFitWindowSizeAndPosition (workAreaSize);
    windowSettings.x                        = bestFitWindowSizeAndPosition[0];
    windowSettings.y                        = bestFitWindowSizeAndPosition[1];
    windowSettings.width                    = bestFitWindowSizeAndPosition[2];
    windowSettings.height                   = bestFitWindowSizeAndPosition[3];

    window = std::make_unique<MyWindowing::Window> (*device, windowSettings);
    window->MakeCurrentContext ();

    uiManager = std::make_unique<MyUI::Core::UIManager> (window->GetGlfwWindow (), MyUI::Styling::EStyle::IM_LIGHT_STYLE);
    uiManager->EnableDocking (true);

    device->SetVsync (true);
}

MyApp::Core::Context::~Context () {}
