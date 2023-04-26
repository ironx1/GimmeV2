cmake_minimum_required(VERSION 3.2)
project(GimmeV2 C)
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()
set(CMAKE_C_STANDARD 23)
file(GLOB SOURCES "./src/*.c")
file(GLOB HEADERS "./inc/*.h")
add_library(GimmeV2 SHARED ${SOURCES} ${HEADERS})
set_target_properties(GimmeV2 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
        )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(Gimme ./main.c)
target_link_libraries(Gimme GimmeV2)
install(TARGETS GimmeV2 Gimme
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
        )
