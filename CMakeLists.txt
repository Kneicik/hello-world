cmake_minimum_required(VERSION 3.1...3.25)

project(SEAMORE)

add_executable(${PROJECT_NAME} main.cpp)

#opcjonalna biblioteka

option(USE_ADDER "Simple library for adding floats" ON)

if(USE_ADDER)
    add_subdirectory(Adder)

    target_include_directories(${PROJECT_NAME}
    PUBLIC Adder 
    )

    target_link_directories(${PROJECT_NAME}
    PRIVATE Adder
    )  
endif()

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please check")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failes.")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE Adder
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
    adder 
    glfw
)

install(TARGETS SEAMORE DESTINATION bin)