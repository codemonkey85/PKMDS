#include "frmboxes.h"
#include "ui_frmboxes.h"
#include "pkmviewer.h"
#include "frmreport.h"
#include "otinfo.h"
#include <QFileDialog>
#include <QMessageBox>
#if (defined __APPLE__)
const char * appath;
#endif
frmBoxes::frmBoxes(const char *apppath, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmBoxes)
{
#if (defined __APPLE__)
    #if (defined QT_NO_DEBUG)
    appath = apppath;
    QString apppathq = QString(appath);
    QStringList allparts = apppathq.split("/");
    QStringList rootdir = QStringList();//[allparts.length() - 4];
    for(int i = 0; i < allparts.length()-2; i++)
    {
        rootdir.append(allparts[i]);
    }
    QString wholepath = rootdir.join("/") + "/Resources/";
    std::string dbpath = wholepath.toStdString() + "veekun-pokedex.sqlite";
    std::string imgdbpath = wholepath.toStdString() + "images.sqlite";
    opendb(dbpath.c_str());
    openimgdb(imgdbpath.c_str());
#else
    opendb();
    openimgdb();
#endif
#else
    opendb("F:\\Dropbox\\PKMDS Databases\\veekun-pokedex.sqlite");
    openimgdb("F:\\Dropbox\\PKMDS Databases\\images.sqlite");
#endif
    ui->setupUi(this);
    ui->saBoxes->setVisible(false);
    ui->saBoxes->setEnabled(false);
    ui->sbBoxIncrem->setVisible(false);
    ui->sbBoxIncrem->setEnabled(false);
    mouseEventEater = new MouseEventEater(this);
    extern pkmviewer * pview;
    pview = new pkmviewer(this);
    partygraphics[0] = ui->pbPartySlot01;
    partygraphics[1] = ui->pbPartySlot02;
    partygraphics[2] = ui->pbPartySlot03;
    partygraphics[3] = ui->pbPartySlot04;
    partygraphics[4] = ui->pbPartySlot05;
    partygraphics[5] = ui->pbPartySlot06;
    boxgraphics[0] = ui->pbBoxSlot01;
    boxgraphics[1] = ui->pbBoxSlot02;
    boxgraphics[2] = ui->pbBoxSlot03;
    boxgraphics[3] = ui->pbBoxSlot04;
    boxgraphics[4] = ui->pbBoxSlot05;
    boxgraphics[5] = ui->pbBoxSlot06;
    boxgraphics[6] = ui->pbBoxSlot07;
    boxgraphics[7] = ui->pbBoxSlot08;
    boxgraphics[8] = ui->pbBoxSlot09;
    boxgraphics[9] = ui->pbBoxSlot10;
    boxgraphics[10] = ui->pbBoxSlot11;
    boxgraphics[11] = ui->pbBoxSlot12;
    boxgraphics[12] = ui->pbBoxSlot13;
    boxgraphics[13] = ui->pbBoxSlot14;
    boxgraphics[14] = ui->pbBoxSlot15;
    boxgraphics[15] = ui->pbBoxSlot16;
    boxgraphics[16] = ui->pbBoxSlot17;
    boxgraphics[17] = ui->pbBoxSlot18;
    boxgraphics[18] = ui->pbBoxSlot19;
    boxgraphics[19] = ui->pbBoxSlot20;
    boxgraphics[20] = ui->pbBoxSlot21;
    boxgraphics[21] = ui->pbBoxSlot22;
    boxgraphics[22] = ui->pbBoxSlot23;
    boxgraphics[23] = ui->pbBoxSlot24;
    boxgraphics[24] = ui->pbBoxSlot25;
    boxgraphics[25] = ui->pbBoxSlot26;
    boxgraphics[26] = ui->pbBoxSlot27;
    boxgraphics[27] = ui->pbBoxSlot28;
    boxgraphics[28] = ui->pbBoxSlot29;
    boxgraphics[29] = ui->pbBoxSlot30;
    boxpreviewgraphics[0] = ui->pbBox01;
    boxpreviewgraphics[1] = ui->pbBox02;
    boxpreviewgraphics[2] = ui->pbBox03;
    boxpreviewgraphics[3] = ui->pbBox04;
    boxpreviewgraphics[4] = ui->pbBox05;
    boxpreviewgraphics[5] = ui->pbBox06;
    boxpreviewgraphics[6] = ui->pbBox07;
    boxpreviewgraphics[7] = ui->pbBox08;
    boxpreviewgraphics[8] = ui->pbBox09;
    boxpreviewgraphics[9] = ui->pbBox10;
    boxpreviewgraphics[10] = ui->pbBox11;
    boxpreviewgraphics[11] = ui->pbBox12;
    boxpreviewgraphics[12] = ui->pbBox13;
    boxpreviewgraphics[13] = ui->pbBox14;
    boxpreviewgraphics[14] = ui->pbBox15;
    boxpreviewgraphics[15] = ui->pbBox16;
    boxpreviewgraphics[16] = ui->pbBox17;
    boxpreviewgraphics[17] = ui->pbBox18;
    boxpreviewgraphics[18] = ui->pbBox19;
    boxpreviewgraphics[19] = ui->pbBox20;
    boxpreviewgraphics[20] = ui->pbBox21;
    boxpreviewgraphics[21] = ui->pbBox22;
    boxpreviewgraphics[22] = ui->pbBox23;
    boxpreviewgraphics[23] = ui->pbBox24;
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    //    connect(mouseEventEater, SIGNAL(send_rightButtonClicked(const QPoint&)),
    //                this, SLOT(rightButtonClicked(const QPoint&)));

    //    /*
    ////    QMenu* pContextMenu = new QMenu(this);
    ////    //    QTreeWidget* pTreeWidget = new QTreeWidget();
    ////    QAction* qaDeletePKM = new QAction(tr("Delete Pokemon"), pContextMenu);
    ////    ui->pbBoxSlot01->setContextMenuPolicy(Qt::ActionsContextMenu);
    ////    //    pTreeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
    ////    //    pTreeWidget->addAction(pOpenFile);
    ////    //connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    ////    //    connect(qaDeletePKM,
    ////    //            SIGNAL(triggered()),
    ////    //            this,
    ////    //            SLOT(frmBoxes::on_actionDeletePKM(QGraphicsView * gView)));
    ////    //    QString ss("QMenu{background-color: #ABABAB;border: 1px solid black;}");
    ////    this->connect(
    ////                qaDeletePKM,
    ////                SIGNAL(triggered()),
    ////                this,
    ////                SLOT(open())
    ////                );
    ////    ui->pbBoxSlot01->addAction(qaDeletePKM);
    ////    //    qApp->setStyleSheet(ss);
    ////    boxgraphics[0]->setContextMenuPolicy(Qt::CustomContextMenu);
    //*/
    //    boxgraphics[0]->setContextMenuPolicy(Qt::ActionsContextMenu);
    //    QMenu* pContextMenu = new QMenu(this);
    //    QAction* qaDeletePKM = new QAction(tr("Delete Pokemon"), pContextMenu);
    //    /*this->*//*QObject::*/connect(
    //                qaDeletePKM,
    //                SIGNAL(triggered()),
    //                /*this*/boxgraphics[0],
    //                SLOT(on_actionDeletePKM(boxgraphics[0]))
    //                );
    //    boxgraphics[0]->addAction(qaDeletePKM);
}
//void frmBoxes::on_actionDeletePKM(QGraphicsView * gView)
//{
//    this->setWindowTitle("THIS IS A TEST");
//    gView->setVisible(false);
//    QMessageBox msg;
//    msg.setText("TEST");
//    msg.show();
//}
frmBoxes * boxViewer;
frmReport * report;
bw2sav_obj * sav = new bw2sav_obj;
bw2savblock_obj * cursavblock = new bw2savblock_obj;
bw2savblock_obj * baksavblock = new bw2savblock_obj;
box_obj * frmCurBox = new box_obj;
int frmCurBoxNum = 0;
party_obj * frmParty = new party_obj;
void * theSlot;
QString SaveFileName = "";
bool SavDecrypted = false;
const QString wTitle = "PKMDS Qt Edition";
frmBoxes::~frmBoxes()
{
    try
    {
        closeimgdb();
        closedb();
    }
    catch(...){}
    delete ui;
}
void frmBoxes::on_actionLoad_SAV_triggered()
{
    SaveFileName = QFileDialog::getOpenFileName(this,tr("Load a save file"),tr(""),tr("Save Files (*.sav *.dsv)"));
    if(SaveFileName != "")
    {
        boxViewer = this;
        SavDecrypted = false;
        read(SaveFileName.toStdString().c_str(),sav);
        cursavblock = &(sav->cur);
        baksavblock = &(sav->bak);
        this->setWindowTitle(wTitle + QString::fromStdString(" - ") + QString::fromStdWString(getsavtrainername(cursavblock))); // QString::fromStdWString(getwstring(cursavblock->trainername)));
        QGraphicsScene * partyscene = new QGraphicsScene();
        for(int i = 0; i < 6; i++)
        {
            pix = QPixmap();
            partyscene = new QGraphicsScene();
            partyscene->addPixmap(pix);
            partygraphics[i]->setScene(partyscene);
        }
        for(uint32 pslot = 0; pslot < cursavblock->party.size; pslot++)
        {
            decryptpkm(&(cursavblock->party.pokemon[pslot]));
            pix = getpkmicon(cursavblock->party.pokemon[pslot]);
            partyscene = new QGraphicsScene();
            partyscene->addPixmap(pix);
            partygraphics[pslot]->setScene(partyscene);
            partygraphics[pslot]->installEventFilter(mouseEventEater);
        }
        if(ui->cbBoxes->count() == 0)
        {
            for(int i = 0; i < 24; i++)
            {
                ui->cbBoxes->addItem("");
            }
        }
        for(int boxnum = 0; boxnum < 24; boxnum++)
        {
            //            ui->cbBoxes->setItemText(boxnum,QString::fromStdString(std::string(cursavblock->boxnames[boxnum])));

            std::wstring testing = getwstring((char*)(cursavblock->boxnames[boxnum]), 20);
            ui->cbBoxes->setItemText(boxnum,QString::fromStdWString(testing));

            //            ui->cbBoxes->setItemText(boxnum,QString::fromStdWString(getwstring(cursavblock->boxnames[boxnum])));
            for(int boxslot = 0; boxslot < 30; boxslot++)
            {
                decryptpkm(&(cursavblock->boxes[boxnum].pokemon[boxslot]));
            }
        }
        SavDecrypted = true;
        ui->sbBoxIncrem->setEnabled(true);
        ui->sbBoxIncrem->setVisible(true);
        ui->saBoxes->setEnabled(true);
        ui->saBoxes->setVisible(true);
        ui->cbBoxes->setEnabled(true);
        ui->sbBoxIncrem->setValue(cursavblock->curbox);
        frmParty = &(cursavblock->party);
        for(int ic = 0; ic < 24; ic++)
        {
            boxpreviewgraphics[ic]->installEventFilter(mouseEventEater);
            boxpreviewgraphics[ic]->viewport()->setMouseTracking(true);
            boxpreviewgraphics[ic]->viewport()->setProperty("Index",ic);
            boxpreviewgraphics[ic]->viewport()->installEventFilter(mouseEventEater);
        }
        refreshboxgrids();
        changebox(cursavblock->curbox);
    }
}
void frmBoxes::changebox(int index)
{
    int box = index;
    refreshboxgrid(frmCurBoxNum);
    frmCurBoxNum = index;
    frmCurBox = &(cursavblock->boxes[box]);

    for(int bslot = 0; bslot < 30; bslot++)
    {
        pix = QPixmap();
        if(cursavblock->boxes[box].pokemon[bslot].species != Species::NOTHING)
        {
            pix = getpkmicon(cursavblock->boxes[box].pokemon[bslot]);
        }

        QGraphicsScene * boxscene = boxgraphics[bslot]->scene();
        if (boxscene == NULL)
        {
            boxscene = new QGraphicsScene();
            boxgraphics[bslot]->setScene(boxscene);
            boxgraphics[bslot]->installEventFilter(mouseEventEater);
        }
        boxscene->clear();
        boxscene->addPixmap(pix);
    }
    if(ui->cbBoxes->currentIndex() != index)
    {
        ui->cbBoxes->setCurrentIndex(index);
    }
    if(ui->sbBoxIncrem->value() != index)
    {
        ui->sbBoxIncrem->setValue(index);
    }
    QPixmap wallpaperpixmap = getwallpaperimage(cursavblock->boxwallpapers[box]);
    QGraphicsScene * wallpaperscene = ui->pbPCBox->scene();
    if (wallpaperscene == NULL)
    {
        wallpaperscene = new QGraphicsScene;
        ui->pbPCBox->setScene(wallpaperscene);
        ui->pbPCBox->setSceneRect(0,0,192,160);
        ui->pbPCBox->fitInView(0,0,153,111);
    }

    wallpaperscene->clear();
    wallpaperscene->addPixmap(wallpaperpixmap);
    for(int box = 0; box < 24; box++)
    {
        boxpreviewgraphics[box]->setFrameStyle(0);
    }
    ui->saBoxes->verticalScrollBar()->setValue(index * 76);
    boxpreviewgraphics[index]->setFrameStyle(1);
}
void frmBoxes::on_cbBoxes_currentIndexChanged(int index)
{
    if(SavDecrypted)
    {
        changebox(index);
    }
}
void frmBoxes::on_sbBoxIncrem_valueChanged(int value)
{
    if(SavDecrypted)
    {
        changebox(value);
    }
}
void frmBoxes::on_actionSave_changes_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Save Data");
    msgBox.setText("Changes have been made to this save.");
    msgBox.setInformativeText("Do you want to overwrite the file and save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    // You can simply use QMessageBox::<ButtonType> as the result code
    if(ret == QMessageBox::Save) // 2048 (or 0x800) = Save, 4194304 (or 0x400000) = Cancel
    {
        if((sav > 0)/* && (cursavblock->adventurestarted != 0)*/)
        {
            bw2sav_obj * savout = new bw2sav_obj;
            *savout = *sav;
            bool isbw2 = savisbw2(savout);
            savout->cur.curbox = frmCurBoxNum; // ui->cbBoxes->currentIndex();
            for(uint32 pslot = 0; pslot < savout->cur.party.size; pslot++)
            {
                encryptpkm(&(savout->cur.party.pokemon[pslot]));
            }
            calcpartychecksum(&(savout->cur),isbw2);
            for(int boxnum = 0; boxnum < 24; boxnum++)
            {
                for(int boxslot = 0; boxslot < 30; boxslot++)
                {
                    encryptpkm(&(savout->cur.boxes[boxnum].pokemon[boxslot]));
                }
                calcboxchecksum(&(savout->cur),boxnum,isbw2);
            }
            savout->cur.block1checksum = getchecksum(&(savout->cur),0x0,0x3e0);
            fixsavchecksum(savout, isbw2);
            write(SaveFileName.toStdString().c_str(),savout);
            msgBox.setText("The file has been saved.");
            msgBox.setInformativeText("");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
        }
        else
        {
            msgBox.setText("The file will not be saved.");
            msgBox.setInformativeText("");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
        }
    }
    else
    {
        msgBox.setText("The file will not be saved.");
        msgBox.setInformativeText("");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
    }
    ret = msgBox.exec();
}
void frmBoxes::refreshboxgrid(int box)
{
    QImage grid = QImage(60,50,QImage::Format_RGB32);
    QPixmap gridpix;
    pokemon_obj * pkm_c;
    uint32 color_val = 0;
    for(int sloty = 0; sloty < 5; sloty++)
    {
        QGraphicsScene * gridscene = boxpreviewgraphics[box]->scene();
        if (gridscene == NULL)
        {
            gridscene = new QGraphicsScene;
            boxpreviewgraphics[box]->setScene(gridscene);
        }

        for(int slotx = 0; slotx < 6; slotx++)
        {
            pkm_c = &(sav->cur.boxes[box].pokemon[(sloty*6)+slotx]);
            color_val = getpkmcolor(pkm_c->species);
            for(int x = 0; x < 10; x++)
            {
                for(int y = 0; y < 10; y++)
                {
                    grid.setPixel((slotx * 10) + x,(sloty * 10) + y,color_val);
                }
            }
        }
        gridscene->clear();
        gridpix = QPixmap::fromImage(grid);
        gridscene->addPixmap(gridpix);
    }
}
void frmBoxes::refreshboxgrids()
{
    for(int box = 0; box < 24; box++)
    {
        refreshboxgrid(box);
    }
}
void frmBoxes::on_actionSearch_triggered()
{
    report = new frmReport();
    report->show();
}
void frmBoxes::on_pbBoxSlot01_customContextMenuRequested(const QPoint &pos)
{
    //        pContextMenu->show();
}
void frmBoxes::on_actionDelete_HMs_triggered()
{
    party_pkm * ppkm_ = new party_pkm();
    pokemon_obj * pkm_ = new pokemon_obj();
    for(int pslot = 0; pslot < sav->cur.party.size; pslot++)
    {
        ppkm_ = &(sav->cur.party.pokemon[pslot]);
        deletehms(ppkm_);
        calcchecksum(ppkm_);
    }
    for(int box = 0; box < 24; box++)
    {
        for(int slot = 0; slot < 30; slot++)
        {
            pkm_ = &(sav->cur.boxes[box].pokemon[slot]);
            deletehms(pkm_);
            calcchecksum(pkm_);
        }
    }
}
void frmBoxes::on_actionView_PKM_File_triggered()
{
    QString PKMFileName = QFileDialog::getOpenFileName(this,tr("Load a PKM file"),tr(""),tr("PKM Files (*.pkm)"));
    if(PKMFileName != "")
    {
        pokemon_obj * pkm = new pokemon_obj();
        read(PKMFileName.toStdString().c_str(),pkm);
        pkmviewer * pview = new pkmviewer();
        pview->setPKM(pkm,frmCurBoxNum, false);
        pview->displayPKM();
        pview->show();
    }
}
void frmBoxes::on_actionOT_Info_triggered()
{
    if(SavDecrypted)
    {
        OTInfo * oti = new OTInfo(this);
        oti->setSAV(sav);
        oti->displayOTInfo();
        oti->show();
    }
}
