/********************************************************************************
** Form generated from reading UI file 'gamemodewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMODEWINDOW_H
#define UI_GAMEMODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameModeWindow
{
public:
    QPushButton *singlePlayerButton;
    QPushButton *multiPlayerButton;

    void setupUi(QWidget *GameModeWindow)
    {
        if (GameModeWindow->objectName().isEmpty())
            GameModeWindow->setObjectName("GameModeWindow");
        GameModeWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameModeWindow->sizePolicy().hasHeightForWidth());
        GameModeWindow->setSizePolicy(sizePolicy);
        GameModeWindow->setMinimumSize(QSize(800, 600));
        GameModeWindow->setMaximumSize(QSize(800, 600));
        GameModeWindow->setStyleSheet(QString::fromUtf8(""));
        singlePlayerButton = new QPushButton(GameModeWindow);
        singlePlayerButton->setObjectName("singlePlayerButton");
        singlePlayerButton->setGeometry(QRect(50, 100, 300, 400));
        multiPlayerButton = new QPushButton(GameModeWindow);
        multiPlayerButton->setObjectName("multiPlayerButton");
        multiPlayerButton->setGeometry(QRect(450, 100, 299, 400));

        retranslateUi(GameModeWindow);

        QMetaObject::connectSlotsByName(GameModeWindow);
    } // setupUi

    void retranslateUi(QWidget *GameModeWindow)
    {
        GameModeWindow->setWindowTitle(QCoreApplication::translate("GameModeWindow", "Form", nullptr));
        singlePlayerButton->setText(QCoreApplication::translate("GameModeWindow", "Single-Player", nullptr));
        multiPlayerButton->setText(QCoreApplication::translate("GameModeWindow", "Multi-player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameModeWindow: public Ui_GameModeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMODEWINDOW_H
