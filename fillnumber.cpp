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

void FillNumber::setNumber(int num,int color)
{
    number = num;
    bw=color;
    QString name = QString::number(num);
    QString filename;
    if(color==2){
         filename  = ":/image/image/" + name + ".png";
    }
    else if(color==1){
         filename  = ":/image/image/b" + name + ".png";
    }
    else{
         filename  = ":/image/image/w" + name + ".png";
    }
    pixmap->load(filename);
    *pixmap = pixmap->scaled(QSize(80,80));
    update();
}

void FillNumber::setBNumber(int num)
{
    number = num;
    bw=1;
    QString name = QString::number(num);
    QString filename  = ":/image/image/b" +name + ".png";
    pixmap->load(filename);
    *pixmap = pixmap->scaled(QSize(80,80));
    update();
}

void FillNumber::setWNumber(int num)
{
    number = num;
    bw=0;
    QString name = QString::number(num);
    QString filename  = ":/image/image/w" + name + ".png";
    pixmap->load(filename);
    *pixmap = pixmap->scaled(QSize(80,80));
    update();
}




