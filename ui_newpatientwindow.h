/********************************************************************************
** Form generated from reading UI file 'newpatientwindow.ui'
**
** Created: Mon Apr 4 19:05:26 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPATIENTWINDOW_H
#define UI_NEWPATIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewPatientWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLineEdit *fNameLine;
    QLineEdit *lNameLine;
    QLineEdit *healthLine;
    QLineEdit *dateOfAdminLine;
    QLineEdit *dateOnListLine;
    QLineEdit *reqCareLine;
    QLineEdit *occCareLine;
    QLabel *label_8;
    QLabel *crossImg;

    void setupUi(QMainWindow *NewPatientWindow)
    {
        if (NewPatientWindow->objectName().isEmpty())
            NewPatientWindow->setObjectName(QString::fromUtf8("NewPatientWindow"));
        NewPatientWindow->resize(451, 428);
        centralwidget = new QWidget(NewPatientWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 380, 391, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        okBtn = new QPushButton(layoutWidget_2);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout_2->addWidget(okBtn, 0, 0, 1, 1);

        cancelBtn = new QPushButton(layoutWidget_2);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout_2->addWidget(cancelBtn, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 100, 431, 271));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 191, 251));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 5, 0, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 6, 0, 1, 1);

        widget1 = new QWidget(frame);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(220, 9, 191, 251));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        fNameLine = new QLineEdit(widget1);
        fNameLine->setObjectName(QString::fromUtf8("fNameLine"));

        gridLayout->addWidget(fNameLine, 0, 0, 1, 1);

        lNameLine = new QLineEdit(widget1);
        lNameLine->setObjectName(QString::fromUtf8("lNameLine"));

        gridLayout->addWidget(lNameLine, 1, 0, 1, 1);

        healthLine = new QLineEdit(widget1);
        healthLine->setObjectName(QString::fromUtf8("healthLine"));

        gridLayout->addWidget(healthLine, 2, 0, 1, 1);

        dateOfAdminLine = new QLineEdit(widget1);
        dateOfAdminLine->setObjectName(QString::fromUtf8("dateOfAdminLine"));

        gridLayout->addWidget(dateOfAdminLine, 3, 0, 1, 1);

        dateOnListLine = new QLineEdit(widget1);
        dateOnListLine->setObjectName(QString::fromUtf8("dateOnListLine"));

        gridLayout->addWidget(dateOnListLine, 4, 0, 1, 1);

        reqCareLine = new QLineEdit(widget1);
        reqCareLine->setObjectName(QString::fromUtf8("reqCareLine"));

        gridLayout->addWidget(reqCareLine, 5, 0, 1, 1);

        occCareLine = new QLineEdit(widget1);
        occCareLine->setObjectName(QString::fromUtf8("occCareLine"));

        gridLayout->addWidget(occCareLine, 6, 0, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 70, 91, 21));
        crossImg = new QLabel(centralwidget);
        crossImg->setObjectName(QString::fromUtf8("crossImg"));
        crossImg->setGeometry(QRect(340, 10, 71, 71));
        NewPatientWindow->setCentralWidget(centralwidget);

        retranslateUi(NewPatientWindow);

        QMetaObject::connectSlotsByName(NewPatientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *NewPatientWindow)
    {
        NewPatientWindow->setWindowTitle(QApplication::translate("NewPatientWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("NewPatientWindow", "OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("NewPatientWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewPatientWindow", "First Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewPatientWindow", "Last Name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewPatientWindow", "Health Card Number:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewPatientWindow", "Date of Admission:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewPatientWindow", "Date Placed on Waiting List:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NewPatientWindow", "Required type of care:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NewPatientWindow", "Occupying type of care:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NewPatientWindow", "Patient Data", 0, QApplication::UnicodeUTF8));
        crossImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewPatientWindow: public Ui_NewPatientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPATIENTWINDOW_H
