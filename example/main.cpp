#include <QApplication>
#include <QWidget>
#include "qjenkins.h"

int main(int argc,char **argv)
{
    QApplication app(argc, argv);
    QJenkins jenClient(&app);

    jenClient.init();
    QWidget w;
    w.show();
    int ret=app.exec();
    return ret;
}
