cmake_minimum_required(VERSION 3.8)

project(AdventureKraft)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin/${PROJECT_NAME}")

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PRIVATE
	"../DangerEngine/src"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../bin/DangerEngine/DangerEngine.lib"
)