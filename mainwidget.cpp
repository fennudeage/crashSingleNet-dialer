
#include "ui_mainwidget.h"
#include "mainwidget.h"
#include"addicon.h"
#include<QApplication>
#include<QIcon>
#include <QPalette>
#include<iostream>
#include<QDebug>
#include<QFile>
#include<QTextStream>
#include"dialup.h"
#include"about.h"
#include<windows.h>
#include<QUrl>
#define tr QStringLiteral
mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
   this->setWindowFlags(Qt::FramelessWindowHint);

    funnymap.load(":/img/funny_1.png");
    ui->FunnyLabel->resize(funnymap.size());
    ui->FunnyLabel->setPixmap(funnymap);
    setWindowOpacity(0.95);
   // getConfigFile();
    quait=new QAction(QStringLiteral("退出"),this);
    about=new QAction(QStringLiteral("关于"),this);
    autoRunA=new QAction(QStringLiteral("开机启动"),this);
    autoRunA->setCheckable(true);
    QAction *aboutqt=new QAction(QStringLiteral("关于Qt"),this);
    systemMenu=new QMenu(this);
    systemMenu->addAction(autoRunA);
    systemMenu->addAction(about);
    systemMenu->addAction(aboutqt);
    systemMenu->addSeparator();
    systemMenu->addAction(quait);
getIpADDR();
    ui->dialingButton->setShortcut(Qt::Key_Enter);
ui->quitapp->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
ui->mini->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
connect(ui->dialingButton,SIGNAL(clicked(bool)),this,SLOT(on_dialupButtonclicked()));
connect(ui->hangupButton,SIGNAL(clicked(bool)),this,SLOT(on_hangupclicked()));
connect(quait,SIGNAL(triggered(bool)),this,SLOT(close()));
connect(about,SIGNAL(triggered(bool)),this,SLOT(showabouDial()));
connect(aboutqt,SIGNAL(triggered(bool)),this,SLOT(showqt()));
connect(autoRunA,SIGNAL(toggled(bool)),this,SLOT(autoRun(bool)));
connect(this,SIGNAL(accpetreport()),this,SLOT(timerout()));
SaveConfigFile=new QSettings("FunnyCompany",QApplication::applicationName());
QPixmap titlepix(":/img/funny_1.png");

qDebug()<<QString(tempnet);

}
mainWidget::~mainWidget()
{
   // checkpasswdSaveAction();
    delete ui;
}

void mainWidget::on_quitapp_clicked()
{
    this->hide();

    if(flag){
        flag=FALSE;
    systemTraIcon=new QSystemTrayIcon(this);
connect(systemTraIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_systemTrayIconEvent(QSystemTrayIcon::ActivationReason)));
connect(systemTraIcon,SIGNAL(messageClicked()),this,SLOT(showNormal()));
    systemTraIcon->setIcon(QIcon(":/img/funny_1.png"));

    systemTraIcon->setToolTip(QStringLiteral("把你的贱爪子拿开！"));
    systemTraIcon->setContextMenu(systemMenu);
    systemTraIcon->show();
    systemTraIcon->showMessage(QStringLiteral("滑稽拨号器"),QStringLiteral("双击恢复"),QSystemTrayIcon::Information,10000);


    }
}


void mainWidget::on_mini_clicked()
{
    //this->hide();
    this->showMinimized();


}
void mainWidget::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        point=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}
void mainWidget::mouseMoveEvent(QMouseEvent*event)
{
   if(event->buttons()&Qt::LeftButton){
       move(event->globalPos()-point);
       event->accept();




}





}
void mainWidget::on_dialupButtonclicked(){
    dialing=new dialup(ui->accountEdit->text(),ui->passwdEitd->text());
QPalette textColor;
textColor.setColor(QPalette::WindowText,Qt::red);
ui->dialingInfo->setPalette(textColor);


 //QString ti="sdadasd";
 /*wcscpy_s(reinterpret_cast<wchar_t*>(temp),
     sizeof(temp) / sizeof(wchar_t),
     reinterpret_cast<const wchar_t*>(ti.utf16()));*/
//memset(temp,0,sizeof(QString ));
    //ti.toWCharArray(temp);

 //QString str=QString::fromWCharArray(temp);

    /*QFile file(QApplication::applicationDirPath().append( "log.txt"));
    file.open(QFile::WriteOnly);
    QTextStream text(&file);
    text<<temp;
    file.flush();
    file.close();
*/



   if(dialing->res==0)
   {
       ui->dialingInfo->setText(QString("成功连接"));
        systemTraIcon->showMessage(tr("成功连接"),getIpADDR(),QSystemTrayIcon::Information,20000);
       emit accpetreport();
   }
   else{
       switch(dialing->res) {
       case PENDING:
           ui->dialingInfo->setText(tr("操作挂起"));
           break;
       case 615:
           ui->dialingInfo->setText(tr("未找到指定端口"));break;

       case 616:
       ui->dialingInfo->setText(tr("发生内部错误"));break;
       case 617:
           ui->dialingInfo->setText(tr("调制解调器断开"));break;
       case 628:
           ui->dialingInfo->setText(tr("连接被关闭"));break;
       case 629:
           ui->dialingInfo->setText(tr("连接被远程计算机关闭"));break;
       case 638:
           ui->dialingInfo->setText(tr("请求超时"));break;
       case 651:
           ui->dialingInfo->setText(tr("网线断了"));break;
       default:


         ui->dialingInfo->setText(QString("%1").arg( dialing->res));
           break;
       }
   }

}
void mainWidget::on_hangupclicked(){



}
void mainWidget::on_systemTrayIconEvent(QSystemTrayIcon::ActivationReason reason)
{
    if(reason==QSystemTrayIcon::DoubleClick){
               this->show();
           }
}
void mainWidget::showabouDial(){
    //aboutdia =new AboutMe;

     aboutme=new About();


          this->show();
    //aboutme->show();
    aboutme->exec();





}
void mainWidget::showqt(){
    this->showNormal();
  AboutQt * AQt=new AboutQt;
}
void mainWidget::autoRun(bool check){
//check=qobject_cast<QAction*>(autoRunA)->isChecked();
set=new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);

if(check){
   set->setValue(QApplication::applicationName(),QApplication::applicationFilePath());
    qDebug()<<"1";

}
else{
    set->setValue(QApplication::applicationName(),"");
     qDebug()<<"2";
}

}
void mainWidget::checkpasswdSaveAction(){
    if(ui->checkBox->isChecked()&&(!ui->accountEdit->text().isEmpty())&&(!ui->passwdEitd->text().isEmpty())){

        SaveConfigFile->setValue("Account",ui->accountEdit->text());
        SaveConfigFile->setValue("passwd",ui->passwdEitd->text());

    }



}
void mainWidget::getConfigFile(){
    if (!SaveConfigFile->value("Account").isNull()){
        ui->accountEdit->setText(SaveConfigFile->value("Account").toString());
        ui->passwdEitd->setText(SaveConfigFile->value("passwd").toString());

    }
}
QString mainWidget::getIpADDR(){
    QNetworkAccessManager*  ACM=new QNetworkAccessManager();
      QNetworkReply  *reply =ACM->get(QNetworkRequest(QUrl("http://city.ip138.com/ip2city.asp")));
   QEventLoop LOOP;
   connect(reply,SIGNAL(finished()),&LOOP,SLOT(quit()));
   LOOP.exec();
  tempnet=reply->readAll();

     int wqstrpos=tempnet.indexOf('[');
     qDebug()<<wqstrpos;
       tempnet=tempnet.right(tempnet.length()-wqstrpos);
       tempnet=tempnet.remove(tempnet.indexOf('['),1);
       tempnet=tempnet.remove(tempnet.indexOf(']'),tempnet.length()-tempnet.indexOf('<'));
       tempnet=tempnet.remove(tempnet.indexOf('>'),1);





QFile file("D:/Qtlianxi/comicaldialing/debugLog.txt");
QTextStream textstr(&file);
file.open(QFile::WriteOnly|QFile::Text);
textstr<<tempnet;
file.flush();
file.close();



    //tempqstr.replace(tempqstr.length()-1,1,"");

    //tempqstr=tempqstr.mid( tempqstr.indexOf('['));
    //tempqstr.replace(tempqstr.indexOf(']'),1,QString(""));

    return QString(tempnet);




}
void mainWidget::timerout(){
  reportLOOP=new QTimer(this);
  sock=new QUdpSocket(this);
   //sock->bind();
  reportLOOP->start(1000);

 connect(reportLOOP,SIGNAL(timeout()),this,SLOT(timerout()));
  //sock->writeDatagram(QByteArray(""),QHostAddress::Any,5555);







}
