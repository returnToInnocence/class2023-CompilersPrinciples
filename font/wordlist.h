#ifndef WORDLIST_H
#define WORDLIST_H

#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include "HttpClient.h"
namespace Ui {
class WordList;
}
 
class WordList : public QWidget
{
    Q_OBJECT

public:
    explicit WordList(QWidget *parent = nullptr);
    ~WordList();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_clicked2();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::WordList *ui;
    QStringList word;
};

#endif // WORDLIST_H
