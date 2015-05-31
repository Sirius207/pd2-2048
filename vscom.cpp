#include "vscom.h"
#include "ui_vscom.h"
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include "finish.h"


vscom::vscom(QWidget *parent,finish *res) :
    QMainWindow(parent),
    ui(new Ui::vscom)
{
    ui->setupUi(this);
    connect(this,SIGNAL(changed(int)),ui->lcdNumber,
            SLOT(display(int)));
    connect(this,SIGNAL(changedcom(int)),ui->lcdNumber_2,
            SLOT(display(int)));
    resWindow=res;
    score = 0;
    score2 = 0;
    fillTable();
    initGame();
    rememberNumber();
    redo();
}

vscom::~vscom()
{
    delete ui;
}
void vscom::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_W:{
            if(canMoved()){
                 direction[0]->setNumber(12,2);
                 rememberNumber();
                 moveUp(0);}
            else endGame();
            break;
        }
        case Qt::Key_S:{
            if(canMoved()){
                direction[0]->setNumber(14,2);
               rememberNumber();
                moveDown(0);}
            else endGame();
            break;
        }
        case Qt::Key_A:{
            if(canMoved()){
                direction[0]->setNumber(13,2);
               rememberNumber();
                moveLeft(0);}
            else endGame();
            break;
        }
        case Qt::Key_D:{
            if(canMoved()){
                direction[0]->setNumber(11,2);
                rememberNumber();
                moveRight(0);}
            else endGame();
            break;
        }
        case Qt::Key_R:{
            redo();
            break;
        }
        case Qt::Key_Right:{
            if(canMoved()){
                direction[1]->setNumber(21,2);
                rememberNumber();
                moveRight(1);}
            else endGame();
            break;
        }
    case Qt::Key_Down:{
        if(canMoved()){
            direction[1]->setNumber(24,2);
            rememberNumber();
            moveDown(1);}
        else endGame();
        break;
    }
    case Qt::Key_Left:{
        if(canMoved()){
            direction[1]->setNumber(23,2);
            rememberNumber();
            moveLeft(1);}
        else endGame();
        break;
    }
    case Qt::Key_Up:{
        if(canMoved()){
            direction[1]->setNumber(22,2);
            rememberNumber();
            moveUp(1);}
        else endGame();
        break;
    }

        default: QWidget::keyPressEvent(event);
    }
}

void vscom::moveUp(int bw){

     emptyBoxMoveDown();
     emptyBoxMoveDown();
     for(int j = 0;j < 4;j++){
         for(int i = 3;i > 0;i--){
             if(!Table[i][j]->isEmpty()){
                 if(Table[i][j]->Number() == Table[i-1][j]->Number()){
                     if(i>=3&&Table[i-2][j]->Number() == Table[i-3][j]->Number()){
                         goto jumpup;

                     }
                     else if(i>=2&&Table[i-1][j]->Number() == Table[i-2][j]->Number()){

                         Table[i-1][j]->setNumber(0,2);
                         if(bw==0){
                            Table[i-2][j]->setWNumber(Table[i-2][j]->Number()*2);
                         }
                         else{
                            Table[i-2][j]->setBNumber(Table[i-2][j]->Number()*2);
                         }
                         if(bw==0){
                             score += Table[i-2][j]->Number();
                             emit changed(score);
                         }
                         else{
                             score2 += Table[i-2][j]->Number();
                             emit changedcom(score2);
                         }
                         if(Table[i-2][j]->Number() == 2048){
                             endGame();
                         }
                         goto stopmoveup;
                     }
                     else if(i>=2&&Table[i-1][j]->Number()*2 == Table[i-2][j]->Number()){
                         Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i-1][j]->setWNumber(Table[i-1][j]->Number()*2);
                        }
                        else{
                           Table[i-1][j]->setBNumber(Table[i-1][j]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i-1][j]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i-1][j]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i-1][j]->Number() == 2048){
                             endGame();
                         }
                         goto stopmoveup;
                     }
                     else{
                        jumpup:
                        Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i-1][j]->setWNumber(Table[i-1][j]->Number()*2);
                        }
                        else{
                            Table[i-1][j]->setBNumber(Table[i-1][j]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i-1][j]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i-1][j]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i-1][j]->Number() == 2048){
                            endGame();

                        }
                     }
                 }
             }
         }
         stopmoveup:;
     }
     emptyBoxMoveDown();
     randomBox();
}
void vscom::moveRight(int bw)
{
    emptyBoxMoveLft();
    emptyBoxMoveLft();
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 3;j++){
            if(!Table[i][j]->isEmpty()){
                if(Table[i][j]->Number()== Table[i][j+1]->Number()){
                    if(j<=0&&Table[i][j+2]->Number()== Table[i][j+3]->Number()){
                        goto jumpright;
                    }
                    else if(j<=1&&Table[i][j+1]->Number()== Table[i][j+2]->Number()){
                        Table[i][j+1]->setNumber(0,2);
                        if(bw==0){
                            Table[i][j+2]->setWNumber(Table[i][j+2]->Number()*2);
                        }
                        else{
                            Table[i][j+2]->setBNumber(Table[i][j+2]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i][j+2]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i][j+2]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i][j+2]->Number() == 2048){
                            endGame();
                        }
                        goto stopright;
                    }
                    else if(j<=1&&Table[i][j+1]->Number()*2== Table[i][j+2]->Number()){
                        Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i][j+1]->setWNumber(Table[i][j+1]->Number()*2);
                        }
                        else{
                            Table[i][j+1]->setBNumber(Table[i][j+1]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i][j+1]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i][j+1]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i][j+1]->Number() == 2048){
                            endGame();
                        }
                        goto stopright;
                    }

                    else{
                        jumpright:
                        Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i][j+1]->setWNumber(Table[i][j+1]->Number()*2);
                        }
                        else{
                            Table[i][j+1]->setBNumber(Table[i][j+1]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i][j+1]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i][j+1]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i][j+1]->Number() == 2048){
                            endGame();
                        }

                    }
                }
            }
        }
        stopright:;
    }
    emptyBoxMoveLft();
    randomBox();
}

void vscom::moveLeft(int bw)
{
    emptyBoxMoveRight();
    emptyBoxMoveRight();
    for(int i = 0;i < 4;i++){
        for(int j = 3;j > 0;j--){
            if(!Table[i][j]->isEmpty()){
                if(Table[i][j]->Number()== Table[i][j-1]->Number()){
                    if(j>=3&&Table[i][j-2]->Number()== Table[i][j-3]->Number()){
                        goto jumpleft;
                    }
                    else if(j>=2&&Table[i][j-1]->Number()== Table[i][j-2]->Number()){
                        Table[i][j-1]->setNumber(0,2);
                        if(bw==0){
                            Table[i][j-2]->setWNumber(Table[i][j-2]->Number()*2);
                        }
                        else{
                            Table[i][j-2]->setBNumber(Table[i][j-2]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i][j-2]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i][j-2]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i][j-2]->Number() == 2048){
                            endGame();
                        }
                        goto stopleft;
                    }
                    else if(j>=2&&Table[i][j-1]->Number()*2== Table[i][j-2]->Number()){
                        Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i][j-1]->setWNumber(Table[i][j-1]->Number()*2);
                        }
                        else{
                            Table[i][j-1]->setBNumber(Table[i][j-1]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i][j-1]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i][j-1]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i][j-1]->Number() == 2048){
                            endGame();
                        }
                        goto stopleft;

                    }
                    else{
                        jumpleft:
                        Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i][j-1]->setWNumber(Table[i][j-1]->Number()*2);
                        }
                        else{
                            Table[i][j-1]->setBNumber(Table[i][j-1]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i][j-1]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i][j-1]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i][j-1]->Number() == 2048){
                            endGame();
                        }
                    }
                }
            }
        }
        stopleft:;
    }
    emptyBoxMoveRight();
    randomBox();
}

void vscom::moveDown(int bw)
{
    emptyBoxMoveUp();
    emptyBoxMoveUp();
    for(int j = 0;j < 4;j++){
        for(int i = 0;i < 3;i++){
            if(!Table[i][j]->isEmpty()){
                if(Table[i][j]->Number()== Table[i+1][j]->Number()){
                    if(i<=0&&Table[i+2][j]->Number()== Table[i+3][j]->Number()){

                        goto jumpdown;
                    }

                    else if(i<=1&&Table[i+1][j]->Number()== Table[i+2][j]->Number()){
                        Table[i+1][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i+2][j]->setWNumber(Table[i+2][j]->Number()*2);
                        }
                        else{
                            Table[i+2][j]->setBNumber(Table[i+2][j]->Number()*2);
                        }

                        if(bw==0){
                            score += Table[i+2][j]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i+2][j]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i+2][j]->Number() == 2048){
                            endGame();
                        }
                        goto stopdown;
                    }
                    else if(i<=1&&Table[i+1][j]->Number()*2== Table[i+2][j]->Number()){
                        Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i+1][j]->setWNumber(Table[i+1][j]->Number()*2);
                        }
                        else{
                            Table[i+1][j]->setBNumber(Table[i+1][j]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i+1][j]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i+1][j]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i+1][j]->Number() == 2048){
                            endGame();
                        }
                        goto stopdown;
                    }
                    else{
                        jumpdown:
                        Table[i][j]->setNumber(0,2);
                        if(bw==0){
                            Table[i+1][j]->setWNumber(Table[i+1][j]->Number()*2);
                        }
                        else{
                            Table[i+1][j]->setBNumber(Table[i+1][j]->Number()*2);
                        }
                        if(bw==0){
                            score += Table[i+1][j]->Number();
                            emit changed(score);
                        }
                        else{
                            score2 += Table[i+1][j]->Number();
                            emit changedcom(score2);
                        }
                        if(Table[i+1][j]->Number() == 2048){
                            endGame();
                        }
                   }
                }
            }
        }
        stopdown:;
    }
    emptyBoxMoveUp();
    randomBox();
}

bool vscom::canMoved()
{
    if(isFull()){
        for(int i = 0;i < 4; i++){
            for(int j = 0;j < 3;j++){
                if(Table[i][j]->Number() ==   Table[i][j+1]->Number())
                    return true;
            }
        }
        for(int j = 0;j < 4; j++){
            for(int i = 0;i < 3;i++){
                if(Table[i][j]->Number() == Table[i+1][j]->Number())
                   return true;
            }
        }
        return false;
    } else {
        return true;
    }
}
void vscom::endGame()
{

    qDebug() << "End Game";

 //   QMessageBox::about(this,tr("End Game"),tr("Game Over!!!<br/>You Score is %1").arg(score));
 //   qApp->exit();
    resWindow->show();
}
void vscom::initGame()
{
    for(int i = 0;i < 2;i++){
        int x = qrand()%4;
        int y = qrand()%4;
        if(Table[x][y]->isEmpty()){
            int n = (qrand()%2+1)*2;
            Table[x][y]->setNumber(n,2);
        }
        direction[0]->setNumber(0,2);
        direction[1]->setNumber(0,2);
    }
}
void vscom::fillTable()
{
    Table[0][0] = ui->f11;
    Table[0][1] = ui->f12;
    Table[0][2] = ui->f13;
    Table[0][3] = ui->f14;

    Table[1][0] = ui->f21;
    Table[1][1] = ui->f22;
    Table[1][2] = ui->f23;
    Table[1][3] = ui->f24;

    Table[2][0] = ui->f31;
    Table[2][1] = ui->f32;
    Table[2][2] = ui->f33;
    Table[2][3] = ui->f34;

    Table[3][0] = ui->f41;
    Table[3][1] = ui->f42;
    Table[3][2] = ui->f43;
    Table[3][3] = ui->f44;
    direction[0]= ui->player;
    direction[1]= ui->com;

}

void vscom::randomBox()
{

    QList<FillNumber*> list;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(Table[i][j]->isEmpty())
                list.append(Table[i][j]);
        }
    }
    int n = (qrand()%2+1)*2;
    int emptyBoxCount = list.count();
    if(emptyBoxCount)
        list.at(qrand()%emptyBoxCount)->setNumber(n,2);

}

bool vscom::isFull()
{
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(Table[i][j]->isEmpty())
                return false;
        }
    }
    return true;
}
bool vscom::checkBlank(int direction){
    int check=0;
    if(direction=1){
        for(int i = 0;i < 4; i++){
            for(int j = 0;j < 4;j++){
               if(Table[i][j]->Number()!=0)
                    check=1;
               if(Table[i][j]->Number()==0&&check==1)
                    return true;
            }
            check=0;
        }
    }
    else if(direction=3){
        for(int i = 0;i < 4; i++){
            for(int j = 3;j <= 0;j--){
               if(Table[i][j]->Number()!=0)
                    check=1;
               if(Table[i][j]->Number()==0&&check==1)
                    return true;
            }
            check=0;
        }
    }
    else if(direction=2){
        for(int j = 0;j < 4; j++){
            for(int i = 3;i <= 0;i--){
               if(Table[i][j]->Number()!=0)
                    check=1;
               if(Table[i][j]->Number()==0&&check==1)
                    return true;
            }
            check=0;
        }
    }
    else if(direction=4){
        for(int j = 0;j < 4; j++){
            for(int i = 0;i <= 3;i++){
               if(Table[i][j]->Number()!=0)
                    check=1;
               if(Table[i][j]->Number()==0&&check==1)
                    return true;
            }
            check=0;
        }
    }
    return false;


}

bool vscom::hitWall(int direction){
      if(direction=2){
          for(int j = 0;j < 4; j++){
              for(int i = 0;i < 3;i++){
                  if((Table[i][j]->Number() == Table[i+1][j]->Number()))
                     return false;
              }
          }
      }
      else if(direction=1){
          for(int i = 0;i < 4; i++){
              for(int j = 0;j < 3;j++){
                  if(Table[i][j]->Number() ==   Table[i][j+1]->Number())
                      return false;
              }
          }
      }
      else if(direction=4){
          for(int j = 0;j < 4; j++){
              for(int i = 0;i < 3;i++){
                  if((Table[i][j]->Number() == Table[i+1][j]->Number()))
                     return false;
              }
          }
      }
      else if(direction=3){
          for(int i = 0;i < 4; i++){
              for(int j = 0;j < 3;j++){
                  if((Table[i][j]->Number() ==   Table[i][j+1]->Number()))
                      return false;
              }
          }
      }




    return true;
}


void vscom::swapBox(FillNumber *firstBox, FillNumber *lastBox)
{
     int Num = firstBox->Number();
     int fcolor = firstBox->color();

     firstBox->setNumber(lastBox->Number(),lastBox->color());
     lastBox->setNumber(Num,fcolor);

}


void vscom::emptyBoxMoveDown()
{
    for(int j = 0;j <=3;j++){
        for(int i = 0;i < 3;i++){
            if(Table[i][j]->isEmpty()){
                for(int m = i;m < 3;m++){
                    swapBox(Table[m][j],Table[m+1][j]);
                }
            }
        }
    }
}
void vscom::emptyBoxMoveLft()
{
    for(int i = 0;i < 4;i++){
        for(int j = 3;j > 0;j--){
            if(Table[i][j]->isEmpty()){
                for(int m = j;m > 0;m--){
                    swapBox(Table[i][m],Table[i][m-1]);
                }
            }
        }
    }
}
void vscom::emptyBoxMoveRight()
{
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++){
            if(Table[i][j]->isEmpty()){
                for(int m = j;m < 3;m++){
                    swapBox(Table[i][m],Table[i][m+1]);
                }
            }
        }
    }
}

void vscom::emptyBoxMoveUp()
{
    for(int j = 0;j < 4;j++){
        for(int i = 3;i > 0;i--){
            if(Table[i][j]->isEmpty()){
                for(int m = i;m > 0;m--){
                    swapBox(Table[m][j],Table[m-1][j]);
                }
            }
        }
    }
}

void vscom::rememberNumber()
{
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            recordNumber[i*4+j]=Table[i][j]->Number();

        }

    }
    recordDirection[0]=direction[0]->Number();
    recordDirection[1]=direction[1]->Number();

}

void vscom::redo(){

     for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
              Table[i][j]->setNumber(recordNumber[i*4+j],2);
        }
      }
     direction[0]->setNumber(recordDirection[0],2);
     direction[1]->setNumber(recordDirection[1],2);

}

void vscom::comMove(){




}
