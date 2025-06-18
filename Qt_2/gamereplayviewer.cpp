#include "gamereplayviewer.h"
#include "gamereplayviewer.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>
#include <QDebug>

GameReplayViewer::GameReplayViewer(const QString& gameData, QWidget *parent)
    : QWidget(parent), gameData(gameData), moveIndex(0)
{
    initializeUI();
    loadGame();
    updateBoard();
}


GameReplayViewer::~GameReplayViewer() {}

void GameReplayViewer::initializeUI()
{    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(131, 61, 121));
    gradient.setColorAt(1, QColor(165, 64, 134));

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* gridLayout = new QGridLayout();
    QHBoxLayout* controls = new QHBoxLayout();
    QHBoxLayout* navigation = new QHBoxLayout();

    QFont buttonFont;
    buttonFont.setPointSize(24);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            boardButtons[row][col] = new QPushButton("");
            boardButtons[row][col]->setFixedSize(80, 80);
            boardButtons[row][col]->setFont(buttonFont);
            boardButtons[row][col]->setEnabled(false); // Disable interaction
            gridLayout->addWidget(boardButtons[row][col], row, col);
        }
    }

    undoButton = new QPushButton("Undo");
    redoButton = new QPushButton("Redo");
    backButton = new QPushButton("Back");

    connect(undoButton, &QPushButton::clicked, this, &GameReplayViewer::handleUndo);
    connect(redoButton, &QPushButton::clicked, this, &GameReplayViewer::handleRedo);
    connect(backButton, &QPushButton::clicked, this, &GameReplayViewer::handleBack);

    controls->addWidget(undoButton);
    controls->addWidget(redoButton);

    navigation->addWidget(backButton);
    navigation->addStretch();

    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(controls);
    mainLayout->addLayout(navigation);

    setLayout(mainLayout);
    resize(320, 400);
    setWindowTitle("Replay Game");
    QString roundedButtonStyle =
        "QPushButton {"
        "   background-color: %1;"  // Color will be inserted
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 20px;"
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    undoButton->setStyleSheet(roundedButtonStyle
                                      .arg("#4acdd5")
                                      .arg("#2192a2")
                                      .arg("#798596"));
    redoButton->setStyleSheet(roundedButtonStyle
                                      .arg("#4acdd5")
                                      .arg("#2192a2")
                                      .arg("#798596"));
    backButton->setStyleSheet(roundedButtonStyle
                                        .arg("#ff9a48")  // Normal color (red)
                                        .arg("#de6a25")  // Hover color
                                        .arg("#b71c1c"));  // Pressed color

}

void GameReplayViewer::loadGame()
{
    QStringList moves = gameData.split(';', Qt::SkipEmptyParts);
    for (const QString& move : moves) {
        QStringList parts = move.split(',');
        if (parts.size() == 3) {
            int row = parts[0].toInt();
            int col = parts[1].toInt();
            QChar symbol = parts[2].trimmed().at(0);

            moveOrder.append(qMakePair(row, col));
            moveSymbols.append(symbol);
        }
    }
}

void GameReplayViewer::updateBoard()
{
    // Clear board
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            boardButtons[row][col]->setText("");

    // Replay up to moveIndex
    for (int i = 0; i < moveIndex; ++i) {
        int row = moveOrder[i].first;
        int col = moveOrder[i].second;
        boardButtons[row][col]->setText(QString(moveSymbols[i]));
    }
}

void GameReplayViewer::handleUndo()
{
    if (moveIndex > 0) {
        moveIndex--;
        updateBoard();
    }
}

void GameReplayViewer::handleRedo()
{
    if (moveIndex < moveOrder.size()) {
        moveIndex++;
        updateBoard();
    }
}

void GameReplayViewer::handleBack()
{
    this->close();
}
