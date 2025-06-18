#include "gamehistorylist.h"
#include "choosedifficulty.h"
#include "gameplaywindow.h"
#include "loginpage.h"
#include "mainwindow.h"
#include "playerselection.h"
#include "qlabel.h"
#include "qmessagebox.h"
#include "ui_gamehistory.h"
#include "userprofile.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QDateTime>
// gamehistory.cpp
#include "globalvars.h"

gameHistory::gameHistory(QWidget *parent)
    : QWidget(parent), ui(new Ui::gameHistory), isPlayer1View(true)
{
    ui->setupUi(this);
    Initialize();
    fetchGameHistory();

    // Connect signals
    connect(ui->backButton, &QPushButton::clicked, this, &gameHistory::onBackButtonClicked);
    connect(ui->mainMenuButton, &QPushButton::clicked, this, &gameHistory::onMainMenuButtonClicked);
    connect(ui->gameList, &QListWidget::itemClicked, this, &gameHistory::onGameSelected);
    connect(ui->switchPlayerButton, &QPushButton::clicked, this, &gameHistory::onPlayerSwitchClicked);
    connect(ui->newGameButton, &QPushButton::clicked, this, &gameHistory::onNewGameClicked);
}

gameHistory::~gameHistory()
{
    delete ui;
}

void gameHistory::Initialize()
{
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(131, 61, 121));
    gradient.setColorAt(1, QColor(165, 64, 134));

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);

    QString roundedButtonStyle =
        "QPushButton {"
        "   background-color: %1;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   border-radius: 20px;"
        "   min-width: 100px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover { background-color: %2; }"
        "QPushButton:pressed { background-color: %3; }";

    ui->backButton->setStyleSheet(roundedButtonStyle
                                      .arg("#4acdd5")
                                      .arg("#2192a2")
                                      .arg("#798596")
                                  + "font-size: 50px");

    ui->mainMenuButton->setStyleSheet(roundedButtonStyle
                                          .arg("#4acdd5")
                                          .arg("#2192a2")
                                          .arg("#798596")
                                      + "font-size: 50px");

    ui->newGameButton->setStyleSheet(roundedButtonStyle
                                         .arg("#4acdd5")
                                         .arg("#2192a2")
                                         .arg("#798596")
                                     + "font-size: 50px");

    ui->switchPlayerButton->setStyleSheet(roundedButtonStyle
                                              .arg("#4acdd5")
                                              .arg("#2192a2")
                                              .arg("#798596")
                                          + "font-size: 50px");

    ui->gameList->setStyleSheet(
        "QListWidget { background-color: rgba(255, 255, 255, 150); border-radius: 10px; }"
        "QListWidget::item { padding: 10px; border-bottom: 1px solid #ddd; }"
        "QListWidget::item:hover { background-color: rgba(200, 200, 255, 100); }"
        );
}

void gameHistory::fetchGameHistory()
{
    QSqlQuery query;
    query.prepare("SELECT game_data, created_at, result FROM game_history WHERE username = :username ORDER BY id DESC LIMIT 20;");

    QString currentUsername;
    if(GameMode == MULTIPLAYER_MODE && Historyplayer == 0 && Historyback == 1) {
        currentUsername = username1;
    } else if(GameMode == MULTIPLAYER_MODE && Historyplayer == 1 && Historyback == 1) {
        currentUsername = username;
    } else if(first == 1) {
        currentUsername = username1;
    } else if(first == 2) {
        currentUsername = username;
    }

    query.bindValue(":username", currentUsername);

    if (!query.exec()) {
        qDebug() << "Error: failed to execute query - " << query.lastError();
        return;
    }

    ui->gameList->clear();

    while (query.next()) {
        QString gameData = query.value(0).toString();
        QDateTime gameDate = query.value(1).toDateTime();
        QString result = query.value(2).toString();

        QString itemText = gameDate.toString("yyyy-MM-dd hh:mm:ss");
        if (!result.isEmpty()) {
            itemText += " - " + result;
        }

        QListWidgetItem *item = new QListWidgetItem(itemText);
        item->setData(Qt::UserRole, gameData);
        ui->gameList->addItem(item);
    }
}
void gameHistory::refreshGameList()
{
    ui->gameList->clear();  // Clear before repopulating

    QSqlQuery query;
    query.prepare("SELECT game_data, created_at, result FROM game_history "
                  "WHERE username = :username ORDER BY created_at DESC LIMIT 20");

    // Bind username based on current mode
    if(GameMode == MULTIPLAYER_MODE && Historyplayer == 1) {
        query.bindValue(":username", username);  // Player 2
    } else {
        query.bindValue(":username", username1); // Player 1 or single player
    }

    if (!query.exec()) {
        qDebug() << "Refresh failed:" << query.lastError();
        return;
    }

    while (query.next()) {
        QString gameData = query.value(0).toString();
        QDateTime date = query.value(1).toDateTime();
        QString result = query.value(2).toString();

        QString itemText = date.toString("MMM d h:mm AP");
        if (!result.isEmpty()) itemText += " - " + result;

        QListWidgetItem *item = new QListWidgetItem(itemText);
        item->setData(Qt::UserRole, gameData);
        ui->gameList->addItem(item);
    }
}
void gameHistory::onBackButtonClicked()
{
    if(Historyback == 1) {
        gameplayWindow = new GameplayWindow;
        gameplayWindow->show();
    } else {
        userprofile = new userProfile;
        userprofile->show();
    }
    this->close();
}

void gameHistory::onMainMenuButtonClicked()
{
    first = 0;
    mainWindow = new MainWindow;
    mainWindow->show();
    this->close();
}

void gameHistory::onGameSelected(QListWidgetItem *item)
{
    QString gameData = item->data(Qt::UserRole).toString();
    GameReplayWindow *replayWindow = new GameReplayWindow(gameData);
    replayWindow->show();
}

void gameHistory::onPlayerSwitchClicked()
{
    isPlayer1View = !isPlayer1View;
    Historyplayer = isPlayer1View ? 0 : 1;
    fetchGameHistory();
}

void gameHistory::onNewGameClicked()
{
    if(GameMode == SINGLEPLAYER_MODE) {
        choosedifficulty = new chooseDifficulty;
        choosedifficulty->show();
    } else {
        playerSelection = new PlayerSelection;
        playerSelection->show();
    }
    this->close();
}

// GameReplayWindow implementation
GameReplayWindow::GameReplayWindow(const QString& gameData, QWidget *parent)
    : QWidget(parent), currentMoveIndex(0), gameCompleted(false)
{
    setWindowTitle("Game Replay");
    setFixedSize(500, 600);

    // Parse game data
    QStringList moves = gameData.split(';', Qt::SkipEmptyParts);
    for (const QString& move : moves) {
        if (!move.trimmed().isEmpty()) {
            moveHistory.append(move);
        }
    }

    // Set current username
    if(GameMode == MULTIPLAYER_MODE && Historyplayer == 0 && Historyback == 1) {
        currentUsername = username1;
    } else if(GameMode == MULTIPLAYER_MODE && Historyplayer == 1 && Historyback == 1) {
        currentUsername = username;
    } else if(first == 1) {
        currentUsername = username1;
    } else if(first == 2) {
        currentUsername = username;
    }

    // Create UI
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Result label
    resultLabel = new QLabel(this);
    resultLabel->setAlignment(Qt::AlignCenter);
    resultLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    mainLayout->addWidget(resultLabel);

    // Game board
    QWidget *boardWidget = new QWidget(this);
    QGridLayout *boardLayout = new QGridLayout(boardWidget);
    boardLayout->setSpacing(5);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            boardButtons[row][col] = new QPushButton("", boardWidget);
            boardButtons[row][col]->setFixedSize(80, 80);
            boardButtons[row][col]->setStyleSheet(
                "QPushButton {"
                "   font-size: 36px;"
                "   background-color: white;"
                "   border: 2px solid #aaa;"
                "   border-radius: 5px;"
                "}"
                "QPushButton:hover {"
                "   background-color: #f0f0f0;"
                "}"
                );
            boardLayout->addWidget(boardButtons[row][col], row, col);
        }
    }

    mainLayout->addWidget(boardWidget, 0, Qt::AlignCenter);

    // Controls
    QHBoxLayout *controlsLayout = new QHBoxLayout();

    QPushButton *undoButton = new QPushButton("Undo", this);
    undoButton->setFixedSize(100, 40);
    connect(undoButton, &QPushButton::clicked, this, &GameReplayWindow::onUndoClicked);

    QPushButton *redoButton = new QPushButton("Redo", this);
    redoButton->setFixedSize(100, 40);
    connect(redoButton, &QPushButton::clicked, this, &GameReplayWindow::onRedoClicked);

    QPushButton *replayButton = new QPushButton("Replay", this);
    replayButton->setFixedSize(100, 40);
    connect(replayButton, &QPushButton::clicked, this, &GameReplayWindow::onReplayClicked);

    QPushButton *backButton = new QPushButton("Back", this);
    backButton->setFixedSize(100, 40);
    connect(backButton, &QPushButton::clicked, this, &GameReplayWindow::onBackClicked);

    controlsLayout->addWidget(undoButton);
    controlsLayout->addWidget(redoButton);
    controlsLayout->addWidget(replayButton);
    controlsLayout->addWidget(backButton);
    mainLayout->addLayout(controlsLayout);

    // Initialize board
    updateBoard();
}

GameReplayWindow::~GameReplayWindow()
{
}

void GameReplayWindow::updateMoveHistory(const QString& move)
{
    moveHistory.append(move);
    currentMoveIndex = moveHistory.size();
    updateBoard();
}

void GameReplayWindow::onUndoClicked()
{
    if (currentMoveIndex > 0) {
        currentMoveIndex--;
        updateBoard();
    }
}

void GameReplayWindow::onRedoClicked()
{
    if (currentMoveIndex < moveHistory.size()) {
        currentMoveIndex++;
        updateBoard();
    }
}

void GameReplayWindow::onReplayClicked()
{
    currentMoveIndex = 0;
    updateBoard();

    // Animate through all moves
    QTimer::singleShot(500, this, [this]() {
        if (currentMoveIndex < moveHistory.size()) {
            currentMoveIndex++;
            updateBoard();
            QTimer::singleShot(500, this, SLOT(onReplayClicked()));
        }
    });
}

void GameReplayWindow::onBackClicked()
{
    this->close();
}

void GameReplayWindow::updateBoard()
{
    // Clear board
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            boardButtons[row][col]->setText("");
        }
    }

    // Apply moves up to current index
    for (int i = 0; i < currentMoveIndex && i < moveHistory.size(); ++i) {
        QString move = moveHistory[i];
        QStringList parts = move.split(',');
        if (parts.size() == 3) {
            int row = parts[0].toInt();
            int col = parts[1].toInt();
            QString symbol = parts[2];

            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                boardButtons[row][col]->setText(symbol);

                // Highlight the last move
                if (i == currentMoveIndex - 1) {
                    boardButtons[row][col]->setStyleSheet(
                        "QPushButton {"
                        "   font-size: 36px;"
                        "   background-color: #e6f7ff;"
                        "   border: 2px solid #4acdd5;"
                        "   border-radius: 5px;"
                        "}"
                        );
                } else {
                    boardButtons[row][col]->setStyleSheet(
                        "QPushButton {"
                        "   font-size: 36px;"
                        "   background-color: white;"
                        "   border: 2px solid #aaa;"
                        "   border-radius: 5px;"
                        "}"
                        );
                }
            }
        }
    }

    // Update status
    if (currentMoveIndex == moveHistory.size()) {
        resultLabel->setText("Game completed");
        gameCompleted = true;
    } else {
        resultLabel->setText(QString("Move %1 of %2").arg(currentMoveIndex).arg(moveHistory.size()));
        gameCompleted = false;
    }
}

void GameReplayWindow::saveGameToHistory()
{
    if (!gameCompleted || currentUsername.isEmpty()) return;

    QString gameData = moveHistory.join(";");

    QSqlQuery query;
    query.prepare("INSERT INTO game_history (username, game_data, created_at) "
                  "VALUES (:username, :game_data, datetime('now'))");
    query.bindValue(":username", currentUsername);
    query.bindValue(":game_data", gameData);

    if (!query.exec()) {
        qDebug() << "Error saving game history:" << query.lastError().text();
    }
}
