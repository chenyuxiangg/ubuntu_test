#ifndef CYX_FILE_CHECK_H
#define CYX_FILE_CHECK_H
#include "ui_cyx_base_window.h"
#include "cyx_base_window.h"
#include "cyx_worker.h"
#include <QPushButton>
#include <QStringList>
#include <QHash>
#include <QLineEdit>
#include <QListWidget>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QThread>

class Cyx_File_Check : public Cyx_Base_Window
{
    Q_OBJECT
public:
    explicit Cyx_File_Check(QWidget* parent = 0);
    virtual ~Cyx_File_Check();

signals:
    void gotPath(const QString&);

public slots:
    void on_select_btn_clicked();
    void on_display();
    void on_gotProgress(const int& cur,const int& total);
    void on_addItems(QString);

public:
    QPushButton* m_select_btn;
    QLineEdit* m_line_edit;
    QListWidget* m_md5_list;
    QListWidget* m_filename_list;
    QVBoxLayout* m_v_main_layout;
    QHBoxLayout* m_h_select_layout;
    QHBoxLayout* m_h_show_layout;
    QProgressBar* m_progressbar;
    Ui::Cyx_Base_Window* m_base_ui;
    QThread* m_thread;
    Cyx_Worker m_worker;
};

#endif // CYX_FILE_CHECK_H
