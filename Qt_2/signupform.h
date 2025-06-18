#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QMainWindow>
#include <QtSql>
#include <QCryptographicHash>
#include "loginpage.h"

class LoginPage;
namespace Ui {
class SignupForm;
}

class SignupForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignupForm(QWidget *parent = nullptr);
    ~SignupForm();

private slots:
    void on_signupButton_clicked();
    void on_backButton_clicked();  // Added back button slot

private:
    void Initialize();
    void clearFields();
    void setupDatabase();

    Ui::SignupForm *ui;
    LoginPage* loginPage;
};

#endif // SIGNUPFORM_H
