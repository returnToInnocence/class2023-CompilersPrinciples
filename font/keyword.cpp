#include "keyword.h"
#include "ui_keyword.h"
 
KeyWord::KeyWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyWord)
{
    ui->setupUi(this);
    setWindowTitle("关键字");
    HttpClient("http://localhost/keyWord").success([this](const QString &response) {
            qDebug() << response;
            //将数据在tablewidget中显示出来
            QString strtmp = response;
            qDebug() << response;
            this->word = strtmp.split("|");
            ui->tableWidget->setColumnCount(2);
            ui->tableWidget->setRowCount(word.length());
            //设置表头信息
            ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"ID"<<"关键字");
            ui->tableWidget->verticalHeader()->setVisible(false);//隐藏左边的默认行号
            for(int i=0;i<this->word.length();i++){
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(word[i]));
            }
        }).get();
}

KeyWord::~KeyWord()
{
    delete ui;
}

void KeyWord::on_pushButton_2_clicked()
{
    bool ok;
    // 获取字符串
    QString string = QInputDialog::getText(this, tr("输入关键字对话框"),
                                           tr("请输入要查询的关键字："),
                                           QLineEdit::Normal,tr("keyword"), &ok);
    bool flag = false;
    if(ok){
        //如果用户点击ok则将输入的单词输出出来
        qDebug() << "用户查询的关键字为:" << string;
        for (int i = 0; i < this->word.length() ; ++i) {
            if(string == this->word[i]){
                QMessageBox::information(this, "查找结果", "\n查找成功！用户查找的字符存在！");
                flag = true;
            }
        }
        if(flag == false){
            QMessageBox::information(this, "查找结果", "\n查找失败！用户查找的字符不存在！");
        }
    }
}

void KeyWord::on_pushButton_clicked()
{
    //添加新的关键字，从文本框中获取
    QString string = ui->textEdit->toPlainText();
    qDebug() << "用户添加的关键字为:" << string;
    bool flag = false;
    for (int i = 0; i < this->word.length() ; ++i) {
        if(string == this->word[i]){
            QMessageBox::information(this, "添加结果", "\n添加失败！用户添加的字符早已存在！");
            flag = true;
        }
    }
    if(flag == false){
        HttpClient("http://localhost/keyWordAdd").success([](const QString &response) {
                qDebug() << response;
            }).param("keyWordName", string).post();
        HttpClient("http://localhost/keyWord").success([this](const QString &response) {
                qDebug() << response;
                //将数据在tablewidget中显示出来
                QString strtmp = response;
                qDebug() << response;
                this->word = strtmp.split("|");
                ui->tableWidget->setColumnCount(2);
                ui->tableWidget->setRowCount(word.length());
                //设置表头信息
                ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"ID"<<"关键字");
                ui->tableWidget->verticalHeader()->setVisible(false);//隐藏左边的默认行号
                for(int i=0;i<this->word.length();i++){
                    ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
                    ui->tableWidget->setItem(i,1,new QTableWidgetItem(word[i]));
                }
            }).get();
        QMessageBox::information(this, "添加结果", "\n添加成功！");
    }
}

void KeyWord::on_pushButton_3_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this, tr("输入关键字对话框"),
                                           tr("请输入要删除的关键字："),
                                           QLineEdit::Normal,tr("keyword"), &ok);
    if(ok){
        //如果用户点击ok则将输入的单词输出出来
        qDebug() << "用户删除的关键字为:" << string;
        bool flag = false;
        for (int i = 0; i < this->word.length() ; ++i) {
            if(string == this->word[i]){
                HttpClient("http://localhost/keyWord").success([](const QString &response) {
                        qDebug() << response;
                    }).param("keyWordName", string).post();
                QMessageBox::information(this, "删除结果", "\n删除成功！所选字符已经删除！");
                flag = true;
            }
        }
        if(flag == false){
            QMessageBox::information(this, "删除结果", "\n删除失败！用户想要删除的字符不存在！");
        }
        HttpClient("http://localhost/keyWord").success([this](const QString &response) {
                qDebug() << response;
                //将数据在tablewidget中显示出来
                QString strtmp = response;
                qDebug() << response;
                this->word = strtmp.split("|");
                ui->tableWidget->setColumnCount(2);
                ui->tableWidget->setRowCount(word.length());
                //设置表头信息
                ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"ID"<<"关键字");
                ui->tableWidget->verticalHeader()->setVisible(false);//隐藏左边的默认行号
                for(int i=0;i<this->word.length();i++){
                    ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
                    ui->tableWidget->setItem(i,1,new QTableWidgetItem(word[i]));
                }
            }).get();
    }
}

