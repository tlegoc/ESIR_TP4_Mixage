cmake_minimum_required(VERSION 3.25)

project(TP4)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(TP4
        src/main.cpp
        src/imp_flot.cpp
        src/imp_flot.h
        src/signal_constant.cpp
        src/signal_constant.h
        src/producteur_base.cpp
        src/producteur_base.h
        src/harmonique.cpp
        src/harmonique.h
        src/consommateur_base.cpp
        src/consommateur_base.h
        src/filtre_base.h
        src/multiplicateur.cpp
        src/multiplicateur.h
        src/operation_binaire.h
        src/volume.cpp
        src/volume.h
        src/filtre_compose.cpp
        src/filtre_compose.h
        src/volume_compose.cpp
        src/volume_compose.h
        src/mixeur.cpp
        src/mixeur.h
        )

target_link_libraries(TP4 ${CMAKE_SOURCE_DIR}/lib/liboutils.a)
target_include_directories(TP4 PUBLIC include)