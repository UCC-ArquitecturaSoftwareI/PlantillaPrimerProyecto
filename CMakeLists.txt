cmake_minimum_required(VERSION 3.17)
project(ProjectTemaplate)
include(FetchContent)
set(CMAKE_CXX_STANDARD 17)

#
# Install SFML if not installed
#
set(SFML_VERSION "2.5.1")
find_package(SFML ${SFML_VERSION} COMPONENTS system window graphics QUIET)

if (NOT SFML_FOUND)
    message(STATUS "SFML not found, fetching from github...")
    include(FetchContent)
    FetchContent_Declare(
            sfml
            URL https://github.com/SFML/SFML/releases/download/${SFML_VERSION}/SFML-${SFML_VERSION}-sources.zip
    )

    FetchContent_GetProperties(sfml)
    if(NOT sfml_POPULATED)
        FetchContent_Populate(sfml)
        add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
    endif()
endif()


#
# Install TMXLITE if not installed
#
find_package(TMXLITE QUIET)

if (NOT ${TMXLITE_FOUND})
    message(STATUS "tmxlite not found, fetching from github...")
    include(FetchContent)
    FetchContent_Declare(
            tmxlite
            GIT_REPOSITORY https://github.com/fallahn/tmxlite
            GIT_TAG        v1.2.1
    )
    FetchContent_MakeAvailable(tmxlite)
    add_subdirectory(${tmxlite_SOURCE_DIR}/tmxlite)
    set(TMXLITE_LIBRARIES tmxlite)
    set(TMXLITE_INCLUDE_DIR ${tmxlite_SOURCE_DIR}/tmxlite/include)
endif()

include_directories(
        ${TMXLITE_INCLUDE_DIR}
        ${SFML_INCLUDE_DIR})

add_executable(ProjectTemaplate main.cpp)

target_link_libraries(ProjectTemaplate
        PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
        ${TMXLITE_LIBRARIES}
        )
target_compile_options(ProjectTemaplate PRIVATE -Wall)