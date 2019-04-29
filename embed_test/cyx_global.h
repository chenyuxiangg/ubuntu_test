#ifndef CYX_GLOBAL_H
#define CYX_GLOBAL_H
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QMutex>
#include <QSize>

extern const char* g_filename;
extern cv::VideoCapture g_cap;
extern cv::Mat g_frame;
extern int g_framerate;
extern int g_framecounts;
extern int g_delay;
extern QMutex g_mutex;
extern int g_currentcount;

#endif // CYX_GLOBAL_H
