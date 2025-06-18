#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>

class userProfile;

namespace Ui {
class statisticsWindow;
}

class statisticsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit statisticsWindow(QWidget *parent = nullptr);
    ~statisticsWindow();

    void Initialize();  // For custom background and initial setup
    void loadStatistics();  // Renamed from statisticsWindowShow for clarity

private slots:
    void onBackButtonClicked();  // Renamed from on_pushButton_clicked

private:
    Ui::statisticsWindow *ui;
    userProfile *userprofile;

    // Moved these to be class members instead of globals
    int wins;
    int losses;
    int ties;
};

#endif // STATISTICSWINDOW_H
