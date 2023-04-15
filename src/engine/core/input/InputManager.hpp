#pragma once

#include <string>
#include <map>
#include <glm/vec2.hpp>
#include <GLFW/glfw3.h>

namespace Gengine {
    class InputManager {
    public:
        InputManager();
        ~InputManager();

        bool isElemClicked();
        void initKeys();
        bool isActionTriggered(std::string actionName);
        glm::vec2 getMousePosition();
        void updateMousePosition(GLFWwindow* window);
        std::map<std::string, int> keyBinds;
        std::map<std::string, int> mouseBinds;
    private:
        glm::vec2 mousePosition;
    };
}
