/********************************************************************************
** Form generated from reading UI file 'choosedifficulty.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEDIFFICULTY_H
#define UI_CHOOSEDIFFICULTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseDifficulty
{
public:
    QPushButton *easyButton;
    QPushButton *hardButton;
    QPushButton *mediumButton;

    void setupUi(QWidget *chooseDifficulty)
    {
        if (chooseDifficulty->objectName().isEmpty())
            chooseDifficulty->setObjectName("chooseDifficulty");
        chooseDifficulty->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chooseDifficulty->sizePolicy().hasHeightForWidth());
        chooseDifficulty->setSizePolicy(sizePolicy);
        chooseDifficulty->setMinimumSize(QSize(800, 600));
        chooseDifficulty->setMaximumSize(QSize(800, 600));
        easyButton = new QPushButton(chooseDifficulty);
        easyButton->setObjectName("easyButton");
        easyButton->setGeometry(QRect(50, 100, 200, 400));
        hardButton = new QPushButton(chooseDifficulty);
        hardButton->setObjectName("hardButton");
        hardButton->setGeometry(QRect(550, 100, 200, 400));
        mediumButton = new QPushButton(chooseDifficulty);
        mediumButton->setObjectName("mediumButton");
        mediumButton->setGeometry(QRect(300, 100, 200, 400));

        retranslateUi(chooseDifficulty);

        QMetaObject::connectSlotsByName(chooseDifficulty);
    } // setupUi

    void retranslateUi(QWidget *chooseDifficulty)
    {
        chooseDifficulty->setWindowTitle(QCoreApplication::translate("chooseDifficulty", "Form", nullptr));
        easyButton->setText(QCoreApplication::translate("chooseDifficulty", "Easy", nullptr));
        hardButton->setText(QCoreApplication::translate("chooseDifficulty", "Hard", nullptr));
        mediumButton->setText(QCoreApplication::translate("chooseDifficulty", "Medium", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chooseDifficulty: public Ui_chooseDifficulty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEDIFFICULTY_H
