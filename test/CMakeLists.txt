cmake_minimum_required(VERSION 3.9)
project(test-covert-action-engine VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Modules)

add_compile_definitions(TEST_ACTIVE)

add_executable(
        ${PROJECT_NAME}
        ../src/covert.cpp
        ../src/disk/loadsave.cpp
        ../src/gameplay/agentgenerator.cpp
        ../src/gameplay/case.cpp
        ../src/gameplay/casegenerator.cpp
        ../src/gameplay/gamestate.cpp
        ../src/gfx/picloader.cpp
        ../src/gui/font.cpp
        ../src/gui/gui.cpp
        ../src/gui/menu.cpp
        ../src/gui/point.cpp
        ../src/minigame/combat.cpp
        ../src/minigame/driving.cpp
        ../src/minigame/cryptography.cpp
        ../src/minigame/electronics.cpp
        ../src/sound/fx.cpp
        ../src/sound/music.cpp
        test.cpp
)

find_package(PNG REQUIRED)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})
