cmake_minimum_required(VERSION 3.28)
project(Pong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML 3.0 und seine Abhaengigkeiten nutzen teilweise cmake_minimum_required < 3.5,
# was CMake 4.x nicht mehr akzeptiert.
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Audio zieht libogg/vorbis/FLAC nach; libogg laesst sich mit der MinGW-Toolchain
# nicht konfigurieren ("No 16 bit type found"). Pong braucht weder Audio noch Netzwerk.
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(Pong main.cpp)
target_link_libraries(Pong PRIVATE SFML::Graphics SFML::Window SFML::System)
