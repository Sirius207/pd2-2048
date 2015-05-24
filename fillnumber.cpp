#include <QDebug>
#include "fillnumber.h"

FillNumber::FillNumber(QWidget *parent) :
     QFrame(parent)
{
    number = 0;
    pixmap = new QPixmap(":/image/image/0.png");

}

void FillNumber::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,80,80,*pixmap);
}

void FillNumber::setNumber(int num)
{
    number = num;
    QString name = QString::number(num);
    QString filename  = ":/image/image/" + name + ".png";
    pixmap->load(filename);
    *pixmap = pixmap->scaled(QSize(80,80));
    update();
}




