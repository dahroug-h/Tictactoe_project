// gamemodewindow.cpp
#include "gamemodewindow.h"
#include "choosedifficulty.h"
#include "loginpage.h"
#include "playerselection.h"
#include "ui_gamemodewindow.h"

unsigned char GameMode = SINGLEPLAYER_MODE;

GameModeWindow::GameModeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameModeWindow),
    gameplayWindow(nullptr),
    loginPage(nullptr),
    playerSelection(nullptr),
    choosedifficulty(nullptr)
{
    ui->setupUi(this);
    InitializeUI();
}

GameModeWindow::~GameModeWindow()
{
    delete ui;
    if (gameplayWindow) delete gameplayWindow;
    if (loginPage) delete loginPage;
    if (playerSelection) delete playerSelection;
    if (choosedifficulty) delete choosedifficulty;
}

void GameModeWindow::InitializeUI()
{
    // Set window size
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
    ui->singlePlayerButton->setStyleSheet(roundedButtonStyle
                                       .arg("#4acdd5")
                                       .arg("#2192a2")
                                       .arg("#798596"));
    ui->multiPlayerButton->setStyleSheet(roundedButtonStyle
                                      .arg("#ff9a48")  // Normal color (red)
                                      .arg("#de6a25")  // Hover color
                                      .arg("#b71c1c"));  // Pressed color

}

void GameModeWindow::on_singlePlayerButton_clicked()
{
    if (!gameplayWindow) {
        gameplayWindow = new GameplayWindow();
    }
    GameMode = SINGLEPLAYER_MODE;
    choosedifficulty = new chooseDifficulty;
    choosedifficulty->show();
    this->close();
}

void GameModeWindow::on_multiPlayerButton_clicked()
{
    GameMode = MULTIPLAYER_MODE;
    loginPage = new LoginPage();
    loginPage->show();
    this->close();
}
