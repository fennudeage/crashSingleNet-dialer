#ifndef ADDICON_H
#define ADDICON_H

#include <QObject>
#include<QPushButton>
#include<QStyle>
#include<QVector>
#include<QStandardPaths>
class addIcon : public QObject
{
    Q_OBJECT
public:
    explicit addIcon(QObject *parent = 0);


    static void titleIcon(QPushButton*ttBTN,QString Bpath){

    ttBTN->setIcon(QIcon(Bpath));






    }





signals:

public slots:
};

#endif // ADDICON_H
