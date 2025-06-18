#include "statisticswindow.h"
#include "loginpage.h"
#include "ui_statisticswindow.h"
#include "gameplaywindow.h"
#include "qlabel.h"
#include "userprofile.h"

statisticsWindow::statisticsWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::statisticsWindow),
    userprofile(nullptr),
    wins(0),
    losses(0),
    ties(0)
{
    ui->setupUi(this);
    Initialize();
    loadStatistics();

    // Display the statistics
    ui->winsLabel->setText(QString::number(wins));
    ui->lossesLabel->setText(QString::number(losses));
    ui->tiesLabel->setText(QString::number(ties));

    // Connect the back button
    connect(ui->backButton, &QPushButton::clicked, this, &statisticsWindow::onBackButtonClicked);
}

statisticsWindow::~statisticsWindow()
{
    delete ui;
}

void statisticsWindow::Initialize()
{
    setWindowTitle("Game Statistics");

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
        "   font-size: 40px;"
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "   min-width: 100px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    ui->backButton->setStyleSheet(roundedButtonStyle
                                       .arg("#4acdd5")
                                       .arg("#2192a2")
                                       .arg("#798596"));
    // Bring all interactive elements to front
    ui->winsLabel->raise();
    ui->lossesLabel->raise();
    ui->tiesLabel->raise();
    ui->backButton->raise();
}

void statisticsWindow::loadStatistics()
{
    QSqlQuery query;
    query.prepare("SELECT wins, losses, ties FROM game_history WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Error retrieving statistics:" << query.lastError();
        return;
    }

    if (query.next()) {
        wins = query.value(0).toInt();
        losses = query.value(1).toInt();
        ties = query.value(2).toInt();
    } else {
        qDebug() << "No statistics found for username:" << username;
    }
}

void statisticsWindow::onBackButtonClicked()
{
    userprofile = new userProfile;
    userprofile->show();
    this->close();
}
