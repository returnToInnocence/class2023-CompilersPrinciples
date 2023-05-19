#ifndef KEYWORD_H
#define KEYWORD_H

#include <QWidget>
#include <QInputDialog>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include "HttpClient.h"
namespace Ui {
class KeyWord;
} 

class KeyWord : public QWidget
{
    Q_OBJECT

public:
    explicit KeyWord(QWidget *parent = nullptr);
    ~KeyWord();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::KeyWord *ui;
    QStringList word;
};

#endif // KEYWORD_H
