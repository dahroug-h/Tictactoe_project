/********************************************************************************
** Form generated from reading UI file 'userprofile.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILE_H
#define UI_USERPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userProfile
{
public:
    QPushButton *historyButton;
    QPushButton *logoutButton;
    QPushButton *statsButton;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *label;
    QLabel *label_2;
    QPushButton *playButton;
    QLabel *label_3;

    void setupUi(QWidget *userProfile)
    {
        if (userProfile->objectName().isEmpty())
            userProfile->setObjectName("userProfile");
        userProfile->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userProfile->sizePolicy().hasHeightForWidth());
        userProfile->setSizePolicy(sizePolicy);
        userProfile->setMinimumSize(QSize(800, 600));
        userProfile->setMaximumSize(QSize(800, 600));
        historyButton = new QPushButton(userProfile);
        historyButton->setObjectName("historyButton");
        historyButton->setGeometry(QRect(450, 450, 150, 50));
        logoutButton = new QPushButton(userProfile);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(10, 150, 100, 400));
        sizePolicy.setHeightForWidth(logoutButton->sizePolicy().hasHeightForWidth());
        logoutButton->setSizePolicy(sizePolicy);
        statsButton = new QPushButton(userProfile);
        statsButton->setObjectName("statsButton");
        statsButton->setGeometry(QRect(200, 450, 150, 50));
        usernameLabel = new QLabel(userProfile);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(450, 200, 150, 50));
        passwordLabel = new QLabel(userProfile);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(450, 300, 150, 50));
        label = new QLabel(userProfile);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 200, 200, 50));
        label_2 = new QLabel(userProfile);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 300, 200, 50));
        playButton = new QPushButton(userProfile);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(650, 150, 100, 400));
        label_3 = new QLabel(userProfile);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 800, 131));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(72);
        font.setWeight(QFont::Thin);
        font.setItalic(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font: 100\n"
"pt \"Segoe UI\";\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 90, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_3->setFrameShape(QFrame::Shape::NoFrame);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(userProfile);

        QMetaObject::connectSlotsByName(userProfile);
    } // setupUi

    void retranslateUi(QWidget *userProfile)
    {
        userProfile->setWindowTitle(QCoreApplication::translate("userProfile", "Form", nullptr));
        historyButton->setText(QCoreApplication::translate("userProfile", "History", nullptr));
        logoutButton->setText(QCoreApplication::translate("userProfile", "Main Menu", nullptr));
        statsButton->setText(QCoreApplication::translate("userProfile", "Stats", nullptr));
        usernameLabel->setText(QCoreApplication::translate("userProfile", "TextLabel", nullptr));
        passwordLabel->setText(QCoreApplication::translate("userProfile", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("userProfile", "<html><head/><body><p><span style=\" font-size:26pt; color:#eeeeee;\">Username</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("userProfile", "<html><head/><body><p><span style=\" font-size:26pt; color:#eeeeee;\">password</span></p></body></html>", nullptr));
        playButton->setText(QCoreApplication::translate("userProfile", "Play", nullptr));
        label_3->setText(QCoreApplication::translate("userProfile", "<html><head/><body><p><span style=\" font-weight:700; color:#49b8c3;\">Tic-</span><span style=\" font-weight:700; color:#ff9a48;\">Tac-</span><span style=\" font-weight:700; color:#fe7486;\">Toe</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userProfile: public Ui_userProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILE_H
