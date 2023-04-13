#pragma once
#include "globals.hpp"

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

#define SPLASH_STATE_SHOW_TIME 1.0
 
// DEFAULT HUD SETTINGS
#define DEFAULT_HUD_FONT_SIZE 20
#define DEFAULT_HUD_FONT_COLOR sf::Color::White
#define DEFAULT_HUD_FONT_STYLE sf::Text::Regular
#define DEFAULT_HUD_FONT ROOT_RESOURCE_PATH "fonts/Roboto/Roboto-Light.ttf"

#define DEFAULT_HUD_BUTTON_FONT DEFAULT_HUD_FONT
#define DEFAULT_HUD_BUTTON_FONT_SIZE DEFAULT_HUD_FONT_SIZE
#define DEFAULT_HUD_BUTTON_FONT_COLOR DEFAULT_HUD_FONT_COLOR
#define DEFAULT_HUD_BUTTON_FONT_STYLE DEFAULT_HUD_FONT_STYLE
#define DEFAULT_HUD_BUTTON_HAS_BACKGROUND false
#define DEFAULT_HUD_BUTTON_BACKGROUND_COLOR sf::Color::White
#define DEFAULT_HUD_BUTTON_HAS_BORDER false
#define DEFAULT_HUD_BUTTON_BORDER_COLOR sf::Color::Black
#define DEFAULT_HUD_BUTTON_BORDER_SIZE 1
#define DEFAULT_HUD_BUTTON_BORDER_RADIUS 0
#define DEFAULT_HUD_BUTTON_HAS_ICON false
#define DEFAULT_HUD_BUTTON_HOVER_COLOR sf::Color::Magenta
#define DEFAULT_HUD_BUTTON_CLICK_COLOR sf::Color::White
#define DEFAULT_HUD_BUTTON_ICON_POSITION 0
#define DEFAULT_HUD_BUTTON_ICON_SIZE 0
#define DEFAULT_HUD_BUTTON_PADDING sf::Vector2f(0, 0)

// 
#define ACTION_MAIN "MAIN_ACTION"
#define ACTION_SECONDARY "SECONDARY_ACTION"
#define ACTION_TERTIARY "TERTIARY_ACTION"
#define ACTION_MOVE_LEFT "MOVE_LEFT"
#define ACTION_MOVE_RIGHT "MOVE_RIGHT"
#define ACTION_MOVE_UP "MOVE_UP"
#define ACTION_MOVE_DOWN "MOVE_DOWN"
#define ACTION_INTERACT  "INTERACT"
#define ACTION_PAUSE  "PAUSE"
#define ACTION_INVENTORY  "INVENTORY"
#define ACTION_ESCAPE  "ESCAPE"
#define ACTION_DEBUG  "DEBUG"


#define KEY_FULLSCREEN  "FULLSCREEN"
#define KEY_RESOLUTION  "RESOLUTION"
#define KEY_FRAMERATE  "FRAMERATE"
#define KEY_VSYNC  "VSYNC"
#define KEY_ANTIALIASING  "ANTIALIASING"
#define KEY_MUSIC  "MUSIC"
#define KEY_SOUND  "SOUND"
#define KEY_MUSIC_VOLUME  "MUSIC_VOLUME"
#define KEY_SOUND_VOLUME  "SOUND_VOLUME"



#define DEFAULT_MAIN_ACTION sf::Mouse::Left
#define DEFAULT_SECONDARY_ACTION sf::Mouse::Right
#define DEFAULT_TERTIARY_ACTION sf::Mouse::Middle


#define DEFAULT_HUD_DROPDOWN_FONT DEFAULT_HUD_FONT
#define DEFAULT_HUD_DROPDOWN_FONT_SIZE DEFAULT_HUD_FONT_SIZE
#define DEFAULT_HUD_DROPDOWN_FONT_COLOR DEFAULT_HUD_FONT_COLOR
#define DEFAULT_HUD_DROPDOWN_FONT_STYLE DEFAULT_HUD_FONT_STYLE
#define DEFAULT_HUD_DROPDOWN_PADDING sf::Vector2f(0, 0)
#define DEFAULT_HUD_DROPDOWN_HAS_BORDER true
#define DEFAULT_HUD_DROPDOWN_BORDER_SIZE 1
#define DEFAULT_HUD_DROPDOWN_BORDER_COLOR sf::Color::White
#define DEFAULT_HUD_DROPDOWN_BACKGROUND_COLOR sf::Color::Black
#define DEFAULT_HUD_DROPDOWN_MARGIN 10
#define DEFAULT_HUD_DROPDOWN_BUTTON_MARGIN 2
#define DEFAULT_HUD_DROPDOWN_BUTTON_PADDING sf::Vector2f(0, 0)
#define DEFAULT_HUD_DROPDOWN_BUTTON_BORDER_SIZE 1
#define DEFAULT_HUD_DROPDOWN_BUTTON_BORDER_COLOR sf::Color::Black
#define DEFAULT_HUD_DROPDOWN_HOVER_COLOR DEFAULT_HUD_BUTTON_HOVER_COLOR
#define DEFAULT_HUD_DROPDOWN_CLICK_COLOR DEFAULT_HUD_DROPDOWN_HOVER_COLOR

// SETTINGS OPTIONS

#define SETTINGS_RESOLUTION "Resolution"
#define SETTINGS_FULLSCREEN "Fullscreen"
#define SETTINGS_FRAMERATE "Framerate"
#define SETTINGS_VSYNC "Vsync"
#define SETTINGS_ANTIALIASING "Antialiasing"
#define SETTINGS_MUSIC "Music"
#define SETTINGS_SOUND "Sound"


#define SETTINGS_DEFAULT_OPTIONS_BOOL_TRUE "Yes"
#define SETTINGS_DEFAULT_OPTIONS_BOOL_FALSE "No"
#define SETTINGS_DEFAULT_OPTIONS_BOOL {SETTINGS_DEFAULT_OPTIONS_BOOL_TRUE, SETTINGS_DEFAULT_OPTIONS_BOOL_FALSE}
#define SETTINGS_DEFAULT_FRAMERATES {"30", "60", "120", "240"}

// LAYER SETTINGS
#define DROPDROWN_LAYER 500
#define DROPDOWN_ELEMENTS_LAYER 501

#define LAYER_2D_BACKGROUND "2D_BACKGROUND"
#define LAYER_2D_HUD "2D_HUD"
#define LAYER_2D_DROPDOWN_BG "2D_DROPDOWN_BG"
#define LAYER_2D_DROPDOWN "2D_DROPDOWN"

// WORLD SETTINGS
#define BLOCK_SIZE 32

#define CHUNK_LOAD_RADIUS 2
#define CHUNK_UNLOAD_RADIUS 3

#define CHUNK_SIZE_X 100
#define CHUNK_SIZE_Y 100
#define CHUNK_SIZE_Z 50

#define INITIAL_WORLD_SIZE_X_IN_CHUNKS 10
#define INITIAL_WORLD_SIZE_Y_IN_CHUNKS 10
#define INITIAL_WORLD_SIZE_Z_IN_CHUNKS 4

#define WORLD_MAX_SIZE_Z_IN_CHUNKS 4

// BLOCK SETTINGS

#define BLOCK_AIR_COLOR sf::Color(0, 0, 0, 0)
#define BLOCK_DIRT_COLOR sf::Color(100, 100, 100)
#define BLOCK_GRASS_COLOR sf::Color(0, 255, 0)

#define BLOCK_UNDEFINED_COLOR sf::Color(255, 0, 255)

// SAVE SETTINGS

#if _IS_MAC
    #define ROOT_RESOURCE_PATH "../Resources/"
#else
    #define ROOT_RESOURCE_PATH "../resources/"
#endif

#define TEMP_VERT_SHADER SHADERS_FILE_PATH "temp.vert"
#define TEMP_FRAG_SHADER SHADERS_FILE_PATH "temp.frag"

#define SAVE_FILE_PATH ROOT_RESOURCE_PATH "save/"
#define SHADERS_FILE_PATH ROOT_RESOURCE_PATH "shaders/"
#define SAVE_SETTINGS_FILE_PATH "settings.ini"
#define SAVE_MAP_ROOT_PATH SAVE_FILE_PATH "map/"

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
#define SPLASH_SCENE_BACKGROUND_FILEPATH ROOT_RESOURCE_PATH "states/splash/bg.png"

// MAIN MENU
#define MM_SCENE_BACKGROUND_FILEPATH ROOT_RESOURCE_PATH "states/splash/bg.png"
#define MM_SCENE_LOGO_FILEPATH ROOT_RESOURCE_PATH "states/mainMenu/logo.png"
#define MM_SCENE_BUTTON_PLAY ROOT_RESOURCE_PATH "states/mainMenu/play.png"
#define MM_SCENE_BUTTON_OUTER ROOT_RESOURCE_PATH "states/mainMenu/button_outer.png"
#define MM_SCENE_BUTTON_QUIT ROOT_RESOURCE_PATH "states/mainMenu/quit.png"
#define MM_SCENE_BUTTON_TEST ROOT_RESOURCE_PATH "states/mainMenu/test.png"

// QUIT SCREEN
#define QUIT_SCENE_BACKGROUND_FILEPATH ROOT_RESOURCE_PATH "states/quit/bg.png"
#define QUIT_STATE_SHOW_TIME 1.0

// GAME SCREEN
#define GAME_SCENE_BACKGROUND_FILEPATH ROOT_RESOURCE_PATH "states/mainMenu/bg.png"

// TEST GAME SCREEN
#define TEST_GAME_STATE_BACKGROUND_FILEPATH ROOT_RESOURCE_PATH "states/mainMenu/bg.png"
#define TEST_GAME_STATE_SPRITE_FILEPATH ROOT_RESOURCE_PATH "states/testGame/sprite.png"