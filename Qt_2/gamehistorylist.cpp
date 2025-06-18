#include "gamehistorylist.h"
#include "gamereplayviewer.h"
#include "userprofile.h"

#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QSqlError>
#include <QDebug>

extern QString username; // already used in your existing code

GameHistoryList::GameHistoryList(userProfile* parentProfile, QWidget *parent)
    : QWidget(parent), gameListWidget(new QListWidget(this)), replayViewer(nullptr), parentProfile(parentProfile)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(131, 61, 121));
    gradient.setColorAt(1, QColor(165, 64, 134));

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);

    // Create back button
    backButton = new QPushButton("Back to Profile", this);
    backButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #ff9a48;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 16px;"
        "   border-radius: 10px;"
        "}"
        "QPushButton:hover { background-color: #de6a25; }"
        "QPushButton:pressed { background-color: #b71c1c; }"
        );

    // Add widgets to layout
    mainLayout->addWidget(backButton);
    mainLayout->addWidget(gameListWidget);
    setLayout(mainLayout);

    resize(400, 600);
    setWindowTitle("Game History");

    connect(gameListWidget, &QListWidget::itemClicked, this, &GameHistoryList::onGameClicked);
    connect(backButton, &QPushButton::clicked, this, &GameHistoryList::onBackButtonClicked);

    loadGameHistory();
}

GameHistoryList::~GameHistoryList() {}

void GameHistoryList::loadGameHistory()
{
    QSqlQuery query;
    query.prepare("SELECT id, game_data FROM game_history WHERE username = :username ORDER BY id DESC;");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Failed to fetch history:" << query.lastError();
        return;
    }

    while (query.next()) {
        QString gameData = query.value("game_data").toString();
        int id = query.value("id").toInt();
        QString title = QString("Game #%1").arg(id);

        QListWidgetItem* item = new QListWidgetItem(title, gameListWidget);
        gameDataMap[item] = gameData;
    }
}

void GameHistoryList::onGameClicked(QListWidgetItem* item)
{
    if (!gameDataMap.contains(item)) return;

    QString gameData = gameDataMap[item];

    if (replayViewer)
        delete replayViewer;

    replayViewer = new GameReplayViewer(gameData);
    replayViewer->show();
}

void GameHistoryList::onBackButtonClicked()
{
    if (parentProfile) {
        parentProfile->show();
    }
    this->close();
}
