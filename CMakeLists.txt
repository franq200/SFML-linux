cmake_minimum_required(VERSION 3.4)

project(SFML)

file (GLOB src_files src/*.cpp)
include_directories(${Animals_SOURCE_DIR}/include)
add_executable(main ${src_files})

#set(SFML_STATIC_LIBRARIES TRUE)
#find_package(SFML COMPONENTS window graphic system)
target_link_libraries(main sfml-graphics sfml-window sfml-system)#${SFML_LIBRARIES})