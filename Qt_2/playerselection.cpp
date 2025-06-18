#include "playerselection.h"
#include "ui_playerselection.h"
#include "App.h"

unsigned char Choice1 = 0, Choice2 = 0, playerstarted = 1;

PlayerSelection::PlayerSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerSelection),
    gameplayWindow(nullptr)
{
    ui->setupUi(this);
    InitializeUI();
    if (GameMode ==  SINGLEPLAYER_MODE)
    {
        ui->player1SelectO->hide();
        ui->player1SelectX->hide();
        ui->player2SelectO->hide();
        ui->player2SelectX->hide();
        ui->player2Label->hide();
        ui->player1Starts->hide();
        ui->player2Starts->hide();
        ui->spSelectO->show();
        ui->spSelectX->show();
        ui->spStartGame->show();
    }
    else
    {
        ui->player1SelectO->show();
        ui->player1SelectX->show();
        ui->player2SelectO->show();
        ui->player2SelectX->show();
        ui->player2Label->show();
        ui->player1Starts->show();
        ui->player2Starts->show();
        ui->spSelectO->hide();
        ui->spSelectX->hide();
        ui->spStartGame->hide();
    }

    ui->player1Label->setAlignment(Qt::AlignCenter);
    ui->player2Label->setAlignment(Qt::AlignCenter);
    ui->player1Label->setText(username1 + " Selection:");
    ui->player2Label->setText(username + " Selection:");

    if (GameMode == SINGLEPLAYER_MODE) {
        setupSingleplayerUI();
    } else {
        setupMultiplayerUI();
    }
}

void PlayerSelection::InitializeUI()
{
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(131, 61, 121));    // Dark blue-gray
    gradient.setColorAt(1, QColor(165, 64, 134));    // Darker blue-gray

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);

}

void PlayerSelection::setupMultiplayerUI()
{
    ui->multiplayerWidget->show();
    ui->singleplayerWidget->hide();
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
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "   min-width: 100px;"
        "   min-height: 40px;"
        "   font-size: %4;"  // Add font-size as a parameter
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    ui->player1SelectO->setStyleSheet(roundedButtonStyle
                                       .arg("#4acdd5")
                                       .arg("#2192a2")
                                       .arg("#798596")
                                      .arg("60px"));
    ui->player1SelectX->setStyleSheet(roundedButtonStyle
                                      .arg("#ff9a48")  // Normal color (red)
                                      .arg("#de6a25")  // Hover color
                                      .arg("#b71c1c")
                                     .arg("60px"));  // Pressed color
    ui->player2SelectO->setStyleSheet(roundedButtonStyle
                                          .arg("#4acdd5")
                                          .arg("#2192a2")
                                          .arg("#798596")
                                      .arg("60px"));
    ui->player2SelectX->setStyleSheet(roundedButtonStyle
                                          .arg("#ff9a48")  // Normal color (red)
                                          .arg("#de6a25")  // Hover color
                                          .arg("#b71c1c")
                                      .arg("60px"));  // Pressed color
    ui->player1Starts->setStyleSheet(roundedButtonStyle
                                         .arg("#434173")  // Normal color (red)
                                         .arg("#2192a2")  // Hover color
                                         .arg("#798596")
                                     .arg("30px"));  // Pressed color
    ui->player2Starts->setStyleSheet(roundedButtonStyle
                                          .arg("#434173")  // Normal color (red)
                                          .arg("#2192a2")  // Hover color
                                          .arg("#798596")
                                     .arg("30px"));  // Pressed color
}

void PlayerSelection::setupSingleplayerUI()
{
    ui->multiplayerWidget->hide();
    ui->singleplayerWidget->show();
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
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "   min-width: 100px;"
        "   min-height: 40px;"
        "   font-size: %4;"  // Add font-size as a parameter
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    ui->spSelectO->setStyleSheet(roundedButtonStyle
                                          .arg("#4acdd5")
                                          .arg("#2192a2")
                                          .arg("#798596")
                                 .arg("60px"));
    ui->spSelectX->setStyleSheet(roundedButtonStyle
                                          .arg("#ff9a48")  // Normal color (red)
                                          .arg("#de6a25")  // Hover color
                                          .arg("#b71c1c")
                                 .arg("60px"));  // Pressed color
    ui->spStartGame->setStyleSheet(roundedButtonStyle
                                         .arg("#434173")  // Normal color (red)
                                         .arg("#2192a2")  // Hover color
                                         .arg("#798596")
                                   .arg("30px"));  // Pressed color

}

// Multiplayer slots
void PlayerSelection::on_player1SelectX_clicked() { Choice1 = 'X'; }
void PlayerSelection::on_player1SelectO_clicked() { Choice1 = 'O'; }
void PlayerSelection::on_player2SelectX_clicked() { Choice2 = 'X'; }
void PlayerSelection::on_player2SelectO_clicked() { Choice2 = 'O'; }

void PlayerSelection::on_player1Starts_clicked()
{
    if(Choice1 == 'X' || Choice1 == 'O')
    {
        StartPLayer = Choice1;
        playerstarted = 1;
        Player1 = Choice1;
        Player2 = (Choice1 == PLAYER_X) ? 'O' : 'X';
        gameplayWindow = new GameplayWindow;
        gameplayWindow->show();
        this->close();
    }
    Choice2 = 0;
    Choice1 = 0;
}

void PlayerSelection::on_player2Starts_clicked()
{
    if(Choice2 == 'X' || Choice2 == 'O')
    {
        StartPLayer = Choice2;
        playerstarted = 2;
        Player2 = Choice2;
        Player1 = (Choice2 == PLAYER_X) ? 'O' : 'X';
        gameplayWindow = new GameplayWindow;
        gameplayWindow->show();
        this->close();
    }
    Choice2 = 0;
    Choice1 = 0;
}

// Singleplayer slots
void PlayerSelection::on_spSelectX_clicked() { Choice1 = 'X'; }
void PlayerSelection::on_spSelectO_clicked() { Choice1 = 'O'; }

void PlayerSelection::on_spStartGame_clicked()
{
    if(Choice1 == 'X' || Choice1 == 'O')
    {
        StartPLayer = Choice1;
        Player1 = Choice1;
        Player2 = (Choice1 == PLAYER_X) ? 'O' : 'X';
        gameplayWindow = new GameplayWindow;
        gameplayWindow->show();
        this->close();
    }
    Choice1 = 0;
}

void PlayerSelection::changeButtonStyle(const QString &styleName)
{
    // Implement your style changing logic here
    if (styleName == "Style 1") {
        ui->player1SelectX->setStyleSheet(style1);
        ui->player1SelectO->setStyleSheet(style1);
    } else if (styleName == "Style 2") {
        ui->player1SelectX->setStyleSheet(style2);
        ui->player1SelectO->setStyleSheet(style2);
    }
}

PlayerSelection::~PlayerSelection()
{
    delete ui;
}
