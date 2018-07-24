cmake_minimum_required(VERSION 2.8)

project(FANN-test)
include_directories("fann-src/include")
#add_subdirectory("D:/PROGRAMOWANIE/QT/QT_kurs/FANN-test/fann-src")


set(SOURCE_FILES  "main.cpp"
    "fann-src/doublefann.c"
    "fann-src/fann.c"
    "fann-src/fann_cascade.c"
    "fann-src/fann_error.c"
    "fann-src/fann_io.c"
    "fann-src/fann_train.c"
    "fann-src/fann_train_data.c"
    "fann-src/fixedfann.c"
    "fann-src/floatfann.c"
    "fann-src/parallel_doublefann_cpp.cpp"
    "fann-src/parallel_fann.c"
    "fann-src/parallel_fann_cpp.cpp"
    "fann-src/parallel_floatfann_cpp.cpp"
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DBT_TEST -DK -fopenmp")
add_executable(${PROJECT_NAME} ${GLOB} ${SOURCE_FILES})
