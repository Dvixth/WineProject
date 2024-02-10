cmake_minimum_required(VERSION 3.26)
project(WineProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(WineProject main.cpp
        Cave.cpp
        Cave.hpp
        Fournisseur.cpp
        Fournisseur.hpp
        Vin.cpp
        Vin.hpp
        Marge.cpp
        Fournir.cpp
        Reduction.hpp
        Reduction.hpp
        Reduction.cpp)
