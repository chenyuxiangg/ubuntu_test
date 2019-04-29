#ifndef CYX_BASE_WINDOW_H
#define CYX_BASE_WINDOW_H

#include <QWidget>

namespace Ui {
class Cyx_Base_Window;
}

class Cyx_Base_Window : public QWidget
{
    Q_OBJECT

public:
    explicit Cyx_Base_Window(QWidget *parent = 0);
    Ui::Cyx_Base_Window* getUi();
    void setTitle(const QString& title);
    virtual ~Cyx_Base_Window();

private:
    Ui::Cyx_Base_Window *ui;
    QPoint m_z;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void on_close_btn_clicked();
    void on_max_btn_clicked();
    void on_min_btn_clicked();
};

#endif // CYX_BASE_WINDOW_H
