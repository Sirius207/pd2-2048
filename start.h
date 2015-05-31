#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QWidget>
#include "mainwindow.h"
#include "finish.h"
#include "battlecom.h"
#include "vscom.h"



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
    Battlecom *battlecomwindow;
    vscom *vscomwindow;
    finish *resDialog;

private slots:

    void on_newgame_clicked();
    void resetGame();    

    void on_choosebattle_clicked();
    void resetbattle();

};

#endif // START_H
