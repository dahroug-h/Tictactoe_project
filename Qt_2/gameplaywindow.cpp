#include "gameplaywindow.h"
#include "choosedifficulty.h"
#include "gamehistorylist.h"
#include "loginpage.h"
#include "playerselection.h"
#include "qlabel.h"
#include "qmessagebox.h"
#include "ui_gameplaywindow.h"
#include"mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QFont>
#include <QList>
#include <QThread>
#include<QSqlQuery>
#include<QSqlError>
// gameplaywindow.cpp
#include "globalvars.h"  // Add this at top
unsigned char StartPLayer;
unsigned char currentPlayer;
unsigned char Player1;
unsigned char Player2;
unsigned char GameState = GAME_RUNNING;
unsigned char replay[7][9] ={{10}};
unsigned char replayindex[6]={0};
unsigned char Player1State[7]={0};
unsigned char Player2State[7]={0};
unsigned char numberofplays[6]={0};
unsigned char playindex = 0;
unsigned char trig=-1;
QPushButton *buttons[3][3];
QString buttons_history1[6][3][3];
QString gameData;
int count_times=0;

GameplayWindow::GameplayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameplayWindow)
{
    ui->setupUi(this);
    Initialize();
    game.setCurrentPlayer();
    // QGridLayout *gridLayout = new QGridLayout(this);
    currentPlayer = game.getCurrentPlayer();
    if(currentPlayer == Player1)
    {
        ui->label->setText(username1 + " Selection:");
        if (currentPlayer=='O')
        {
            ui->label_2->setText( " O ");
        }
        else
        {
            ui->label_2->setText( " X ");
        }
    }
    else if(currentPlayer == Player2)
    {
        ui->label->setText(username + " Selection:");
        if (currentPlayer=='O')
        {
            ui->label_2->setText( " X ");
        }
        else
        {
            ui->label_2->setText( " O ");
        }
    }

    for(int row = 0; row < 3; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
            //  QString buttonName = QString("button%1%2").arg(row).arg(col);
            //  buttons[row][col] = window()->findChild<QPushButton*>(buttonName);
            buttons[row][col] = new QPushButton("", this);
            buttons[row][col]->setFixedSize(100, 100);  // Set a fixed size for buttons
            buttons[row][col]->setStyleSheet("background-color: rgba(255, 255, 255, 0);");  // Set button colors

            QFont font = buttons[row][col]->font();
            font.setPointSize(30);  // Adjust the font size as needed
            buttons[row][col]->setFont(font);
            buttons[row][col]->setGeometry(120*(row+1)-37, 120*(col+1)+55, 100, 30); // (x, y, width, height)
            connect(buttons[row][col], &QPushButton::clicked, [=]()
                    {
                        onButtonClick(row, col);
                    });
        }
    }

    // setLayout(gridLayout);

}

void GameplayWindow::Initialize()
{

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
        "   font-size: 20px;"
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    ui->pushButton->setStyleSheet(roundedButtonStyle
                                      .arg("#4acdd5")
                                      .arg("#2192a2")
                                      .arg("#798596"));
    ui->pushButton_2->setStyleSheet(roundedButtonStyle
                                        .arg("#4acdd5")
                                        .arg("#2192a2")
                                        .arg("#798596"));
    ui->pushButton_3->setStyleSheet(roundedButtonStyle
                                        .arg("#4acdd5")
                                        .arg("#2192a2")
                                        .arg("#798596"));
    ui->pushButton_4->setStyleSheet(roundedButtonStyle
                                        .arg("#4acdd5")
                                        .arg("#2192a2")
                                        .arg("#798596"));
    ui->pushButton_5->setStyleSheet(roundedButtonStyle
                                        .arg("#ff9a48")  // Normal color (red)
                                        .arg("#de6a25")  // Hover color
                                        .arg("#b71c1c"));  // Pressed color
    ui->pushButton_6->setStyleSheet(roundedButtonStyle
                                        .arg("#4acdd5")  // Normal color (red)
                                        .arg("#2192a2")  // Hover color
                                        .arg("#798596"));  // Pressed
    ui->pushButton_7->setStyleSheet(roundedButtonStyle
                                        .arg("#4acdd5")  // Normal color (red)
                                        .arg("#2192a2")  // Hover color
                                        .arg("#798596"));  // Pressed
    ui->pushButton_9->setStyleSheet(roundedButtonStyle
                                        .arg("#4acdd5")  // Normal color (red)
                                        .arg("#2192a2")  // Hover color
                                        .arg("#798596"));  // Pressed
    ui->pushButton_10->setStyleSheet(roundedButtonStyle
                                         .arg("#4acdd5")  // Normal color (red)
                                         .arg("#2192a2")  // Hover color
                                         .arg("#798596"));  // Pressed

}

void GameplayWindow::onButtonClick(int row, int col)
{
    // Check if the button is already marked
    if((buttons[row][col]->text() != "") || (GameState == GAME_ENDED))
        return;

    currentPlayer = game.getCurrentPlayer();
    QChar mark;
    if (GameMode == MULTIPLAYER_MODE)
    {
        if (playerstarted == 1)
        {
            mark = (currentPlayer == PLAYER_X) ? 'X' : 'O';
        }
        else if (playerstarted == 2)
        {
            mark = (currentPlayer == PLAYER_X) ? 'O' : 'X';
        }
    }
    else
    {
        mark = (currentPlayer == PLAYER_X) ? 'X' : 'O';
    }
    QString winnerMessage;
    // Set the button text to X or O
    buttons[row][col]->setText(QString(mark));

    // Make human move in game logic
    game.humanMove(game.board, currentPlayer, row, col);
    switch(row)
    {
    case 0:
        replay[0][playindex++] = col;
        break;
    case 1:
        replay[0][playindex++] = col+3;
        break;
    case 2:
        replay[0][playindex++] = col+6;
        break;
    }

    // Check for win or draw
    if(game.isWinner(game.board, currentPlayer))
    {
        GameState = GAME_ENDED;
        // Handle win condition
        if(currentPlayer == Player1)
        {
            trig=1;
            setStats();
            winnerMessage =  QString(username1) + " wins!";
        }else
        {
            trig=0;
            setStats();
            winnerMessage =  QString(username) + " wins!";
        }
        QMessageBox::information(this,"Success",winnerMessage);
        setHistory();
    }
    else if(game.isBoardFull(game.board))
    {
        trig=2;
        setStats();
        // Handle draw condition
        QMessageBox::information(this,"Success"," It's a draw ");
        setHistory();
            // Additional logic for end of game
    }
    else if (GameMode == SINGLEPLAYER_MODE)
    {
        // Computer's move (if applicable)
        game.computerMove((currentPlayer == PLAYER_X) ? 'O' : 'X');

        // Update UI with computer's move
        Move computerMove = game.currentMove;
        QChar computerMark = (currentPlayer == PLAYER_X) ? 'O' : 'X';
        buttons[computerMove.row][computerMove.col]->setText(QString(computerMark));
        switch(computerMove.row)
        {
        case 0:
            replay[0][playindex++] = computerMove.col;
            break;
        case 1:
            replay[0][playindex++] = computerMove.col+3;
            break;
        case 2:
            replay[0][playindex++] = computerMove.col+6;
            break;
        }
        // Check for win or draw after computer's move
        if(game.isWinner(game.board, Player2))
        {
            // Handle win condition
            QString winnerMessage = "Computer wins!";
            QMessageBox::information(this,"Success",winnerMessage);
            trig=0;
            setStats();
            setHistory();
            qDebug(" Computer wins ");
            GameState = GAME_ENDED;
            // Additional logic for end of game
        }
        else if(game.isBoardFull(game.board))
        {
            ;
            // Handle draw condition
            QMessageBox::information(this,"Success"," It's a draw ");
            trig=2;
            setStats();
            setHistory();
            // Additional logic for end of game
        }
    }
    currentPlayer = game.getCurrentPlayer();
    if(currentPlayer == Player1 && (GameState != GAME_ENDED))
    {
        ui->label->setText(username1 + " Selection:");
    }
    else if(currentPlayer == Player2 &&(GameState != GAME_ENDED))
    {
        ui->label->setText(username + " Selection:");
    }
    if (GameMode == MULTIPLAYER_MODE && (GameState != GAME_ENDED))
    {
        if (mark=='O')
        {
            ui->label_2->setText( " X ");
        }
        else
        {
            ui->label_2->setText( " O ");
        }
    }
}

//void GameplayWindow::qDebug(const QString &message)
//{
//  CustomDialog dialog(this);
//dialog.setMessage(message);
//dialog.exec();
//}


GameplayWindow::~GameplayWindow()
{
    delete ui;
}

void GameplayWindow::on_pushButton_clicked()
{
    for(int row = 0; row < 3; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
            buttons[row][col]->setText("");
        }
    }
    game.clearBoard(game.board);
    first = 0;
    game.setCurrentPlayer();
    GameState = GAME_RUNNING;
    mainWindow=new MainWindow;
    mainWindow->show();
    this->hide();
}


void GameplayWindow::on_pushButton_2_clicked()
{
    for(int row = 0; row < 3; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
            buttons[row][col]->setText("");
        }
    }
    game.clearBoard(game.board);
    game.setCurrentPlayer();
    GameState = GAME_RUNNING;
    currentPlayer = game.getCurrentPlayer();
    if(currentPlayer == Player1)
    {
        ui->label->setText(username1 + " Selection:");
        if (currentPlayer=='O')
        {
            ui->label_2->setText( " O ");
        }
        else
        {
            ui->label_2->setText( " X ");
        }
    }
    else if(currentPlayer == Player2)
    {
        ui->label->setText(username + " Selection:");
        if (currentPlayer=='O')
        {
            ui->label_2->setText( " X ");
        }
        else
        {
            ui->label_2->setText( " O ");
        }
    }
}


void GameplayWindow::on_pushButton_4_clicked()
{
    GameplayWindow::ClearBoard();
    gameModeWindow=new GameModeWindow;
    gameModeWindow->show();
    this->hide();
}


void GameplayWindow::on_pushButton_3_clicked()
{
    GameplayWindow::ClearBoard();
    for(int j=5;j>=0;j--)
    {
        replayindex[j]=numberofplays[j];
    }
    Historyback=1;
    GameHistoryList* historyList = new GameHistoryList;
    historyList->show();


    this->hide();
}
void GameplayWindow::setHistory()
{
    QString Switch ;
    unsigned char swap;
    swap = numberofplays[5];
    numberofplays[5]=numberofplays[3];
    numberofplays[3] =swap;
    swap =Player1State[4];
    Player1State[4]=Player1State[6];
    Player1State[6]=swap;
    swap =Player2State[4];
    Player2State[4]=Player2State[6];
    Player2State[6]=swap;
    for(int i =6;i>0;i--)
    {
        Player1State[i]=Player1State[i-1];
        Player2State[i]=Player2State[i-1];
    }
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            Switch = buttons_history1[3][row][col];
            buttons_history1[3][row][col] = buttons_history1[5][row][col] ;
            buttons_history1[5][row][col] = Switch;
        }
    }
    for(int i=0;i<9;i++)
    {
        swap = replay[4][i];
        replay[4][i]=replay[6][i];
        replay[6][i]=swap;
    }
    for(int index=5;index>0;index--)
    {
        for(int row=0;row<3;row++)
        {
            for(int col=0;col<3;col++)
            {
                buttons_history1[index][row][col] =buttons_history1[index-1][row][col];
            }
        }
    }
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            buttons_history1[0][row][col] =buttons[row][col]->text();
        }
    }
    gameData.clear();  // Clear any leftover content
    for (int i = 0; i < playindex; ++i) {
        int pos = replay[0][i];  // Linear 0–8
        int row = pos / 3;
        int col = pos % 3;
        QString symbol = buttons[row][col]->text();
        if (!symbol.isEmpty()) {
            gameData.append(QString("%1,%2,%3").arg(row).arg(col).arg(symbol));
            if (i < playindex - 1)
                gameData.append(";");
        }
    }

    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            Switch = buttons_history1[3][row][col];
            buttons_history1[3][row][col] = buttons_history1[5][row][col] ;
            buttons_history1[5][row][col] = Switch;
        }
    }
    for(int j=5;j>0;j--)
    {
        for(int i=0;i<9;i++)
        {
            replay[j][i]= replay[j-1][i];
        }
        numberofplays[j]=numberofplays[j-1];

    }
    QString replayData;
    for (int i = 0; i < 9; ++i) {
        replayData.append(QString::number(replay[0][i]));
        if (i < 8) {
            replayData.append(",");
        }
    }
    for(int i=0;i<9;i++)
    {
        swap = replay[4][i];
        replay[4][i]=replay[6][i];
        replay[6][i]=swap;
    }
    numberofplays[0]=playindex;
    playindex=0;
    swap = numberofplays[5];
    numberofplays[5]=numberofplays[3];
    numberofplays[3] =swap;
    swap =Player1State[4];
    Player1State[4]=Player1State[6];
    Player1State[6]=swap;
    swap =Player2State[4];
    Player2State[4]=Player2State[6];
    Player2State[6]=swap;
    storeGameHistory(username1, gameData,replayData);
    if(GameMode==MULTIPLAYER_MODE)
        storeGameHistory(username, gameData,replayData);
    gameData=0;
    replayData=0;
}

void GameplayWindow::ClearBoard()
{
    for(int row = 0; row < 3; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
            buttons[row][col]->setText("");
        }
    }
    game.clearBoard(game.board);
    game.setCurrentPlayer();
    GameState = GAME_RUNNING;
}
void GameplayWindow::storeGameHistory(const QString& username1, const QString& gameData, const QString& replayData)
{
    QSqlQuery query;
    query.prepare("INSERT INTO game_history (username, game_data, replay) VALUES (:username, :game_data, :replay)");
    query.bindValue(":username", username1);
    query.bindValue(":game_data", gameData);
    query.bindValue(":replay", replayData);

    if (!query.exec()) {
        qDebug() << "Error: failed to insert data - " << query.lastError();
    } else {
        qDebug() << "Game history stored successfully for username: " << username1;
    }
}


void GameplayWindow::on_pushButton_5_clicked()
{
    for(int row = 0; row < 3; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
            buttons[row][col]->setText("");
        }
    }
    game.clearBoard(game.board);
    game.setCurrentPlayer();
    GameState = GAME_RUNNING;
    if(GameMode==SINGLEPLAYER_MODE)
    {
        choosedifficulty=new chooseDifficulty;
        choosedifficulty->show();
    }
    else
    {
        playerSelection=new PlayerSelection;
        playerSelection->show();
    }
    this->hide();
}

void GameplayWindow::setStats()
{
    QSqlQuery query;

    if (trig == 0) // Player lost
    {
        int temp_losses = 0;
        Player1State[0]=3;
        query.prepare("SELECT losses FROM game_history WHERE username = :username;");
        query.bindValue(":username", username1);
        if (!query.exec()) {
            qDebug() << "Error: failed to execute query - " << query.lastError();
            return;
        }
        if (query.next())
            temp_losses = query.value(0).toInt();
        temp_losses++;
        query.prepare("UPDATE game_history SET losses = :losses WHERE username = :username");
        query.bindValue(":losses", temp_losses);
        query.bindValue(":username", username1);

        if (!query.exec()) {
            qDebug() << "Error updating record:" << query.lastError();
        } else {
            qDebug() << "Record updated successfully";
        }

        if (GameMode == MULTIPLAYER_MODE)
        {
            int temp_wins = 0;
            Player2State[0]=1;
            query.prepare("SELECT wins FROM game_history WHERE username = :username1;");
            query.bindValue(":username1", username);
            if (!query.exec()) {
                qDebug() << "Error: failed to execute query - " << query.lastError();
                return;
            }
            if (query.next())
                temp_wins = query.value(0).toInt();
            temp_wins++;
            query.prepare("UPDATE game_history SET wins = :wins WHERE username = :username1");
            query.bindValue(":wins", temp_wins);
            query.bindValue(":username1", username);

            if (!query.exec()) {
                qDebug() << "Error updating record:" << query.lastError();
            } else {
                qDebug() << "Record updated successfully";
            }
        }
    }
    else if (trig == 1) // Player won
    {
        int temp_wins = 0;
        Player1State[0]=1;
        query.prepare("SELECT wins FROM game_history WHERE username = :username;");
        query.bindValue(":username", username1);
        if (!query.exec()) {
            qDebug() << "Error: failed to execute query - " << query.lastError();
            return;
        }
        if (query.next())
            temp_wins = query.value(0).toInt();
        temp_wins++;
        query.prepare("UPDATE game_history SET wins = :wins WHERE username = :username");
        query.bindValue(":wins", temp_wins);
        query.bindValue(":username", username1);

        if (!query.exec()) {
            qDebug() << "Error updating record:" << query.lastError();
        } else {
            qDebug() << "Record updated successfully";
        }

        if (GameMode == MULTIPLAYER_MODE)
        {
            int temp_losses = 0;
            Player2State[0]=3;
            query.prepare("SELECT losses FROM game_history WHERE username = :username1;");
            query.bindValue(":username1", username);
            if (!query.exec()) {
                qDebug() << "Error: failed to execute query - " << query.lastError();
                return;
            }
            if (query.next())
                temp_losses = query.value(0).toInt();
            temp_losses++;
            query.prepare("UPDATE game_history SET losses = :losses WHERE username = :username1");
            query.bindValue(":losses", temp_losses);
            query.bindValue(":username1", username);

            if (!query.exec()) {
                qDebug() << "Error updating record:" << query.lastError();
            } else {
                qDebug() << "Record updated successfully";
            }
        }
    }
    else if (trig == 2) // Tie
    {
        int temp_ties = 0;
        Player1State[0]=2;
        query.prepare("SELECT ties FROM game_history WHERE username = :username;");
        query.bindValue(":username", username1);
        if (!query.exec()) {
            qDebug() << "Error: failed to execute query - " << query.lastError();
            return;
        }
        if (query.next())
            temp_ties = query.value(0).toInt();
        temp_ties++;
        query.prepare("UPDATE game_history SET ties = :ties WHERE username = :username");
        query.bindValue(":ties", temp_ties);
        query.bindValue(":username", username1);

        if (!query.exec()) {
            qDebug() << "Error updating record:" << query.lastError();
        } else {
            qDebug() << "Record updated successfully";
        }

        if (GameMode == MULTIPLAYER_MODE)
        {
            int temp_ties2 = 0;
            Player2State[0]=2;
            query.prepare("SELECT ties FROM game_history WHERE username = :username1;");
            query.bindValue(":username1", username);
            if (!query.exec()) {
                qDebug() << "Error: failed to execute query - " << query.lastError();
                return;
            }
            if (query.next())
                temp_ties2 = query.value(0).toInt();
            temp_ties2++;
            query.prepare("UPDATE game_history SET ties = :ties WHERE username = :username1");
            query.bindValue(":ties", temp_ties2);
            query.bindValue(":username1", username);

            if (!query.exec()) {
                qDebug() << "Error updating record:" << query.lastError();
            } else {
                qDebug() << "Record updated successfully";
            }
        }
    }

    trig = -1; // Reset trig after updating statistics
}
