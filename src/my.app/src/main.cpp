#include "core/application.h"
#include <context/device.h>
#include <memory>
#include <settings/device_settings.h>
#include <settings/window_settings.h>
#include <window.h>

int main () {
    MyApp::Core::Application app;
    app.Run ();
    return 0;
}