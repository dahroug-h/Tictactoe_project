/********************************************************************************
** Form generated from reading UI file 'statisticswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSWINDOW_H
#define UI_STATISTICSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statisticsWindow
{
public:
    QPushButton *backButton;
    QLabel *label_2;
    QLabel *winsLabel;
    QLabel *label;
    QLabel *tiesLabel;
    QLabel *lossesLabel;
    QLabel *label_3;

    void setupUi(QWidget *statisticsWindow)
    {
        if (statisticsWindow->objectName().isEmpty())
            statisticsWindow->setObjectName("statisticsWindow");
        statisticsWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statisticsWindow->sizePolicy().hasHeightForWidth());
        statisticsWindow->setSizePolicy(sizePolicy);
        statisticsWindow->setMinimumSize(QSize(800, 600));
        statisticsWindow->setMaximumSize(QSize(800, 600));
        backButton = new QPushButton(statisticsWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(80, 70, 100, 50));
        label_2 = new QLabel(statisticsWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 200, 200, 100));
        winsLabel = new QLabel(statisticsWindow);
        winsLabel->setObjectName("winsLabel");
        winsLabel->setGeometry(QRect(100, 400, 200, 100));
        winsLabel->setStyleSheet(QString::fromUtf8("font: 48pt \"Segoe UI\";"));
        label = new QLabel(statisticsWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 200, 200, 100));
        tiesLabel = new QLabel(statisticsWindow);
        tiesLabel->setObjectName("tiesLabel");
        tiesLabel->setGeometry(QRect(375, 400, 200, 100));
        tiesLabel->setStyleSheet(QString::fromUtf8("font: 48pt \"Segoe UI\";"));
        lossesLabel = new QLabel(statisticsWindow);
        lossesLabel->setObjectName("lossesLabel");
        lossesLabel->setGeometry(QRect(600, 400, 200, 100));
        lossesLabel->setStyleSheet(QString::fromUtf8("font: 48pt \"Segoe UI\";"));
        label_3 = new QLabel(statisticsWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 200, 200, 100));

        retranslateUi(statisticsWindow);

        QMetaObject::connectSlotsByName(statisticsWindow);
    } // setupUi

    void retranslateUi(QWidget *statisticsWindow)
    {
        statisticsWindow->setWindowTitle(QCoreApplication::translate("statisticsWindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("statisticsWindow", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("statisticsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; color:#ff0000;\">Losses</span></p></body></html>", nullptr));
        winsLabel->setText(QCoreApplication::translate("statisticsWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#eeeeee;\">TextLabel</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("statisticsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; color:#eeeeee;\">Ties</span></p></body></html>", nullptr));
        tiesLabel->setText(QCoreApplication::translate("statisticsWindow", "<html><head/><body><p><span style=\" color:#eeeeee;\">TextLabel</span></p></body></html>", nullptr));
        lossesLabel->setText(QCoreApplication::translate("statisticsWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">TextLabel</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("statisticsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; color:#00ff00;\">Wins</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statisticsWindow: public Ui_statisticsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSWINDOW_H
