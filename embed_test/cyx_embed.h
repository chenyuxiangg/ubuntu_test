#ifndef CYX_EMBED_H
#define CYX_EMBED_H
#include <QWindow>
#include <QBackingStore>
#include <QThread>
#include <QString>
#include "cyx_support.h"
#include "cyx_event.h"
#include "cyx_convert.h"

class Cyx_Embed : public QWindow
{
    Q_OBJECT
public:
    explicit Cyx_Embed(QWindow *parent = 0);
    void SetFileName(const char* name);
    void RebootCap(const QString& filename);
    bool event(QEvent* e);
    ~Cyx_Embed();

signals:
    void readyLoad(const QString&);
    void endProcess();
    void startLoad();

public slots:
    void on_loadImage(const QImage&);
    void on_endProcess();
    void on_Ready(const QString&);


private:
    QBackingStore m_store;
    QWindow* hwnd;
    QThread* m_thread;
    QThread* m_thread_convert;
    Cyx_Support* m_support;
    Cyx_Convert* m_convert;
    QImage m_image;
    bool m_flag;
};

#endif // CYX_EMBED_H
