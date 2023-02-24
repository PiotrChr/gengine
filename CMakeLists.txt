cmake_minimum_required(VERSION 3.22)
project(GEngine)
set(CMAKE_CXX_STANDARD 17)

if(NOT TARGET_DEB OR NOT TARGET_MAC OR NOT TARGET_RASP_ARM)
    set(TARGET_DEB)
endif()

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CUR_TARGET GEngine)

file(GLOB SOURCES 
"src/main.cpp"

"src/engine/DEFINITIONS.hpp"
"src/engine/game/GameComponents.hpp"


"src/engine/utils/window.cpp"
"src/engine/gameManager/GameManager.cpp"
"src/engine/game/Game.cpp"
"src/engine/core/audio/AudioManager.cpp"
"src/engine/core/asset/AssetManager.cpp"
"src/engine/core/input/InputManager.cpp"
"src/engine/core/object/ObjectManager.cpp"
"src/engine/core/object/InGameObject.cpp"
"src/engine/core/state/State.hpp"
"src/engine/core/state/State.cpp"
"src/engine/core/state/StateMachine.cpp"
"src/engine/core/window/WindowManager.cpp"
"src/engine/core/world/generator/WorldGenerator.cpp"
"src/engine/core/world/loader/WorldLoader.cpp"
"src/engine/core/save/SaveGameManager.cpp"
"src/engine/core/save/SettingsLoader.cpp"
"src/engine/core/audio/AudioManager.cpp"

"src/states/BaseState.cpp"
"src/states/default/splash/SplashState.cpp"
"src/states/default/mainMenu/MainMenuState.cpp"
"src/states/default/quit/QuitState.cpp"
"src/states/game/BaseGameState.cpp"

"src/states/game/TestGameState.cpp"

"src/gameObjects/player/TestPlayer.cpp"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

if(TARGET_MAC)
    set (LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/mac_x64")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/mac_x64/)
    
elseif(TARGET_WIN)
    set (LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/win_x64")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/win_x64/)
    
elseif(TARGET_DEB)
    set (LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/deb_x64")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/deb_x64/)
    
elseif(TARGET_RASP_ARM)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/deb_rasp_arm/)
else()
    message("Target is not set")
endif()

link_directories(${LIB_DIR})

# if(TARGET_MAC)
#     find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
# endif()

# if(TARGET_MAC)
#     include_directories("include/mac_x64/")
# elseif(TARGET_DEB)
#     include_directories("include/deb_x64/")
# elseif(TARGET_RASP_ARM)
#     include_directories("include/deb_rasp_arm/")
# endif()

# add_executable(GEngine ${SOURCES})

if (TARGET_MAC)
    add_executable(${CUR_TARGET} MACOSX_BUNDLE ${SOURCES})

    set_target_properties(${CUR_TARGET} PROPERTIES
        BUNDLE True
        MACOSX_BUNDLE_GUI_IDENTIFIER com.pchrusciel.${CUR_TARGET}
        MACOSX_BUNDLE_BUNDLE_NAME ${CUR_TARGET}
        MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/gengine.plist.in
    )
else()
    add_executable(${CUR_TARGET} ${SOURCES})
endif()

# target_link_libraries(GEngine ${LIBRARIES})

if(TARGET_MAC)
    target_link_libraries(${CUR_TARGET} "-framework CoreGraphics" "-framework Foundation")
endif()

target_link_libraries(${CUR_TARGET} "-L${CMAKE_CURRENT_SOURCE_DIR}/lib/mac_x64")
target_link_libraries(${CUR_TARGET} "sfml-graphics" "sfml-window" "sfml-system" "sfml-audio")

if(!TARGET_MAC)
install(
    TARGETS ${CUR_TARGET}
    RUNTIME DESTINATION "bin"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    COMPONENT library
)
endif()
if (TARGET_MAC)
    add_custom_command(TARGET GEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/frameworks/"
            $<TARGET_FILE_DIR:GEngine>/../Frameworks)
    add_custom_command(TARGET GEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/lib/mac_x64/"
        $<TARGET_FILE_DIR:GEngine>/../Frameworks)
    add_custom_command(TARGET GEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/resources/"
        $<TARGET_FILE_DIR:GEngine>/../resources)
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

if(TARGET_MAC)
    # set_target_properties(GEngine PROPERTIES LINK_FLAGS "-Wl,-F ${CMAKE_CURRENT_LIST_DIR}/frameworks/")
elseif(TARGET_DEB)
    # set_target_properties(GEngine PROPERTIES LINK_FLAGS "-Wl,-F ${CMAKE_CURRENT_LIST_DIR}/frameworks/")
elseif(TARGET_RASP_ARM)
    # set_target_properties(GEngine PROPERTIES LINK_FLAGS "-Wl,-F ${CMAKE_CURRENT_LIST_DIR}/frameworks/")
endif()
