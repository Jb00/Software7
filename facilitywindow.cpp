#include "facilitywindow.h"
#include "ui_facilitywindow.h"

FacilityWindow::FacilityWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FacilityWindow)
{
    ui->setupUi(this);

    connect(ui->cancelBtn, SIGNAL(pressed()), this, SLOT(cancelBtn_clicked()));
    connect(ui->okBtn, SIGNAL(pressed()), this, SLOT(okBtn_clicked()));

    connect(ui->acuteRaio, SIGNAL(toggled(bool)), this, SLOT(AcuteSelected()));
    connect(ui->complexRadio, SIGNAL(toggled(bool)), this, SLOT(ComplexSelected()));
    connect(ui->longRadio, SIGNAL(toggled(bool)), this, SLOT(LTCSelected()));
    connect(ui->waitingBtn, SIGNAL(pressed()), this, SLOT(waitingBtn_clicked()));


}

void FacilityWindow::setUI(Facility* aFacility)
{
    facility = aFacility;
    //Set num to QString
    QString id;
    id.setNum(facility->getId()); //int to string
    QString x;
    x.setNum(facility->getX());
    QString y;
    y.setNum(facility->getY());


    ui->nameLbl->setText(facility->getName());
    ui->idLbl->setText(id);
    ui->xLbl->setText(x);
    ui->yLbl->setText(y);

    //for acute occupancy as it is the default one
    QString occ;
    occ.setNum(facility->getSizePatientAcute());
    ui->occLbl->setText(occ);

    //Available
    QString Available;
    Available.setNum(facility->getSizeAvailableAcute());
    ui->availLbl->setText(Available);

    //Total Bed
    QString total;
    total.setNum(facility->getSizeAcute());
    ui->totalLbl->setText(total);


}

FacilityWindow::~FacilityWindow()
{
    delete ui;
}

void FacilityWindow::AcuteSelected()
{
    //for acute occupancy as it is the default one
    QString occ;
    occ.setNum(facility->getSizePatientAcute());
    ui->occLbl->setText(occ);

    //Available
    QString Available;
    Available.setNum(facility->getSizeAvailableAcute());
    ui->availLbl->setText(Available);

    //Total Bed
    QString total;
    total.setNum(facility->getSizeAcute());
    ui->totalLbl->setText(total);
}

void FacilityWindow::ComplexSelected()
{

    //for acute occupancy as it is the default one
    QString occ;
    occ.setNum(facility->getSizePatientComplex());
    ui->occLbl->setText(occ);

    //Available
    QString Available;
    Available.setNum(facility->getSizeAvailableComplex());
    ui->availLbl->setText(Available);

    //Total Bed
    QString total;
    total.setNum(facility->getSizeComplex());
    ui->totalLbl->setText(total);

}

void FacilityWindow::LTCSelected()
{

    //for acute occupancy as it is the default one
    QString occ;
    occ.setNum(facility->getSizePatientLTC());
    ui->occLbl->setText(occ);

    //Available
    QString Available;
    Available.setNum(facility->getSizeAvailableLTC());
    ui->availLbl->setText(Available);

    //Total Bed
    QString total;
    total.setNum(facility->getSizeLTC());
    ui->totalLbl->setText(total);
}

void FacilityWindow::okBtn_clicked()
{
       if(ui->acuteRaio->isChecked())
       {
           AddBedController::getInstance()->addtoBed(ui->addBedNum->text(),"Acute",facility);
           AcuteSelected(); //To refresh the UI
       }
           else
               if (ui->complexRadio->isChecked())
               {
                  AddBedController::getInstance()->addtoBed(ui->addBedNum->text(),"Complex",facility);
                   ComplexSelected();//To refresh the UI
               }
                   if (ui->longRadio->isChecked())
                   {
                         AddBedController::getInstance()->addtoBed(ui->addBedNum->text(),"LTC",facility);
                         LTCSelected(); //To refresh the UI
                   }
                   this->close();
}

void FacilityWindow::cancelBtn_clicked()
{
//ADD PATIENT TO A BED TO A FACILITY
    QDateTime aDate = QDateTime::fromString("2003-05-30T09:00:00","yyyy-MM-dThh:mm:ss");

    aPatient2 = new Patient ("12e","Bob","Henry",aDate,aDate,7,8);


    if(ui->acuteRaio->isChecked())
    {
        AssignHospitalController::getInstance()->addtoBed(aPatient2,facility,"Acute");
        AcuteSelected(); //To refresh the UI
    }
        else
            if (ui->complexRadio->isChecked())
            {
               AssignHospitalController::getInstance()->addtoBed(aPatient2,facility,"Complex");
                ComplexSelected();//To refresh the UI
            }
}

void FacilityWindow::waitingBtn_clicked(){

    FacilityWinCtrl::getInstance()->goToWaiting();

}

/*void FacilityWindow::setScheme(){

    this->setPalette(Qt::white);

    QImage cross("red_cross2.png");
    ui->crossImg->setScaledContents(TRUE);
    ui->crossImg->setPixmap(QPixmap::fromImage(cross));
}*/

void FacilityWindow::keyPressEvent(QKeyEvent *event){

    switch(event->key()){

    case Qt::Key_Escape:
        qApp->quit();
        break;

    }
}
