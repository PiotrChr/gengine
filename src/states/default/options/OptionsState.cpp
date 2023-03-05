#include "OptionsState.hpp"

namespace Gengine {
    OptionsState::OptionsState(GameComponentsRef& data): BaseState(data), _optionsContainer(data) {
        _settingsLoader = new SettingsLoader();
    };
    
    OptionsState::~OptionsState() {
        delete _settingsLoader;
    }

    void OptionsState::handleInput(sf::Event event, const float dt) {
        _optionsContainer.handleInput(event, dt);
        _backButton.handleInput(event, dt);
        _saveButton.handleInput(event, dt);
        _applyButton.handleInput(event, dt);
    }

    void OptionsState::update(float dt) {
        _optionsContainer.update(dt);
        _backButton.update(dt);
        _saveButton.update(dt);
        _applyButton.update(dt);
    }

    void OptionsState::init() {
        _data->assetManager.loadTexture("Main Menu Background", MM_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assetManager.getTexture("Main Menu Background"));
        scaleToWindow(_background);

        auto windowModes = _data->windowManager.getVideoModes();

        std::vector<std::string> windowModesStrings;
        for (auto mode : windowModes) {
            windowModesStrings.push_back(mode.first);
        }

        _optionsContainer.setElementSize(sf::Vector2f(600.f, 30.f));
        _optionsContainer.setPadding({10.f, 10.f});
        _optionsContainer.setElementSpacing(10.f);

        _optionsContainer.addOption(
            "Resolution",
            windowModesStrings,
            _data->windowManager.getResolution(),
            [this](std::string option) { 
                std::cout << "Resolution option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Resolution", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(
            "Fullscreen",
            {"On", "Off"},
            _data->windowManager.isFullscreen ? "On" : "Off",
            [this](std::string option) { 
                std::cout << "Fullscreen option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Fullscreen", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(
            "VSync",
            {"On", "Off"},
            _data->windowManager.isVsync ? "On" : "Off",
            [this](std::string option) { 
                std::cout << "VSync option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("VSync", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(
            "Antialiasing",
            {"On", "Off"},
            _data->windowManager.antialiasing ? "On" : "Off",
            [this](std::string option) { 
                std::cout << "Antialiasing option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Antialiasing", option);
                this->_dirty = true;
        });
        
        _optionsContainer.addOption(
            "Framerate",
            {"30", "60", "120", "240", "Unlimited"},
            std::to_string(_data->windowManager.framerate),
            [this](std::string option) { 
                std::cout << "Framerate Limit option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Framerate", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(
            "Music",
            {"On", "Off"},
            _data->audioManager.isMusic ? "On" : "Off",
            [this](std::string option) { 
                std::cout << "Music option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Music", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(
            "Sound",
            {"On", "Off"},
            _data->audioManager.isSound ? "On" : "Off",
            [this](std::string option) { 
                std::cout << "Sound option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Sound", option);
                this->_dirty = true;
        });

        _saveButton = MainMenuButton(
            _data,
            "Save",
            sf::Vector2f(200, 100),
            [this]() {
                _data->windowManager.setResolution(_optionsContainer.getCurrentOption("Resolution"));
                _data->windowManager.setFullscreen(_optionsContainer.getCurrentOption("Fullscreen") == "On");
                _settingsLoader->saveSettings(_data);
                _data->stateMachine.removeState();
            }
        );
        
        _backButton = MainMenuButton(
            _data,
            "Back",
            sf::Vector2f(200, 100),
            [this]() {
                std::cout << "Back button clicked" << std::endl;
                _data->stateMachine.removeState();
            }
        );

        _applyButton = MainMenuButton(
            _data,
            "Apply",
            sf::Vector2f(200, 100),
            [this]() {
                _data->windowManager.setResolution(
                    _optionsContainer.getCurrentOption("Resolution"),
                    _optionsContainer.getCurrentOption("Fullscreen") == "On"
                );
                
                _data->windowManager.changeMode();
            }
        );

        _backButton.init();
        _saveButton.init();
        _applyButton.init();

        // align horizontally save, back and apply buttons to bottom right
        _saveButton.setPosition(sf::Vector2f(
            _data->windowManager.window->getSize().x - _saveButton.getSize().x - 10,
            _data->windowManager.window->getSize().y - _saveButton.getSize().y - 10
        ));
        _backButton.setPosition(sf::Vector2f(
            _saveButton.getPosition().x - _backButton.getSize().x - 10,
            _data->windowManager.window->getSize().y - _backButton.getSize().y - 10
        ));
        _applyButton.setPosition(sf::Vector2f(
            _backButton.getPosition().x - _applyButton.getSize().x - 10,
            _data->windowManager.window->getSize().y - _applyButton.getSize().y - 10
        ));
        
        _optionsContainer.init();
        _optionsContainer.setPosition({
            _data->windowManager.width/2 - _optionsContainer.getSize().x/2,
            100
        });
    }

    void OptionsState::setResolution(std::string option) {
        std::cout << "2 Set resolution to " << "123" << std::endl;
    }

    void OptionsState::draw(float dt) {
        _data->windowManager.window->clear(sf::Color::Black);
        _data->windowManager.window->draw(_background);

        _optionsContainer.draw(_data->windowManager.window, dt);
        _backButton.draw(_data->windowManager.window);
        _saveButton.draw(_data->windowManager.window);
        _applyButton.draw(_data->windowManager.window);

        _data->windowManager.window->display();
    }

    

    void OptionsState::pause() {
        std::cout << "OptionsState paused" << std::endl;
    }

    void OptionsState::resume() {
        std::cout << "OptionsState resumed" << std::endl;
    }
}