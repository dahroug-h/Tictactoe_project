#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamemodewindow.h"
#include "loginpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reopen() { this->show(); }

private slots:
    void on_startButton_clicked();  // Renamed for auto-connect
    void on_exitButton_clicked();   // Renamed for auto-connect

private:
    void Initialize();  // For non-UI initialization

    Ui::MainWindow *ui;
    GameModeWindow *gameModeWindow;
    LoginPage *loginPage;
};

#endif // MAINWINDOW_H
