#ifndef FRMREPORT_H
#define FRMREPORT_H

#include <QDialog>
#include <../../QT Projects/qt_sqlite.h>
#include <../../QT Projects/mouseeventeater.h>
#include "pkmviewer.h"
namespace Ui {
class frmReport;
}

class frmReport : public QDialog
{
    Q_OBJECT
    
public:
    party_pkm * ppkm;
    pokemon_obj * pkm;
    pkmviewer * pview_;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    explicit frmReport(QWidget *parent = 0);
    ~frmReport();
#if (defined __linux__) || (defined __APPLE__)
    void createtable();
    void dosearch(vector<string> columns, string where = "", string order = "", int limit = 0);
#else
    void frmReport::createtable();
    void frmReport::dosearch(vector<string> columns, string where = "", string order = "", int limit = 0);
#endif
private slots:
    void on_btnSearch_clicked();

    void on_tblPKM_cellDoubleClicked(int row, int column);

private:
    Ui::frmReport *ui;

};

#endif // FRMREPORT_H
