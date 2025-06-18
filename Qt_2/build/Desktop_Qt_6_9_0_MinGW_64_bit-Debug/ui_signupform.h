/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupForm
{
public:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmEdit;
    QPushButton *signupButton;
    QPushButton *backButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *SignupForm)
    {
        if (SignupForm->objectName().isEmpty())
            SignupForm->setObjectName("SignupForm");
        SignupForm->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SignupForm->sizePolicy().hasHeightForWidth());
        SignupForm->setSizePolicy(sizePolicy);
        SignupForm->setMinimumSize(QSize(800, 600));
        SignupForm->setMaximumSize(QSize(800, 600));
        SignupForm->setStyleSheet(QString::fromUtf8(""));
        usernameEdit = new QLineEdit(SignupForm);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(300, 150, 300, 50));
        passwordEdit = new QLineEdit(SignupForm);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(300, 250, 300, 50));
        confirmEdit = new QLineEdit(SignupForm);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setGeometry(QRect(300, 350, 300, 50));
        signupButton = new QPushButton(SignupForm);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(250, 500, 400, 50));
        backButton = new QPushButton(SignupForm);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(50, 50, 200, 50));
        label = new QLabel(SignupForm);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 150, 200, 50));
        label_2 = new QLabel(SignupForm);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 250, 200, 50));
        label_3 = new QLabel(SignupForm);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 350, 200, 50));

        retranslateUi(SignupForm);

        QMetaObject::connectSlotsByName(SignupForm);
    } // setupUi

    void retranslateUi(QWidget *SignupForm)
    {
        SignupForm->setWindowTitle(QCoreApplication::translate("SignupForm", "Form", nullptr));
        signupButton->setText(QCoreApplication::translate("SignupForm", "sign up", nullptr));
        backButton->setText(QCoreApplication::translate("SignupForm", "back to log in page", nullptr));
        label->setText(QCoreApplication::translate("SignupForm", "<html><head/><body><p><span style=\" font-size:24pt; color:#eeeeee;\">username</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SignupForm", "<html><head/><body><p><span style=\" font-size:24pt; color:#eeeeee;\">password</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("SignupForm", "<html><head/><body><p><span style=\" font-size:16pt; color:#eeeeee;\">confirm password</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupForm: public Ui_SignupForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
