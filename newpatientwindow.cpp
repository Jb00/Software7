#include "newpatientwindow.h"
#include "ui_newpatientwindow.h"

NewPatientWindow::NewPatientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewPatientWindow)
{
    ui->setupUi(this);

    this->setPalette(Qt::white);

    connect(ui->okBtn, SIGNAL(pressed()), this, SLOT(okBtn_clicked()));
    connect(ui->cancelBtn, SIGNAL(pressed()), this, SLOT(cancelBtn_clicked()));

    ui->dateOnListLine->setDisabled(true);
    ui->occCareLine->setDisabled(true);
    ui->dateOfAdminLine->setText(QDateTime::currentDateTime().toString());

    setScheme();
}

NewPatientWindow::~NewPatientWindow()
{
    delete ui;
}

void NewPatientWindow::setScheme(){

    //QImage welcome("welcome.png");
    QImage cross("red_cross2.png");

    //ui->welcomeLabel->setScaledContents(TRUE);
    //ui->welcomeLabel->setPixmap(QPixmap::fromImage(welcome));

    ui->crossImg->setScaledContents(TRUE);
    ui->crossImg->setPixmap(QPixmap::fromImage(cross));

    QPalette btnPal(Qt::white);
    btnPal.setColor(QPalette::ButtonText, QColor(255, 255, 255));

    ui->okBtn->setStyleSheet("background-color: red");
    ui->cancelBtn->setStyleSheet("background-color: red");

    ui->okBtn->setPalette(btnPal);
    ui->cancelBtn->setPalette(btnPal);
}

void NewPatientWindow::currentFacility(Facility *current){aFacility = current;}

void NewPatientWindow::okBtn_clicked(){

    if((ui->fNameLine->text().isEmpty())
        || (ui->lNameLine->text().isEmpty())
        || (ui->healthLine->text().isEmpty())
        || (ui->reqCareLine->text().isEmpty())){

        NewPatientCtrl::getInstance()->invalid("Please complete the form.");
        ui->fNameLine->clear();
        ui->lNameLine->clear();
        ui->healthLine->clear();
        ui->reqCareLine->clear();
    }
    else{

        NewPatientCtrl::getInstance()->addPatient(ui->healthLine->text(), ui->fNameLine->text(), ui->lNameLine->text(),
                                                  QDateTime::currentDateTime(), QDateTime::currentDateTime(),
                                                  ui->reqCareLine->text().toInt(), -1, aFacility);

        this->close();
    }

}

void NewPatientWindow::cancelBtn_clicked(){this->close();}
