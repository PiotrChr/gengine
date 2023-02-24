#pragma once


// DEAULT SETTINGS
#define DEFAULT_SCREEN_WIDTH 1024
#define DEFAULT_SCREEN_HEIGHT 768
#define DEFAULT_RESOLUTION "1024x768"
#define DEFAULT_FULLSCREEN false
#define DEFAULT_FRAMERATE 60
#define DEFAULT_VSYNC false
#define DEFAULT_ANTIALIASING 0
#define DEFAULT_MUSIC true
#define DEFAULT_SOUND true
#define DEFAULT_MUSIC_VOLUME 100
#define DEFAULT_SOUND_VOLUME 100

#define SPLASH_STATE_SHOW_TIME 2.0

// SAVE SETTINGS
#define SAVE_FILE_PATH "../resources/save/save.txt"
#define SAVE_SETTINGS_FILE_PATH "settings.ini"

// DEFAULT KEY BINDINGS
#define DEFAULT_MOVE_UP sf::Keyboard::W
#define DEFAULT_MOVE_DOWN sf::Keyboard::S
#define DEFAULT_MOVE_LEFT sf::Keyboard::A
#define DEFAULT_MOVE_RIGHT sf::Keyboard::D
#define DEFAULT_INTERACT sf::Keyboard::E
#define DEFAULT_PAUSE sf::Keyboard::P
#define DEFAULT_INVENTORY sf::Keyboard::I
#define DEFAULT_ESCAPE sf::Keyboard::Escape
#define DEFAULT_DEBUG sf::Keyboard::F3

// SPLASH SCREEN
#define SPLASH_SCENE_BACKGROUND_FILEPATH "../resources/states/splash/bg.png"

// MAIN MENU
#define MM_SCENE_BACKGROUND_FILEPATH "../resources/states/splash/bg.png"
#define MM_SCENE_LOGO_FILEPATH "../resources/states/mainMenu/logo.png"
#define MM_SCENE_BUTTON_PLAY "../resources/states/mainMenu/play.png"
#define MM_SCENE_BUTTON_OUTER "../resources/states/mainMenu/button_outer.png"
#define MM_SCENE_BUTTON_QUIT "../resources/states/mainMenu/quit.png"
#define MM_SCENE_BUTTON_TEST "../resources/states/mainMenu/test.png"

// QUIT SCREEN
#define QUIT_SCENE_BACKGROUND_FILEPATH "../resources/states/quit/bg.png"
#define QUIT_STATE_SHOW_TIME 3.0

// GAME SCREEN
#define GAME_SCENE_BACKGROUND_FILEPATH "../resources/states/mainMenu/bg.png"

// TEST GAME SCREEN
#define TEST_GAME_STATE_BACKGROUND_FILEPATH "../resources/states/mainMenu/bg.png"
#define TEST_GAME_STATE_SPRITE_FILEPATH "../resources/states/testGame/sprite.png"