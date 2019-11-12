cmake_minimum_required(VERSION 3.4.1)

#declaring project name
project("jerryscriptwrapper" C)

#lets add the jerryscript's sub directory to be created as well
add_subdirectory("jerryscript/jerry-core")
add_subdirectory("jerryscript/jerry-ext")
add_subdirectory("jerryscript/jerry-libm")
add_subdirectory("jerryscript/jerry-port/default")

#declaring porject as shared lib
add_library("${PROJECT_NAME}" SHARED "jerryscriptwrapper.c")
#to make this as shared lib
#find the header (include directories at)
target_include_directories("${PROJECT_NAME}" PRIVATE "include")
#find the link libraries at
target_link_libraries("${PROJECT_NAME}" "jerry-core" "jerry-ext" "jerry-libm" "jerry-port-default")
link_directories("jerry-core" "jerry-ext" "jerry-libm" "jerry-port-default")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

#test executable
if(CREATEATESTAPP)
    add_executable("testapp" testapp.c)
    target_include_directories("testapp" PRIVATE "include")
    target_link_libraries("testapp" "${PROJECT_NAME}")
    link_directories("./")
endif()
