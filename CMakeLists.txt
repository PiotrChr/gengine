cmake_minimum_required(VERSION 3.22)
project(GEngine)
set(CMAKE_CXX_STANDARD 17)

if(NOT TARGET_DEB OR NOT TARGET_MAC OR NOT TARGET_RASP_ARM)
    set(TARGET_DEB)
endif()

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(GLOB SOURCES 
"src/main.cpp"

"src/engine/DEFINITIONS.hpp"
"src/engine/game/GameComponents.hpp"


"src/engine/utils/window.cpp"
"src/engine/gameManager/GameManager.cpp"
"src/engine/game/Game.cpp"
# "src/engine/core/gfx/BlockRenderer.cpp"
# "src/engine/core/gfx/Cube.cpp"
# "src/engine/core/gfx/Shader.cpp"
"src/engine/core/audio/AudioManager.cpp"
# "src/engine/core/asset/AssetManager.cpp"
"src/engine/core/input/InputManager.cpp"
# "src/engine/core/object/ObjectManager.cpp"
# "src/engine/core/object/InGameObject.cpp"
# "src/engine/core/object/Hud.cpp"
# "src/engine/core/object/HudObject.cpp"
# "src/engine/core/object/hud/elements/Button.cpp"
# "src/engine/core/object/hud/elements/Label.cpp"
# "src/engine/core/object/hud/elements/LabeledDropDown.cpp"
# "src/engine/core/object/hud/elements/GameRectangle.cpp"

# "src/engine/core/state/State.hpp"
# "src/engine/core/state/State.cpp"
# "src/engine/core/state/StateMachine.cpp"
"src/engine/core/window/WindowManager.cpp"
# "src/engine/core/world/generator/WorldGenerator.cpp"
# "src/engine/core/world/generator/CaveGenerator.cpp"
# "src/engine/core/world/loader/WorldLoader.cpp"
# "src/engine/core/world/World.cpp"
# "src/engine/core/world/Chunk.cpp"
# "src/engine/core/save/SaveGameManager.cpp"
"src/engine/core/save/SettingsLoader.cpp"
# "src/engine/core/audio/AudioManager.cpp"

# "src/states/BaseState.cpp"
# "src/states/default/splash/SplashState.cpp"
# "src/states/default/mainMenu/MainMenuState.cpp"
# "src/states/default/quit/QuitState.cpp"
# "src/states/game/BaseGameState.cpp"

# "src/states/game/TestGameState.cpp"
# "src/states/game/GameState.cpp"
# "src/states/game/GameSetupState.cpp"
# "src/states/default/options/OptionsState.cpp"

# "src/gameObjects/player/TestPlayer.cpp"
# "src/gameObjects/player/Player.cpp"

# "src/gameObjects/hud/mainMenu/MainMenuButton.cpp"
# "src/gameObjects/hud/game/GameButton.cpp"
# "src/gameObjects/hud/options/OptionsContainer.cpp"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

if(TARGET_MAC)
    set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/mac_x64/")
    set(MOLTENVK_LIBRARY "${LIB_DIR}/libMoltenVK.dylib")
    set(FRAMEWORKS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/frameworks/")
    set(INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/mac_x64/")
elseif(TARGET_WIN)
    set (LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/win_x64")
    set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/win_x64/)
elseif(TARGET_DEB)
    set (LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/deb_x64")
    set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/deb_x64/)    
elseif(TARGET_RASP_ARM)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/deb_rasp_arm/)
else()
    message("Target is not set")
endif()

# find_package(OpenGL REQUIRED)

include_directories(${INCLUDES_DIR})

if (TARGET_MAC)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})

    set_target_properties(${PROJECT_NAME} PROPERTIES
        BUNDLE True
        MACOSX_BUNDLE_GUI_IDENTIFIER com.pchrusciel.${PROJECT_NAME}
        MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME}
        MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/gengine.plist.in
    )
else()
    add_executable(${PROJECT_NAME} ${SOURCES})
endif()

if (TARGET_MAC)
    target_link_libraries(${PROJECT_NAME} "${LIB_DIR}/libMoltenVK.dylib")
    target_link_libraries(${PROJECT_NAME} "-framework CoreGraphics" "-framework Foundation")
    target_link_libraries(${PROJECT_NAME} ${MOLTENVK_LIB_DIRS})
endif()

target_link_libraries(${PROJECT_NAME} "${LIB_DIR}/libglfw.3.3.dylib")

if(!TARGET_MAC)
    install(
        TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
        COMPONENT library
    )
endif()

if (TARGET_MAC)
    install(
        DIRECTORY ${FRAMEWORKS_DIR}
        DESTINATION ${CMAKE_BINARY_DIR}/Gengine.app/Contents/Frameworks
    )

    install(
        DIRECTORY ${PROJECT_SOURCE_DIR}/lib/mac_x64/
        DESTINATION ${CMAKE_BINARY_DIR}/GEngine.app/Contents/Frameworks
    )

    install(
        DIRECTORY ${PROJECT_SOURCE_DIR}/resources/
        DESTINATION ${CMAKE_BINARY_DIR}/GEngine.app/Contents/Resources
    )

    # install(
    #     FILES ${PROJECT_SOURCE_DIR}/scripts/launch.sh
    #     DESTINATION ${CMAKE_BINARY_DIR}/GEngine.app/Contents/MacOS/
    # )

    add_custom_command(TARGET GEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/scripts/"
            $<TARGET_FILE_DIR:GEngine>)

    install(CODE "
        include(BundleUtilities)
        fixup_bundle(\"${CMAKE_BINARY_DIR}/GEngine.app\" \"\" \"${LIB_DIR}\")
    " COMPONENT Runtime
    )

    
    # add_custom_command(TARGET GEngine POST_BUILD
    #     COMMAND ${CMAKE_COMMAND} -E copy_directory
    #     "${PROJECT_SOURCE_DIR}/resources/"
    #     $<TARGET_FILE_DIR:GEngine>/../Resources)
endif()

# add_custom_command(TARGET GEngine POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#         "${PROJECT_SOURCE_DIR}/resources/"
#         $<TARGET_FILE_DIR:GEngine>/resources/)

#configure_file(resources/shaders/default.frag res/default.frag COPYONLY)
#configure_file(resources/shaders/default.vert res/default.vert COPYONLY)
#configure_file(resources/shaders/gof.vert res/gof.vert COPYONLY)
#configure_file(resources/shaders/gof.frag res/gof.frag COPYONLY)
#configure_file(resources/shaders/gof_display.frag res/gof_display.frag COPYONLY)

#set(RESOURCE_FILES
#    resources/shaders/default.frag
#    resources/shaders/default.vert
#    resources/shaders/gof.vert
#    resources/shaders/gof.frag
#    resources/shaders/gof_display.frag
#    )
