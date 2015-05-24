#ifndef START_H
#define START_H

#include <QMainWindow>
#include "mainwindow.h"
#include "finish.h"


namespace Ui {
class start;
}

class start : public QMainWindow
{
    Q_OBJECT

public:
    explicit start(QWidget *parent =0);
    ~start();

private:
    Ui::start *ui;
    MainWindow *Gamewindow;
    finish *resDialog;

private slots:

    void on_newgame_clicked();
    void resetGame();

};

#endif // START_H
