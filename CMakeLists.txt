cmake_minimum_required(VERSION 3.10)
project(Blackjack LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Blackjack
    src/main.cpp
    src/game.cpp
    src/player.cpp
)

set(RAYLIB_MIN_VERSION 4.0)

find_package(raylib ${RAYLIB_MIN_VERSION} CONFIG QUIET)

if(NOT raylib_FOUND)
    find_package(PkgConfig QUIET)
    if(PkgConfig_FOUND)
        pkg_check_modules(RAYLIB_PC QUIET raylib>=${RAYLIB_MIN_VERSION})
        if(RAYLIB_PC_FOUND)
            set(raylib_FOUND TRUE)
            if(NOT TARGET raylib)
                add_library(raylib INTERFACE)
            endif()
            target_include_directories(raylib INTERFACE ${RAYLIB_PC_INCLUDE_DIRS})
            target_link_libraries(raylib INTERFACE ${RAYLIB_PC_LIBRARIES})
        endif()
    endif()
endif()

if(NOT raylib_FOUND)
    message(STATUS "raylib not found on system; fetching from GitHub...")

    include(FetchContent)

    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
    )

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(raylib)

    if(NOT TARGET raylib)
        if(TARGET raylib_static)
            add_library(raylib ALIAS raylib_static)
        elseif(TARGET raylib_shared)
            add_library(raylib ALIAS raylib_shared)
        endif()
    endif()
endif()

target_link_libraries(Blackjack PRIVATE raylib)

if(UNIX AND NOT APPLE)
    target_link_libraries(Blackjack PRIVATE m dl pthread)
endif()
