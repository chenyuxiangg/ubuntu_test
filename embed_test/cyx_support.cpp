#include "cyx_support.h"
#include <QDebug>
#include <QThread>
#include <QMutexLocker>
#include <memory.h>

Cyx_Support::Cyx_Support(QObject* parent):QObject(parent)
  ,m_loading(true)
{

}

void Cyx_Support::on_loading() {
    while(m_loading){
        {
            QMutexLocker locker(&g_mutex);
            if(g_currentcount >= g_framecounts){
                g_currentcount = 0;
                g_cap.set(CV_CAP_PROP_POS_FRAMES,g_currentcount);
            }
            g_cap >> g_frame;
            if (g_frame.empty()) {
                qDebug() << "fault for a frame!";
                return;
            }
        }
        g_currentcount++;
        transToImage(g_frame);
        emit signal_loadImage(m_image);
        QThread::msleep(g_delay);
    }
}

void Cyx_Support::on_endLoading()
{
    m_loading = false;
}

void Cyx_Support::transToImage(const cv::Mat& currentFrame) {
    cv::Mat tmp = currentFrame;
    cv::cvtColor(tmp, tmp, CV_BGR2RGB);				//转换颜色模式
    m_image = QImage((const unsigned char*)(tmp.data), tmp.cols, tmp.rows
        , QImage::Format_RGB888);					//将Mat类型数据转换位QImage
}
