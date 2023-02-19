#include "../../../engine/DEFINITIONS.hpp"
#include "../BaseState.hpp"
#include "../../../engine/game/GameComponents.hpp"


namespace Gengine {
    class MainMenuState : public BaseState {
    public:
        MainMenuState(GameComponentsRef& data) : BaseState(data) {};
        ~MainMenuState() {};
        void init();
        void handleInput(sf::Event event);
        void update(float dt);
        void draw(float dt);
        void pause();
        void resume();
    private:
        sf::Sprite _background;
        sf::Sprite _playButton;
        sf::Sprite _playButtonOuter;
        sf::Sprite _quitButton;
        sf::Sprite _testButton;
        sf::Sprite _title;
    };
}