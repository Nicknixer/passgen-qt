#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_generateButton_clicked();
    QTime time;
    qsrand(time.msecsTo(QTime::currentTime())); // srand init
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::generate(int chars = 8, bool nums = true, bool spec = false)
{
    QString password;
    for(int i = 0; i < chars; i++)
    {
        switch (qrand()%4) // Случайно выбираем добавление маленькой буквы, большой буквы, цифры или символа
        {
        case 0:
            password.append(qrand()%25+65); // Добавляем строчную букву
            break;
        case 1:
            if(nums) // Если нужно использовать цифры
               password.append(qrand()%10+48); // Добавляем цифру
            else
               --i; // Повторяем итерацию
            break;
        case 2:
            password.append(qrand()%25+97); // Добавляем прописную букву
            break;
        case 3:
            if(spec) // Если нужно использовать спец-символы
                password.append(qrand()%15+33); // Добавляем символ
            else
                --i; // Повторяем итерацию
            break;
        }
    }
    return password;
}

void MainWindow::on_generateButton_clicked()
{
    ui->passwordEdit->setText(generate(ui->spinSymbols->value(), ui->checkNums->isChecked(), ui->checkSpec->isChecked()));
}
