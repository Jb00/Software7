/********************************************************************************
** Form generated from reading UI file 'facilitywindow.ui'
**
** Created: Mon Apr 4 19:05:26 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACILITYWINDOW_H
#define UI_FACILITYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FacilityWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *acuteRaio;
    QRadioButton *complexRadio;
    QRadioButton *longRadio;
    QFrame *frame_4;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *occLbl;
    QLabel *label_2;
    QLabel *availLbl;
    QLabel *label_4;
    QLabel *totalLbl;
    QFrame *frame_5;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *addBedLine;
    QPushButton *bedAddBtn;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_2;
    QLabel *label_7;
    QWidget *layoutWidget4;
    QFormLayout *formLayout;
    QLabel *label_8;
    QLabel *nameLbl;
    QLabel *label_11;
    QLabel *idLbl;
    QLabel *label_13;
    QLabel *xLbl;
    QLabel *label_14;
    QLabel *yLbl;
    QLabel *crossImg;
    QFrame *frame_6;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_3;
    QPushButton *waitingBtn;
    QPushButton *patientAddBtn;
    QPushButton *cancelBtn;

    void setupUi(QMainWindow *FacilityWindow)
    {
        if (FacilityWindow->objectName().isEmpty())
            FacilityWindow->setObjectName(QString::fromUtf8("FacilityWindow"));
        FacilityWindow->resize(420, 522);
        centralWidget = new QWidget(FacilityWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 270, 401, 241));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 0, 81, 21));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 30, 161, 131));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 138, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        acuteRaio = new QRadioButton(layoutWidget);
        acuteRaio->setObjectName(QString::fromUtf8("acuteRaio"));
        acuteRaio->setChecked(true);

        verticalLayout->addWidget(acuteRaio);

        complexRadio = new QRadioButton(layoutWidget);
        complexRadio->setObjectName(QString::fromUtf8("complexRadio"));

        verticalLayout->addWidget(complexRadio);

        longRadio = new QRadioButton(layoutWidget);
        longRadio->setObjectName(QString::fromUtf8("longRadio"));

        verticalLayout->addWidget(longRadio);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(170, 30, 221, 131));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(frame_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 201, 111));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        occLbl = new QLabel(layoutWidget1);
        occLbl->setObjectName(QString::fromUtf8("occLbl"));

        gridLayout->addWidget(occLbl, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        availLbl = new QLabel(layoutWidget1);
        availLbl->setObjectName(QString::fromUtf8("availLbl"));

        gridLayout->addWidget(availLbl, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        totalLbl = new QLabel(layoutWidget1);
        totalLbl->setObjectName(QString::fromUtf8("totalLbl"));

        gridLayout->addWidget(totalLbl, 2, 1, 1, 1);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 160, 381, 71));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        layoutWidget2 = new QWidget(frame_5);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 361, 29));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        addBedLine = new QLineEdit(layoutWidget2);
        addBedLine->setObjectName(QString::fromUtf8("addBedLine"));

        gridLayout_2->addWidget(addBedLine, 0, 1, 1, 1);

        bedAddBtn = new QPushButton(layoutWidget2);
        bedAddBtn->setObjectName(QString::fromUtf8("bedAddBtn"));

        gridLayout_2->addWidget(bedAddBtn, 0, 2, 1, 1);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_6 = new QVBoxLayout(layoutWidget3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 90, 261, 171));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 10, 141, 20));
        layoutWidget4 = new QWidget(frame_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 50, 231, 101));
        formLayout = new QFormLayout(layoutWidget4);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_8);

        nameLbl = new QLabel(layoutWidget4);
        nameLbl->setObjectName(QString::fromUtf8("nameLbl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLbl);

        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_11);

        idLbl = new QLabel(layoutWidget4);
        idLbl->setObjectName(QString::fromUtf8("idLbl"));

        formLayout->setWidget(1, QFormLayout::FieldRole, idLbl);

        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        xLbl = new QLabel(layoutWidget4);
        xLbl->setObjectName(QString::fromUtf8("xLbl"));

        formLayout->setWidget(2, QFormLayout::FieldRole, xLbl);

        label_14 = new QLabel(layoutWidget4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_14);

        yLbl = new QLabel(layoutWidget4);
        yLbl->setObjectName(QString::fromUtf8("yLbl"));

        formLayout->setWidget(3, QFormLayout::FieldRole, yLbl);

        crossImg = new QLabel(centralWidget);
        crossImg->setObjectName(QString::fromUtf8("crossImg"));
        crossImg->setGeometry(QRect(320, 10, 71, 71));
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(270, 90, 141, 171));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        layoutWidget5 = new QWidget(frame_6);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(12, 10, 121, 151));
        gridLayout_3 = new QGridLayout(layoutWidget5);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        waitingBtn = new QPushButton(layoutWidget5);
        waitingBtn->setObjectName(QString::fromUtf8("waitingBtn"));

        gridLayout_3->addWidget(waitingBtn, 0, 0, 1, 1);

        patientAddBtn = new QPushButton(layoutWidget5);
        patientAddBtn->setObjectName(QString::fromUtf8("patientAddBtn"));

        gridLayout_3->addWidget(patientAddBtn, 1, 0, 1, 1);

        cancelBtn = new QPushButton(layoutWidget5);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout_3->addWidget(cancelBtn, 2, 0, 1, 1);

        FacilityWindow->setCentralWidget(centralWidget);

        retranslateUi(FacilityWindow);

        QMetaObject::connectSlotsByName(FacilityWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FacilityWindow)
    {
        FacilityWindow->setWindowTitle(QApplication::translate("FacilityWindow", "FacilityWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FacilityWindow", "Occupancy", 0, QApplication::UnicodeUTF8));
        acuteRaio->setText(QApplication::translate("FacilityWindow", "Acute Care", 0, QApplication::UnicodeUTF8));
        complexRadio->setText(QApplication::translate("FacilityWindow", "Complex  Care", 0, QApplication::UnicodeUTF8));
        longRadio->setText(QApplication::translate("FacilityWindow", "Long Term Care", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FacilityWindow", "Occupancy", 0, QApplication::UnicodeUTF8));
        occLbl->setText(QString());
        label_2->setText(QApplication::translate("FacilityWindow", "Available Beds", 0, QApplication::UnicodeUTF8));
        availLbl->setText(QString());
        label_4->setText(QApplication::translate("FacilityWindow", "Total Beds", 0, QApplication::UnicodeUTF8));
        totalLbl->setText(QString());
        label_5->setText(QApplication::translate("FacilityWindow", "Number of Beds:", 0, QApplication::UnicodeUTF8));
        bedAddBtn->setText(QApplication::translate("FacilityWindow", "Add Bed(s)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FacilityWindow", "Facility Information", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FacilityWindow", "Name:", 0, QApplication::UnicodeUTF8));
        nameLbl->setText(QString());
        label_11->setText(QApplication::translate("FacilityWindow", "ID:", 0, QApplication::UnicodeUTF8));
        idLbl->setText(QString());
        label_13->setText(QApplication::translate("FacilityWindow", "X coord.:", 0, QApplication::UnicodeUTF8));
        xLbl->setText(QString());
        label_14->setText(QApplication::translate("FacilityWindow", "Y coord.:", 0, QApplication::UnicodeUTF8));
        yLbl->setText(QString());
        crossImg->setText(QString());
        waitingBtn->setText(QApplication::translate("FacilityWindow", "Search", 0, QApplication::UnicodeUTF8));
        patientAddBtn->setText(QApplication::translate("FacilityWindow", "New Patient", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("FacilityWindow", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FacilityWindow: public Ui_FacilityWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACILITYWINDOW_H
