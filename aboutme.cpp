#include "aboutme.h"
#include "ui_aboutme.h"
#include"mainwidget.h"

AboutMe::AboutMe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutMe)
{
    ui->setupUi(this);
}

AboutMe::~AboutMe()
{
    delete ui;
}
