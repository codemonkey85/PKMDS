#include "otinfo.h"
#include "ui_otinfo.h"
bw2sav_obj * otinfosav = new bw2sav_obj();
bw2sav_obj * tempotinfosav = new bw2sav_obj();
bool otinforedisplayok = false;
OTInfo::OTInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OTInfo)
{
    ui->setupUi(this);
    ui->txtOTName->setMaxLength(OTLENGTH);
}
OTInfo::~OTInfo()
{
    delete ui;
}
void OTInfo::setSAV(bw2sav_obj * otinfosav_)
{
    otinfosav = otinfosav_;
    *(tempotinfosav) = *(otinfosav);
}
void OTInfo::on_buttonBox_accepted()
{
    *(otinfosav) = *(tempotinfosav);
}
void OTInfo::on_buttonBox_rejected()
{
    this->close();
}
void OTInfo::displayOTInfo()
{
    switch(tempotinfosav->cur.trainergender)
    {
    case Genders::male:
        ui->rbOTMale->setChecked(true);
        break;
    case Genders::female:
        ui->rbOTFemale->setChecked(true);
        break;
    default:
        ui->rbOTMale->setChecked(true);
        break;
    }

    ui->sbTID->setValue(tempotinfosav->cur.tid);
    ui->sbSID->setValue(tempotinfosav->cur.sid);
    QColor otcolor = Qt::blue;
    if(tempotinfosav->cur.trainergender == Genders::female)
    {
        otcolor = Qt::red;
    }
    QPalette OTpalette = ui->txtOTName->palette();
    OTpalette.setColor(ui->txtOTName->foregroundRole(), otcolor);
    ui->txtOTName->setPalette(OTpalette);
#if (defined __linux__) || (defined __APPLE__)
    ui->txtOTName->setText(QString::fromStdWString(getwstring((char*)tempotinfosav->cur.trainername, OTLENGTH*2)));
#else
    ui->txtOTName->setText(QString::fromStdWString(getwstring(tempotinfosav->cur.trainername)));
#endif
    otinforedisplayok = true;
}
void OTInfo::on_txtOTName_textChanged(const QString &arg1)
{
    if(otinforedisplayok)
    {
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
        for(int i = 0; i < arg1.length(); i++)
        {
            tempotinfosav->cur.trainername[2*i] = arg1[i].unicode();
        }
#else
        arg1.toWCharArray(tempotinfosav->cur.trainername);
#endif
#endif
        if(ui->txtOTName->text().length() < OTLENGTH)
        {
            byte * btpnt = new byte;
            btpnt = reinterpret_cast<byte*>(&(tempotinfosav->cur.trainername));
            memset(btpnt+(ui->txtOTName->text().length()*2),0xff,2);
            btpnt += (OTLENGTH*2)-2;
            memset(btpnt,0xff,2);
        }
    }
}

void OTInfo::on_sbTID_valueChanged(int arg1)
{
    if(otinforedisplayok)
    {
        tempotinfosav->cur.tid = arg1;
    }
}

void OTInfo::on_sbSID_valueChanged(int arg1)
{
    if(otinforedisplayok)
    {
        tempotinfosav->cur.sid = arg1;
    }
}

void OTInfo::on_rbOTMale_toggled(bool checked)
{
    if(otinforedisplayok)
    {
        if(checked)
        {
            tempotinfosav->cur.trainergender = Genders::male;
            QColor otcolor = Qt::blue;
            QPalette OTpalette = ui->txtOTName->palette();
            OTpalette.setColor(ui->txtOTName->foregroundRole(), otcolor);
            ui->txtOTName->setPalette(OTpalette);
        }
    }
}

void OTInfo::on_rbOTFemale_toggled(bool checked)
{
    if(otinforedisplayok)
    {
        if(checked)
        {
            tempotinfosav->cur.trainergender = Genders::female;
            QColor otcolor = Qt::red;
            QPalette OTpalette = ui->txtOTName->palette();
            OTpalette.setColor(ui->txtOTName->foregroundRole(), otcolor);
            ui->txtOTName->setPalette(OTpalette);
        }
    }
}
