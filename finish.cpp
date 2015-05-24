#include "finish.h"
#include "ui_finish.h"

finish::finish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);
}

finish::~finish()
{
    delete ui;
}

void finish::on_pushButton_clicked()
{
    emit reset();
}

void finish::on_pushButton_2_clicked()
{
    QApplication::exit(0);
}
