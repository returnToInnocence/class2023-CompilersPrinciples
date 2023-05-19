#ifndef WORDDFA_H
#define WORDDFA_H

#include <QWidget>
#include<QPainter>
#include<QPixmap>
namespace Ui {
class WordDFA;
} 

class WordDFA : public QWidget
{
    Q_OBJECT

public:
    explicit WordDFA(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~WordDFA();

private:
    Ui::WordDFA *ui;
};

#endif // WORDDFA_H
