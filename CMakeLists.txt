cmake_minimum_required(VERSION 3.26.5)

project(SFML)
add_compile_options(-Wall -Wextra -Wpedantic)

file (GLOB src_files src/*.cpp)
include_directories(${Animals_SOURCE_DIR}/include)
find_package(X11 REQUIRED)
#link_libraries(${X11_LIBRARIES})
add_executable(main ${src_files})

#set(SFML_STATIC_LIBRARIES TRUE)
#find_package(SFML COMPONENTS window graphic system)
target_link_libraries(main sfml-graphics sfml-window sfml-system ${X11_LIBRARIES})#${SFML_LIBRARIES})