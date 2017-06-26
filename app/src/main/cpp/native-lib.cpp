#include <jni.h>
#include <string>
#include <android/log.h>
#include <opencv2/core.hpp>
#include <include/opencv/cv.hpp>
#include "VideoFaceDetector.h"

#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,"native-lib",__VA_ARGS__)

const cv::String CASCADE_FILE("haarcascade_frontalface_default.xml");
extern "C"
JNIEXPORT jstring JNICALL
Java_com_orange_opencv_MainActivity_stringFromJNI(JNIEnv *env, jobject) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_orange_opencv_MainActivity_loadJpeg(JNIEnv *env, jobject instance, jstring root_,
                                             jstring path_) {
    clock_t start, finish;
    start = clock();
    const char *root = env->GetStringUTFChars(root_, NULL);
    const char *path = env->GetStringUTFChars(path_, NULL);
    std::string rootStr = root;
    rootStr = rootStr + "/" + CASCADE_FILE;


    VideoFaceDetector detector(rootStr);

    cv::Mat_<unsigned char> img(cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE));

    detector.getDetect(img);

    if (detector.isFaceFound()) {
        cv::Rect face_rect = detector.face();
        LOGW("RECT X: %d", face_rect.x);
        LOGW("RECT Y: %d", face_rect.y);
        LOGW("RECT WIDTH: %d", face_rect.width);
        LOGW("RECT HEIGHT: %d", face_rect.height);
    }

    finish = clock();
    long x = finish - start;
    LOGW(" spend = %ld", x);
    env->ReleaseStringUTFChars(root_, root);
    env->ReleaseStringUTFChars(path_, path);

}