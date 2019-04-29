/********************************************************************************
** Form generated from reading UI file 'cyx_base_window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYX_BASE_WINDOW_H
#define UI_CYX_BASE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cyx_Base_Window
{
public:
    QHBoxLayout *h_main_layout;
    QWidget *content_widget;
    QVBoxLayout *v_content_layout;
    QHBoxLayout *h_top_layout;
    QLabel *title_label;
    QPushButton *min_btn;
    QPushButton *max_btn;
    QPushButton *close_btn;
    QWidget *thrid_widget;

    void setupUi(QWidget *Cyx_Base_Window)
    {
        if (Cyx_Base_Window->objectName().isEmpty())
            Cyx_Base_Window->setObjectName(QStringLiteral("Cyx_Base_Window"));
        Cyx_Base_Window->resize(400, 300);
        h_main_layout = new QHBoxLayout(Cyx_Base_Window);
        h_main_layout->setSpacing(6);
        h_main_layout->setContentsMargins(11, 11, 11, 11);
        h_main_layout->setObjectName(QStringLiteral("h_main_layout"));
        content_widget = new QWidget(Cyx_Base_Window);
        content_widget->setObjectName(QStringLiteral("content_widget"));
        content_widget->setStyleSheet(QLatin1String("#content_widget{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
"}"));
        v_content_layout = new QVBoxLayout(content_widget);
        v_content_layout->setSpacing(0);
        v_content_layout->setContentsMargins(11, 11, 11, 11);
        v_content_layout->setObjectName(QStringLiteral("v_content_layout"));
        v_content_layout->setContentsMargins(0, 0, 0, 0);
        h_top_layout = new QHBoxLayout();
        h_top_layout->setSpacing(0);
        h_top_layout->setObjectName(QStringLiteral("h_top_layout"));
        title_label = new QLabel(content_widget);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setStyleSheet(QStringLiteral("font: 75 12pt \"Adobe Garamond Pro\";"));
        title_label->setAlignment(Qt::AlignCenter);

        h_top_layout->addWidget(title_label);

        min_btn = new QPushButton(content_widget);
        min_btn->setObjectName(QStringLiteral("min_btn"));
        min_btn->setMinimumSize(QSize(32, 32));
        min_btn->setMaximumSize(QSize(32, 32));
        min_btn->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	background-color: rgb(233, 234, 226);\n"
"	image:url(D:/git_Workspace/windows_screen/windows_screen/Resources/min.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(214, 211, 209);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(233, 234, 226);\n"
"}"));

        h_top_layout->addWidget(min_btn);

        max_btn = new QPushButton(content_widget);
        max_btn->setObjectName(QStringLiteral("max_btn"));
        max_btn->setMinimumSize(QSize(32, 32));
        max_btn->setMaximumSize(QSize(32, 32));
        max_btn->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	background-color: rgb(234, 230, 228);\n"
"	image:url(D:/git_Workspace/windows_screen/windows_screen/Resources/max.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(214, 211, 209);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(234, 230, 228);\n"
"}"));

        h_top_layout->addWidget(max_btn);

        close_btn = new QPushButton(content_widget);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        close_btn->setMinimumSize(QSize(32, 32));
        close_btn->setMaximumSize(QSize(32, 32));
        close_btn->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-top-right-radius:5px;\n"
"	background-color: rgb(255, 130, 58);\n"
"	image:url(D:/git_Workspace/windows_screen/windows_screen/Resources/close.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(227, 75, 0);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(255, 153, 69);\n"
"}"));

        h_top_layout->addWidget(close_btn);


        v_content_layout->addLayout(h_top_layout);

        thrid_widget = new QWidget(content_widget);
        thrid_widget->setObjectName(QStringLiteral("thrid_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(thrid_widget->sizePolicy().hasHeightForWidth());
        thrid_widget->setSizePolicy(sizePolicy);

        v_content_layout->addWidget(thrid_widget);


        h_main_layout->addWidget(content_widget);


        retranslateUi(Cyx_Base_Window);

        QMetaObject::connectSlotsByName(Cyx_Base_Window);
    } // setupUi

    void retranslateUi(QWidget *Cyx_Base_Window)
    {
        Cyx_Base_Window->setWindowTitle(QApplication::translate("Cyx_Base_Window", "Cyx_Base_Window", Q_NULLPTR));
        title_label->setText(QString());
        min_btn->setText(QString());
        max_btn->setText(QString());
        close_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cyx_Base_Window: public Ui_Cyx_Base_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYX_BASE_WINDOW_H
