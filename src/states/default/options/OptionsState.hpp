#pragma once 

#include "../../../engine/DEFINITIONS.hpp"
#include "../../BaseState.hpp"
#include "../../../engine/game/GameComponents.hpp"
#include "../../../engine/core/save/SettingsLoader.hpp"
#include "../../../engine/core/object/Hud.hpp"
#include "../../../gameObjects/hud/mainMenu/MainMenuButton.hpp"
#include "../../../gameObjects/hud/options/OptionsContainer.hpp"

namespace Gengine {
    class OptionsState : public BaseState {
    public:
        OptionsState(GameComponentsRef data);
        ~OptionsState();
        void init();
        void handleInput(sf::Event event, const float dt);
        void update(float dt);
        void cleanup();
        void draw(float dt);
        void pause();
        void resume();
    private:
        sf::Sprite _background;
        Hud _hud;
        // OptionsContainer _optionsContainer;
        // MainMenuButton _backButton;
        // MainMenuButton _saveButton;
        std::shared_ptr<GameObject> _applyButton;
        SettingsLoader* _settingsLoader;
        bool _dirty = false;

        std::string boolToOption(bool value);
    };
}