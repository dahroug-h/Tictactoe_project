#ifndef GAMEREPLAYVIEWER_H
#define GAMEREPLAYVIEWER_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QStringList>

class GameReplayViewer : public QWidget
{
    Q_OBJECT

public:
    explicit GameReplayViewer(const QString& gameData, QWidget *parent = nullptr);
    ~GameReplayViewer();

private slots:
    void handleUndo();
    void handleRedo();
    void handleBack();

private:
    void initializeUI();
    void loadGame();
    void updateBoard();

    QString gameData;
    QPushButton* boardButtons[3][3];
    QPushButton* undoButton;
    QPushButton* redoButton;
    QPushButton* backButton;

    QVector<QPair<int, int>> moveOrder;
    QVector<QChar> moveSymbols;
    int moveIndex;
};

#endif // GAMEREPLAYVIEWER_H
