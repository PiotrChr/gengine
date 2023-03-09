#include "OptionsState.hpp"

namespace Gengine {
    OptionsState::OptionsState(GameComponentsRef data): BaseState(data), _optionsContainer(data) {
        _settingsLoader = new SettingsLoader();
    };
    
    OptionsState::~OptionsState() {
        delete _settingsLoader;
        
    }

    void OptionsState::cleanup() {
        std::cout << "Destroying" << std::endl;
        _data->renderManager.removeAll2DLayers();
        std::cout << "OptionsState destroyed" << std::endl;
    }

    void OptionsState::init() {
        _data->renderManager.add2DLayer(LAYER_2D_BACKGROUND);
        _data->renderManager.add2DLayer(LAYER_2D_HUD);
        _data->renderManager.add2DLayer(LAYER_2D_DROPDOWN_BG);
        _data->renderManager.add2DLayer(LAYER_2D_DROPDOWN);

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

        _optionsContainer.addOption(SETTINGS_RESOLUTION, windowModesStrings, _data->windowManager.getResolution(),
            [this](std::string option) { 
                std::cout << "Resolution option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Resolution", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(SETTINGS_FULLSCREEN, SETTINGS_DEFAULT_OPTIONS_BOOL,
            boolToOption(_data->windowManager.isFullscreen),
            [this](std::string option) { 
                std::cout << "Fullscreen option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Fullscreen", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(SETTINGS_VSYNC, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->windowManager.isVsync),
            [this](std::string option) { 
                std::cout << "VSync option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("VSync", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(SETTINGS_ANTIALIASING, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->windowManager.antialiasing),
            [this](std::string option) { 
                std::cout << "Antialiasing option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Antialiasing", option);
                this->_dirty = true;
        });
        
        _optionsContainer.addOption(SETTINGS_FRAMERATE, SETTINGS_DEFAULT_FRAMERATES, std::to_string(_data->windowManager.framerate),
            [this](std::string option) { 
                std::cout << "Framerate Limit option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Framerate", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(SETTINGS_MUSIC, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->audioManager.isMusic),
            [this](std::string option) { 
                std::cout << "Music option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Music", option);
                this->_dirty = true;
        });

        _optionsContainer.addOption(SETTINGS_SOUND, SETTINGS_DEFAULT_OPTIONS_BOOL, boolToOption(_data->audioManager.isSound),
            [this](std::string option) { 
                std::cout << "Sound option clicked: " << option << std::endl;
                this->_optionsContainer.setCurrentOption("Sound", option);
                this->_dirty = true;
        });

        _saveButton = MainMenuButton(
            _data, "Save", sf::Vector2f(200, 100),
            [this]() {
                _data->windowManager.setResolution(_optionsContainer.getCurrentOption("Resolution"));
                _data->windowManager.setFullscreen(_optionsContainer.getCurrentOption("Fullscreen") == "On");
                _settingsLoader->saveSettings(_data);
                _data->stateMachine.removeState();
            }
        );
        
        _backButton = MainMenuButton(
            _data, "Back", sf::Vector2f(200, 100),
            [this]() {
                std::cout << "Back button clicked" << std::endl;
                _data->stateMachine.removeState();
            }
        );

        _applyButton = MainMenuButton(
            _data, "Apply", sf::Vector2f(200, 100),
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

        _data->renderManager.addTo2DLayer(LAYER_2D_HUD, GameObjectRef(&_applyButton));
        _data->renderManager.addTo2DLayer(LAYER_2D_HUD, GameObjectRef(&_backButton));
        _data->renderManager.addTo2DLayer(LAYER_2D_HUD, GameObjectRef(&_saveButton));
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

    void OptionsState::draw(float dt) {
        _data->windowManager.window->clear(sf::Color::Black);
        _data->windowManager.window->draw(_background);

        for (GameObjectRef item: _data->renderManager.popLayer(LAYER_2D_HUD)) {
            item->draw(_data->windowManager.window);
        }

        for (GameObjectRef item: _data->renderManager.popLayer(LAYER_2D_DROPDOWN_BG)) {
            item->draw(_data->windowManager.window);
        }

        for (GameObjectRef item: _data->renderManager.popLayer(LAYER_2D_DROPDOWN)) {
            item->draw(_data->windowManager.window);
        }
        
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