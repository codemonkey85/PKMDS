#ifndef FRMBOXES_H
#define FRMBOXES_H
#include <../../QT Projects/qt_sqlite.h>
#include <../../QT Projects/mouseeventeater.h>
namespace Ui {
class frmBoxes;
}
class frmBoxes : public QMainWindow
{
    Q_OBJECT
public:
    explicit frmBoxes(QWidget *parent = 0);
    MouseEventEater *mouseEventEater;
    QGraphicsView * partygraphics[6];
    QPixmap pix;
    QGraphicsView* boxgraphics[30];
    QGraphicsView* boxpreviewgraphics[24];
    void changebox(int index);
    void refreshboxgrid(int box);
    void refreshboxgrids();
    ~frmBoxes();
private slots:
    void on_actionLoad_SAV_triggered();
    void on_cbBoxes_currentIndexChanged(int index);
    void on_sbBoxIncrem_valueChanged(int value);
    void on_actionSave_changes_triggered();

    void on_actionSearch_triggered();

    void on_pbBoxSlot01_customContextMenuRequested(const QPoint &pos);
//void on_actionDeletePKM(QGraphicsView * gView);
private:
    Ui::frmBoxes *ui;
};
#endif // FRMBOXES_H
