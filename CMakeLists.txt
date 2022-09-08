cmake_minimum_required(VERSION 3.9)
project(covert-action-engine VERSION 0.1.5)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)



add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        src/covert.cpp
        src/gameplay/casegenerator.cpp
        src/minigame/combat.cpp
        src/minigame/driving.cpp
        src/minigame/cryptography.cpp
        src/minigame/electronics.cpp
        src/disk/loadsave.cpp
        src/sound/fx.cpp
        src/sound/music.cpp
        src/gfx/picloader.cpp
        src/gui/gui.cpp
        src/gui/point.cpp
        src/gameplay/gamestate.cpp
        src/gameplay/agentgenerator.cpp
        src/gui/menu.cpp
)

find_package(PNG REQUIRED)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})

# Copy resources into same directory as binary
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
    set(RESOURCES_TO_COPY test.wav)
    foreach(item IN LISTS RESOURCES_TO_COPY)
        message(STATUS ${item})
        add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/src/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/${item}"
        )
    endforeach()
endif()

add_custom_target(data-target ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/test.wav")