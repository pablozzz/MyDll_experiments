// classes.cpp: определяет точку входа для консольного приложения.
#include <iostream>
#include <windows.h>
using namespace std;

class mClass{
};

int main(int argc, char* argv[])
{
    HMODULE hLib; //hadle of library
    hLib = LoadLibrary("OOP_lib.dll"); //path to library

    void (mClass::*pConstructor)();
    (FARPROC &)pConstructor = GetProcAddress(hLib, "DllMain@12"); // constuctor pointer

    char *_pc = new char[sizeof(mClass)]; //create a new object in the heap
    mClass *pc = (mClass *)_pc;

    (pc->*pConstructor)(); // we must start constructor by manual

    void (mClass::*pFunction)(int);
    (FARPROC &)pFunction = GetProcAddress(hLib, "_ZN7myClass12myStaticFuncEi"); //function address
    (pc->*pFunction)(5);
    return 0;
}
