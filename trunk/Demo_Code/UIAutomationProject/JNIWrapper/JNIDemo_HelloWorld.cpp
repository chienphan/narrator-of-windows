#include <stdio.h>
#include "JNIDemo_HelloWorld.h"   // this header file was generated by javah

JNIEXPORT void JNICALL Java_JNIDemo_HelloWorld_displayMessage(JNIEnv *env, jobject obj, jint nIdex) 
{
	printf("Hello World [%d]!\n", nIdex);
	//System::DateTime now = System::DateTime::Now;
    //printf("%d:%d:%d\n", now.Hour, now.Minute, now.Second);
}