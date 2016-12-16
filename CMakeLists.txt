cmake_minimum_required(VERSION 3.6)
project(mycpp)
INCLUDE_DIRECTORIES(
        include
)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(src DIR_SRCS)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests/sum_linkedlist)
ADD_SUBDIRECTORY(tests/reverse_linkedlist)
ADD_SUBDIRECTORY(tests/delete_duplicate_linkedlist)
ADD_SUBDIRECTORY(tests/partition_linkedlist)
ADD_SUBDIRECTORY(tests/find_first_samenode_linkedlist)

#set(SOURCE_FILES ${DIR_SRCS})
#add_executable(mycpp tests/main.cc)
#target_link_libraries(mycpp )