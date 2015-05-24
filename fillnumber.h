#ifndef FILLNUMBER_H
#define FILLNUMBER_H

#include <QFrame>
#include <QPainter>
#include <QPaintEvent>

class FillNumber  : public QFrame
{
     Q_OBJECT
public:

    explicit FillNumber(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setNumber(int num);
    int Number() { return number;}
    bool isEmpty() { return !number;}

private:
    int number;
    QPixmap *pixmap;
};

#endif // FILLNUMBER_H
