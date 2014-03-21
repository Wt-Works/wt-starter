## GENERAL ##

cmake_minimum_required(VERSION 2.8)

## WT SPECIFIC ##

#provide wt install directory in environment var or directly
set(WT_INSTALL_DIR $ENV{WT_INSTALL_DIR})
#set(WT_INSTALL_DIR "/path/to/wt-install-dir")

## library locations ##
include_directories(${WT_INSTALL_DIR}/include)
link_directories(${WT_INSTALL_DIR}/lib) 

## PROJECT SPECIFIC ##

PROJECT(LAYOUT)

## SOURCES ##

file(GLOB_RECURSE sources *.c*)


## TARGET ##

set(TARGET ${PROJECT_NAME}.wt)
add_executable(${TARGET} ${sources} )

## LINKING ##

set(WT_CONNECTOR "wthttp" CACHE STRING "Connector used (wthttp or wtfcgi)")
set(CMAKE_BUILD_TYPE Debug CACHE STRING " Debug Release RelWithDebInfo MinSizeRel" FORCE )

target_link_libraries(
  ${TARGET}
  optimized ${WT_CONNECTOR} debug ${WT_CONNECTOR}d
  optimized wt              debug wtd

)

## IDE and CONVENIENCE ##

source_group(sources FILES ${sources}) # for some IDE's (MSVC), to show files grouped

