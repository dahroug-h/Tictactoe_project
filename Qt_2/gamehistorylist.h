#ifndef GAMEHISTORYLIST_H
#define GAMEHISTORYLIST_H

#include <QWidget>
#include <QListWidget>
#include <QSqlQuery>
#include <QMap>
#include <QPushButton>

class GameReplayViewer;
class userProfile;

class GameHistoryList : public QWidget
{
    Q_OBJECT

public:
    explicit GameHistoryList(userProfile* parentProfile = nullptr, QWidget *parent = nullptr);
    ~GameHistoryList();

private slots:
    void onGameClicked(QListWidgetItem* item);
    void onBackButtonClicked();

private:
    void loadGameHistory();
    QListWidget* gameListWidget;
    QPushButton* backButton;  // Add back button
    QMap<QListWidgetItem*, QString> gameDataMap;
    GameReplayViewer* replayViewer;
    userProfile* parentProfile;  // Reference to parent userProfile
};

#endif // GAMEHISTORYLIST_H
