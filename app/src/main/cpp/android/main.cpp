//
// Created by Simonppg on 11/4/2017.
//

#include "../game.hpp"
#include "filesManager.hpp"

Game *game;

#ifdef __cplusplus
extern "C" {
#endif

#include <jni.h>
#include <android/asset_manager_jni.h>

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_surfaceCreated
        (JNIEnv * env, jclass cls) {
    game->surfaceCreated();
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_surfaceChanged
        (JNIEnv * env, jclass cls, jint width, jint height) {
    game->surfaceChanged(width, height);
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_drawFrame
        (JNIEnv * env, jclass cls) {
    game->update();
    game->render();
}

JNIEXPORT bool JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1touch_1event
        (JNIEnv * env, jclass cls, jdouble xpos, jdouble ypos) {
    return on_touch_event(xpos, ypos);
}

//TODO Remove this function
JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_load_1asset_1manager
        (JNIEnv *env, jclass type, jobject mgr) {
    //AAssetManager *mgr2 = AAssetManager_fromJava(env, mgr);
    //load_asset_manager(mgr2);
}

JNIEXPORT jobjectArray JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_getTestsList
        (JNIEnv * env, jclass cls) {

#define LEN 3
    const char *tests[LEN]={"SandBox", "Window", "Triangle"};

    jstring str;
    jobjectArray test = 0;
    jsize len = LEN;
    int i;

    test = (*env).NewObjectArray(len, (*env).FindClass("java/lang/String"), 0);

    for(i = 0; i < LEN; i++)
    {
        str = (*env).NewStringUTF(tests[i]);
        (*env).SetObjectArrayElement(test, i, str);
    }

    return test;
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_init(JNIEnv *env, jclass type,
                                                                jint position, jobject mgr) {
    AAssetManager *mgr2 = AAssetManager_fromJava(env, mgr);
    assert(mgr2);
    load_asset_manager(mgr2);
    game = Game::init(position);
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_pause(JNIEnv *env, jclass type) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_resume(JNIEnv *env, jclass type) {

    // TODO

}

#ifdef __cplusplus
}
#endif