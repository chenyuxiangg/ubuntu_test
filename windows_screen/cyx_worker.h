#ifndef CYX_WORKER_H
#define CYX_WORKER_H

#include <QObject>
#include <QStringList>
#include <QHash>

class Cyx_Worker : public QObject
{
    Q_OBJECT
public:
    explicit Cyx_Worker(QObject *parent = 0);
    void getFile(const QString& path,QStringList& res);

signals:
    void gotProgress(const int&,const int&);
    void gotFiles(const QStringList&);
    void gotMd5();

public slots:
    void on_getFilesMd5(const QStringList& filenames);
    void on_getFile(const QString& path);

public:
    QHash<QString,QStringList> m_md5_filename;
};

#endif // CYX_WORKER_H
