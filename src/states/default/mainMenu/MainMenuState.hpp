#include "../../../engine/DEFINITIONS.hpp"
#include "../../BaseState.hpp"
#include "../../../engine/game/GameComponents.hpp"
#include "../../../gameObjects/hud/mainMenu/MainMenuButton.hpp"


namespace Gengine {
    class MainMenuState : public BaseState {
    public:
        MainMenuState(GameComponentsRef& data): BaseState(data) {};
        ~MainMenuState() {};
        void init();
        void handleInput(sf::Event event, const float dt);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
    private:
        sf::Sprite _background;
        MainMenuButton _playButton;
        MainMenuButton _quitButton;
        MainMenuButton _testButton;
        sf::Sprite _title;
    };
}