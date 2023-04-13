#include "OptionsState.hpp"

namespace Gengine {
    OptionsState::OptionsState(GameComponentsRef data): BaseState(data) {
        _settingsLoader = new SettingsLoader();
    };
    
    OptionsState::~OptionsState() {
        delete _settingsLoader;
        
    }

    void OptionsState::cleanup() {
        std::cout << "Destroying" << std::endl;
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

        auto optionsContainer = std::make_shared<OptionsContainer>(_data);
        optionsContainer->setElementSize(sf::Vector2f(600.f, 30.f));
        optionsContainer->setPadding({10.f, 10.f});
        optionsContainer->setElementSpacing(10.f);
        
        optionsContainer->addOption(SETTINGS_RESOLUTION, windowModesStrings, _data->windowManager.getResolution(),
            [this, optionsContainer](std::string option) { 
                std::cout << "Resolution option clicked: " << option << std::endl;
                optionsContainer->setCurrentOption("Resolution", option);
                this->_dirty = true;
        });

        optionsContainer->addOption(SETTINGS_FULLSCREEN, SETTINGS_DEFAULT_OPTIONS_BOOL,
            boolToOption(_data->windowManager.isFullscreen),
            [this, optionsContainer](std::string option) { 
                std::cout << "Fullscreen option clicked: " << option << std::endl;
                optionsContainer->setCurrentOption("Fullscreen", option);
                this->_dirty = true;
        });

        optionsContainer->addOption(SETTINGS_VSYNC, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->windowManager.isVsync),
            [this, optionsContainer](std::string option) { 
                std::cout << "VSync option clicked: " << option << std::endl;
                optionsContainer->setCurrentOption("VSync", option);
                this->_dirty = true;
        });

        optionsContainer->addOption(SETTINGS_ANTIALIASING, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->windowManager.antialiasing),
            [this, optionsContainer](std::string option) { 
                std::cout << "Antialiasing option clicked: " << option << std::endl;
                optionsContainer->setCurrentOption("Antialiasing", option);
                this->_dirty = true;
        });
        
        optionsContainer->addOption(SETTINGS_FRAMERATE, SETTINGS_DEFAULT_FRAMERATES, std::to_string(_data->windowManager.framerate),
            [this, optionsContainer](std::string option) { 
                std::cout << "Framerate Limit option clicked: " << option << std::endl;
                optionsContainer->setCurrentOption("Framerate", option);
                this->_dirty = true;
        });

        optionsContainer->addOption(SETTINGS_MUSIC, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->audioManager.isMusic),
            [this, optionsContainer](std::string option) { 
                std::cout << "Music option clicked: " << option << std::endl;
                optionsContainer->setCurrentOption("Music", option);
                this->_dirty = true;
        });

        optionsContainer->addOption(SETTINGS_SOUND, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->audioManager.isSound),
            [this, optionsContainer](std::string option) {
                std::cout << "Sound option clicked: " << option << std::endl;
                optionsContainer->setCurrentOption("Sound", option);
                this->_dirty = true;
        });

        auto saveButton = std::make_shared<MainMenuButton>(
            _data, "Save", sf::Vector2f(200, 100),
            [this]() {
                std::cout << "Save button clicked" << std::endl;
                // _data->windowManager.setResolution(_optionsContainer.getCurrentOption("Resolution"));
                // _data->windowManager.setFullscreen(_optionsContainer.getCurrentOption("Fullscreen") == "On");
                _settingsLoader->saveSettings(_data);
                _data->stateMachine.removeState();
            }
        );
        
        auto backButton = std::make_shared<MainMenuButton>(
            _data, "Back", sf::Vector2f(200, 100),
            [this]() {
                std::cout << "Back button clicked" << std::endl;
                _data->stateMachine.removeState();
            }
        );

        auto applyButton = std::make_shared<MainMenuButton>(
            _data, "Apply", sf::Vector2f(200, 100),
            [this, optionsContainer]() {
                std::cout << "Apply button clicked" << std::endl;
                _data->windowManager.setResolution(
                    optionsContainer->getCurrentOption("Resolution"),
                    optionsContainer->getCurrentOption("Fullscreen") == "On"
                );
                
                _data->windowManager.changeMode();
            }
        );

        saveButton->init();
        backButton->init();
        applyButton->init();
        
        saveButton->setPosition(sf::Vector2f(
            _data->windowManager.window->getSize().x - saveButton->getSize().x - 10,
            _data->windowManager.window->getSize().y - saveButton->getSize().y - 10
        ));
        backButton->setPosition(sf::Vector2f(
            saveButton->getPosition().x - backButton->getSize().x - 10,
            _data->windowManager.window->getSize().y - backButton->getSize().y - 10
        ));
        applyButton->setPosition(sf::Vector2f(
            backButton->getPosition().x - applyButton->getSize().x - 10,
            _data->windowManager.window->getSize().y - applyButton->getSize().y - 10
        ));
        
        optionsContainer->init();
        optionsContainer->setPosition({
            _data->windowManager.width/2 - optionsContainer->getSize().x/2,
            100
        });

        _hud.addComponent(saveButton);
        _hud.addComponent(backButton);
        _hud.addComponent(applyButton);
        _hud.addComponent(optionsContainer);
    }

     void OptionsState::handleInput(sf::Event event, const float dt) {
        _hud.handleEvent(event, dt);
    }

    void OptionsState::update(float dt) {
        _hud.update(dt);
    }

    void OptionsState::draw(float dt) {
        _data->windowManager.window->clear(sf::Color::Black);
        _data->windowManager.window->draw(_background);
        
        _hud.draw(_data->windowManager.window);
        
        _data->windowManager.window->display();
    }

    std::string OptionsState::boolToOption(bool value) {
        return value ? SETTINGS_DEFAULT_OPTIONS_BOOL_TRUE : SETTINGS_DEFAULT_OPTIONS_BOOL_FALSE;
    }

    void OptionsState::pause() {
        std::cout << "OptionsState paused" << std::endl;
    }

    void OptionsState::resume() {
        std::cout << "OptionsState resumed" << std::endl;
    }
}