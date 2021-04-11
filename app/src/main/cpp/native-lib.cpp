#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" {    //注意在 C++ 中调用 C 语言方法 , 需要做兼容设置
extern int add(int a, int b);
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_quarkboom_ndkstaticaddtest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}extern "C"
JNIEXPORT jint JNICALL
Java_com_quarkboom_ndkstaticaddtest_MainActivity_getNumber(JNIEnv *env, jobject thiz, jint a, jint b) {
    int t = 0;
    t = add(a, b);
    return t;
}