#ifndef WORDCLASSFIY_H
#define WORDCLASSFIY_H

#include <QWidget>
 
namespace Ui {
class wordClassfiy;
}

class wordClassfiy : public QWidget
{
    Q_OBJECT

public:
    explicit wordClassfiy(QWidget *parent = nullptr);
    ~wordClassfiy();

private:
    Ui::wordClassfiy *ui;
};

#endif // WORDCLASSFIY_H
