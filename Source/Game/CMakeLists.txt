cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.

# Переменные
set(CMAKE_CXX_STANDARD 17)

# Расположение файлов библиотеки
FILE(GLOB_RECURSE INCLUDES ${GAME_SOURCE}/*.h)
FILE(GLOB_RECURSE SOURCES ${GAME_SOURCE}/*.cpp)
source_group(TREE ${GAME_SOURCE} TREE PREFIX "" FILES ${INCLUDES} ${SOURCES})

# Расположение заголовочных файлов
include_directories(${ENGINE_SOURCE})
include_directories(${BRAIN_SOURCE})

# ThirdPathy
include_directories(${JSONCPP_INCLUDES})

# Создание статической библиотеки
add_library(${GAME_NAME} STATIC ${INCLUDES} ${SOURCES})
