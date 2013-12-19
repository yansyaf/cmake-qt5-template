#include <QApplication>

#include "mainui.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("MyQtApplication");
    a.setQuitOnLastWindowClosed(true);

    mainui w;
    w.setFixedSize(600,570);
    w.show();

    return a.exec();
}
