#include "WindowManager.hpp"

namespace Gengine {
    
    void WindowManager::init(int width, int height, std::string title) {
        window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    }

    bool WindowManager::isOpen() {
        return window.isOpen();
    }
}
