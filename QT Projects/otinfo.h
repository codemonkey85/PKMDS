#ifndef OTINFO_H
#define OTINFO_H
#include <../../../PKMDS/include/pkmds/pkmds_g5.h>
#include <QDialog>

namespace Ui {
class OTInfo;
}

class OTInfo : public QDialog
{
    Q_OBJECT

public:
    explicit OTInfo(QWidget *parent = 0);
    ~OTInfo();
#if (defined __linux__) || (defined __APPLE__)
    void setSAV(bw2sav_obj * otinfosav_);
    void displayOTInfo();
#else
    void OTInfo::setSAV(bw2sav_obj * sav_);
    void OTInfo::displayOTInfo();
#endif
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_txtOTName_textChanged(const QString &arg1);

    void on_sbTID_valueChanged(int arg1);

    void on_sbSID_valueChanged(int arg1);

    void on_rbOTMale_toggled(bool checked);

    void on_rbOTFemale_toggled(bool checked);

private:
    Ui::OTInfo *ui;
};

#endif // OTINFO_H
