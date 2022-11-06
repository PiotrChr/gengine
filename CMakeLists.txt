cmake_minimum_required(VERSION 3.22)
project(GEngine)

if(NOT TARGET_DEB OR NOT TARGET_MAC OR NOT TARGET_RASP_ARM)
    set(TARGET_DEB)
endif()

set(CMAKE_CXX_STANDARD 17)
if(TARGET_MAC)
    include_directories(include/mac_x64/)
    link_directories(lib/mac_x64/)
elseif(TARGET_DEB)
    include_directories(include/deb_x64/)
    link_directories(lib/deb_x64/)
elseif(TARGET_RASP_ARM)
    set(CMAKE_MODULE_PATH cmake/deb_rasp_arm/)
else()
    message("Target is not set")
endif()

# if(TARGET_MAC)
#     find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
# endif()

if(TARGET_MAC)
    include_directories("includes/mac_x64")
elseif(TARGET_DEB)
    include_directories("includes/deb_x64")
elseif(TARGET_RASP_ARM)
    include_directories("includes/deb_rasp_arm")
endif()

add_executable(
    GEngine
    src/main.cpp
    )

target_link_libraries(GEngine "-l sfml-graphics -l sfml-system -l sfml-window")

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
    set_target_properties(GEngine PROPERTIES LINK_FLAGS "-Wl,-F ${CMAKE_CURRENT_LIST_DIR}/frameworks/")
elseif(TARGET_DEB)
    # set_target_properties(GEngine PROPERTIES LINK_FLAGS "-Wl,-F ${CMAKE_CURRENT_LIST_DIR}/frameworks/")
elseif(TARGET_RASP_ARM)
    set_target_properties(GEngine PROPERTIES LINK_FLAGS "-Wl,-F ${CMAKE_CURRENT_LIST_DIR}/frameworks/")
endif()
