#include "about.h"
#include "ui_about.h"
#include<QMessageBox>
bool About::flag=true;
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{

    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    About::flag=false;
   ui->tabWidget->addTab(NULL,"Qt open resource");
    gif=new QMovie(":/img/20161109113530914.gif");
    ui->label->setMovie(gif);
    gif->setScaledSize(ui->label->size());
    gif->start();
    this->setFixedSize(this->size());
    this->setWindowTitle(QStringLiteral("关于"));

}

About::~About()
{

    delete ui;

}
void About::ondialogcloseEvent(QCloseEvent *event){

    About::flag=true;

}
