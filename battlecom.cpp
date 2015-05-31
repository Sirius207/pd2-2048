#include "battlecom.h"
#include "ui_battlecom.h"
#include <QMainWindow>
#include <QWidget>
#include "finish.h"


Battlecom::Battlecom(QWidget *parent,finish *res) :
    QWidget(parent),
    ui(new Ui::Battlecom)
{
    ui->setupUi(this);
    resWindow=res;

}

Battlecom::~Battlecom()
{
    delete ui;
}
