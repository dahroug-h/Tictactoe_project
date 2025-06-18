#include "signupform.h"
#include "ui_signupform.h"
#include <QMessageBox>
#include <QLabel>

SignupForm::SignupForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignupForm)
{
    ui->setupUi(this);
    Initialize();
}

SignupForm::~SignupForm()
{
    delete ui;
}

void SignupForm::Initialize()
{
    setWindowTitle("Sign Up");
    setFixedSize(800, 600);

    // Gradient background
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(131, 61, 121));
    gradient.setColorAt(1, QColor(165, 64, 134));

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    setPalette(palette);

    // Button styling template
    QString buttonStyle =
        "QPushButton {"
        "   background-color: %1;"
        "   color: white;"
        "   border: none;"
        "   padding: 10px 20px;"
        "   font-size: 16px;"
        "   border-radius: 10px;"
        "   min-width: 100px;"
        "   min-height: 40px;"
        "}"
        "QPushButton:hover { background-color: %2; }"
        "QPushButton:pressed { background-color: %3; }";

    // Style signup button (blue)
    ui->signupButton->setStyleSheet(buttonStyle
                                        .arg("#4acdd5")
                                        .arg("#2192a2")
                                        .arg("#798596")
                                                                        + "font-size: 30px");

    // Style back button (orange)
    ui->backButton->setStyleSheet(buttonStyle
                                      .arg("#ff9a48")
                                      .arg("#de6a25")
                                      .arg("#b71c1c"));

}

void SignupForm::clearFields()
{
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
}

void SignupForm::on_signupButton_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();
    QString confirm = ui->confirmEdit->text().trimmed();

    // Check if password matches confirm password
    if (password != confirm) {
        QMessageBox::warning(this, "Error", "Passwords do not match.");
        return;
    }

    // Check if username already exists in database
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM Players WHERE username = ?");
    checkQuery.bindValue(0, username);
    if (checkQuery.exec() && checkQuery.next()) {
        QMessageBox::warning(this, "Error", "Username already exists in database.");
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Insert new user into database
    QSqlQuery query;
    query.prepare("INSERT INTO Players (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword.toHex());
    if (!query.exec()) {
        qDebug() << "Error inserting data:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to insert data into database.");
    } else {
        QMessageBox::information(this, "Success", "Signup successful!");
        clearFields();
        loginPage = new LoginPage;
        loginPage->show();
        this->close();
    }
}
void SignupForm::on_backButton_clicked()
{
    loginPage = new LoginPage();
    loginPage->show();
    this->close();
}
