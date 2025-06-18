/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginPage->sizePolicy().hasHeightForWidth());
        LoginPage->setSizePolicy(sizePolicy);
        LoginPage->setMinimumSize(QSize(800, 600));
        LoginPage->setMaximumSize(QSize(800, 600));
        LoginPage->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(LoginPage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 375, 300, 50));
        QFont font;
        font.setPointSize(24);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(LoginPage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 500, 200, 50));
        QFont font1;
        font1.setPointSize(12);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8(""));
        lineEdit_pass = new QLineEdit(LoginPage);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(300, 300, 300, 50));
        lineEdit = new QLineEdit(LoginPage);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 225, 300, 50));
        label = new QLabel(LoginPage);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 225, 200, 50));
        label->setAutoFillBackground(false);
        label_2 = new QLabel(LoginPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 300, 200, 50));
        label_3 = new QLabel(LoginPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 30, 600, 150));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(72);
        font2.setWeight(QFont::Thin);
        font2.setItalic(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("font: 100\n"
"pt \"Segoe UI\";\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 90, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_3->setFrameShape(QFrame::Shape::NoFrame);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginPage", "Create new account", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; color:#eeeeee;\">UserName</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginPage", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; color:#eeeeee;\">Password</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("LoginPage", "<html><head/><body><p><span style=\" font-weight:700; color:#49b8c3;\">Tic-</span><span style=\" font-weight:700; color:#ff9a48;\">Tac-</span><span style=\" font-weight:700; color:#fe7486;\">Toe</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
