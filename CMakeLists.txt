PROJECT(c_met)

# Uncomment next line to "debug" the make files
#SET(CMAKE_VERBOSE_MAKEFILE TRUE)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)

# Allows ENDIF() instead of ENDIF(...)
SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)

# Custom cmake modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

IF (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug CACHE STRING
        "Choose the type of build, options are: None Debug Release Strict RelWithDebInfo." FORCE)
ENDIF (NOT CMAKE_BUILD_TYPE)

IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    SET(_DEF_FLAGS "-fmessage-length=0 -pthread -Wall -Wextra -Waddress -Wchar-subscripts -Wcomment -Wempty-body")
    SET(_DEF_FLAGS "-Wmissing-braces -Wreturn-type -Wtrigraphs -Wtype-limits -Wunused-value")
    SET(_DEF_FLAGS "${_DEF_FLAGS} -Werror")
    SET(CMAKE_C_FLAGS             "${CMAKE_C_FLAGS}   ${_DEF_FLAGS}")
    SET(CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS} ${_DEF_FLAGS} -std=c++11 -Wnon-virtual-dtor -Wctor-dtor-privacy")
    SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-as-needed")
    SET(CMAKE_MODULE_LINKER_FLAGS "-Wl,--no-as-needed")

    SET(_DEBUG_FLAGS "-g -ggdb3 -O0 -DDEBUG -fno-inline -fstack-protector-all -Wstack-protector")
    SET(CMAKE_C_FLAGS_DEBUG             "${CMAKE_C_FLAGS}   ${_DEBUG_FLAGS}")
    SET(CMAKE_CXX_FLAGS_DEBUG           "${CMAKE_CXX_FLAGS} ${_DEBUG_FLAGS}")
    SET(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    SET(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")

    SET(_RELWITHDEBINFO_FLAGS "-O3 -ggdb3 -D_FORTIFY_SOURCE=2 -fstack-protector-all -Wstack-protector -mmmx -msse -msse2 -mno-sse3 -mno-3dnow")
    SET(CMAKE_C_FLAGS_RELWITHDEBINFO   "${CMAKE_C_FLAGS}   ${_RELWITHDEBINFO_FLAGS}")
    SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS} ${_RELWITHDEBINFO_FLAGS}")
    SET(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_SHARED_LINKER_FLAGS}")
    SET(CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_MODULE_LINKER_FLAGS}")

    SET(_REL_FLAGS "${_RELWITHDEBINFO_FLAGS} -D_FORTIFY_SOURCE=2 -fstack-protector-all -DNDEBUG")
    SET(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS}   ${_REL_FLAGS}")
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${_REL_FLAGS}")
    SET(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    SET(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")

    SET(_MINSIZEREL_FLAGS "-Os -DNDEBUG -D_FORTIFY_SOURCE=2 -fstack-protector-all -mmmx -msse -msse2 -mno-sse3 -mno-3dnow")
    SET(CMAKE_C_FLAGS_MINSIZEREL   "${CMAKE_C_FLAGS}   ${_MINSIZEREL_FLAGS}")
    SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS} ${_MINSIZEREL_FLAGS}")
    SET(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL "${CMAKE_SHARED_LINKER_FLAGS}")
    SET(CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL "${CMAKE_MODULE_LINKER_FLAGS}")

ELSE ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(FATAL_ERROR "Unsupported compiler '${CMAKE_CXX_COMPILER_ID}'!")
ENDIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

# Find all third party packages
FIND_PACKAGE(Log4cplus REQUIRED)

# Includes, please keep sorted
INCLUDE_DIRECTORIES(hello/include)
# Includes, please keep sorted

# Applications, please keep sorted
ADD_SUBDIRECTORY(hello)
ADD_SUBDIRECTORY(hellolog4cplus)
# Applications, please keep sorted

