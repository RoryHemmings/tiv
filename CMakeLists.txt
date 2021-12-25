cmake_minimum_required(VERSION 3.18.4)
project( tiv )

find_package( OpenCV REQUIRED )

include_directories( include )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(HEADERS include/image.h include/window.h )
set(SOURCES src/main.cpp src/image.cpp src/window.cpp )

add_executable( tiv_bin ${SOURCES} ${HEADERS} )
target_link_libraries( tiv_bin ${OpenCV_LIBS} )

