#include "cyx_worker.h"
#include <QFile>
#include <QCryptographicHash>
#include <QDir>
#include <QFileInfoList>

Cyx_Worker::Cyx_Worker(QObject *parent) : QObject(parent)
{

}

void Cyx_Worker::on_getFilesMd5(const QStringList &filenames)
{
    m_md5_filename.clear();
    for(auto it = filenames.begin();it != filenames.end();++it){
        QFile file((*it));
        file.open(QIODevice::ReadOnly);
        QCryptographicHash md5(QCryptographicHash::Md5);
        while(!file.atEnd()){
            md5.addData(file.read(1024*1024));
        }
        m_md5_filename[md5.result().toHex()].append((*it));
        emit gotProgress(it-filenames.begin()+1,filenames.count());
    }
    emit gotMd5();
}

void Cyx_Worker::on_getFile(const QString &path)
{
    QStringList res;
    getFile(path,res);
    emit gotFiles(res);
}

void Cyx_Worker::getFile(const QString &path,QStringList& res)
{
    QDir dir(path);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    if(dir.exists()){
        QFileInfoList fileinfolist = dir.entryInfoList();
        for(auto it = fileinfolist.begin();it != fileinfolist.end();++it){
            if((*it).isDir()){
                getFile((*it).absoluteFilePath(),res);
            }
            else{
                res.append((*it).absoluteFilePath());
            }
        }
    }
}
