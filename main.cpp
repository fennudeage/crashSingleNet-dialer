#include "mainwidget.h"
#include <QApplication>
#include<QFile>
#include<QTranslator>
//#include"md5.h"
#define WINVER 0x0401
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;
    w.show();
   QFile srcfile(":/img/style.css");
   srcfile.open(QIODevice::ReadOnly);
   QString css=QLatin1String(srcfile.readAll());
   qApp->setStyleSheet(css);
    QTranslator *translation=new QTranslator(qApp);
    translation->load(":/img/qt_zh_CN.qm");
    qApp->installTranslator(translation);


    return a.exec();
}
