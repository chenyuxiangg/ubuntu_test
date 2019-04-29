#ifndef CYX_UTIL_H
#define CYX_UTIL_H
#include <Windows.h>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")

class Cyx_Util
{
public:
    Cyx_Util();
    static HWND GetShowWindow();
};

#endif // CYX_UTIL_H
