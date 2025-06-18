#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginpage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameModeWindow(nullptr),
    loginPage(nullptr)
{
    ui->setupUi(this);
    Initialize();

    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(131, 61, 121));    // Dark blue-gray
    gradient.setColorAt(1, QColor(165, 64, 134));    // Darker blue-gray

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);
    QString roundedButtonStyle =
        "QPushButton {"
        "   background-color: %1;"  // Color will be inserted
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 50px;"
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "   min-width: 100px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    ui->startButton->setStyleSheet(roundedButtonStyle
                                       .arg("#4acdd5")
                                       .arg("#2192a2")
                                       .arg("#798596"));
    ui->exitButton->setStyleSheet(roundedButtonStyle
                                      .arg("#ff9a48")  // Normal color (red)
                                      .arg("#de6a25")  // Hover color
                                      .arg("#b71c1c"));  // Pressed color

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    // Set window size - can also set this in Qt Designer
}

void MainWindow::on_startButton_clicked()
{
    loginPage = new LoginPage;
    loginPage->show();
    this->close();
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}
