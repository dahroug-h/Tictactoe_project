#include "loginpage.h"
#include "gamemodewindow.h"
#include"gameplaywindow.h"
#include "playerselection.h"
#include "qlabel.h"
#include "signupform.h"
#include "ui_loginpage.h"
#include "userprofile.h"

QString username,password,username1,password1;
unsigned char first =0;

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    Initialize();
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/ahmed/OneDrive/Desktop/TicTacToe_Game/TicTacToe_Game/Qt_2/TicTacToe.db");
    mydb.open();
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_2_clicked()
{
    signupForm=new SignupForm;
    signupForm->show();
    this->close();
}
void LoginPage::Initialize()
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
        "   border-radius: 20px;"  // Adjust this value for more/less rounding
        "   min-width: 100px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover { background-color: %2; }"  // Darker color
        "QPushButton:pressed { background-color: %3; }";  // Even darker
    ui->pushButton->setStyleSheet(roundedButtonStyle
                                       .arg("#4acdd5")
                                       .arg("#2192a2")
                                       .arg("#798596")
                                       + "font-size: 50px");
    ui->pushButton_2->setStyleSheet(roundedButtonStyle
                                      .arg("#ff9a48")  // Normal color (red)
                                      .arg("#de6a25")  // Hover color
                                      .arg("#b71c1c")
                                    + "font-size: 15px");  // Pressed color
}

void LoginPage::on_pushButton_clicked()
{
    username=ui->lineEdit->text();
    password = ui->lineEdit_pass->text().trimmed();

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QSqlQuery qry;
    qry.prepare("SELECT * FROM Players WHERE username = :username AND password = :password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", hashedPassword.toHex());
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            QMessageBox::information(this, "Success", "SignIn successful,Hello "+username);

            if(first==1)
            {
                first = 2;
            }
            if (first ==0)
            {
                username1 = username;
                password1 = password;
                first = 1;
            }
            userprofile=new userProfile;
            userprofile->show();
            this->close();

        }
        if(count<1)
            QMessageBox::critical(this, "Error", "username or password is incorrect.");
    }

}
