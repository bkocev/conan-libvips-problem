cmake_minimum_required(VERSION 3.15)
project(PyramidalImagesConverter C)

find_package(ZLIB REQUIRED)
find_package(libvips REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} 
			PRIVATE ZLIB::ZLIB 
			PRIVATE libvips::libvips)
