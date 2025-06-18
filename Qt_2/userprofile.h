#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QWidget>
#include <QCryptographicHash>

class gameHistory;
class MainWindow;
class GameModeWindow;
class PlayerSelection;
class statisticsWindow;

namespace Ui {
class userProfile;
}

class userProfile : public QWidget
{
    Q_OBJECT

public:
    explicit userProfile(QWidget *parent = nullptr);
    ~userProfile();
    void Initialize();  // Maintain this for custom background setup

private slots:
    void onPlayButtonClicked();       // Previously pushButton
    void onLogoutButtonClicked();     // Previously pushButton_2
    void onHistoryButtonClicked();    // Previously pushButton_4
    void onStatsButtonClicked();      // Previously pushButton_3

private:
    Ui::userProfile *ui;
    GameModeWindow *GamemodeWindow;
    MainWindow *mainWindow;
    gameHistory *gamehistory;
    PlayerSelection *playerSelection;
    statisticsWindow *statisticswindow;
};

extern QString password, password1;

#endif // USERPROFILE_H
