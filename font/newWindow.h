#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
namespace Ui {
class newWindow;
}
 
class newWindow : public QWidget
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();


private:
    Ui::newWindow *ui;
};

#endif // NEWWINDOW_H
