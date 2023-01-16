cmake_minimum_required(VERSION 3.20)
project(ProjetoAEDeLP C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetoAEDeLP main.c Numeros_inteiros/Inteiros.c Numeros_inteiros/Inteiros.h Numeros_inteiros/Parte1.c Numeros_inteiros/Parte1.h Libs_util/libs.c Libs_util/libs.h Libs_util/libs_stats.c Libs_util/libs_stats.h Numeros_chars/Parte2.c Numeros_chars/Parte2.h)
