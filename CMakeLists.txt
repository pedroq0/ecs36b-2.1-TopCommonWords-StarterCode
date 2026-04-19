cmake_minimum_required(VERSION 3.28)
project(TopCommonWords)

set(CMAKE_CXX_STANDARD 23)
set(CXX_WARNINGS -Wall -Werror -Wextra)

set(SRC_LIB_NAME TopCommonWordsLib)
set(EXE_NAME TopCommonWordsExe)
set(TESTING_NAME TopCommonWordsTests)

add_subdirectory(src)
add_subdirectory(testing)
