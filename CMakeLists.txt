cmake_minimum_required(VERSION 2.6)

#Configuration du projet

project(ProjectOCR)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})

#inclusion des entete
include_directories( include/ extlib/ )
link_directories( extlib/gmp-5.1.1/.libs/ )


#Génération de la liste des fichiers sources

file(

        GLOB_RECURSE

        source_files

        src/*

        include/*

)

#Déclaration de l'exécutable

add_executable(

        Release

        ${source_files}

)

#definition des links

target_link_libraries(

        Release

        X11
        pthread
        config++
        gmp

)
