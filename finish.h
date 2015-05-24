#ifndef FINISH_H
#define FINISH_H

#include <QWidget>

namespace Ui {
class finish;
}

class finish : public QWidget
{
    Q_OBJECT

public:
    explicit finish(QWidget *parent = 0);
    ~finish();
signals:
    void reset();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::finish *ui;
    QWidget *mainWindow;

};

#endif // FINISH_H
