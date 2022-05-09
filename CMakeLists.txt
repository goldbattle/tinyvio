cmake_minimum_required(VERSION 3.0.0)


# package name
project(tinyvio)


# find required packages
find_package(Eigen3 REQUIRED)
find_package(OpenCV 3 QUIET)
if (NOT OpenCV_FOUND)
	find_package(OpenCV 4 REQUIRED)
endif()
find_package(Pangolin 0.8 REQUIRED)


# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fsee -fomit-frame-pointer -fno-signed-zeros -fno-math-errno -funroll-loops")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -Wall -Wuninitialized -Wmaybe-uninitialized -fno-omit-frame-pointer")

# include dir
# Include our header files
include_directories(src ${EIGEN3_INCLUDE_DIR} ${Pangolin_INCLUDE_DIRS})

# binary
add_executable(test_opencv src/test_opencv.cpp)
target_link_libraries(test_opencv ${OpenCV_LIBRARIES})
add_executable(test_pangolin src/test_pangolin.cpp)
target_link_libraries(test_pangolin ${OpenCV_LIBRARIES} ${Pangolin_LIBRARIES})

add_executable(test_reading src/test_reading.cpp)
target_link_libraries(test_reading ${OpenCV_LIBRARIES} ${Pangolin_LIBRARIES})



