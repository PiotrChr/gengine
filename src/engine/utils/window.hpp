#pragma once

#include <tuple>
#include <fstream>
#include <string>
#include "../globals.hpp"
#include "../DEFINITIONS.hpp"


#if _IS_WINDOWS
    #include <windows.h>
#elif _IS_LINUX
    #include <X11/Xlib.h>
#elif _IS_MAC
    #include <CoreGraphics/CGDisplayConfiguration.h>
#endif

namespace Gengine {
    int* getCurrentResolution();
    bool fileExists(const std::string& name);
}