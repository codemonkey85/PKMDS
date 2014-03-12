#ifndef PKMVIEWER_H
#define PKMVIEWER_H
#include <QDialog>
#include <../../QT Projects/qt_sqlite.h>
#include <../../QT Projects/mouseeventeater.h>
namespace Ui {
class pkmviewer;
}
class pkmviewer : public QDialog
{
    Q_OBJECT
public:
    MouseEventEater *mouseEventEater;
    QGraphicsView * markingsgraphics[6];
    QPixmap markingspix[6];
    QGraphicsScene* markingsscene[6];
    QGraphicsView * ribbonpix[80];
#if (defined __linux__) || (defined __APPLE__)
    void setPKM(pokemon_obj * pkm_, int box, bool isPartyPKM);
    void displayPKM(/*bool rename = true*/);
    void updatemarks();
    void updatestats();
    void updatestatcolors();
    void updatemovepp();
    void updatemoveflavor();
    void updateabilityflavor();
    void updategenderpic();
    void updatemoveimages();
    void updatemoveinfo();
    void updatepkrs();
    void updatehidpwr();
    void updateribbons();
    void egg_display(bool isegg);
#else
    void pkmviewer::setPKM(pokemon_obj * pkm_, int box, bool isPartyPKM);
    void pkmviewer::displayPKM(/*bool rename = true*/);
    void pkmviewer::updatemarks();
    void pkmviewer::updatestats();
    void pkmviewer::updatestatcolors();
    void pkmviewer::updatemovepp();
    void pkmviewer::updatemoveflavor();
    void pkmviewer::updateabilityflavor();
    void pkmviewer::updategenderpic();
    void pkmviewer::updatemoveimages();
    void pkmviewer::updatemoveinfo();
    void pkmviewer::updatepkrs();
    void pkmviewer::updatehidpwr();
    void pkmviewer::updateribbons();
    void pkmviewer::egg_display(bool isegg);
#endif
    explicit pkmviewer(QWidget *parent = 0);
    ~pkmviewer();
private slots:
    void on_cbPKMItem_currentIndexChanged(int index);

    void on_sbLevel_valueChanged(int arg1);

    void on_btnSaveChanges_clicked();

    void on_btnExportPKMFile_clicked();

    void on_cbPKMSpecies_currentIndexChanged(int index);

    void on_sbSpecies_valueChanged(int arg1);

    void on_txtNickname_textChanged(const QString &arg1);

    void on_sbEXP_valueChanged(int arg1);

    void on_rbOTMale_toggled(bool checked);

    void on_rbOTFemale_toggled(bool checked);

    void on_cbNicknamed_toggled(bool checked);

    void on_txtOTName_textChanged(const QString &arg1);

    void on_sbTID_valueChanged(int arg1);

    void on_sbSID_valueChanged(int arg1);

    void on_sbHPIV_valueChanged(int arg1);

    void on_sbAtkIV_valueChanged(int arg1);

    void on_sbDefIV_valueChanged(int arg1);

    void on_sbSpAtkIV_valueChanged(int arg1);

    void on_sbSpDefIV_valueChanged(int arg1);

    void on_sbSpeedIV_valueChanged(int arg1);

    void on_sbHPEV_valueChanged(int arg1);

    void on_sbSpeedEV_valueChanged(int arg1);

    void on_sbSpDefEV_valueChanged(int arg1);

    void on_sbSpAtkEV_valueChanged(int arg1);

    void on_sbDefEV_valueChanged(int arg1);

    void on_sbAtkEV_valueChanged(int arg1);

    void on_cbNatures_currentIndexChanged(int index);

    void on_cbMove1_currentIndexChanged(int index);

    void on_cbMove2_currentIndexChanged(int index);

    void on_cbMove3_currentIndexChanged(int index);

    void on_cbMove4_currentIndexChanged(int index);

    void on_sbMove1PPUps_valueChanged(int arg1);

    void on_sbMove1PP_valueChanged(int arg1);

    void on_sbMove2PPUps_valueChanged(int arg1);

    void on_sbMove2PP_valueChanged(int arg1);

    void on_sbMove3PPUps_valueChanged(int arg1);

    void on_sbMove3PP_valueChanged(int arg1);

    void on_sbMove4PPUps_valueChanged(int arg1);

    void on_sbMove4PP_valueChanged(int arg1);

    void on_cbPKMAbility_currentIndexChanged(int index);

    void on_cbBall_currentIndexChanged(int index);

    void on_sbCurrentSlot_valueChanged(int value);

    void on_chkHex_toggled(bool checked);

    void on_cbForm_currentIndexChanged(int index);

    void on_chkMetAsEgg_toggled(bool checked);

    void on_chkNsPKM_toggled(bool checked);

    void on_chkFateful_toggled(bool checked);

    void on_sbMetLevel_valueChanged(int arg1);

    void on_cbMetLocation_currentIndexChanged(int index);

    void on_dtMetDate_dateChanged(const QDate &date);

    void on_cbEggLocation_currentIndexChanged(int index);

    void on_dtEggDate_dateChanged(const QDate &date);

    void on_cbHometown_currentIndexChanged(int index);

    void on_cbCountry_currentIndexChanged(int index);

    void on_sbPKRSStrain_valueChanged(int arg1);

    void on_sbPKRSDays_valueChanged(int arg1);

    void on_chkIsEgg_toggled(bool checked);

    void on_sbTameness_valueChanged(int arg1);

    void on_chkNicknamed_toggled(bool checked);

private:
    Ui::pkmviewer *ui;
};
#endif // PKMVIEWER_H
