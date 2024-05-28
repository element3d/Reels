cmake_minimum_required(VERSION 3.4.1)

set(PROJECT RidersReels)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -frtti -fexceptions -Wall")
#add_definitions( -Wall -O2 -fexceptions )

if(WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -static-openmp")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -static-openmp")
endif(WIN32)

if(WIN32)
	add_definitions(-D__E3_EXPORTING__)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

file(GLOB SRC_PRIVATE CONFIGURE_DEPENDS
	private/*.cpp 
	#private/*.h
)

file(GLOB SRC CONFIGURE_DEPENDS
	*.cpp 
	*.h
)

if(ANDROID)
	set(SRC ${SRC} Android/android_main.cpp)
endif(ANDROID)

set (SRC
    ${SRC}
	${SRC_PRIVATE}
    Application.cpp
)

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/get_elementary_libs.cmake)
	include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/get_elementary_libs.cmake)
	get_elementary_libs()
endif()

add_library(${PROJECT} SHARED ${SRC})

target_include_directories(${PROJECT} PRIVATE private)
#include_directories(D:/Narek/OCV/opencv/build/install/include)
#link_directories(D:/Narek/opencv/build/x64/vc16/lib)

target_link_libraries(${PROJECT}
    element3d
	${ELEMENTARY_LIBS}
    opencv_core490d
	opencv_highgui490d
	opencv_videoio490d
	opencv_imgproc490d
	opencv_imgcodecs490d
	cpr
	libcurl
	sdl2d
)

if(ANDROID)
	target_link_libraries(${PROJECT}
		android
		EGL
		GLESv3
		log
	)	
elseif(EMSCRIPTEN)
	target_link_libraries(${PROJECT}
		yoga
	)
elseif(WIN32)
	target_link_libraries(${PROJECT}
		glew32
		OpenGL32
	)
endif()
