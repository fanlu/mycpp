# CMakeLists for src directory
PROJECT(mycpp)

SET(LINKEDLIST_SRCS
        linkedlist_functions/linkedlist_functions.cc
        )

# shared library
ADD_LIBRARY(linkedlist SHARED ${LINKEDLIST_SRCS})

# static library
ADD_LIBRARY(linkedlist_static STATIC ${LINKEDLIST_SRCS})

SET_TARGET_PROPERTIES(linkedlist_static PROPERTIES OUTPUT_NAME "linkedlist")
SET_TARGET_PROPERTIES(linkedlist PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(linkedlist_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)