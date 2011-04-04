/********************************************************************************
** Form generated from reading UI file 'genreportwin.ui'
**
** Created: Mon Apr 4 12:03:23 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENREPORTWIN_H
#define UI_GENREPORTWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenReportWin
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *startDate;
    QLineEdit *endDate;
    QFrame *frame_2;
    QListWidget *facListWidget;
    QLabel *label_4;
    QFrame *frame_3;
    QLabel *label_5;
    QFrame *line_2;
    QLabel *label_6;
    QFrame *line_3;
    QLabel *label_7;
    QFrame *line_4;
    QCheckBox *waitingCheck;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QCheckBox *acuteCheck;
    QCheckBox *cccCheck;
    QCheckBox *ltcCheck;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QRadioButton *totalRadio;
    QRadioButton *occRadio;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_4;
    QCheckBox *numAcuteInCCC;
    QCheckBox *numCCCInAcute;
    QCheckBox *numLTCInAcute;
    QCheckBox *numLTCInCCC;
    QLabel *crossImg;
    QSplitter *splitter;
    QPushButton *genBtn;
    QPushButton *cancelBtn;

    void setupUi(QMainWindow *GenReportWin)
    {
        if (GenReportWin->objectName().isEmpty())
            GenReportWin->setObjectName(QString::fromUtf8("GenReportWin"));
        GenReportWin->resize(501, 686);
        centralwidget = new QWidget(GenReportWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 100, 481, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(196, 10, 81, 20));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 30, 291, 71));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        startDate = new QLineEdit(layoutWidget);
        startDate->setObjectName(QString::fromUtf8("startDate"));

        gridLayout->addWidget(startDate, 0, 1, 1, 1);

        endDate = new QLineEdit(layoutWidget);
        endDate->setObjectName(QString::fromUtf8("endDate"));

        gridLayout->addWidget(endDate, 1, 1, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 220, 241, 411));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        facListWidget = new QListWidget(frame_2);
        facListWidget->setObjectName(QString::fromUtf8("facListWidget"));
        facListWidget->setGeometry(QRect(20, 50, 201, 341));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 10, 81, 20));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(260, 220, 231, 411));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 10, 111, 20));
        line_2 = new QFrame(frame_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 30, 231, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(56, 50, 111, 20));
        line_3 = new QFrame(frame_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 160, 231, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 180, 141, 20));
        line_4 = new QFrame(frame_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 360, 231, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        waitingCheck = new QCheckBox(frame_3);
        waitingCheck->setObjectName(QString::fromUtf8("waitingCheck"));
        waitingCheck->setGeometry(QRect(10, 380, 221, 21));
        layoutWidget1 = new QWidget(frame_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 130, 211, 24));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        acuteCheck = new QCheckBox(layoutWidget1);
        acuteCheck->setObjectName(QString::fromUtf8("acuteCheck"));

        gridLayout_3->addWidget(acuteCheck, 0, 0, 1, 1);

        cccCheck = new QCheckBox(layoutWidget1);
        cccCheck->setObjectName(QString::fromUtf8("cccCheck"));

        gridLayout_3->addWidget(cccCheck, 0, 1, 1, 1);

        ltcCheck = new QCheckBox(layoutWidget1);
        ltcCheck->setObjectName(QString::fromUtf8("ltcCheck"));

        gridLayout_3->addWidget(ltcCheck, 0, 2, 1, 1);

        layoutWidget2 = new QWidget(frame_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 90, 211, 24));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        totalRadio = new QRadioButton(layoutWidget2);
        totalRadio->setObjectName(QString::fromUtf8("totalRadio"));

        gridLayout_2->addWidget(totalRadio, 0, 0, 1, 1);

        occRadio = new QRadioButton(layoutWidget2);
        occRadio->setObjectName(QString::fromUtf8("occRadio"));

        gridLayout_2->addWidget(occRadio, 0, 1, 1, 1);

        layoutWidget3 = new QWidget(frame_3);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(14, 210, 201, 141));
        gridLayout_4 = new QGridLayout(layoutWidget3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        numAcuteInCCC = new QCheckBox(layoutWidget3);
        numAcuteInCCC->setObjectName(QString::fromUtf8("numAcuteInCCC"));

        gridLayout_4->addWidget(numAcuteInCCC, 0, 0, 1, 1);

        numCCCInAcute = new QCheckBox(layoutWidget3);
        numCCCInAcute->setObjectName(QString::fromUtf8("numCCCInAcute"));

        gridLayout_4->addWidget(numCCCInAcute, 1, 0, 1, 1);

        numLTCInAcute = new QCheckBox(layoutWidget3);
        numLTCInAcute->setObjectName(QString::fromUtf8("numLTCInAcute"));

        gridLayout_4->addWidget(numLTCInAcute, 2, 0, 1, 1);

        numLTCInCCC = new QCheckBox(layoutWidget3);
        numLTCInCCC->setObjectName(QString::fromUtf8("numLTCInCCC"));

        gridLayout_4->addWidget(numLTCInCCC, 3, 0, 1, 1);

        crossImg = new QLabel(centralwidget);
        crossImg->setObjectName(QString::fromUtf8("crossImg"));
        crossImg->setGeometry(QRect(400, 10, 71, 71));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(80, 650, 351, 27));
        splitter->setOrientation(Qt::Horizontal);
        genBtn = new QPushButton(splitter);
        genBtn->setObjectName(QString::fromUtf8("genBtn"));
        splitter->addWidget(genBtn);
        cancelBtn = new QPushButton(splitter);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        splitter->addWidget(cancelBtn);
        GenReportWin->setCentralWidget(centralwidget);

        retranslateUi(GenReportWin);

        QMetaObject::connectSlotsByName(GenReportWin);
    } // setupUi

    void retranslateUi(QMainWindow *GenReportWin)
    {
        GenReportWin->setWindowTitle(QApplication::translate("GenReportWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GenReportWin", "Date Range", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GenReportWin", "Start Date (yyyy/mm/dd):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GenReportWin", "End Date (yyyy/mm/dd):", 0, QApplication::UnicodeUTF8));
        startDate->setText(QApplication::translate("GenReportWin", "yyyy-mm-dd", 0, QApplication::UnicodeUTF8));
        endDate->setText(QApplication::translate("GenReportWin", "yyyy-mm-dd", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GenReportWin", "Facility List", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GenReportWin", "Report Details", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("GenReportWin", "Bed Information", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("GenReportWin", "Patient Information", 0, QApplication::UnicodeUTF8));
        waitingCheck->setText(QApplication::translate("GenReportWin", "NO. Patients on Waiting List", 0, QApplication::UnicodeUTF8));
        acuteCheck->setText(QApplication::translate("GenReportWin", "Acute", 0, QApplication::UnicodeUTF8));
        cccCheck->setText(QApplication::translate("GenReportWin", "CCC", 0, QApplication::UnicodeUTF8));
        ltcCheck->setText(QApplication::translate("GenReportWin", "LTC", 0, QApplication::UnicodeUTF8));
        totalRadio->setText(QApplication::translate("GenReportWin", "Total", 0, QApplication::UnicodeUTF8));
        occRadio->setText(QApplication::translate("GenReportWin", "Occupied", 0, QApplication::UnicodeUTF8));
        numAcuteInCCC->setText(QApplication::translate("GenReportWin", "Number Acute in CCC", 0, QApplication::UnicodeUTF8));
        numCCCInAcute->setText(QApplication::translate("GenReportWin", "Number CCC in Acute", 0, QApplication::UnicodeUTF8));
        numLTCInAcute->setText(QApplication::translate("GenReportWin", "Number LTC in Acute", 0, QApplication::UnicodeUTF8));
        numLTCInCCC->setText(QApplication::translate("GenReportWin", "Number LTC in CCC", 0, QApplication::UnicodeUTF8));
        crossImg->setText(QString());
        genBtn->setText(QApplication::translate("GenReportWin", "Generate", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("GenReportWin", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GenReportWin: public Ui_GenReportWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENREPORTWIN_H
