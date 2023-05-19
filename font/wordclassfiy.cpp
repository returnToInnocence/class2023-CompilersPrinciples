#include "wordclassfiy.h"
#include "ui_wordclassfiy.h"

wordClassfiy::wordClassfiy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wordClassfiy)
{ 
    ui->setupUi(this);
    setWindowTitle("单词分类");
    ui->textEdit->setStyleSheet("QTextEdit{background-color:rgba(128,128,128,128)}");
    ui->textEdit_1->setStyleSheet("QTextEdit{background-color:rgba(128,128,128,128)}");
    ui->textEdit_2->setStyleSheet("QTextEdit{background-color:rgba(128,128,128,128)}");
    ui->textEdit_3->setStyleSheet("QTextEdit{background-color:rgba(128,128,128,128)}");
}

wordClassfiy::~wordClassfiy()
{
    delete ui;
}
