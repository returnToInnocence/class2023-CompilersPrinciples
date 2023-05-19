#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wordlist.h"
#include "wordclassfiy.h"
#include "worddfa.h"
#include "wordanalyse.h"
#include "keyword.h"
#include "keyclassify.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("编译程序");
}
 
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //显示字符表界面
    WordList *configWindow = new WordList;
    configWindow->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    wordClassfiy *Window = new wordClassfiy;
    Window->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this,tr("系统提示"),tr("暂未开放"),QMessageBox::Ok);
}

void MainWindow::on_pushButton_6_clicked()
{
    WordDFA *dfa = new WordDFA;
    dfa->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    WordAnalyse *analyse = new WordAnalyse;
    analyse->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    KeyWord *keyword = new KeyWord;
    keyword->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    Keyclassify *keyclassify = new Keyclassify;
    keyclassify->show();
}

void MainWindow::on_action_triggered()
{
    WordList *configWindow = new WordList;
    configWindow->show();
}

void MainWindow::on_action_2_triggered()
{
    wordClassfiy *Window = new wordClassfiy;
    Window->show();
}

void MainWindow::on_action_3_triggered()
{
    QMessageBox::information(this,tr("系统提示"),tr("暂未开放"),QMessageBox::Ok);
}

void MainWindow::on_action_4_triggered()
{
    KeyWord *keyword = new KeyWord;
    keyword->show();
}

void MainWindow::on_action_5_triggered()
{
    Keyclassify *keyclassify = new Keyclassify;
    keyclassify->show();
}

void MainWindow::on_action_DFA_triggered()
{
    WordDFA *dfa = new WordDFA;
    dfa->show();
}

void MainWindow::on_action_6_triggered()
{
    WordAnalyse *analyse = new WordAnalyse;
    analyse->show();
}
