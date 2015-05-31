#ifndef BATTLECHOOSE_H
#define BATTLECHOOSE_H

#include <QWidget>

namespace Ui {
class battlechoose;
}

class battlechoose : public QWidget
{
    Q_OBJECT

public:
    explicit battlechoose(QWidget *parent = 0);
    ~battlechoose();

private:
    Ui::battlechoose *ui;
};

#endif // BATTLECHOOSE_H
