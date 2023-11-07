#include "ACES.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ACES application;
    application.show();
    return a.exec();
}
