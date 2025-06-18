#ifndef PLAYERSELECTION_H
#define PLAYERSELECTION_H

#define EASY  0
#define MEDIUM 1
#define HARD 2

#include <QWidget>
#include "gameplaywindow.h"

class GameplayWindow;
namespace Ui {
class PlayerSelection;
}

class PlayerSelection : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerSelection(QWidget *parent = nullptr);
    ~PlayerSelection();

private slots:
    // Multiplayer slots
    void on_player1SelectX_clicked();
    void on_player1SelectO_clicked();
    void on_player2SelectX_clicked();
    void on_player2SelectO_clicked();
    void on_player1Starts_clicked();
    void on_player2Starts_clicked();

    // Singleplayer slots
    void on_spSelectX_clicked();
    void on_spSelectO_clicked();
    void on_spStartGame_clicked();

    void changeButtonStyle(const QString &styleName);

private:
    void InitializeUI();
    void setupMultiplayerUI();
    void setupSingleplayerUI();

    Ui::PlayerSelection *ui;
    GameplayWindow *gameplayWindow;
    QString style1;
    QString style2;
};

extern QString username, username1;
extern unsigned char currentPlayer;
extern unsigned char Player1;
extern unsigned char Player2;
extern unsigned char difficulty;

#endif // PLAYERSELECTION_H
