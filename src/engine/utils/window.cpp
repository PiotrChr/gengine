#include "window.hpp"

namespace Gengine {
    int* getCurrentResolution() {
        int* resolution = new int[2];

        #if _IS_WINDOWS
            resolution[0] = GetSystemMetrics(SM_CXSCREEN);
            resolution[1] = GetSystemMetrics(SM_CYSCREEN);
        #elif _IS_LINUX
            resolution[0] = GetSystemMetrics(SM_CXSCREEN);
            resolution[1] = GetSystemMetrics(SM_CYSCREEN);
        #elif _IS_MAC
            auto mainDisplayId = CGMainDisplayID();

            resolution[0] = CGDisplayPixelsWide(mainDisplayId);
            resolution[1] = CGDisplayPixelsHigh(mainDisplayId);
        #endif

        return resolution;
    }

    bool fileExists(const std::string& name) {
        std::ifstream f(name.c_str());
        return f.good();
    }
}