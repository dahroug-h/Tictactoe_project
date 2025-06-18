#ifndef CHOOSEDIFFICULTY_H
#define CHOOSEDIFFICULTY_H

#include <QWidget>
#include "playerselection.h"

namespace Ui {
class chooseDifficulty;
}

class chooseDifficulty : public QWidget
{
    Q_OBJECT

public:
    explicit chooseDifficulty(QWidget *parent = nullptr);
    ~chooseDifficulty();

private slots:
    void on_easyButton_clicked();
    void on_mediumButton_clicked();
    void on_hardButton_clicked();

private:
    void InitializeUI();
    Ui::chooseDifficulty *ui;
    PlayerSelection *playerSelection;
};

#endif // CHOOSEDIFFICULTY_H
