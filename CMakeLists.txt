cmake_minimum_required(VERSION 3.10)
project(XCSP3toCPP)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ext/XCSP3-CPP-Parser/include
    ${CMAKE_SOURCE_DIR}/ext/XCSP3-CPP-Parser/src
)

add_subdirectory(ext/XCSP3-CPP-Parser)

find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR})

file(GLOB SRC src/*.cpp)
add_executable(converter ${SRC})
target_link_libraries(converter ${LIBXML2_LIBRARIES})

# Lien vers la lib statique du parser
target_link_libraries(converter xcsp3parser ${LIBXML2_LIBRARIES})
