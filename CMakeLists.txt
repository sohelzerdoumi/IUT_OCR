cmake_minimum_required(VERSION 2.6)
SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR} )

#Configuration du projet

project(ProjectOCR)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})

include(ExternalProject)

ExternalProject_Add(
	GMP
	PREFIX extlib/gmp/
	URL ftp://ftp.gmplib.org/pub/gmp/gmp-5.1.1.tar.bz2
	DOWNLOAD_DIR /tmp/
	INSTALL_DIR extlib/gmp/
	CONFIGURE_COMMAND <SOURCE_DIR>/configure --enable-cxx --prefix=<INSTALL_DIR> --disable-examples
	INSTALL_COMMAND make install
)


#inclusion des entete
include_directories( include/ extlib/ )

ExternalProject_Get_Property(GMP PREFIX)
link_directories( ${PREFIX}lib )
include_directories( ${PREFIX}include )
 
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
