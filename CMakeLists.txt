cmake_minimum_required(VERSION 3.5.1)

project(SFML)

file (GLOB src_files src/*.cpp)
include_directories(${Animals_SOURCE_DIR}/include)
find_package(X11 REQUIRED)
#link_libraries(${X11_LIBRARIES})
add_executable(main ${src_files})

#set(SFML_STATIC_LIBRARIES TRUE)
#find_package(SFML COMPONENTS window graphic system)
target_link_libraries(main sfml-graphics sfml-window sfml-system ${X11_LIBRARIES})#${SFML_LIBRARIES})