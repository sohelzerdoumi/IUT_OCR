cmake_minimum_required(VERSION 2.6)
SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/Modules/ )

#Configuration du projet

project(ProjectOCR)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --pedantic -O3 -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})



#inclusion des entete

include_directories( include/ extlib/)

find_package(GMP REQUIRED)
find_package(CIMG REQUIRED)

 
#Génération de la liste des fichiers sources

file(
        GLOB_RECURSE
        source_files

        src/*
        include/*
)

#Déclaration de l'exécutable

add_executable(            Release
        ${source_files}
)

#definition des links

target_link_libraries(     Release
        X11
        pthread
        config++
        sfml-audio
	sfml-graphics
	sfml-window
	sfml-system
        gmp
)

add_dependencies( Release GMP )
add_dependencies( Release CIMG )