/********************************************************************************
** Form generated from reading UI file 'waitinglistwindow.ui'
**
** Created: Mon Apr 4 19:05:26 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGLISTWINDOW_H
#define UI_WAITINGLISTWINDOW_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaitingListWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *label_2;
    QLineEdit *healthLine;
    QPushButton *searchBtn;
    QLabel *label;
    QLabel *label_3;
    QFrame *frame_2;
    QFrame *frame_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *addBtn;
    QPushButton *removeBtn;
    QPushButton *cancelBtn;
    QFrame *frame_4;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *fnameLbl;
    QLabel *label_5;
    QLabel *lnameLbl;
    QLabel *label_6;
    QLabel *facnameLbl;
    QLabel *label_7;
    QLabel *careLbl;
    QLabel *label_8;
    QLabel *cardNumLbl;
    QLabel *label_9;
    QLabel *waitingLbl;
    QLabel *crossImg;

    void setupUi(QMainWindow *WaitingListWindow)
    {
        if (WaitingListWindow->objectName().isEmpty())
            WaitingListWindow->setObjectName(QString::fromUtf8("WaitingListWindow"));
        WaitingListWindow->resize(532, 420);
        centralWidget = new QWidget(WaitingListWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 90, 511, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 101, 31));
        healthLine = new QLineEdit(frame);
        healthLine->setObjectName(QString::fromUtf8("healthLine"));
        healthLine->setGeometry(QRect(120, 20, 261, 27));
        searchBtn = new QPushButton(frame);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setGeometry(QRect(400, 20, 98, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 60, 51, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 170, 51, 20));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(9, 210, 511, 201));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(370, 20, 131, 161));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 95, 141));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        addBtn = new QPushButton(widget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        gridLayout->addWidget(addBtn, 0, 0, 1, 1);

        removeBtn = new QPushButton(widget);
        removeBtn->setObjectName(QString::fromUtf8("removeBtn"));

        gridLayout->addWidget(removeBtn, 1, 0, 1, 1);

        cancelBtn = new QPushButton(widget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 2, 0, 1, 1);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 20, 361, 161));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 341, 141));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        fnameLbl = new QLabel(layoutWidget);
        fnameLbl->setObjectName(QString::fromUtf8("fnameLbl"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fnameLbl);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        lnameLbl = new QLabel(layoutWidget);
        lnameLbl->setObjectName(QString::fromUtf8("lnameLbl"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lnameLbl);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        facnameLbl = new QLabel(layoutWidget);
        facnameLbl->setObjectName(QString::fromUtf8("facnameLbl"));

        formLayout->setWidget(2, QFormLayout::FieldRole, facnameLbl);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        careLbl = new QLabel(layoutWidget);
        careLbl->setObjectName(QString::fromUtf8("careLbl"));

        formLayout->setWidget(3, QFormLayout::FieldRole, careLbl);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        cardNumLbl = new QLabel(layoutWidget);
        cardNumLbl->setObjectName(QString::fromUtf8("cardNumLbl"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cardNumLbl);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        waitingLbl = new QLabel(layoutWidget);
        waitingLbl->setObjectName(QString::fromUtf8("waitingLbl"));

        formLayout->setWidget(5, QFormLayout::FieldRole, waitingLbl);

        crossImg = new QLabel(centralWidget);
        crossImg->setObjectName(QString::fromUtf8("crossImg"));
        crossImg->setGeometry(QRect(420, 10, 71, 71));
        WaitingListWindow->setCentralWidget(centralWidget);

        retranslateUi(WaitingListWindow);

        QMetaObject::connectSlotsByName(WaitingListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WaitingListWindow)
    {
        WaitingListWindow->setWindowTitle(QApplication::translate("WaitingListWindow", "WaitingListWindow", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WaitingListWindow", "Health Card #:", 0, QApplication::UnicodeUTF8));
        searchBtn->setText(QApplication::translate("WaitingListWindow", "Search", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WaitingListWindow", "Search", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WaitingListWindow", "Results", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("WaitingListWindow", "Add to List", 0, QApplication::UnicodeUTF8));
        removeBtn->setText(QApplication::translate("WaitingListWindow", "Remove", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("WaitingListWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WaitingListWindow", "First Name:", 0, QApplication::UnicodeUTF8));
        fnameLbl->setText(QString());
        label_5->setText(QApplication::translate("WaitingListWindow", "Last Name:", 0, QApplication::UnicodeUTF8));
        lnameLbl->setText(QString());
        label_6->setText(QApplication::translate("WaitingListWindow", "Facility Name:", 0, QApplication::UnicodeUTF8));
        facnameLbl->setText(QString());
        label_7->setText(QApplication::translate("WaitingListWindow", "Type of Care:", 0, QApplication::UnicodeUTF8));
        careLbl->setText(QString());
        label_8->setText(QApplication::translate("WaitingListWindow", "Health Card #:", 0, QApplication::UnicodeUTF8));
        cardNumLbl->setText(QString());
        label_9->setText(QApplication::translate("WaitingListWindow", "On Waiting List?:", 0, QApplication::UnicodeUTF8));
        waitingLbl->setText(QString());
        crossImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WaitingListWindow: public Ui_WaitingListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGLISTWINDOW_H
