#include "frmboxes.h"
#include <QApplication>
const char * apppath;
int main(int argc, char *argv[])
{
    apppath = argv[0];
    QApplication a(argc, argv);
    frmBoxes w(apppath);
    w.show();
    return a.exec();
}
