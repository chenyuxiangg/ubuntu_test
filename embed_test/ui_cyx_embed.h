/********************************************************************************
** Form generated from reading UI file 'cyx_embed.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYX_EMBED_H
#define UI_CYX_EMBED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cyx_Embed
{
public:

    void setupUi(QWidget *Cyx_Embed)
    {
        if (Cyx_Embed->objectName().isEmpty())
            Cyx_Embed->setObjectName(QStringLiteral("Cyx_Embed"));
        Cyx_Embed->resize(400, 300);

        retranslateUi(Cyx_Embed);

        QMetaObject::connectSlotsByName(Cyx_Embed);
    } // setupUi

    void retranslateUi(QWidget *Cyx_Embed)
    {
        Cyx_Embed->setWindowTitle(QApplication::translate("Cyx_Embed", "Cyx_Embed", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cyx_Embed: public Ui_Cyx_Embed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYX_EMBED_H
