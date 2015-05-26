#include "start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start go;
    go.show();

    return a.exec();
}
