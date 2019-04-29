#ifndef CYX_MANAGER_H
#define CYX_MANAGER_H
#include "cyx_base_window.h"
#include "cyx_embed.h"
#include <QPushButton>
#include <QSystemTrayIcon>

class Cyx_Manager:public Cyx_Base_Window
{
    Q_OBJECT
public:
    Cyx_Manager(QWidget* parent = 0);

signals:
    void got_path(const QString&);

public slots:
    void on_show();
    void on_exit();
    void on_select_clicked();
    void on_activated(QSystemTrayIcon::ActivationReason reason);

private:
    QPushButton* m_btn_select;
    Cyx_Embed m_embed_window;
    QSystemTrayIcon* m_trayicon;
    QMenu* m_menu;
    QAction* m_ashow;
    QAction* m_aexit;
};

#endif // CYX_MANAGER_H
