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

project(auth)

## SOURCES ##

file(GLOB_RECURSE sources src/*.*)
file(GLOB_RECURSE allfiles *.*)

## TARGET ##

set(TARGET ${PROJECT_NAME}.wt)
add_executable(${TARGET} ${sources} ${files} )

## LINKING ##

set(WT_CONNECTOR "wthttp" CACHE STRING "Connector used (wthttp or wtfcgi)")
set(CMAKE_BUILD_TYPE Debug CACHE STRING " Debug Release RelWithDebInfo MinSizeRel" FORCE )

target_link_libraries(
  ${TARGET}
  optimized ${WT_CONNECTOR} debug ${WT_CONNECTOR}d
  optimized wt              debug wtd

  optimized wtdbo           debug wtdbod
  optimized wtdbosqlite3    debug wtdbosqlite3d
)

## IDE and CONVENIENCE ##

source_group(sources FILES ${sources}) # for some IDE's (MSVC), to show files grouped
source_group(sources FILES ${allfiles}) # for some IDE's (MSVC), to show files grouped
