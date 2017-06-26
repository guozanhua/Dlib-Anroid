# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html
cmake_minimum_required(VERSION 3.4.1)

#add_subdirectory(src/main/cpp/dlib)

add_library(native-lib SHARED src/main/cpp/native-lib.cpp src/main/cpp/VideoFaceDetector.cpp)

INCLUDE_DIRECTORIES(src/main/cpp src/main/cpp/include src/main/cpp/includ/opencv src/main/cpp/includ/opencv2)

find_library(log-lib log)

add_library(opencv SHARED IMPORTED)

set_target_properties(opencv
                      PROPERTIES IMPORTED_LOCATION
                      ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

target_link_libraries(native-lib opencv ${log-lib} )
