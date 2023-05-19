#include "keyclassify.h"
#include "ui_keyclassify.h"

Keyclassify::Keyclassify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyclassify)
{
    ui->setupUi(this);
    setWindowTitle("单字符分界符");
 
    HttpClient("http://localhost/keyClassify").success([this](const QString &response) {
            qDebug() << response;
            //将数据在tablewidget中显示出来
            QString strtmp = response;
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

Keyclassify::~Keyclassify()
{
    delete ui;
}

void Keyclassify::on_pushButton_3_clicked()
{
    //添加
    QString string = ui->textEdit->toPlainText();
    qDebug() << "用户添加的字符为:" << string;

    bool flag = false;
    for (int i = 0; i < this->word.length() ; ++i) {
        if(string == this->word[i]){
            QMessageBox::information(this, "添加结果", "\n添加失败！用户添加的字符早已存在！");
            flag = true;
        }
    }
    if(flag == false){
        HttpClient("http://localhost/keyClassifyAdd").success([this](const QString &response) {
                qDebug() << response;
                HttpClient("http://localhost/keyClassify").success([this](const QString &response) {
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
            }).param("keyWordName", string).post();

        QMessageBox::information(this, "添加结果", "\n添加成功！");
    }
}

void Keyclassify::on_pushButton_clicked()
{
    bool ok;
    // 获取字符串
    QString string = QInputDialog::getText(this, tr("输入单字符分界符对话框"),
                                           tr("请输入要查询的单字符分界符："),
                                           QLineEdit::Normal,tr("keyword"), &ok);
    bool flag = false;
    if(ok){
        //如果用户点击ok则将输入的单词输出出来
        qDebug() << "用户查询的单字符分界符为:" << string;
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

void Keyclassify::on_pushButton_2_clicked()
{
    //删除
    bool ok;
    // 获取字符串
    QString string = QInputDialog::getText(this, tr("输入单字符分界符对话框"),
                                           tr("请输入要删除的单字符分界符："),
                                           QLineEdit::Normal,tr("keyword"), &ok);
    if(ok){
        //如果用户点击ok则将输入的单词输出出来
        if(string.length()>1){
            QMessageBox::information(this,tr("系统提示"),tr("字符不符合规范,请重新输入"),QMessageBox::Ok);
        }
        else{
            //可以进行修改
            bool flag = false;
            for (int i = 0; i < this->word.length() ; ++i) {
                if(string == this->word[i]){
                    qDebug() << "用户删除的单字符分界符为:" << string;
                    HttpClient("http://localhost/keyClassify").success([](const QString &response) {
                            qDebug() << response;
                        }).param("keyWordName", string).post();
                    QMessageBox::information(this, "删除结果", "\n删除成功！所选字符已经删除！");
                    flag = true;
                }
            }
            if(flag == false){
                QMessageBox::information(this, "删除结果", "\n删除失败！用户想要删除的字符不存在！");
            }
            HttpClient("http://localhost/keyClassify").success([this](const QString &response) {
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
}

