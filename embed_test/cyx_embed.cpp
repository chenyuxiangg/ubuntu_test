#include "cyx_embed.h"
#include <QPainter>
#include <QDebug>
#include <QCoreApplication>
#include <QMutexLocker>
#include "cyx_util.h"
#include "cyx_global.h"

Cyx_Embed::Cyx_Embed(QWindow *parent) :
    QWindow(parent),m_store(this),
    m_thread(new QThread),m_thread_convert(new QThread),m_support(new Cyx_Support)
  ,m_flag(false),m_convert(new Cyx_Convert)
{
    hwnd = QWindow::fromWinId((WId)Cyx_Util::GetShowWindow());
    this->setParent(hwnd);
    this->resize(640,480);

    m_support->moveToThread(m_thread);
    m_thread->start();

    m_convert->moveToThread(m_thread_convert);
    m_thread_convert->start();

    connect(m_support,SIGNAL(signal_loadImage(const QImage&)),this,SLOT(on_loadImage(const QImage&)));
    connect(this,SIGNAL(readyLoad(const QString&)),m_convert,SLOT(on_CheckSource(const QString&)));
    connect(m_convert,SIGNAL(Converted(const QString&)),this,SLOT(on_Ready(const QString&)));
    connect(this,SIGNAL(startLoad()),m_support,SLOT(on_loading()));
    connect(this,SIGNAL(endProcess()),m_support,SLOT(on_endLoading()));
    this->showFullScreen();
}

void Cyx_Embed::SetFileName(const char *name)
{
    g_filename = name;
}

void Cyx_Embed::RebootCap(const QString &filepath)
{
    QMutexLocker locker(&g_mutex);
    if(g_cap.isOpened()){
        g_cap.release();
        m_flag = true;
    }
    size_t len = filepath.size();
    char* path = new char[len+1];
    memcpy(path,filepath.toLocal8Bit().data(),len);
    path[len] = '\0';
    SetFileName(path);
    if(g_filename != ""){
        g_cap.open(g_filename);
        g_currentcount = 0;
    }
    else{
        qDebug() << "file name is null!";
        return;
    }
    if (!g_cap.isOpened()) {
        qDebug() << "can not open file!";
        return;
    }
    //获取帧率
    g_framerate = g_cap.get(CV_CAP_PROP_FPS);
    //获取视频帧数并用该帧数计算播放延时
    g_framecounts = g_cap.get(CV_CAP_PROP_FRAME_COUNT);

    if (g_framerate == 0) {
        return;
    }
    g_delay = (int)(1000 / g_framerate);
    delete[] path;
    path = nullptr;
}

bool Cyx_Embed::event(QEvent* e)
{
    QRect rect(QPoint(0,0),this->size());
    if(e->type() == Cyx_Event::Cyx_Event_Type){
        m_store.resize(this->size());
        m_store.beginPaint(rect);
        QPainter painter(m_store.paintDevice());
        painter.fillRect(rect,Qt::white);
        painter.drawImage(0,0,m_image);
        m_store.endPaint();
        m_store.flush(rect,this);
    }
    return QWindow::event(e);
}

Cyx_Embed::~Cyx_Embed()
{
    m_thread->exit();
    m_thread_convert->exit();
    m_thread->wait(10*1000);
    m_thread_convert->wait(10*1000);
}

void Cyx_Embed::on_loadImage(const QImage& image)
{
    m_image = image;
    Cyx_Event e(Cyx_Event::Cyx_Event_Type);
    QCoreApplication::sendEvent(this,&e);
}

void Cyx_Embed::on_endProcess()
{
    emit endProcess();
    this->close();
    this->hide();
}

void Cyx_Embed::on_Ready(const QString& filepath)
{
    RebootCap(filepath);
    if(!m_flag){
        emit startLoad();
    }
}
