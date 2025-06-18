/********************************************************************************
** Form generated from reading UI file 'playerselection.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSELECTION_H
#define UI_PLAYERSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerSelection
{
public:
    QPushButton *player1SelectX;
    QPushButton *player1SelectO;
    QPushButton *player2SelectO;
    QLabel *player2Label;
    QLabel *player1Label;
    QPushButton *player2SelectX;
    QPushButton *player1Starts;
    QPushButton *player2Starts;
    QPushButton *spSelectX;
    QPushButton *spSelectO;
    QPushButton *spStartGame;
    QWidget *multiplayerWidget;
    QWidget *singleplayerWidget;

    void setupUi(QWidget *PlayerSelection)
    {
        if (PlayerSelection->objectName().isEmpty())
            PlayerSelection->setObjectName("PlayerSelection");
        PlayerSelection->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlayerSelection->sizePolicy().hasHeightForWidth());
        PlayerSelection->setSizePolicy(sizePolicy);
        PlayerSelection->setMinimumSize(QSize(800, 600));
        PlayerSelection->setMaximumSize(QSize(800, 600));
        PlayerSelection->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        PlayerSelection->setStyleSheet(QString::fromUtf8(""));
        player1SelectX = new QPushButton(PlayerSelection);
        player1SelectX->setObjectName("player1SelectX");
        player1SelectX->setGeometry(QRect(110, 190, 131, 131));
        player1SelectX->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:none"));
        player1SelectO = new QPushButton(PlayerSelection);
        player1SelectO->setObjectName("player1SelectO");
        player1SelectO->setGeometry(QRect(560, 190, 141, 131));
        player1SelectO->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:none"));
        player2SelectO = new QPushButton(PlayerSelection);
        player2SelectO->setObjectName("player2SelectO");
        player2SelectO->setGeometry(QRect(110, 410, 131, 121));
        player2SelectO->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:none"));
        player2Label = new QLabel(PlayerSelection);
        player2Label->setObjectName("player2Label");
        player2Label->setGeometry(QRect(90, 349, 611, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Gilroy-Bold")});
        font.setPointSize(14);
        font.setBold(false);
        player2Label->setFont(font);
        player1Label = new QLabel(PlayerSelection);
        player1Label->setObjectName("player1Label");
        player1Label->setGeometry(QRect(90, 146, 611, 51));
        player1Label->setFont(font);
        player1Label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        player2SelectX = new QPushButton(PlayerSelection);
        player2SelectX->setObjectName("player2SelectX");
        player2SelectX->setGeometry(QRect(560, 410, 141, 121));
        player2SelectX->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:none"));
        player1Starts = new QPushButton(PlayerSelection);
        player1Starts->setObjectName("player1Starts");
        player1Starts->setGeometry(QRect(330, 240, 131, 51));
        player1Starts->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:none"));
        player2Starts = new QPushButton(PlayerSelection);
        player2Starts->setObjectName("player2Starts");
        player2Starts->setGeometry(QRect(330, 450, 131, 51));
        player2Starts->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border:none"));
        spSelectX = new QPushButton(PlayerSelection);
        spSelectX->setObjectName("spSelectX");
        spSelectX->setGeometry(QRect(130, 230, 201, 171));
        spSelectX->setStyleSheet(QString::fromUtf8(""));
        spSelectO = new QPushButton(PlayerSelection);
        spSelectO->setObjectName("spSelectO");
        spSelectO->setGeometry(QRect(460, 230, 191, 171));
        spSelectO->setStyleSheet(QString::fromUtf8(""));
        spStartGame = new QPushButton(PlayerSelection);
        spStartGame->setObjectName("spStartGame");
        spStartGame->setGeometry(QRect(340, 460, 121, 51));
        spStartGame->setStyleSheet(QString::fromUtf8(""));
        multiplayerWidget = new QWidget(PlayerSelection);
        multiplayerWidget->setObjectName("multiplayerWidget");
        multiplayerWidget->setGeometry(QRect(0, 0, 800, 600));
        singleplayerWidget = new QWidget(PlayerSelection);
        singleplayerWidget->setObjectName("singleplayerWidget");
        singleplayerWidget->setGeometry(QRect(0, 0, 800, 600));
        singleplayerWidget->setStyleSheet(QString::fromUtf8(""));
        singleplayerWidget->raise();
        player2Label->raise();
        player1Label->raise();
        multiplayerWidget->raise();
        spSelectX->raise();
        spSelectO->raise();
        spStartGame->raise();
        player1SelectO->raise();
        player1SelectX->raise();
        player1Starts->raise();
        player2SelectO->raise();
        player2SelectX->raise();
        player2Starts->raise();

        retranslateUi(PlayerSelection);

        QMetaObject::connectSlotsByName(PlayerSelection);
    } // setupUi

    void retranslateUi(QWidget *PlayerSelection)
    {
        PlayerSelection->setWindowTitle(QCoreApplication::translate("PlayerSelection", "Form", nullptr));
        player1SelectX->setText(QCoreApplication::translate("PlayerSelection", "x", nullptr));
        player1SelectO->setText(QCoreApplication::translate("PlayerSelection", "o", nullptr));
        player2SelectO->setText(QCoreApplication::translate("PlayerSelection", "O", nullptr));
        player2Label->setText(QCoreApplication::translate("PlayerSelection", "TextLabel", nullptr));
        player1Label->setText(QCoreApplication::translate("PlayerSelection", "TextLabel", nullptr));
        player2SelectX->setText(QCoreApplication::translate("PlayerSelection", "X", nullptr));
        player1Starts->setText(QCoreApplication::translate("PlayerSelection", "select", nullptr));
        player2Starts->setText(QCoreApplication::translate("PlayerSelection", "select", nullptr));
        spSelectX->setText(QCoreApplication::translate("PlayerSelection", "X", nullptr));
        spSelectO->setText(QCoreApplication::translate("PlayerSelection", "O", nullptr));
        spStartGame->setText(QCoreApplication::translate("PlayerSelection", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerSelection: public Ui_PlayerSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSELECTION_H
