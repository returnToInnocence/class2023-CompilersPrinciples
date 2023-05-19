#include "form1.h"
#include "ui_form1.h"

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newForm)
{
    ui->setupUi(this);
    this->setWindowTitle("编译原理");
    ui->textEdit->setReadOnly(true);
    QObject::connect(ui->pushButton,SIGNAL(clicked(void)),this,SLOT(enableButton1()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked(void)),this,SLOT(enableButton2()));
    QObject::connect(ui->pushButton_3,SIGNAL(clicked(void)),this,SLOT(enableButton3()));
    QObject::connect(ui->pushButton_4,SIGNAL(clicked(void)),this,SLOT(enableButton4()));
} 

QString Form1::Rule1(QString str){
    ui->textEdit->insertPlainText("****************************************************\n");
    if(str[0] < 48 || str[0] > 57 ){
            return ">> Error! Please input Rule1\n";
    }else{
        ui->textEdit->insertPlainText(">> Input correct ! Loading...\n");
    }
    for(int i = 0 ;  i < str.length();++i){
        ui->textEdit->insertPlainText(">> judge ["+str[i]+"]...\n");
        if(str[i] < 48 || str[i] > 57 ){
            return ">> Error! Please input Rule1\n";
        }
    }
    return ">> Job down ! This is Rule1 ^_^\n";
}


QString Form1::Rule2(QString str){
       ui->textEdit->insertPlainText("****************************************************\n");
       QString KeyWord[28]={"program","function","procedure","array","const","file","record","set","type","var","case","of",
                    "begin","end","do","if","else","for","repeat","then","while","with","string","integer","class","not",
                    "read","write"};
       if(str[0] < 65 || str[0] > 122 || (str[0]>90 && str[0]<97) ){
            return ">> Error! Please input Rule2\n";
        }else{
            ui->textEdit->insertPlainText(">> Input correct! Loading...\n");
        }
        for(int i = 0 ;  i < str.length();++i){
             ui->textEdit->insertPlainText(">> judge ["+str[i]+"]...\n");
            if(str[i] < 48 || (str[i] > 57&&str[0] < 65) ||  str[0] > 122 || (str[0]>90 && str[0]<97) ){
                return ">> error! please input Rule2\n";
            }
        }
        return ">> Job down! This is Rule2 ^_^\n";
}

QString Form1::Rule3(QString str){
    ui->textEdit->insertPlainText("****************************************************\n");
    char array[11] ={'+','-','*','/','(',')',':','[',']','=','<'};
    for(int i = 0 ; i<11; ++i){
        if(str[0] == array[i])
        {
           ui->textEdit->insertPlainText(">> input correct! loading...\n");
           for(int i = 0 ;  i < str.length();++i){
                ui->textEdit->insertPlainText(">> judge ["+str[i]+"]...\n");
                bool flag = false;
                for(int j = 0 ; j<11; ++j){
                    if(str[i] == array[j]){
                        flag = true;
                    }
                }
                if(flag){
                    continue;
                }else{
                    return ">> Error! Please input Rule3\n";
                }
           }
           break;
        }else{
            return ">> Error! Please input Rule3\n";
        }
    }
    return ">> Job down! this is rule3 ^_^\n";
}

Form1::~Form1()
{
    delete ui;
}

void Form1::enableButton1(void){
    ui->textEdit->insertPlainText(Rule1(ui->lineEdit->text())+"\n");
}
void Form1::enableButton2(void){
    ui->lineEdit->setText("");
}

void Form1::enableButton3(void){
     ui->textEdit->insertPlainText(Rule2(ui->lineEdit->text())+"\n");
}
void Form1::enableButton4(void){
    ui->textEdit->insertPlainText(Rule3(ui->lineEdit->text())+"\n");
}
void Form1::calcClicked(void){

}
