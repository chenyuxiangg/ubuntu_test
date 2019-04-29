#ifndef CYX_CONVERT_H
#define CYX_CONVERT_H
#include <QObject>
#include <QString>
#include <Windows.h>

class Cyx_Convert:public QObject
{
    Q_OBJECT
public:
    Cyx_Convert(QObject* parent = 0);
    void Convert(const QString&);
    void DoCommand(LPWSTR command);

signals:
    void Converted(const QString&);

public slots:
    void on_CheckSource(const QString&);

private:
    QString m_outpath;
};

#endif // CYX_CONVERT_H
