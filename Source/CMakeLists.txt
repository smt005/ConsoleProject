cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.

# Проект
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_NAME Windows)
set(PROJECT_DIR_FILES "${PROJECT_DIR}/Engine/Source/main")
FILE(GLOB_RECURSE PROJECT_INCLUDE ${PROJECT_DIR_FILES}/*.h)
FILE(GLOB_RECURSE PROJECT_SOURCE ${PROJECT_DIR_FILES}/*.cpp)
source_group(TREE ${PROJECT_DIR_FILES} TREE PREFIX "" FILES ${PROJECT_INCLUDE} ${PROJECT_SOURCE})

# defines
add_definitions(-DWIN_PLATFORM)
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотеки

# Engine
set(ENGINE_NAME Engine)
set(ENGINE_DIR "${PROJECT_DIR}/${ENGINE_NAME}")
set(ENGINE_SOURCE "${ENGINE_DIR}/Source")

# Game
set(GAME_NAME Game)
set(GAME_DIR "${PROJECT_DIR}/${GAME_NAME}")
set(GAME_SOURCE "${GAME_DIR}/Source")

# Создание

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_DIR}/../Executable)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_DIR}/../Executable)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/../Executable)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Библиотеки

# Engine
include_directories(${ENGINE_SOURCE})					# Заголовочные файлы библиотек
add_subdirectory(${ENGINE_DIR})							# Добавление подпроекта, указывается имя дирректории
target_link_libraries(${PROJECT_NAME} ${ENGINE_NAME})	# Линковка программы с библиотекой
link_directories(${ENGINE_DIR})

# Game
include_directories(${GAME_SOURCE})
add_subdirectory(${GAME_DIR})
target_link_libraries(${PROJECT_NAME} ${GAME_NAME})
link_directories(${GAME_DIR})
