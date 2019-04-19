#include "cyx_file_check.h"
#include <QDebug>
#include <QDir>
#include <QStringList>
#include <QFileInfoList>
#include <QHash>
#include <QCryptographicHash>
#include <QFileDialog>
#include <QMetaType>

Cyx_File_Check::Cyx_File_Check(QWidget *parent):Cyx_Base_Window(parent),
    m_base_ui(this->getUi())
{
    //----窗口设置----
    QString title = tr("File check tool");
    this->setTitle(title);
    this->resize(640,480);
    qRegisterMetaType<QHash<QString,QStringList> >("QHash<QString,QStringList>");

    //----变量初始化----
    //选择文件按钮
    m_select_btn = new QPushButton("selet file",m_base_ui->thrid_widget);
    QString select_btn_sty = "QPushButton{border-radius:5px;\n"
                             "background-color:rgb(197,202,197)\n"
                             "}\n"
                             "QPushButton:hover{\n"
                             "background-color:rgb(157, 156, 152)}\n"
                             "QPushButton:pressed{\n"
                             "background-color:rgb(197,202,197)}";
    m_select_btn->setStyleSheet(select_btn_sty);
    m_select_btn->setMinimumSize(80,25);
    m_select_btn->setMaximumSize(80,25);

    //文件路径显示栏
    m_line_edit = new QLineEdit(m_base_ui->thrid_widget);

    //MD5显示框
    m_md5_list = new QListWidget(m_base_ui->thrid_widget);

    //文件名显示框
    m_filename_list = new QListWidget(m_base_ui->thrid_widget);

    //进度条
    m_progressbar = new QProgressBar(m_base_ui->thrid_widget);

    //m_h_select_layout
    m_h_select_layout = new QHBoxLayout;
    m_h_select_layout->addWidget(m_line_edit);
    m_h_select_layout->addWidget(m_select_btn);

    //m_h_show_layout
    m_h_show_layout = new QHBoxLayout;
    m_h_show_layout->addWidget(m_md5_list);
    m_h_show_layout->addWidget(m_filename_list);

    //m_v_main_layout
    m_v_main_layout = new QVBoxLayout(m_base_ui->thrid_widget);
    m_v_main_layout->addLayout(m_h_select_layout);
    m_v_main_layout->addLayout(m_h_show_layout);
    m_v_main_layout->addWidget(m_progressbar);

    //移动工作对象到线程中
    m_thread = new QThread;
    m_thread->start();
    m_worker.moveToThread(m_thread);

    //信号与槽连接
    connect(m_select_btn,SIGNAL(clicked()),this,SLOT(on_select_btn_clicked()));
    connect(this,SIGNAL(gotPath(const QString&)),&m_worker,SLOT(on_getFile(const QString&)));
    connect(&m_worker,SIGNAL(gotFiles(const QStringList&)),&m_worker,SLOT(on_getFilesMd5(const QStringList&)));
    connect(&m_worker,SIGNAL(gotMd5()),this,SLOT(on_display()));
    connect(&m_worker,SIGNAL(gotProgress(const int&,const int&)),this,SLOT(on_gotProgress(const int&,const int&)));
    connect(m_md5_list,SIGNAL(currentTextChanged(QString)),this,SLOT(on_addItems(QString)));
}

Cyx_File_Check::~Cyx_File_Check(){
    m_thread->exit();
    m_thread->wait(10*1000);
}

void Cyx_File_Check::on_select_btn_clicked()
{
    //点击select按钮，获取指定目录下的所有文件
    QString path = QFileDialog::getExistingDirectory(NULL,tr("Open dir"),tr("."));
    m_line_edit->setText(path);
    m_progressbar->setValue(0);
    emit gotPath(path);
}

void Cyx_File_Check::on_display()
{
    m_md5_list->clear();
    bool flag = false;
    for(auto it = m_worker.m_md5_filename.begin();it != m_worker.m_md5_filename.end();++it){
        if(it.value().count() > 1){
            flag = true;
            m_md5_list->addItem(it.key());
        }
    }
    if(!flag){
        m_md5_list->addItem(tr("检测完毕，未发现重复文件！"));
    }
}

void Cyx_File_Check::on_gotProgress(const int &cur, const int &total)
{
    m_progressbar->setValue(cur);
    m_progressbar->setMaximum(total);
}

void Cyx_File_Check::on_addItems(QString md5)
{
    m_filename_list->clear();
    m_filename_list->addItems(m_worker.m_md5_filename[md5]);
}
