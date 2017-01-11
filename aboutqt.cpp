#include "aboutqt.h"
#include"mainwidget.h"
AboutQt::AboutQt(QWidget *parent) : QWidget(parent)
{
    QMessageBox::aboutQt(this,"");

}
