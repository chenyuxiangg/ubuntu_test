#include "cyx_base_window.h"
#include "ui_cyx_base_window.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

Cyx_Base_Window::Cyx_Base_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cyx_Base_Window)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect* pshadow = new QGraphicsDropShadowEffect;
    pshadow->setBlurRadius(5);
    pshadow->setColor(Qt::black);
    pshadow->setOffset(0);
    ui->content_widget->setGraphicsEffect(pshadow);
}

Ui::Cyx_Base_Window *Cyx_Base_Window::getUi()
{
    return ui;
}

void Cyx_Base_Window::setTitle(const QString &title)
{
    ui->title_label->setText(title);
}

Cyx_Base_Window::~Cyx_Base_Window()
{
    delete ui;
}

void Cyx_Base_Window::mousePressEvent(QMouseEvent *event)
{
    QPoint y = event->globalPos();
    QPoint x = this->geometry().topLeft();
    m_z = y - x;
    QWidget::mousePressEvent(event);
}

void Cyx_Base_Window::mouseReleaseEvent(QMouseEvent *event)
{
    m_z = QPoint();
    QWidget::mouseReleaseEvent(event);
}

void Cyx_Base_Window::mouseMoveEvent(QMouseEvent *event)
{
    QPoint y = event->globalPos();
    QPoint x = y - m_z;
    this->move(x);
    QWidget::mouseMoveEvent(event);
}

void Cyx_Base_Window::on_close_btn_clicked()
{
    this->close();
}

void Cyx_Base_Window::on_max_btn_clicked()
{
    if(this->isMaximized()){
        ui->h_main_layout->setMargin(11);
        this->showNormal();
    }
    else{
        ui->h_main_layout->setMargin(0);
        this->showMaximized();
    }
}

void Cyx_Base_Window::on_min_btn_clicked()
{
    this->showMinimized();
}
