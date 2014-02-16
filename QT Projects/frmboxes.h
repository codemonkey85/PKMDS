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
    explicit frmBoxes(const char * apppath = "", QWidget *parent = 0);
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
    void on_actionDelete_HMs_triggered();
    void on_actionView_PKM_File_triggered();
    void on_actionOT_Info_triggered();
private:
    Ui::frmBoxes *ui;
};
#endif // FRMBOXES_H
