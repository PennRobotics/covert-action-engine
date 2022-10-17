find_package(SDL2_mixer REQUIRED)

file(GLOB_RECURSE PSEMEK_AUDIO_HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "include/*.hpp" "include/*.h")
file(GLOB_RECURSE PSEMEK_AUDIO_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "source/*.cpp" "source/*.c")

psemek_add_library(psemek-audio ${PSEMEK_AUDIO_HEADERS} ${PSEMEK_AUDIO_SOURCES})
target_include_directories(psemek-audio PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(psemek-audio PUBLIC psemek-sdl2 psemek-geom psemek-util psemek-log psemek-prof SDL2_mixer)
