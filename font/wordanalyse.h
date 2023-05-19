#ifndef WORDANALYSE_H
#define WORDANALYSE_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QTextBrowser>
#include <QDebug>
#include <QTimer>
 
namespace Ui {
class WordAnalyse;
}

class WordAnalyse : public QWidget
{
    Q_OBJECT

public:
    explicit WordAnalyse(QWidget *parent = nullptr);
    ~WordAnalyse();
    void paintEvent(QPaintEvent *);
    void delay();
    QString reCall(QString str,int &i);
    QString allRuleJude(QString str,int &i);
    QString Rule1(QString str,int &i);
    QString Rule2(QString str,int &i);
    QString Rule3(QString str,int &i);
    QString Rule4(QString str,int &i);
    QString Rule5(QString str,int &i);
    QString Rule6(QString str,int &i);
    QString Rule7(QString str,int &i);
    QString Rule8(QString str,int &i);
    QString Rule9(QString str,int &i);
    QString Rule10(QString str,int &i);

private:
    Ui::WordAnalyse *ui;
    QString path;
    int x=0,y=0;

private slots:
    QString open();
    void ShowTextToWindow();
    void showdata();
    //使能的能耗按钮的槽操作数
    void enableButton1(void);
    void enableButton2(void);
};

#endif // WORDANALYSE_H
