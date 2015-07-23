#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_generateButton_clicked();
    QTime time;
    qsrand(time.msecsTo(QTime::currentTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::generate(int chars = 8, bool nums = true, bool spec = true)
{
    QString password;
    QChar ch;
    for(int i = 0; i < chars; i++)
    {
        switch (qrand()%4)
        {
        case 0:
            password.append(qrand()%25+65);
            break;
        case 1:
            if(nums)
               password.append(qrand()%10+48);
            else
               --i;
            break;
        case 2:
            password.append(qrand()%25+97);
            break;
        case 3:
            if(spec)
                password.append(qrand()%15+33);
            else
                --i;
            break;
        }
    }
    return password;
}

void MainWindow::on_generateButton_clicked()
{
    ui->passwordEdit->setText(generate(ui->spinSymbols->value(), ui->checkNums->isChecked(), ui->checkSpec->isChecked()));
}
