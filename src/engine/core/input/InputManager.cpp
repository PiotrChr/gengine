#include "InputManager.hpp"

namespace Gengine
{
    InputManager::InputManager() {

    }

    InputManager::~InputManager() {

    }

    bool InputManager::isElemClicked() {
        return false;
    }

    glm::vec2 InputManager::getMousePosition() {
        return mousePosition;
    }

    void InputManager::updateMousePosition(GLFWwindow* window) {
        double x, y;
        
        glfwGetCursorPos(window, &x, &y);

        mousePosition.x = x;
        mousePosition.y = y;
    }

    bool InputManager::isActionTriggered(std::string actionName) {
        return false;
    }

} // namespace Gengine
