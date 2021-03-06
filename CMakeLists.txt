cmake_minimum_required(VERSION 2.8)
project(gat1400)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(OUTPUT_BIN_DIR bin CACHE PATH "output directory for executables")

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")  
  
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")  
    MESSAGE(STATUS "current platform: Linux ")  
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")  
    MESSAGE(STATUS "current platform: Windows")  
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")  
    MESSAGE(STATUS "current platform: FreeBSD")  
ELSE ()  
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")  
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

if(WIN32)
    add_definitions(/wd4996)
    add_definitions(/W4)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd" CACHE STRING "" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT" CACHE STRING "" FORCE)
    add_definitions(-DUNICODE -D_UNICODE)
else()
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
    endif(NOT CMAKE_BUILD_TYPE)
    add_definitions(-Wall)

    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
    if(COMPILER_SUPPORTS_CXX11)
        if(CMAKE_COMPILER_IS_GNUCXX)
            set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
            message(STATUS "optional:-std=c++11")   
        endif(CMAKE_COMPILER_IS_GNUCXX)
    else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use higher version C++ compiler.")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--default-symver -Wl,--no-undefined,-z,relro,-z,now,-z,noexecstack -fstack-protector")
endif()

include_directories(/usr/include)
link_directories(/usr/lib /usr/lib64)
aux_source_directory(src                        DIR_SRCS)

#option(BUILD_TEST "Build testcase" ON)
#if(BUILD_TESTS)
#    aux_source_directory(testcase DIR_SRCS)
#endif()

add_executable(xstdtest ${DIR_SRCS})
target_link_libraries(gat1400 curl xml2)
