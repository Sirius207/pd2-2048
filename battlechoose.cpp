#include "battlechoose.h"
#include "ui_battlechoose.h"

battlechoose::battlechoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlechoose)
{
    ui->setupUi(this);
}

battlechoose::~battlechoose()
{
    delete ui;
}
