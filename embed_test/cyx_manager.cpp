#include "cyx_manager.h"
#include "cyx_base_window.h"
#include "ui_cyx_base_window.h"
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QDebug>
#include <QString>
#include <QMenu>
#include <QAction>

Cyx_Manager::Cyx_Manager(QWidget* parent):Cyx_Base_Window(parent),
    m_trayicon(new QSystemTrayIcon(this))
{
    this->setTitle("my desktop");

    //组件定义
    //选择按钮
    m_btn_select = new QPushButton(getUi()->thrid_widget);
    m_btn_select->setText("select");
    //系统托盘
    m_trayicon->setIcon(QIcon(":/cyx/Resources/lion.png"));
    m_trayicon->setToolTip("lion_desktop");
    m_trayicon->show();

    m_menu = new QMenu(this);
    m_ashow = new QAction(m_menu);
    m_aexit = new QAction(m_menu);

    m_ashow->setText("Show");
    m_aexit->setText("exit");

    m_menu->addAction(m_ashow);
    m_menu->addAction(m_aexit);
    m_trayicon->setContextMenu(m_menu);

    //信号与槽连接
    connect(m_btn_select,SIGNAL(clicked()),this,SLOT(on_select_clicked()));
    connect(this,SIGNAL(got_path(const QString&)),&m_embed_window,SIGNAL(readyLoad(const QString&)));
    connect(getUi()->close_btn,SIGNAL(clicked()),&m_embed_window,SLOT(on_endProcess()));
    connect(m_trayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activated(QSystemTrayIcon::ActivationReason)));
    connect(m_ashow, SIGNAL(triggered()), this, SLOT(on_show()));
    connect(m_aexit, SIGNAL(triggered()), this, SLOT(on_exit()));
}

void Cyx_Manager::on_show()
{
    this->showNormal();
}

void Cyx_Manager::on_exit()
{
    this->close();
}

void Cyx_Manager::on_select_clicked()
{
    QString path = QFileDialog::getOpenFileName(nullptr,QString(),QString("..")
                                                ,QString("*.mp4 *.avi *.wav"));
    emit got_path(path);
}

void Cyx_Manager::on_activated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Context:
        qDebug() << "Context";
        break;
    case QSystemTrayIcon::Trigger:
        qDebug() << "Trigger";
        break;
    case QSystemTrayIcon::DoubleClick:
        qDebug() << "DoubleClick";
        break;
    case QSystemTrayIcon::MiddleClick:
        qDebug() << "MiddleClick";
        break;
    default:
        break;
    }
}
