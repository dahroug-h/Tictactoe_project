/********************************************************************************
** Form generated from reading UI file 'gamehistory.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHISTORY_H
#define UI_GAMEHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameHistory
{
public:
    QPushButton *backButton;
    QPushButton *newGameButton;
    QListWidget *gameList;
    QPushButton *mainMenuButton;
    QPushButton *switchPlayerButton;

    void setupUi(QWidget *gameHistory)
    {
        if (gameHistory->objectName().isEmpty())
            gameHistory->setObjectName("gameHistory");
        gameHistory->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gameHistory->sizePolicy().hasHeightForWidth());
        gameHistory->setSizePolicy(sizePolicy);
        gameHistory->setMinimumSize(QSize(800, 600));
        gameHistory->setMaximumSize(QSize(800, 600));
        backButton = new QPushButton(gameHistory);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(30, 230, 80, 18));
        newGameButton = new QPushButton(gameHistory);
        newGameButton->setObjectName("newGameButton");
        newGameButton->setGeometry(QRect(30, 110, 80, 18));
        gameList = new QListWidget(gameHistory);
        gameList->setObjectName("gameList");
        gameList->setGeometry(QRect(130, 30, 500, 491));
        mainMenuButton = new QPushButton(gameHistory);
        mainMenuButton->setObjectName("mainMenuButton");
        mainMenuButton->setGeometry(QRect(30, 140, 80, 18));
        switchPlayerButton = new QPushButton(gameHistory);
        switchPlayerButton->setObjectName("switchPlayerButton");
        switchPlayerButton->setGeometry(QRect(30, 190, 80, 18));

        retranslateUi(gameHistory);

        QMetaObject::connectSlotsByName(gameHistory);
    } // setupUi

    void retranslateUi(QWidget *gameHistory)
    {
        gameHistory->setWindowTitle(QCoreApplication::translate("gameHistory", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("gameHistory", "back", nullptr));
        newGameButton->setText(QCoreApplication::translate("gameHistory", "New game", nullptr));
        mainMenuButton->setText(QCoreApplication::translate("gameHistory", "Main menu", nullptr));
        switchPlayerButton->setText(QCoreApplication::translate("gameHistory", "Switch player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameHistory: public Ui_gameHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHISTORY_H
