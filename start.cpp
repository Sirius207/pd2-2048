#include "start.h"
#include "ui_start.h"

start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    connect(ui->newgame,SIGNAL(clicked()),this,SLOT(on_newgame_clicked()));
    connect(ui->choosebattle,SIGNAL(clicked()),this,SLOT(on_choosebattle_clicked()));
    Gamewindow=NULL;
    battlecomwindow=NULL;
    vscomwindow=NULL;
    resDialog=new finish;

}

start::~start()
{
    delete ui;
}


void start::on_newgame_clicked()
{
    Gamewindow=new MainWindow(this,resDialog);
    connect(resDialog,SIGNAL(reset()),this,SLOT(resetGame()));
    this->setCentralWidget(Gamewindow);
}

void start::resetGame()
{
    resDialog->hide();
    if(Gamewindow!=NULL){
        delete Gamewindow;
    }
    Gamewindow=new MainWindow(this,resDialog);
    this->setCentralWidget(Gamewindow);
}



void start::on_choosebattle_clicked()
{
   vscomwindow=new vscom(this,resDialog);
    connect(resDialog,SIGNAL(reset()),this,SLOT(resetbattle()));
    this->setCentralWidget(vscomwindow);
}

void start::resetbattle()
{
    resDialog->hide();
    if(vscomwindow!=NULL){
        delete vscomwindow;
    }
    vscomwindow=new vscom(this,resDialog);
    this->setCentralWidget(vscomwindow);
}
