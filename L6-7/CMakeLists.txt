cmake_minimum_required(VERSION 3.16)

# Set the version
project(
    L6-7 VERSION 1.0
    DESCRIPTION "Material from lecture 6 and 7"
    LANGUAGES CXX
)

option(USE_OPENMP "Compile with OpenMP" OFF)

if(USE_OPENMP)
    if(APPLE)
        find_package(OpenMP)

        if(NOT OpenMP_FOUND)
            # libomp 15.0+ from brew is keg-only, so have to search in other locations.
            # See https://github.com/Homebrew/homebrew-core/issues/112107#issuecomment-1278042927.
            execute_process(COMMAND brew --prefix libomp
                OUTPUT_VARIABLE HOMEBREW_LIBOMP_PREFIX
                OUTPUT_STRIP_TRAILING_WHITESPACE)
            set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -I${HOMEBREW_LIBOMP_PREFIX}/include")
            set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I${HOMEBREW_LIBOMP_PREFIX}/include")
            set(OpenMP_C_LIB_NAMES omp)
            set(OpenMP_CXX_LIB_NAMES omp)
            set(OpenMP_omp_LIBRARY ${HOMEBREW_LIBOMP_PREFIX}/lib/libomp.dylib)
            find_package(OpenMP REQUIRED)
        endif()
    else()
        find_package(OpenMP REQUIRED)
    endif()
endif()

add_executable(trapezoidal_v1 trapezoidal_v1.cpp)
add_executable(trapezoidal_v2 trapezoidal_v2.cpp)
add_executable(trapezoidal_v3 trapezoidal_v3.cpp)

if(OpenMP_FOUND)
    target_link_libraries(trapezoidal_v1 PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(trapezoidal_v2 PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(trapezoidal_v3 PUBLIC OpenMP::OpenMP_CXX)
endif()