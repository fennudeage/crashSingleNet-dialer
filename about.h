#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include"aboutqt.h"
#include<QMovie>
#include<QCloseEvent>
namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    AboutQt *AQt;
    ~About();
static bool flag;

private:
    Ui::About *ui;
    QMovie *gif;
    void ondialogcloseEvent(QCloseEvent* event);

 signals:


};

#endif // ABOUT_H
