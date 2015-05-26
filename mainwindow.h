#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>
#include "finish.h"

#include "fillnumber.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent ,finish *res);
    ~MainWindow();
signals:
    void changed(int score);
protected:
      void keyPressEvent(QKeyEvent *event);
      void moveUp();
      void moveRight();
      void moveLeft();
      void moveDown();

      bool canMoved();
      bool hitWall(int direction);
      bool checkBlank(int direction);
      void endGame();
      void rememberNumber();
      void redo();


private:
      void initGame();
      void fillTable();
      void randomBox();
      bool isFull();
      void swapBox(FillNumber *firstBox,FillNumber *lastBox);

      void emptyBoxMoveLft();
      void emptyBoxMoveDown();
      void emptyBoxMoveRight();
      void emptyBoxMoveUp();




     Ui::MainWindow *ui;
     FillNumber* Table[4][4];
     finish *resWindow;
     int score;
     int recordNumber[16];
};

#endif // MAINWINDOW_H
