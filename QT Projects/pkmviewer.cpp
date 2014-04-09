#include <QFileDialog>
#include "pkmviewer.h"
#include "ui_pkmviewer.h"
#include "frmboxes.h"
extern frmBoxes * boxViewer;
pkmviewer::pkmviewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pkmviewer)
{
    ui->setupUi(this);
    ui->txtNickname->setMaxLength(NICKLENGTH);
    ui->txtOTName->setMaxLength(OTLENGTH);
    mouseEventEater = new MouseEventEater(this);
    ui->sbCurrentSlot->setEnabled(false);
    ui->sbCurrentSlot->setVisible(false);
    markingsgraphics[(int)Markings::circle] = ui->pbCircle;
    markingsgraphics[(int)Markings::diamond] = ui->pbDiamond;
    markingsgraphics[(int)Markings::heart] = ui->pbHeart;
    markingsgraphics[(int)Markings::square] = ui->pbSquare;
    markingsgraphics[(int)Markings::star] = ui->pbStar;
    markingsgraphics[(int)Markings::triangle] = ui->pbTriangle;
    ribbonpix[0] = ui->pbRibbon_01;
    ribbonpix[1] = ui->pbRibbon_02;
    ribbonpix[2] = ui->pbRibbon_03;
    ribbonpix[3] = ui->pbRibbon_04;
    ribbonpix[4] = ui->pbRibbon_05;
    ribbonpix[5] = ui->pbRibbon_06;
    ribbonpix[6] = ui->pbRibbon_07;
    ribbonpix[7] = ui->pbRibbon_08;
    ribbonpix[8] = ui->pbRibbon_09;
    ribbonpix[9] = ui->pbRibbon_10;
    ribbonpix[10] = ui->pbRibbon_11;
    ribbonpix[11] = ui->pbRibbon_12;
    ribbonpix[12] = ui->pbRibbon_13;
    ribbonpix[13] = ui->pbRibbon_14;
    ribbonpix[14] = ui->pbRibbon_15;
    ribbonpix[15] = ui->pbRibbon_16;
    ribbonpix[16] = ui->pbRibbon_17;
    ribbonpix[17] = ui->pbRibbon_18;
    ribbonpix[18] = ui->pbRibbon_19;
    ribbonpix[19] = ui->pbRibbon_20;
    ribbonpix[20] = ui->pbRibbon_21;
    ribbonpix[21] = ui->pbRibbon_22;
    ribbonpix[22] = ui->pbRibbon_23;
    ribbonpix[23] = ui->pbRibbon_24;
    ribbonpix[24] = ui->pbRibbon_25;
    ribbonpix[25] = ui->pbRibbon_26;
    ribbonpix[26] = ui->pbRibbon_27;
    ribbonpix[27] = ui->pbRibbon_28;
    ribbonpix[28] = ui->pbRibbon_29;
    ribbonpix[29] = ui->pbRibbon_30;
    ribbonpix[30] = ui->pbRibbon_31;
    ribbonpix[31] = ui->pbRibbon_32;
    ribbonpix[32] = ui->pbRibbon_33;
    ribbonpix[33] = ui->pbRibbon_34;
    ribbonpix[34] = ui->pbRibbon_35;
    ribbonpix[35] = ui->pbRibbon_36;
    ribbonpix[36] = ui->pbRibbon_37;
    ribbonpix[37] = ui->pbRibbon_38;
    ribbonpix[38] = ui->pbRibbon_39;
    ribbonpix[39] = ui->pbRibbon_40;
    ribbonpix[40] = ui->pbRibbon_41;
    ribbonpix[41] = ui->pbRibbon_42;
    ribbonpix[42] = ui->pbRibbon_43;
    ribbonpix[43] = ui->pbRibbon_44;
    ribbonpix[44] = ui->pbRibbon_45;
    ribbonpix[45] = ui->pbRibbon_46;
    ribbonpix[46] = ui->pbRibbon_47;
    ribbonpix[47] = ui->pbRibbon_48;
    ribbonpix[48] = ui->pbRibbon_49;
    ribbonpix[49] = ui->pbRibbon_50;
    ribbonpix[50] = ui->pbRibbon_51;
    ribbonpix[51] = ui->pbRibbon_52;
    ribbonpix[52] = ui->pbRibbon_53;
    ribbonpix[53] = ui->pbRibbon_54;
    ribbonpix[54] = ui->pbRibbon_55;
    ribbonpix[55] = ui->pbRibbon_56;
    ribbonpix[56] = ui->pbRibbon_57;
    ribbonpix[57] = ui->pbRibbon_58;
    ribbonpix[58] = ui->pbRibbon_59;
    ribbonpix[59] = ui->pbRibbon_60;
    ribbonpix[60] = ui->pbRibbon_61;
    ribbonpix[61] = ui->pbRibbon_62;
    ribbonpix[62] = ui->pbRibbon_63;
    ribbonpix[63] = ui->pbRibbon_64;
    ribbonpix[64] = ui->pbRibbon_65;
    ribbonpix[65] = ui->pbRibbon_66;
    ribbonpix[66] = ui->pbRibbon_67;
    ribbonpix[67] = ui->pbRibbon_68;
    ribbonpix[68] = ui->pbRibbon_69;
    ribbonpix[69] = ui->pbRibbon_70;
    ribbonpix[70] = ui->pbRibbon_71;
    ribbonpix[71] = ui->pbRibbon_72;
    ribbonpix[72] = ui->pbRibbon_73;
    ribbonpix[73] = ui->pbRibbon_74;
    ribbonpix[74] = ui->pbRibbon_75;
    ribbonpix[75] = ui->pbRibbon_76;
    ribbonpix[76] = ui->pbRibbon_77;
    ribbonpix[77] = ui->pbRibbon_78;
    ribbonpix[78] = ui->pbRibbon_79;
    ribbonpix[79] = ui->pbRibbon_80;
    for(int i = 0; i < 6; i++)
    {
        markingspix[i] = getmarkingimage(Markings::markings(i), false);
        markingsscene[i] = new QGraphicsScene();
        markingsscene[i]->addPixmap(markingspix[i]);
        markingsscene[i]->installEventFilter(mouseEventEater);
        markingsgraphics[i]->setScene(markingsscene[i]);
        markingsgraphics[i]->installEventFilter(mouseEventEater);
    }
    QComboBox * moveboxes[4] = {ui->cbMove1,ui->cbMove2,ui->cbMove3,ui->cbMove4};
    QString itemname = "";
    for(int itemindex = 0; itemindex <= (int)Items::revealglass; itemindex++)
    {
        itemname = QString::fromStdString(lookupitemname(itemindex));
        if(((itemindex >= (int)Items::tm01) & (itemindex <= (int)Items::tm92)) |
                ((itemindex >= (int)Items::tm93) & (itemindex <= (int)Items::tm95)) |
                ((itemindex >= (int)Items::hm01) & (itemindex <= (int)Items::hm06)))
        {
            itemname += QString::fromStdString(" (" + getmachinemovename(Items::items(itemindex)) + ")");
        }
        if((itemname != "") | (itemindex == 0))
        {
            ui->cbPKMItem->addItem(itemname,itemindex);
        }
    }
    for(int speciesindex = 1; speciesindex < 650; speciesindex++)
    {
        itemname = QString::fromStdString(lookuppkmname(speciesindex));
        ui->cbPKMSpecies->addItem(itemname);
    }
    for(int natureindex = 0; natureindex < 25; natureindex++)
    {
        itemname = QString::fromStdString(getnaturename(natureindex));
        ui->cbNatures->addItem(itemname);
    }
    for(int moveid = 0; moveid <= ((int)Moves::fusionbolt); moveid++)
    {
        for(int moveindex = 0; moveindex < 4; moveindex++)
        {
            itemname = QString::fromStdString(lookupmovename(moveid));
            if(!((moveindex == 0) & (itemname == "")))
                moveboxes[moveindex]->addItem(itemname);
        }
    }
    for(int ballnum = 1; ballnum <= (int)Balls::dreamball; ballnum++)
    {
        ui->cbBall->addItem("");
        if((Balls::balls)ballnum != Balls::pokeball_)
        {
            ui->cbBall->setItemIcon((ballnum-1),getballpic((Balls::balls)ballnum));
        }
    }
    for(int abilityindex = 1; abilityindex <= (int)Abilities::teravolt; abilityindex++)
    {
        itemname = QString::fromStdString(lookupabilityname(abilityindex));
        ui->cbPKMAbility->addItem(itemname);
    }
    for(int locationindex = 0; locationindex <= (int)Locations::pledgegrove; locationindex++)
    {
        itemname = QString::fromStdString(lookuplocname(locationindex));
        if(itemname != "")
        {
            ui->cbMetLocation->addItem(itemname,locationindex);
            ui->cbEggLocation->addItem(itemname,locationindex);
        }
    }
    ui->cbMetLocation->addItem("Day-Care Couple (IV)",2000);
    ui->cbEggLocation->addItem("Day-Care Couple (IV)",2000);
    ui->cbMetLocation->addItem("Poké Transfer",30001);
    ui->cbEggLocation->addItem("Poké Transfer",30001);
    ui->cbMetLocation->addItem("Pokémon Dream Radar",30015);
    ui->cbEggLocation->addItem("Pokémon Dream Radar",30015);
    ui->cbMetLocation->addItem("Lovely Place",40001);
    ui->cbEggLocation->addItem("Lovely Place",40001);
    ui->cbMetLocation->addItem("Day-Care Couple",60002);
    ui->cbEggLocation->addItem("Day-Care Couple",60002);
    ui->cbHometown->addItem("Colosseum Bonus",0);
    ui->cbHometown->addItem("Sapphire",1);
    ui->cbHometown->addItem("Ruby",2);
    ui->cbHometown->addItem("Emerald",3);
    ui->cbHometown->addItem("FireRed",4);
    ui->cbHometown->addItem("LeafGreen",5);
    ui->cbHometown->addItem("HeartGold",7);
    ui->cbHometown->addItem("SoulSilver",8);
    ui->cbHometown->addItem("Diamond",10);
    ui->cbHometown->addItem("Pearl",11);
    ui->cbHometown->addItem("Platinum",12);
    ui->cbHometown->addItem("Colosseum / XD",15);
    ui->cbHometown->addItem("White",20);
    ui->cbHometown->addItem("Black",21);
    ui->cbHometown->addItem("White 2",22);
    ui->cbHometown->addItem("Black 2",23);
    ui->cbCountry->addItem("JA", 1);
    ui->cbCountry->addItem("ENG/UK/AUS", 2);
    ui->cbCountry->addItem("FR", 3);
    ui->cbCountry->addItem("ITA", 4);
    ui->cbCountry->addItem("DE", 5);
    ui->cbCountry->addItem("SPA", 7);
    ui->cbCountry->addItem("SOK", 8);
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->setMinimumSize(this->size());
    this->setMaximumSize(this->size());
    this->setSizeGripEnabled(false);
}
// Need to clean this up and figure out what goes where
bool levelchangeok = true;
bool redisplayok = false;
pokemon_obj * temppkm = new pokemon_obj;
pokemon_obj * pkm = new pokemon_obj;
party_pkm * ppkm = new party_pkm;
bool ispartypkm = false;
extern void * theSlot;
extern int frmCurBoxNum;
extern bw2savblock_obj * cursavblock;
extern int frmCurSlotNum;
int startbox = 0;
void pkmviewer::setPKM(pokemon_obj * pkm_, int box, bool isPartyPKM)
{
    startbox = box;
    pkm = pkm_;
    *temppkm = *pkm;
    redisplayok = false;
    ispartypkm = isPartyPKM;
    if(ispartypkm)
    {
        ui->sbCurrentSlot->setMaximum(5);
        ui->sbCurrentSlot->setPageStep(2);
    }
    else
    {
        ui->sbCurrentSlot->setMaximum(29);
        ui->sbCurrentSlot->setPageStep(6);
    }
    ui->sbCurrentSlot->setValue(frmCurSlotNum);
}
void pkmviewer::displayPKM(/*bool rename*/)
{
    //    temppkm->form = 0;
    redisplayok = false;
    int index = 0;
    this->setWindowTitle(QString::fromStdWString(getpkmnickname(temppkm)));
    switch(temppkm->otgender)
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
    ui->sbTID->setValue(temppkm->tid);
    ui->sbSID->setValue(temppkm->sid);
    ui->cbPKMSpecies->setCurrentIndex(temppkm->species_int-1);
    ui->sbSpecies->setValue(temppkm->species_int);
    //    ui->cbPKMItem->setCurrentIndex((int)temppkm->item);
    index = ui->cbPKMItem->findData((int)temppkm->item);
    if ( index != -1 ) { // -1 for not found
        ui->cbPKMItem->setCurrentIndex(index);
    }
    ui->sbLevel->setValue(getpkmlevel(temppkm));
    ui->sbEXP->setMaximum(getpkmexpatlevel(temppkm->species,100));
    ui->sbEXP->setValue(temppkm->exp);
    int tnl = getpkmexptonext(temppkm);
    if(tnl == 0)
    {
        ui->pbTNL->setMinimum(0);
        ui->pbTNL->setMaximum(1);
        ui->pbTNL->setValue(0);
        ui->pbTNL->setTextVisible(false);
    }
    else
    {
        ui->pbTNL->setMinimum(getpkmexpatcur(temppkm));
        ui->pbTNL->setMaximum(tnl + temppkm->exp);
        ui->pbTNL->setValue(temppkm->exp);
        ui->pbTNL->setTextVisible(true);
    }
    ui->lblTNL->setText(QString::number(getpkmexptonext(temppkm)));
    ui->txtNickname->setText(QString::fromStdWString(getpkmnickname(temppkm)));
    //    if(rename)
    //    {
    QColor otcolor = Qt::blue;
    if(temppkm->otgender == Genders::female)
    {
        otcolor = Qt::red;
    }
    QPalette OTpalette = ui->txtOTName->palette();
    OTpalette.setColor(ui->txtOTName->foregroundRole(), otcolor);
    ui->txtOTName->setPalette(OTpalette);
    ui->txtOTName->setText(QString::fromStdWString(getpkmotname(temppkm)));
    //    }
    ui->chkNicknamed->setChecked(temppkm->isnicknamed);
    QPixmap * itempix = new QPixmap();
    QGraphicsScene * itemscene = new QGraphicsScene();
    *itempix = getitemimage(temppkm->item);
    itemscene->addPixmap(*itempix);
    ui->pbHeldItem->setScene(itemscene);
    QPixmap * type1pix = new QPixmap();
    QGraphicsScene * type1scene = new QGraphicsScene();
    *type1pix = gettypepic(lookuppkmtype(temppkm,1));
    type1scene->addPixmap(*type1pix);
    ui->pbType1->setScene(type1scene);
    int pkmtype2 = 0;
    pkmtype2 = lookuppkmtype(temppkm,2);
    QPixmap * type2pix = new QPixmap();
    QGraphicsScene * type2scene = new QGraphicsScene();
    if(pkmtype2 != -1)
    {
        *type2pix = gettypepic(lookuppkmtype(temppkm,2));
    }
    type2scene->addPixmap(*type2pix);
    ui->pbType2->setScene(type2scene);
    QPixmap * shinypix = new QPixmap();
    QGraphicsScene * shinyscene = new QGraphicsScene();
    if(getpkmshiny(temppkm))
    {
        *shinypix = getshinystar();
    }
    shinyscene->addPixmap(*shinypix);
    ui->pbShiny->setScene(shinyscene);
    QPixmap * spritepixmap = new QPixmap();
    QGraphicsScene * spritescene = new QGraphicsScene();
    *spritepixmap = getpkmsprite(temppkm);
    spritescene->addPixmap(*spritepixmap);
    ui->pbSprite->setScene(spritescene);
    ui->cbBall->setCurrentIndex(((int)temppkm->ball)-1);
    ui->sbHPIV->setValue(temppkm->ivs.hp);
    ui->sbAtkIV->setValue(temppkm->ivs.attack);
    ui->sbDefIV->setValue(temppkm->ivs.defense);
    ui->sbSpAtkIV->setValue(temppkm->ivs.spatk);
    ui->sbSpDefIV->setValue(temppkm->ivs.spdef);
    ui->sbSpeedIV->setValue(temppkm->ivs.speed);
    ui->sbHPEV->setValue(temppkm->evs.hp);
    ui->sbAtkEV->setValue(temppkm->evs.attack);
    ui->sbDefEV->setValue(temppkm->evs.defense);
    ui->sbSpAtkEV->setValue(temppkm->evs.spatk);
    ui->sbSpDefEV->setValue(temppkm->evs.spdef);
    ui->sbSpeedEV->setValue(temppkm->evs.speed);
    ui->cbNatures->setCurrentIndex(temppkm->nature);
    ui->cbMove1->setCurrentIndex(((int)temppkm->moves[0])-1);
    ui->cbMove2->setCurrentIndex((int)temppkm->moves[1]);
    ui->cbMove3->setCurrentIndex((int)temppkm->moves[2]);
    ui->cbMove4->setCurrentIndex((int)temppkm->moves[3]);
    ui->cbPKMAbility->setCurrentIndex(((int)temppkm->ability)-1);
    ui->sbPKRSDays->setValue(temppkm->pkrs.days);
    ui->sbPKRSStrain->setValue(temppkm->pkrs.strain);
    QSpinBox * movePPboxes[4] = {ui->sbMove1PP,ui->sbMove2PP,ui->sbMove3PP,ui->sbMove4PP};
    QSpinBox * movePPUpboxes[4] = {ui->sbMove1PPUps,ui->sbMove2PPUps,ui->sbMove3PPUps,ui->sbMove4PPUps};
    for(int movenum = 0; movenum < 4; movenum++)
    {
        movePPboxes[movenum]->setValue(temppkm->pp[movenum]);
        movePPUpboxes[movenum]->setValue(temppkm->ppup[movenum]);
    }
    int base = 10;
    if(ui->chkHex->isChecked())
    {
        base = 16;
    }
    ui->txtPID->setText(QString::number(temppkm->pid,base).toUpper());
    ui->chkNsPKM->setChecked(temppkm->n_pkm);
    ui->chkFateful->setChecked(temppkm->fencounter);
    ui->sbMetLevel->setValue((int)temppkm->metlevel);
    index = ui->cbHometown->findData((int)temppkm->hometown);
    if ( index != -1 ) { // -1 for not found
        ui->cbHometown->setCurrentIndex(index);
    }
    index = ui->cbCountry->findData((int)temppkm->country);
    if ( index != -1 ) { // -1 for not found
        ui->cbCountry->setCurrentIndex(index);
    }
    index = ui->cbMetLocation->findData((int)temppkm->met);
    if ( index != -1 ) { // -1 for not found
        ui->cbMetLocation->setCurrentIndex(index);
    }
    index = ui->cbEggLocation->findData((int)temppkm->eggmet);
    if ( index != -1 ) { // -1 for not found
        ui->cbEggLocation->setCurrentIndex(index);
    }
    ui->dtEggDate->setDate(QDate(((int)temppkm->eggdate.year)+2000,(int)temppkm->eggdate.month,(int)temppkm->eggdate.day));
    ui->dtMetDate->setDate(QDate(((int)temppkm->metdate.year)+2000,(int)temppkm->metdate.month,(int)temppkm->metdate.day));
    ui->cbForm->clear();
    switch(temppkm->species)
    {
    case Species::castform:
        ui->cbForm->addItem("");
        break;
    case Species::rotom:
        ui->cbForm->addItem("");
        break;
    case Species::kyurem:
        ui->cbForm->addItem("");
        break;
    case Species::genesect:
        ui->cbForm->addItem("");
        break;
    default:
        break;
    }
    for(int formid = 0; formid < 28; formid++)
    {
        std::string formname = getpkmformname((int)temppkm->species,formid);
        if(formname != "")
        {
            ui->cbForm->addItem(QString::fromStdString(formname));
        }
    }
    ui->cbForm->setEnabled(ui->cbForm->count() > 0);
    ui->cbForm->setCurrentIndex((int)temppkm->form_int);
    ui->sbTameness->setValue(int(temppkm->tameness));
    updateribbons();
    ui->chkMetAsEgg->setChecked(pkmmetasegg(temppkm));
    ui->cbEggLocation->setEnabled(ui->chkMetAsEgg->isChecked());
    ui->dtEggDate->setEnabled(ui->chkMetAsEgg->isChecked());
    ui->chkIsEgg->setChecked(temppkm->isegg);
    redisplayok = true;
    updatepkrs();
    updategenderpic();
    updateabilityflavor();
    updatemarks();
    updatestats();
    updatestatcolors();
    updatemoveflavor();
    updatemovepp();
    updatemoveimages();
    updatemoveinfo();
    updatehidpwr();
    egg_display(temppkm->isegg);
}
void pkmviewer::updatestats()
{
    if(redisplayok)
    {
        ui->sbTotalEVs->setValue
                (
                    temppkm->evs.hp +
                    temppkm->evs.attack +
                    temppkm->evs.defense +
                    temppkm->evs.spatk +
                    temppkm->evs.spdef +
                    temppkm->evs.speed
                    );
        ui->sbHP->setValue(getpkmstat(temppkm,Stat_IDs::hp));
        ui->sbAtk->setValue(getpkmstat(temppkm,Stat_IDs::attack));
        ui->sbDef->setValue(getpkmstat(temppkm,Stat_IDs::defense));
        ui->sbSpAtk->setValue(getpkmstat(temppkm,Stat_IDs::spatk));
        ui->sbSpDef->setValue(getpkmstat(temppkm,Stat_IDs::spdef));
        ui->sbSpeed->setValue(getpkmstat(temppkm,Stat_IDs::speed));

        std::string thechar = lookupcharacteristic(temppkm);

        ui->lblCharacteristic->setText(QString::fromStdString(lookupcharacteristic(temppkm)));
    }
}
void pkmviewer::updatestatcolors()
{
    if(redisplayok)
    {
        QLabel * statlbls[6] =
        {
            ui->lblHPIV,
            ui->lblAtkIV,
            ui->lblDefIV,
            ui->lblSpAtkIV,
            ui->lblSpDefIV,
            ui->lblSpeedIV
        };
        QColor statcolor;
        int incr = 0;
        int decr = 0;
        for(int i = 0; i < 6; i++)
        {
            statcolor = Qt::black;
            incr = getnatureincrease(temppkm)-1;
            decr = getnaturedecrease(temppkm)-1;

            if(incr == i)
            {
                if(decr == i)
                {
                    statcolor = Qt::black;
                }
                else
                {
                    statcolor = Qt::red;
                }
            }
            if(decr == i)
            {
                if(incr == i)
                {
                    statcolor = Qt::black;
                }
                else
                {
                    statcolor = Qt::blue;
                }
            }
            QPalette statpalette = statlbls[i]->palette();
            statpalette.setColor(statlbls[i]->foregroundRole(), statcolor);
            statlbls[i]->setPalette(statpalette);
        }
    }
}
void pkmviewer::updatemarks()
{
    if(redisplayok)
    {
        for(int i = 0; i < 6; i++)
        {
            bool marked = false;
            switch(Markings::markings(i))
            {
            case Markings::circle:
                marked = temppkm->markings.circle;
                break;
            case Markings::diamond:
                marked = temppkm->markings.diamond;
                break;
            case Markings::heart:
                marked = temppkm->markings.heart;
                break;
            case Markings::square:
                marked = temppkm->markings.square;
                break;
            case Markings::star:
                marked = temppkm->markings.star;
                break;
            case Markings::triangle:
                marked = temppkm->markings.triangle;
                break;
            default:
                marked = false;
                break;
            }
            markingspix[i] = getmarkingimage(Markings::markings(i), marked);
            markingsscene[i] = new QGraphicsScene();
            markingsscene[i]->addPixmap(markingspix[i]);
            markingsscene[i]->installEventFilter(mouseEventEater);
            markingsgraphics[i]->setScene(markingsscene[i]);
            markingsgraphics[i]->installEventFilter(mouseEventEater);
            //        extmarkingsgraphics[i] = markingsgraphics[i];
            //        extmarkingspix[i] = markingspix[i];
            //        extmarkingsscene[i] = markingsscene[i];
        }
    }
}
void pkmviewer::updatemovepp()
{
    if(redisplayok)
    {
        QSpinBox * moveTotalPPboxes[4] = {ui->sbMove1TotalPP,ui->sbMove2TotalPP,ui->sbMove3TotalPP,ui->sbMove4TotalPP};
        QSpinBox * movePPboxes[4] = {ui->sbMove1PP,ui->sbMove2PP,ui->sbMove3PP,ui->sbMove4PP};
        int curppval = 0;
        for(int movenum = 0; movenum < 4; movenum++)
        {
            curppval = getmovetotalpp(temppkm,movenum);
            moveTotalPPboxes[movenum]->setValue(curppval);
            movePPboxes[movenum]->setValue(curppval);
        }
    }
}
void pkmviewer::updatemoveimages()
{
    if(redisplayok)
    {
        QGraphicsView * movetypegraphics[4] = {ui->pbMove1Type,ui->pbMove2Type,ui->pbMove3Type,ui->pbMove4Type};
        QGraphicsView * movecatgraphics[4] = {ui->pbMove1Cat,ui->pbMove2Cat,ui->pbMove3Cat,ui->pbMove4Cat};
        QPixmap * movepix = new QPixmap();
        QGraphicsScene * movescene = new QGraphicsScene();
        for(int movenum = 0; movenum < 4; movenum++)
        {
            movepix = new QPixmap();
            movescene = new QGraphicsScene();
            if(temppkm->moves[movenum] != Moves::NOTHING)
            {
                *movepix = gettypepic((int)(getmovetype(temppkm->moves[movenum])));
            }
            movescene->addPixmap(*movepix);
            movetypegraphics[movenum]->setScene(movescene);

            movepix = new QPixmap();
            movescene = new QGraphicsScene();
            if(temppkm->moves[movenum] != Moves::NOTHING)
            {
                *movepix = getmovecatimage(temppkm->moves[movenum]);
            }
            movescene->addPixmap(*movepix);
            movecatgraphics[movenum]->setScene(movescene);

        }
    }
}
void pkmviewer::updatemoveinfo()
{
    if(redisplayok)
    {
        QLabel * lblPower[4] = {ui->lblMove1Power,ui->lblMove2Power,ui->lblMove3Power,ui->lblMove4Power};
        QLabel * lblAccuracy[4] = {ui->lblMove1Accuracy,ui->lblMove2Accuracy, ui->lblMove3Accuracy,ui->lblMove4Accuracy};
        for(int movenum = 0; movenum < 4; movenum++)
        {
            if(temppkm->moves[movenum] != Moves::NOTHING)
            {
                lblPower[movenum]->setText(QString::number(getmovepower(temppkm->moves[movenum])));
                lblAccuracy[movenum]->setText(QString::number(getmoveaccuracy(temppkm->moves[movenum])));
            }
            else
            {
                lblPower[movenum]->setText("");
                lblAccuracy[movenum]->setText("");
            }
        }
    }
}
void pkmviewer::updatemoveflavor()
{
    if(redisplayok)
    {
        QLabel * lblFlavors[4] = {ui->lblMove1Flavor,ui->lblMove2Flavor,ui->lblMove3Flavor,ui->lblMove4Flavor};
        std::string flavor = "";
        for(int movenum = 0; movenum < 4; movenum++)
        {
            if(temppkm->moves[movenum] != Moves::NOTHING)
            {
                flavor = lookupmoveflavortext(temppkm,movenum);
                lblFlavors[movenum]->setText(QString::fromStdString(flavor));
            }
            else
            {
                lblFlavors[movenum]->setText("");
            }
        }
    }
}
void pkmviewer::updateabilityflavor()
{
    if(redisplayok)
    {
        ui->lblAbilityFlavor->setText(QString::fromStdString(lookupabilityflavortext(temppkm->ability)));
    }
}
void pkmviewer::updategenderpic()
{
    QPixmap * genderpix = new QPixmap();
    QGraphicsScene * genderscene = new QGraphicsScene();
    Genders::genders thegender = calcpkmgender(temppkm);
    if((thegender == Genders::male) || (thegender == Genders::female))
    {
        *genderpix = getgenderpic(thegender);
    }
    genderscene->addPixmap(*genderpix);
    ui->pbGender->setScene(genderscene);

}
void pkmviewer::updatepkrs()
{
    QPixmap * pkrspix = new QPixmap();
    QGraphicsScene * pkrsscene = new QGraphicsScene();
    *pkrspix = getpkrsimage(temppkm->pkrs);
    pkrsscene->addPixmap(*pkrspix);
    ui->pbPkrs->setScene(pkrsscene);
}
void pkmviewer::updatehidpwr()
{
    QPixmap * hptypepix = new QPixmap();
    QGraphicsScene * hptypescene = new QGraphicsScene();
    *hptypepix = gettypepic(gethiddenpowertype(temppkm));
    hptypescene->addPixmap(*hptypepix);
    ui->pbHPType->setScene(hptypescene);
    ui->sbHPPower->setValue(gethiddenpowerpower(temppkm));
}
void pkmviewer::updateribbons()
{
    int ribcount = 0;
    std::array<bool, 80> switches = getribbonswitches(temppkm);
    for(int i = 0; i < 80; i++)
    {
        QPixmap * ribpix = new QPixmap();
        QGraphicsScene * ribscene = new QGraphicsScene();
        if(switches[i])
        {
            *ribpix = getribbonimg(ribbon_identifiers[i],i>47);
            ribcount++;
        }
        ribscene->addPixmap(*ribpix);
        ribbonpix[i]->setScene(ribscene);
    }
    ui->sbRibbonCount->setValue(ribcount);
}
void pkmviewer::egg_display(bool isegg)
{
    if(redisplayok)
    {
        if(isegg)
        {
            ui->lblTameness->setText("Hatch cycles");
            ui->txtSteps->setText(QString::number(int(temppkm->tameness) * 255));
        }
        else
        {
            ui->lblTameness->setText("Tameness");
        }
        ui->dtMetDate->setEnabled(!isegg);
        ui->cbMetLocation->setEnabled(!isegg);
        ui->dtEggDate->setEnabled(isegg | ui->chkMetAsEgg->isChecked());
        ui->cbEggLocation->setEnabled(isegg | ui->chkMetAsEgg->isChecked());
        ui->lblEggSteps->setVisible(isegg);
        ui->txtSteps->setVisible(isegg);
        ui->txtNickname->setEnabled(!isegg);
        ui->sbTID->setEnabled(!isegg);
        ui->sbSID->setEnabled(!isegg);
        ui->rbOTFemale->setEnabled(!isegg);
        ui->rbOTMale->setEnabled(!isegg);
        ui->sbEXP->setEnabled(!isegg);
        ui->sbLevel->setEnabled(!isegg);
        ui->cbPKMItem->setEnabled(!isegg);
        ui->sbHPEV->setEnabled(!isegg);
        ui->sbHP->setEnabled(!isegg);
        ui->sbAtkEV->setEnabled(!isegg);
        ui->sbAtk->setEnabled(!isegg);
        ui->sbDefEV->setEnabled(!isegg);
        ui->sbDef->setEnabled(!isegg);
        ui->sbSpAtkEV->setEnabled(!isegg);
        ui->sbSpAtk->setEnabled(!isegg);
        ui->sbSpDefEV->setEnabled(!isegg);
        ui->sbSpDef->setEnabled(!isegg);
        ui->sbSpeedEV->setEnabled(!isegg);
        ui->sbSpeed->setEnabled(!isegg);
        ui->sbMove1PP->setEnabled(!isegg);
        ui->sbMove1PPUps->setEnabled(!isegg);
        ui->sbMove1TotalPP->setEnabled(!isegg);
        ui->sbMove2PP->setEnabled(!isegg);
        ui->sbMove2PPUps->setEnabled(!isegg);
        ui->sbMove2TotalPP->setEnabled(!isegg);
        ui->sbMove3PP->setEnabled(!isegg);
        ui->sbMove3PPUps->setEnabled(!isegg);
        ui->sbMove3TotalPP->setEnabled(!isegg);
        ui->sbMove4PP->setEnabled(!isegg);
        ui->sbMove4PPUps->setEnabled(!isegg);
        ui->sbMove4TotalPP->setEnabled(!isegg);
        ui->sbMetLevel->setEnabled(!isegg);
        ui->chkMetAsEgg->setEnabled(!isegg);
        ui->txtOTName->setEnabled(!isegg);
        ui->chkNicknamed->setEnabled(!isegg);
        ui->cbBall->setEnabled(!isegg);
        ui->chkFateful->setEnabled(!isegg);
        ui->chkNsPKM->setEnabled(!isegg);
        //        if(isegg)
        //        {
        //            ui->chkMetAsEgg->setChecked(false);
        //        }
        //        else
        //        {
        //
        //        }
        //ui->chkMetAsEgg->setChecked(isegg);
        QPixmap * spritepixmap = new QPixmap();
        QGraphicsScene * spritescene = new QGraphicsScene();
        *spritepixmap = getpkmsprite(temppkm);
        spritescene->addPixmap(*spritepixmap);
        ui->pbSprite->setScene(spritescene);
    }
}
pkmviewer::~pkmviewer()
{
    delete ui;
}
void pkmviewer::on_cbPKMItem_currentIndexChanged(int index)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        temppkm->item_int = ui->cbPKMItem->itemData(index).toInt();
        if(redisplayok)
        {
            switch(temppkm->species)
            {
            case Species::giratina:
                if((Items::items)(ui->cbPKMItem->itemData(index).toInt()) == Items::griseousorb)
                {
                    temppkm->form.giratina_form = Forms::Giratina::origin;
                    if(!(temppkm->hasdwability))
                    {
                        temppkm->ability = Abilities::levitate;
                    }
                }
                else
                {
                    temppkm->form_int = 0;
                    if(!(temppkm->hasdwability))
                    {
                        temppkm->ability = Abilities::pressure;
                    }
                }
                break;
            case Species::genesect:
                switch((Items::items)(ui->cbPKMItem->itemData(index).toInt()))
                {
                case Items::burndrive:
                    temppkm->form.genesect_form = Forms::Genesect::burn;
                    break;
                case Items::dousedrive:
                    temppkm->form.genesect_form = Forms::Genesect::douse;
                    break;
                case Items::shockdrive:
                    temppkm->form.genesect_form = Forms::Genesect::shock;
                    break;
                case Items::chilldrive:
                    temppkm->form.genesect_form = Forms::Genesect::chill;
                    break;
                default:
                    temppkm->form_int = 0;
                }
                break;
            case Species::arceus:
                switch((Items::items)(ui->cbPKMItem->itemData(index).toInt()))
                {
                case Items::dracoplate:
                    temppkm->form.arceus_form = Forms::Arceus::draco;
                    break;
                case Items::dreadplate:
                    temppkm->form.arceus_form = Forms::Arceus::dread;
                    break;
                case Items::earthplate:
                    temppkm->form.arceus_form = Forms::Arceus::earth;
                    break;
                case Items::fistplate:
                    temppkm->form.arceus_form = Forms::Arceus::fist;
                    break;
                case Items::flameplate:
                    temppkm->form.arceus_form = Forms::Arceus::flame;
                    break;
                case Items::icicleplate:
                    temppkm->form.arceus_form = Forms::Arceus::icicle;
                    break;
                case Items::insectplate:
                    temppkm->form.arceus_form = Forms::Arceus::insect;
                    break;
                case Items::ironplate:
                    temppkm->form.arceus_form = Forms::Arceus::iron;
                    break;
                case Items::meadowplate:
                    temppkm->form.arceus_form = Forms::Arceus::meadow;
                    break;
                case Items::mindplate:
                    temppkm->form.arceus_form = Forms::Arceus::mind;
                    break;
                case Items::skyplate:
                    temppkm->form.arceus_form = Forms::Arceus::sky;
                    break;
                case Items::splashplate:
                    temppkm->form.arceus_form = Forms::Arceus::splash;
                    break;
                case Items::spookyplate:
                    temppkm->form.arceus_form = Forms::Arceus::spooky;
                    break;
                case Items::stoneplate:
                    temppkm->form.arceus_form = Forms::Arceus::stone;
                    break;
                case Items::toxicplate:
                    temppkm->form.arceus_form = Forms::Arceus::toxic;
                    break;
                case Items::zapplate:
                    temppkm->form.arceus_form = Forms::Arceus::zap;
                    break;
                default:
                    temppkm->form_int = 0;
                    break;
                }
                break;
            default:
                break;
            }
            pkmviewer::displayPKM(/*false*/);
        }
    }
}
void pkmviewer::on_sbLevel_valueChanged(int arg1)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(levelchangeok)
        {
            ui->sbEXP->setValue(getpkmexpatlevel(temppkm->species,arg1));
        }
    }
}
void pkmviewer::on_btnSaveChanges_clicked()
{
    calcchecksum(temppkm);
    *pkm = *temppkm;
    if(getpkmformname(pkm) == "")
    {
        pkm->form_int = 0;
    }
    this->setWindowTitle(QString::fromStdWString(getpkmnickname(temppkm)));
    if((frmCurBoxNum == startbox) || ispartypkm)
    {
        QPixmap * iconpixmap = new QPixmap();
        QGraphicsScene * iconscene = new QGraphicsScene();
        *iconpixmap = getpkmicon(temppkm);
        iconscene->addPixmap(*iconpixmap);
        QGraphicsView * theView = new QGraphicsView;
        theView = (QGraphicsView*)theSlot;
        theView->setScene(iconscene);
        boxViewer->refreshboxgrids();
    }
    if(redisplayok)
    {
        pkmviewer::displayPKM(/*false*/);
    }
}
void pkmviewer::on_btnExportPKMFile_clicked()
{
    pokemon_obj * pkmout = new pokemon_obj;
    *pkmout = *temppkm;
    if(getpkmformname(pkmout) == "")
    {
        pkmout->form_int = 0;
    }
    std::string PKMFileName = "";
    PKMFileName = (QFileDialog::getSaveFileName(this,tr("Save a PKM file"),tr(""),tr("PKM Files (*.pkm)"))).toStdString();
    if(PKMFileName != "")
    {
        calcchecksum(pkmout);
        write(PKMFileName.c_str(),pkmout);
    }
}
void pkmviewer::on_cbPKMSpecies_currentIndexChanged(int index)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(redisplayok)
        {
            temppkm->species = (Species::species)(index+1);
            setpkmgender(temppkm,(int)calcpkmgender(temppkm));
            updategenderpic();
            if((index+1) != ui->sbSpecies->value())
            {
                ui->sbSpecies->setValue(index+1);
            }
            pkmviewer::displayPKM(/*false*/);
        }
    }
}
void pkmviewer::on_sbSpecies_valueChanged(int arg1)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(redisplayok)
        {
            if((arg1-1) != ui->cbPKMSpecies->currentIndex())
            {
                ui->cbPKMSpecies->setCurrentIndex(arg1-1);
            }
        }
    }
}
void pkmviewer::on_txtNickname_textChanged(const QString &arg1)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(redisplayok)
        {
            ui->chkNicknamed->setChecked(true);
            temppkm->isnicknamed = 1;
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
            for(int i = 0; i < arg1.length(); i++)
            {
                temppkm->nickname[2*i] = arg1[i].unicode();//.toAscii();//.toLatin1();
            }
#else
            arg1.toWCharArray(temppkm->nickname);
#endif
#endif
            if(ui->txtNickname->text().length() < NICKLENGTH)
            {
                byte * btpnt = new byte;
                btpnt = reinterpret_cast<byte*>(&(temppkm->nickname));
                memset(btpnt+(ui->txtNickname->text().length()*2),0xff,2);
                btpnt += (NICKLENGTH*2)-2;
                memset(btpnt,0xff,2);
                //                memset(&(temppkm->nickname[ui->txtNickname->text().length()]), 0xffff, 2);
                //                memset(&(temppkm->nickname[NICKLENGTH]), 0xffff, 2);

            }
        }
    }
}
void pkmviewer::on_sbEXP_valueChanged(int arg1)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(redisplayok)
        {
            temppkm->exp = arg1;
            ui->pbTNL->setMinimum(getpkmexpatlevel(temppkm->species,ui->sbLevel->value()));
            ui->pbTNL->setMaximum(getpkmexptonext((int)temppkm->species,arg1) + arg1);
            ui->pbTNL->setValue(arg1);
            ui->lblTNL->setText(QString::number(getpkmexptonext((int)temppkm->species,arg1)));
            levelchangeok = false;
            pkmviewer::displayPKM(/*false*/);
        }
        levelchangeok = true;
    }
}
void pkmviewer::on_rbOTMale_toggled(bool checked)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(checked)
        {
            temppkm->otgender = Genders::male;
            if(redisplayok)
            {
                pkmviewer::displayPKM(/*false*/);
            }
        }
    }
}
void pkmviewer::on_rbOTFemale_toggled(bool checked)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(checked)
        {
            temppkm->otgender = Genders::female;
            if(redisplayok)
            {
                pkmviewer::displayPKM(/*false*/);
            }
        }
    }
}
void pkmviewer::on_cbNicknamed_toggled(bool checked)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        temppkm->isnicknamed = checked;
    }
}
void pkmviewer::on_txtOTName_textChanged(const QString &arg1)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        if(redisplayok)
        {
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
            for(int i = 0; i < arg1.length(); i++)
            {
                temppkm->otname[2*i] = arg1[i].unicode();//.toAscii();//.toLatin1();
            }
#else
            arg1.toWCharArray(temppkm->otname);
#endif
#endif
            if(ui->txtOTName->text().length() < OTLENGTH)
            {
                byte * btpnt = new byte;
                btpnt = reinterpret_cast<byte*>(&(temppkm->otname));
                memset(btpnt+(ui->txtOTName->text().length()*2),0xff,2);
                btpnt += (OTLENGTH*2)-2;
                memset(btpnt,0xff,2);
                //                memset(&(temppkm->otname[ui->txtOTName->text().length()]), 0xffff, 2);
                //                memset(&(temppkm->otname[OTLENGTH]), 0xffff, 2);

            }
        }
    }
}
void pkmviewer::on_sbTID_valueChanged(int arg1)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        temppkm->tid = arg1;
        QPixmap shinypix;
        if(getpkmshiny(temppkm))
        {
            shinypix = getshinystar();
        }

        QGraphicsScene * shinyscene = ui->pbShiny->scene();
        if (shinyscene == NULL)
        {
            shinyscene = new QGraphicsScene;
            ui->pbShiny->setScene(shinyscene);
        }
        shinyscene->addPixmap(shinypix);
        //QPixmap * spritepixmap;
        QGraphicsScene * spritescene = ui->pbSprite->scene();

        if (spritescene == NULL)
        {
            spritescene = new QGraphicsScene;
            ui->pbSprite->setScene(spritescene);
        }
        spritescene->addPixmap(getpkmsprite(temppkm));
    }
}
void pkmviewer::on_sbSID_valueChanged(int arg1)
{
    if((temppkm->species_int > 0) && ((temppkm->pid > 0) || (temppkm->checksum > 0)))
    {
        temppkm->sid = arg1;
        QPixmap shinypix;// new QPixmap();

        if(getpkmshiny(temppkm))
        {
            shinypix = getshinystar();
        }

        QGraphicsScene * shinyscene = ui->pbShiny->scene();
        if (shinyscene == NULL)
        {
            shinyscene = new QGraphicsScene;
            ui->pbShiny->setScene(shinyscene);
        }
        shinyscene->clear();
        shinyscene->addPixmap(shinypix);
        QPixmap spritepixmap;
        QGraphicsScene * spritescene =ui->pbSprite->scene();
        if (spritescene == NULL)
        {
            spritescene = new QGraphicsScene;
            ui->pbSprite->setScene(spritescene);
        }
        spritescene->clear();
        spritescene->addPixmap(getpkmsprite(temppkm));
    }
}
void pkmviewer::on_sbHPIV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ivs.hp = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbAtkIV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ivs.attack = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbDefIV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ivs.defense = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbSpAtkIV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ivs.spatk = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbSpDefIV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ivs.spdef = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbSpeedIV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ivs.speed = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbHPEV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->evs.hp = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbAtkEV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->evs.attack = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbDefEV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->evs.defense = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbSpAtkEV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->evs.spatk = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbSpDefEV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->evs.spdef = arg1;
        updatestats();
    }
}
void pkmviewer::on_sbSpeedEV_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->evs.speed = arg1;
        updatestats();
    }
}
void pkmviewer::on_cbNatures_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->nature = (Natures::natures)index;
        updatestats();
        updatestatcolors();
    }
}
void pkmviewer::on_cbMove1_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->moves[0] = (Moves::moves)(index + 1);
        if(temppkm->species == Species::keldeo)
        {
            if(temppkm->moves[0] == Moves::secretsword)
            {
                temppkm->form.keldeo_form = Forms::Keldeo::resolute;
            }
        }
        updatemoveflavor();
        updatemovepp();
        updatemoveimages();
        updatemoveinfo();
    }
}
void pkmviewer::on_cbMove2_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->moves[1] = (Moves::moves)index;
        if(temppkm->species == Species::keldeo)
        {
            if(temppkm->moves[1] == Moves::secretsword)
            {
                temppkm->form.keldeo_form = Forms::Keldeo::resolute;
            }
        }
        updatemoveflavor();
        updatemovepp();
        updatemoveimages();
        updatemoveinfo();
    }
}
void pkmviewer::on_cbMove3_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->moves[2] = (Moves::moves)index;
        if(temppkm->species == Species::keldeo)
        {
            if(temppkm->moves[2] == Moves::secretsword)
            {
                temppkm->form.keldeo_form = Forms::Keldeo::resolute;
            }
        }
        updatemoveflavor();
        updatemovepp();
        updatemoveimages();
        updatemoveinfo();
    }
}
void pkmviewer::on_cbMove4_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->moves[3] = (Moves::moves)index;
        if(temppkm->species == Species::keldeo)
        {
            if(temppkm->moves[3] == Moves::secretsword)
            {
                temppkm->form.keldeo_form = Forms::Keldeo::resolute;
            }
        }
        updatemoveflavor();
        updatemovepp();
        updatemoveimages();
        updatemoveinfo();
    }
}
void pkmviewer::on_sbMove1PPUps_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ppup[0] = arg1;
        updatemovepp();
    }
}
void pkmviewer::on_sbMove1PP_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->pp[0] = arg1;
    }
}
void pkmviewer::on_sbMove2PPUps_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ppup[1] = arg1;
        updatemovepp();
    }
}
void pkmviewer::on_sbMove2PP_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->pp[1] = arg1;
    }
}
void pkmviewer::on_sbMove3PPUps_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ppup[2] = arg1;
        updatemovepp();
    }
}
void pkmviewer::on_sbMove3PP_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->pp[2] = arg1;
    }
}
void pkmviewer::on_sbMove4PPUps_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->ppup[3] = arg1;
        updatemovepp();
    }
}
void pkmviewer::on_sbMove4PP_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->pp[3] = arg1;
    }
}
void pkmviewer::on_cbPKMAbility_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->ability = (Abilities::abilities)(index+1);
        updateabilityflavor();
    }
}
void pkmviewer::on_cbBall_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->ball = (Balls::balls)(index+1);
    }
}
void pkmviewer::on_sbCurrentSlot_valueChanged(int value)
{
    if(redisplayok)
    {
        frmCurSlotNum = value;
        if(ispartypkm)
        {
            setPKM(&(cursavblock->party.pokemon[value]),startbox,true);
        }
        else
        {
            setPKM(&(cursavblock->boxes[startbox].pokemon[value]),startbox,false);
        }
        displayPKM();
    }
}
void pkmviewer::on_chkHex_toggled(bool checked)
{
    int base = 10;
    if(checked)
    {
        base = 16;
    }
    ui->txtPID->setText(QString::number(temppkm->pid,base).toUpper());
}
void pkmviewer::on_cbForm_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->form_int = (byte)index;
        switch(temppkm->species)
        {
        case Species::giratina:
            if(!(temppkm->hasdwability))
            {
                if(temppkm->form.giratina_form == Forms::Giratina::origin)
                {
                    temppkm->ability = Abilities::levitate;
                }
                else
                {
                    temppkm->ability = Abilities::pressure;
                }
            }
            break;
        case Species::shaymin:
            if(temppkm->form.shaymin_form == Forms::Shaymin::sky)
            {
                temppkm->ability = Abilities::serenegrace;
            }
            else
            {
                temppkm->ability = Abilities::naturalcure;
            }
            break;
        case Species::tornadus:
            if(temppkm->form.tornadus_thundurus_landorus_form == Forms::Tornadus_Thundurus_Landorus::therian)
            {
                temppkm->ability = Abilities::regenerator;
            }
            else
            {
                if(temppkm->hasdwability)
                {
                    temppkm->ability = Abilities::defiant;
                }
                else
                {
                    temppkm->ability = Abilities::prankster;
                }
            }
            break;
        case Species::thundurus:
            if(temppkm->form.tornadus_thundurus_landorus_form == Forms::Tornadus_Thundurus_Landorus::therian)
            {
                temppkm->ability = Abilities::voltabsorb;
            }
            else
            {
                if(temppkm->hasdwability)
                {
                    temppkm->ability = Abilities::defiant;
                }
                else
                {
                    temppkm->ability = Abilities::prankster;
                }
            }
            break;
        case Species::landorus:
            if(temppkm->form.tornadus_thundurus_landorus_form == Forms::Tornadus_Thundurus_Landorus::therian)
            {
                temppkm->ability = Abilities::intimidate;
            }
            else
            {
                if(temppkm->hasdwability)
                {
                    temppkm->ability = Abilities::sheerforce;
                }
                else
                {
                    temppkm->ability = Abilities::sandforce;
                }
            }
            break;
        case Species::kyurem:
            switch(temppkm->form.kyurem_form)
            {
            case Forms::Kyurem::normal:
                temppkm->ability = Abilities::pressure;
                break;
            case Forms::Kyurem::black:
                temppkm->ability = Abilities::teravolt;
                break;
            case Forms::Kyurem::white:
                temppkm->ability = Abilities::turboblaze;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        displayPKM(/*false*/);
    }
}
void pkmviewer::on_chkMetAsEgg_toggled(bool checked)
{
    if(redisplayok)
    {
        ui->cbEggLocation->setEnabled(checked);
        ui->dtEggDate->setEnabled(checked);
        if(checked)
        {
            temppkm->eggdate.year = byte(ui->dtEggDate->date().year()-2000);
            temppkm->eggdate.month = byte(ui->dtEggDate->date().month());
            temppkm->eggdate.day = byte(ui->dtEggDate->date().day());
            temppkm->eggmet_int = ui->cbEggLocation->itemData(ui->cbEggLocation->currentIndex()).toInt();
        }
    }
}
void pkmviewer::on_chkNsPKM_toggled(bool checked)
{
    if(redisplayok)
    {
        temppkm->n_pkm = checked;
    }
}
void pkmviewer::on_chkFateful_toggled(bool checked)
{
    if(redisplayok)
    {
        temppkm->fencounter = checked;
    }
}
void pkmviewer::on_sbMetLevel_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->metlevel = (byte)arg1;
    }
}
void pkmviewer::on_cbMetLocation_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        //temppkm->met = Locations::locations(index);
        temppkm->met_int = ui->cbMetLocation->itemData(index).toInt();
    }
}
void pkmviewer::on_dtMetDate_dateChanged(const QDate &date)
{
    if(redisplayok)
    {
        temppkm->metdate.year = byte(date.year()-2000);
        temppkm->metdate.month = byte(date.month());
        temppkm->metdate.day = byte(date.day());
    }
}
void pkmviewer::on_cbEggLocation_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        if(ui->chkMetAsEgg->isChecked())
        {
            //temppkm->eggmet = Locations::locations(index);
            temppkm->eggmet_int = ui->cbEggLocation->itemData(index).toInt();
        }
    }
}
void pkmviewer::on_dtEggDate_dateChanged(const QDate &date)
{
    if(redisplayok)
    {
        if(ui->chkMetAsEgg->isChecked())
        {
            temppkm->eggdate.year = byte(date.year()-2000);
            temppkm->eggdate.month = byte(date.month());
            temppkm->eggdate.day = byte(date.day());
        }
    }
}
void pkmviewer::on_cbHometown_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->hometown_int = ui->cbHometown->itemData(index).toInt();
    }
}
void pkmviewer::on_cbCountry_currentIndexChanged(int index)
{
    if(redisplayok)
    {
        temppkm->country_int = ui->cbCountry->itemData(index).toInt();
    }
}
void pkmviewer::on_sbPKRSStrain_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->pkrs.strain = arg1;
        updatepkrs();
    }
}
void pkmviewer::on_sbPKRSDays_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->pkrs.days = arg1;
        updatepkrs();
    }
}
void pkmviewer::on_chkIsEgg_toggled(bool checked)
{
    if(redisplayok)
    {
        temppkm->isegg = checked;
        egg_display(checked);
    }
}
void pkmviewer::on_sbTameness_valueChanged(int arg1)
{
    if(redisplayok)
    {
        temppkm->tameness = byte(arg1);
        if(temppkm->isegg)
        {
            ui->txtSteps->setText(QString::number(int(temppkm->tameness) * 255));
        }
    }
}

void pkmviewer::on_chkNicknamed_toggled(bool checked)
{
    if(redisplayok)
    {
        temppkm->isnicknamed = checked;
    }
}
