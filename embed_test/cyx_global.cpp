#include "cyx_global.h"
#include <Windows.h>

const char* g_filename = "";
cv::VideoCapture g_cap;
cv::Mat g_frame;
int g_framerate = 0;
int g_framecounts = 0;
int g_delay = 0;
int g_currentcount = 0;
QMutex g_mutex;
