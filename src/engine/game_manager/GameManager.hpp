
#include "../core/asset/AssetManager.hpp"
#include "../core/window/WindowManager.hpp"
#include "../core/input/InputManager.hpp"
#include "../core/object/ObjectManager.hpp"
#include "../game/Game.hpp"

class GameManager {
private:
    Game game;
    AssetManager assetManager;
    InputManager inputManager;
    WindowManager windowManager;
    ObjectManager objectManager;
public:
    GameManager();
    ~GameManager();
};
