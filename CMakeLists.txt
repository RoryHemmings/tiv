cmake_minimum_required(VERSION 3.18.4)
project( tiv )

find_package( OpenCV REQUIRED )

include_directories( include )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(HEADER_FILES include/image.h include/window.h include/application.h )
set(SOURCES src/main.cpp src/image.cpp src/window.cpp src/application.cpp )

add_executable( tiv_bin ${SOURCES} ${HEADER_FILES} )
target_link_libraries( tiv_bin ${OpenCV_LIBS} )

