#ifndef BATTLECOM_H
#define BATTLECOM_H
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include "finish.h"
#include "fillnumber.h"


namespace Ui {
class Battlecom;
}

class Battlecom : public QWidget
{
    Q_OBJECT

public:
    explicit Battlecom(QWidget *parent ,finish *res);
    ~Battlecom();

private:
    Ui::Battlecom *ui;
    finish *resWindow;
};

#endif // BATTLECOM_H
