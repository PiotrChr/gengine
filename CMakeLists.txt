cmake_minimum_required(VERSION 3.23)
project(GEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_XCODE_ATTRIBUTE_FRAMEWORK_SEARCH_PATHS frameworks)
set(CMAKE_MODULE_PATH cmake/)

#find_package(OpenGL REQUIRED)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories("includes")

add_executable(
    GEngine
    src/main.cpp
    )

target_link_libraries(GEngine "-framework sfml-graphics -framework sfml-system -framework sfml-window")

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


set_target_properties(GEngine PROPERTIES LINK_FLAGS "-Wl,-F ${CMAKE_CURRENT_LIST_DIR}/frameworks/")

#set_target_properties(GameOfLifeCplus PROPERTIES
#        MACOSX_BUNDLE FALSE
#        MACOSX_FRAMEWORK_IDENTIFIER org.cmake.ExecutableTarget
#        )

#target_link_libraries(GameOfLifeCplus "/usr/local/Cellar/glfw/3.3.8/lib/libglfw.3.3.dylib")