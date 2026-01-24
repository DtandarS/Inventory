cmake_minimum_required(VERSION 3.16.0)

#====================================#

project(Inventory)

#====================================#

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES the-inventory/code/maker.cpp)

#====================================#

add_executable(
  Inventory

  ${SOURCE_FILES}
)

#====================================#

add_library(MY_HEADERS INTERFACE)
add_library(SDL INTERFACE)

#====================================#

add_subdirectory(the-inventory/src/lib/SDL EXCLUDE_FROM_ALL)
add_subdirectory(the-inventory/src/lib/SDL-image EXCLUDE_FROM_ALL)

#====================================#

target_include_directories(

  MY_HEADERS

  INTERFACE

  ${CMAKE_CURRENT_SOURCE_DIR}/the-inventory/code/headers

)

target_include_directories(

  SDL

  INTERFACE

  ${CMAKE_CURRENT_SOURCE_DIR}/the-inventory/src/lib/SDL/include/SDL3
  ${CMAKE_CURRENT_SOURCE_DIR}/the-inventory/src/lib/SDL-image/include/SDL3-image

)

#====================================#

target_link_libraries(
  Inventory PRIVATE
  SDL
  MY_HEADERS
  SDL3::SDL3
  SDL3_image::SDL3_image
)

#====================================#


#====================================#
