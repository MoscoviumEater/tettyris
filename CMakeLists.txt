cmake_minimum_required(VERSION 3.20)
project(ttyris C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")

file(GLOB PDCURSES_SRC ${CMAKE_SOURCE_DIR}/pdcmod/pdcurses/*.c)
file(GLOB WINCON_SRC ${CMAKE_SOURCE_DIR}/pdcmod/wincon/*.c)

add_executable(tettyris main.c ${PDCURSES_SRC} ${WINCON_SRC}
        decl.h
        glob.c
        ren.c
        log.c
        pcs.c)

target_include_directories(tettyris PRIVATE
        ${CMAKE_SOURCE_DIR}/pdcmod
        ${CMAKE_SOURCE_DIR}/pdcmod/wincon
)

target_link_libraries(tettyris PRIVATE m)
target_link_libraries(tettyris PRIVATE m winmm)