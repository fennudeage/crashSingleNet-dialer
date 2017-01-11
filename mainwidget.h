#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QMouseEvent>
#include<QSystemTrayIcon>
#include<QIcon>
#include<QMenu>
#include<QAction>
#include<QPixmap>
#include<QSettings>
#include"about.h"
#include"dialup.h"
#include<QtNetwork/QNetworkReply>
#include<QtNetwork/QNetworkAccessManager>
#include<QTimer>
#include<QUdpSocket>
namespace Ui {
class mainWidget;
class QPoint;
}
class mainWidget : public QWidget
{
    Q_OBJECT


public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
 bool flag=true;

private slots:
    void on_quitapp_clicked();

    void on_mini_clicked();
    void on_dialupButtonclicked();
    void on_hangupclicked();
    void on_systemTrayIconEvent(QSystemTrayIcon::ActivationReason reason);
    void showabouDial();
    void showqt();
    void autoRun(bool check);
   // void SheartTimeout();
    void timerout();
private:
    QSettings *set;
    QPixmap funnymap;
    QAction *quait;
    QAction *about;
    QMenu *systemMenu;
    QSystemTrayIcon*systemicon;
    QAction*systemAutoRun;
    QAction*miniquit;
    QSystemTrayIcon*systemTraIcon;
    About *aboutme;
    Ui::mainWidget *ui;
    QPoint point;
    QAction *autoRunA;
    QSettings *SaveConfigFile;
     QString getIpADDR();
   QNetworkAccessManager *ACM;
   QUdpSocket *sock;
    QTimer *reportLOOP;

   QByteArray tempnet;
   QEventLoop LOOP;
    dialup *dialing;

   void checkpasswdSaveAction();
   void getConfigFile();

signals:
   void accpetreport();


};


#endif // MAINWIDGET_H
