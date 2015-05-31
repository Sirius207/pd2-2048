#ifndef VSCOM_H
#define VSCOM_H
#include <QWidget>
#include <QKeyEvent>
#include "finish.h"
#include "fillnumber.h"

#include <QMainWindow>

namespace Ui {
class vscom;
}

class vscom : public QMainWindow
{
    Q_OBJECT

public:
    explicit vscom(QWidget *parent,finish *res );
    ~vscom();
signals:
    void changed(int score);
    void changedcom(int score2);
protected:
      void keyPressEvent(QKeyEvent *event);

      void moveUp(int bw);
      void moveRight(int bw);
      void moveLeft(int bw);
      void moveDown(int bw);

      bool canMoved();
      bool hitWall(int direction);
      bool checkBlank(int direction);
      void endGame();
      void rememberNumber();
      void redo();
      void comMove();
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
      Ui::vscom *ui;
      finish *resWindow;
      FillNumber* Table[4][4];
      int score;
      int score2;
      int recordNumber[16];
      int recordDirection[2];
      int comNumber[16][16];
      FillNumber* direction[2];

};

#endif // VSCOM_H
