set( GMP_FOUND false)
set( GMP_LIBRARY "gmp")
set( GMP_HEADER "gmpxx.h"  "gmp.h") 

find_path( GMP_LIBRARY_PATH  ${GMP_LIBRARY}) 
find_path( GMP_HEADER_PATH  ${GMP_HEADER}) 
if( ("${GMP_LIBRARY_PATH}" STREQUAL "GMP_LIBRARY_PATH-NOTFOUND" ) OR 
	( "${GMP_HEADER_PATH}" STREQUAL "GMP_HEADER_PATH-NOTFOUND") )
	message( "GMP n'as pas été trouvé mais sera installé à la compilation" )
	set( GMP_ROOT ${CMAKE_MODULE_PATH}GMP/ )
	include( ExternalProject )

	ExternalProject_Add( 
		GMP
		PREFIX ${GMP_ROOT}
		URL ftp://ftp.gmplib.org/pub/gmp/gmp-5.1.1.tar.bz2
		DOWNLOAD_DIR /tmp/
		INSTALL_DIR ${GMP_ROOT}
		CONFIGURE_COMMAND <SOURCE_DIR>/configure --enable-cxx --prefix=<INSTALL_DIR> --disable-examples
		INSTALL_COMMAND make install
	)
	set( GMP_LIBRARY_PATH ${GMP_ROOT}lib)
	set( GMP_HEADER_PATH ${GMP_ROOT}include/)


else()
	set( GMP_FOUND true)
	message( "GMP trouvé  "    )

endif()

include_directories( ${GMP_HEADER_PATH} )
link_directories(  ${GMP_LIBRARY_PATH})
