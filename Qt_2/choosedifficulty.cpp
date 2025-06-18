#include "choosedifficulty.h"
#include "ui_choosedifficulty.h"

chooseDifficulty::chooseDifficulty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseDifficulty),
    playerSelection(nullptr)
{
    ui->setupUi(this);
    InitializeUI();
}

void chooseDifficulty::InitializeUI()
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
        "   font-size: 40px;"
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "   min-width: 100px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    ui->easyButton->setStyleSheet(roundedButtonStyle
                                     .arg("#4acdd5")
                                     .arg("#2192a2")
                                     .arg("#798596"));
    ui->hardButton->setStyleSheet(roundedButtonStyle
                                     .arg("#ff9a48")  // Normal color (red)
                                     .arg("#de6a25")  // Hover color
                                     .arg("#b71c1c"));  // Pressed color
    ui->mediumButton->setStyleSheet(roundedButtonStyle
                                         .arg("#434173")  // Normal color (red)
                                         .arg("#2192a2")  // Hover color
                                         .arg("#798596"));  // Pressed

}

void chooseDifficulty::on_easyButton_clicked()
{
    difficulty = EASY;
    playerSelection = new PlayerSelection;
    playerSelection->show();
    this->hide();
}

void chooseDifficulty::on_mediumButton_clicked()
{
    difficulty = MEDIUM;
    playerSelection = new PlayerSelection;
    playerSelection->show();
    this->hide();
}

void chooseDifficulty::on_hardButton_clicked()
{
    difficulty = HARD;
    playerSelection = new PlayerSelection;
    playerSelection->show();
    this->hide();
}

chooseDifficulty::~chooseDifficulty()
{
    delete ui;
}
