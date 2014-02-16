#include "mouseeventeater.h"
#include "frmboxes.h"
#include "pkmviewer.h"
#include <QMenu>
MouseEventEater::MouseEventEater(QObject *parent) :
    QObject(parent)
{
}
extern box_obj * frmCurBox;
extern int frmCurBoxNum;
int frmCurSlotNum = 0;
extern party_obj * frmParty;
pkmviewer * pview;
pokemon_obj * apkm = new pokemon_obj;
extern pokemon_obj * temppkm;
void* extmarkingsscene;
extern frmBoxes * boxViewer;
extern void * theSlot;
bool ispartypkm_ = false;
bool MouseEventEater::eventFilter(QObject *obj, QEvent *event)
{
    QString theObjName = obj->objectName();
    if((theObjName != "" )&(event->type() != QEvent::None)&(event->type() != 39)&(event->type() != 69)&(event->type() != 74)&(event->type() != 75)&(event->type() != 170))
    {
        //        int test = event->type();
        QMouseEvent *mouseEvent;
        int slot = 0;
        slot = (atoi(theObjName.right(2).toStdString().c_str()))-1;
        frmCurSlotNum = slot;
        bool todisplay = false;
        switch(event->type())
        {
        case QEvent::MouseButtonPress:
            //    case QEvent::MouseButtonDblClick:
            mouseEvent = static_cast<QMouseEvent *>(event);
            switch(mouseEvent->button())
            {
            case Qt::LeftButton:
                switch(theObjName.toStdString()[2])
                {
                case 'B':
                    if(theObjName.mid(2,5) == "BoxSl")
                    {
                        theSlot = obj;
                        apkm = &(frmCurBox->pokemon[slot]);
                        ispartypkm_ = false;
                        todisplay = true;
                    }
                    break;
                case 'P':
                    theSlot = obj;
                    apkm = &(frmParty->pokemon[slot]);
                    ispartypkm_ = true;
                    todisplay = true;
                    break;
                default:
                    QPixmap extmarkingspix;
                    int selection = 0;
                    if(theObjName.right(theObjName.length() - 2).toStdString() == "Circle"){
                        temppkm->markings.circle = !(temppkm->markings.circle);
                        selection = (int)Markings::circle;
                        extmarkingspix = getmarkingimage(Markings::circle, temppkm->markings.circle);
                    }
                    if(theObjName.right(theObjName.length() - 2).toStdString() == "Triangle"){
                        temppkm->markings.triangle = !(temppkm->markings.triangle);
                        selection = (int)Markings::triangle;
                        extmarkingspix = getmarkingimage(Markings::triangle, temppkm->markings.triangle);
                    }
                    if(theObjName.right(theObjName.length() - 2).toStdString() == "Square"){
                        temppkm->markings.square = !(temppkm->markings.square);
                        selection = (int)Markings::square;
                        extmarkingspix = getmarkingimage(Markings::square, temppkm->markings.square);
                    }
                    if(theObjName.right(theObjName.length() - 2).toStdString() == "Star"){
                        temppkm->markings.star = !(temppkm->markings.star);
                        selection = (int)Markings::star;
                        extmarkingspix = getmarkingimage(Markings::star, temppkm->markings.star);
                    }
                    if(theObjName.right(theObjName.length() - 2).toStdString() == "Diamond"){
                        temppkm->markings.diamond = !(temppkm->markings.diamond);
                        selection = (int)Markings::diamond;
                        extmarkingspix = getmarkingimage(Markings::diamond, temppkm->markings.diamond);
                    }
                    if(theObjName.right(theObjName.length() - 2).toStdString() == "Heart"){
                        temppkm->markings.heart = !(temppkm->markings.heart);
                        selection = (int)Markings::heart;
                        extmarkingspix = getmarkingimage(Markings::heart, temppkm->markings.heart);
                    }
                    QGraphicsScene * themarkingsscene = (QGraphicsScene*)extmarkingsscene;
                    themarkingsscene = new QGraphicsScene();
                    themarkingsscene->addPixmap(extmarkingspix);
                    QGraphicsView * themarkingsgraphics = (QGraphicsView*)obj;
                    themarkingsgraphics->setScene(themarkingsscene);
                    break;
                }
                if((apkm->species != 0) && todisplay)
                {
                    //                    pview->setWindowTitle(QString::fromStdWString(getpkmnickname(apkm)));
                    pview->setPKM(apkm,frmCurBoxNum, ispartypkm_);
                    pview->displayPKM();
                    pview->show();
                    boxViewer->refreshboxgrids();
                }
                break;
            default:
                break;
            }
            break;
            //        case QEvent::MouseButtonDblClick:
            //            test.setText("Test");
            //            test.show();
            //            break;
        case QEvent::ContextMenu:
            if(theObjName.mid(2,5) == "BoxSl")
            {
                apkm = &(frmCurBox->pokemon[slot]);
                //                send_rightButtonClicked(mouseEvent->globalPos());
                QMenu *menu = new QMenu(static_cast<QWidget*>(this->parent()));
                menu->addAction(new QAction("Delete",static_cast<QWidget*>(this->parent())));
                //    connect(mouseEventEater, SIGNAL(send_rightButtonClicked(const QPoint&)),
                //                this, SLOT(rightButtonClicked(const QPoint&)));
                //                connect(menu,SIGNAL(triggered()),static_cast<QWidget*>(this->parent()),
                //                        SLOT(MouseEventEater::test(apkm)));
                connect(static_cast<QWidget*>(this->parent()),
                        SIGNAL ( customContextMenuRequested(QPoint) ),
                        static_cast<QWidget*>(this->parent()),
                        SLOT ( test(apkm) ) );
                menu->exec(QCursor::pos());
            }
            break;
        default:
            return QObject::eventFilter(obj, event);
            break;
        }
    }
    else
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            int slot = obj->property("Index").toInt();
            boxViewer->changebox(slot);
        }
        return false;
    }
    return false;
}
void MouseEventEater::test(void * apkm)
{
    //    pokemon_obj * thepkm = new pokemon_obj;
    //    thepkm = reinterpret_cast<pokemon_obj*>(apkm);
    //    static_cast<QWidget*>(static_cast<QWidget*>(this->parent())->parent())->setWindowTitle("TEST");
    delete this;
}
