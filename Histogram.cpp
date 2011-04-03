#include "Histogram.h"
//#include "ui_Histogram.h"

Histogram::Histogram(QWidget *parent) :
    QWidget(parent)
{

}

//Histogram::~Histogram()
//{
//}


void Histogram::paintEvent(QPaintEvent *event)
{

    int maxY=0; //To be set from a loop to find maximum in the list in the parameters.
    int numberOfList=data.size();  //
    //Now we have all the data needed, find MAX

    for (int i=0;i<data.size();i++)
    {
        if(maxY < data.at(i))
            maxY=data.at(i); //Find max
    }


    int x = numberOfList * 45 ; // number of row * row space + 5% of it.
    QPen pen(Qt::black,2,Qt::SolidLine);
    QPainter p(this);

    p.setPen(pen); //Set the pen we just declare

    //Draw general lines and min - max on Y and X
    p.drawLine(45,700,700,700); //X line
    p.drawLine(50,705,50,50); //Y line
    p.drawText(30,700,"0"); // 0 line


    //Precision line + Text for Y axis
    QString maxYString;
    maxYString.setNum(maxY);

    int halfY = maxY /2;
    QString halfYString;
    halfYString.setNum(halfY);

    int quarterY = maxY /4;
    QString quarterYString;
    quarterYString.setNum(quarterY);

    int thirdY = 3* maxY /4;
    QString thirdYString;
    thirdYString.setNum(thirdY);


    p.drawText(20,55,maxYString); //Max Y
    p.drawLine(45,375,50,375); //Precision line Y HALF              (700-50 / 2) = 325 + 50
    p.drawLine(45,212,50,212); //Precision line Y Quarter           (700-50 / 4) = 162.5 + 50
    p.drawLine(45,537,50,537); //Precision line Y Quarter           (700 - 162)
    p.drawText(20,375,halfYString);    //Half text
    p.drawText(20,212,thirdYString);    //7.5
    p.drawText(20,537,quarterYString);    //3.5




    int whileXBars=102; //Constant to draw the line between each facility
    int whileRectangle=55; //First rectangle place
    int xConstant =50; //Constant between each rectangle
    int xText =60; //First text place

    for (int k=0;k<numberOfList;k++)
    {
        //Do that  x Facility time
        //Precision line + Text for X axis
        p.drawLine(whileXBars,700,whileXBars,705); //Split between histogram


        p.save();
        p.translate(xText,715);
        p.rotate(45); // or 270
        p.drawText(0,0, facilityList.at(k)); //list->first->getName();
        p.restore();

        //Draw Rectangle
        p.setBrush(Qt::blue);
        qDebug() <<((data.at(k)/maxY)*650);

        p.drawRect(whileRectangle,700,45,-((data.at(k)/maxY)*650)); //Negative so we can draw them from starting line, easier that way.
                                                       //Now we have to format the data so it is proportional to the maxY
                                                       //Aka : n / max * 700
      //  p.drawRect(whileRectangle,700,45,-data.at(k));
        whileXBars = whileXBars+xConstant;
        whileRectangle = whileRectangle + xConstant;
        xText = xText+xConstant;
    }
}

void Histogram::setGeneralData(QList<QString> anIdList,QList<double> aMistmatchList)
{
    facilityList =  anIdList;
    data = aMistmatchList;

    //Get all data needed
}
