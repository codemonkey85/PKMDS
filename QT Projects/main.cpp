#include "frmboxes.h"
#include <QApplication>
#if (defined __APPLE__)
const char * apppath;
#endif
int main(int argc, char *argv[])
{
#if (defined __APPLE__)
    apppath = argv[0];
#endif
    QApplication a(argc, argv);
#if (defined __APPLE__)
    frmBoxes w(apppath);
#else
    frmBoxes w;
#endif
    w.show();
    return a.exec();
}
