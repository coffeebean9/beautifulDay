#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    Q_INIT_RESOURCE(diagramscene);

    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(100, 100, 800, 500);
    w.show();
    return a.exec();
}
