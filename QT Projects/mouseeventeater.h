#ifndef MOUSEEVENTEATER_H
#define MOUSEEVENTEATER_H
#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
class MouseEventEater : public QObject
{
    Q_OBJECT
public:
    explicit MouseEventEater(QObject *parent = 0);
signals:
    //    void send_rightButtonClicked(const QPoint &p);
//#if (defined __linux__) || (defined __APPLE__)
//    void test(void *apkm);
//#else
//    void MouseEventEater::test(void *apkm);
//#endif
public slots:
protected:
#if (defined __linux__) || (defined __APPLE__)
    bool eventFilter(QObject *obj, QEvent *event);
    void test(void *apkm);
#else
    bool MouseEventEater::eventFilter(QObject *obj, QEvent *event);
    void MouseEventEater::test(void *apkm);
#endif
};
#endif // MOUSEEVENTEATER_H
