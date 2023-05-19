#ifndef KEYCLASSIFY_H
#define KEYCLASSIFY_H

#include <QWidget>
#include <QInputDialog>
#include <QDebug>
#include <QMessageBox>
#include "HttpClient.h"
namespace Ui {
class Keyclassify;
}
 
class Keyclassify : public QWidget
{
    Q_OBJECT

public:
    explicit Keyclassify(QWidget *parent = nullptr);
    ~Keyclassify();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Keyclassify *ui;
    QStringList word;
};

#endif // KEYCLASSIFY_H
