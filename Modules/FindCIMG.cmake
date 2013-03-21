set( CIMG_FOUND false)
set( CIMG_ROOT ${CMAKE_MODULE_PATH}CIMG/ )

find_path( CIMG_HEADER_PATH  "CImg.h") 


if("${CIMG_HEADER_PATH}" STREQUAL "CIMG_HEADER_PATH-NOTFOUND"  )
	message( "CIMG n'as pas été trouvé mais sera installé à la compilation" )
	include( ExternalProject )

	ExternalProject_Add( 
		CIMG
		PREFIX ${CIMG_ROOT}
		URL "http://cimg.cvs.sourceforge.net/viewvc/cimg/CImg/?view=tar"
		DOWNLOAD_DIR ${CIMG_ROOT}
		INSTALL_DIR ${CIMG_ROOT}
		INSTALL_COMMAND  ""
		CONFIGURE_COMMAND  ""
		BUILD_COMMAND ""
	)
	set( CIMG_HEADER_PATH  ${CIMG_ROOT}src/CIMG/)

else()
	set( CIMG_FOUND true)
	message( "CIMG trouvé  "  ${CIMG_LIBRARY_PATH}  )
endif()

include_directories( ${CIMG_HEADER_PATH} )
