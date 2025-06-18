#include "userprofile.h"
#include "gamehistorylist.h"
#include "gamemodewindow.h"
#include "loginpage.h"
#include "mainwindow.h"
#include "playerselection.h"
#include "qlabel.h"
#include "statisticswindow.h"
#include "ui_userprofile.h"
// gameplaywindow.cpp
#include "globalvars.h"

userProfile::userProfile(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::userProfile),
    GamemodeWindow(nullptr),
    mainWindow(nullptr),
    gamehistory(nullptr),
    playerSelection(nullptr),
    statisticswindow(nullptr)
{
    ui->setupUi(this);
    Initialize();

    // Connect the renamed buttons to their slots
    connect(ui->playButton, &QPushButton::clicked, this, &userProfile::onPlayButtonClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &userProfile::onLogoutButtonClicked);
    connect(ui->historyButton, &QPushButton::clicked, this, &userProfile::onHistoryButtonClicked);
    connect(ui->statsButton, &QPushButton::clicked, this, &userProfile::onStatsButtonClicked);
}

userProfile::~userProfile()
{
    delete ui;
}

void userProfile::Initialize()
{ setWindowTitle("Sign Up");

    // Gradient background
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(131, 61, 121));
    gradient.setColorAt(1, QColor(165, 64, 134));

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);

    // Button styling template
    QString buttonStyle =
        "QPushButton {"
        "   background-color: %1;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 16px;"
        "   border-radius: 10px;"
        "   min-width: 100px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover { background-color: %2; }"
        "QPushButton:pressed { background-color: %3; }";
    ui->historyButton->setStyleSheet(buttonStyle
                                         .arg("#4acdd5")
                                         .arg("#2192a2")
                                         .arg("#798596")
                                     + "font-size: 30px");
    ui->statsButton->setStyleSheet(buttonStyle
                                       .arg("#4acdd5")
                                       .arg("#2192a2")
                                       .arg("#798596")
                                   + "font-size: 30px");
    // Style back button (orange)
    ui->logoutButton->setStyleSheet(buttonStyle
                                        .arg("#ff9a48")
                                        .arg("#de6a25")
                                        .arg("#b71c1c"));
    // Style back button (orange)
    ui->playButton->setStyleSheet(buttonStyle
                                      .arg("#ff9a48")
                                      .arg("#de6a25")
                                      .arg("#b71c1c"));

    if (first == 1) {
        ui->usernameLabel->setText(username1);
        QByteArray hashedPassword = QCryptographicHash::hash(password1.toUtf8(), QCryptographicHash::Sha256);
        ui->passwordLabel->setText(hashedPassword.toHex());
    }
    else if (first == 2) {
        ui->usernameLabel->setText(username);
        QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
        ui->passwordLabel->setText(hashedPassword.toHex());
    }

    // Bring all interactive elements to front
    ui->playButton->raise();
    ui->logoutButton->raise();
    ui->historyButton->raise();
    ui->statsButton->raise();
    ui->usernameLabel->raise();
    ui->passwordLabel->raise();
}

void userProfile::onPlayButtonClicked()
{
    if (first == 1) {
        GamemodeWindow = new GameModeWindow;
        GamemodeWindow->show();
    } else {
        playerSelection = new PlayerSelection;
        playerSelection->show();
    }
    this->hide();
}

void userProfile::onLogoutButtonClicked()
{
    first = 0;
    mainWindow = new MainWindow;
    mainWindow->show();
    this->hide();
}

void userProfile::onHistoryButtonClicked()
{
    Historyback = 0;
    GameHistoryList* historyList = new GameHistoryList(this);  // Pass 'this' as parentProfile
    historyList->show();
    this->hide();
}

void userProfile::onStatsButtonClicked()
{
    statisticswindow = new statisticsWindow;
    statisticswindow->show();
    this->hide();
}
