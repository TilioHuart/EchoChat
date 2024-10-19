cmake_minimum_required(VERSION 3.14)

project(EchoChat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Activer la nouvelle politique pour CMP0167, nécessaire pour find_package
cmake_policy(SET CMP0167 NEW)

# Trouver Boost avec le composant system pour Asio
find_package(Boost 1.86 REQUIRED COMPONENTS system)

add_subdirectory(src)
include_directories(include)
