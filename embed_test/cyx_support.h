#ifndef CYX_SUPPORT_H
#define CYX_SUPPORT_H
#include <QObject>
#include <QEvent>
#include <QImage>
#include "cyx_global.h"


class Cyx_Support:public QObject
{
    Q_OBJECT
public:
    Cyx_Support(QObject* parent = 0);
    //void SetFileName(const char* name);

signals:
    void signal_loadImage(const QImage&);
    //void startLoad();

public slots:
    //void on_Ready(const QString&);
    void on_loading();
    void on_endLoading();

private:
    QImage m_image;
    bool m_loading;

private:
    void transToImage(const cv::Mat& currentFrame);
};

#endif // CYX_SUPPORT_H
