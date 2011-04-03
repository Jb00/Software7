#include "adduserctrl.h"

AddUserCtrl* AddUserCtrl::anInstance = NULL;


AddUserCtrl::AddUserCtrl()
{
    userName="";
    password="";
    type="";
}
AddUserCtrl::~AddUserCtrl(){}


AddUserCtrl* AddUserCtrl::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AddUserCtrl; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}


void AddUserCtrl::addToDb()
{
   if (!(userName == ""))
    {
        qDebug() <<"BEFORE";
        qDebug() <<userList->size();

        User * aUser = new User(password,userName,type); //Create the facility to add
                qDebug() <<"middle";
        userList->append(aUser); //Append it to the list of facility
        qDebug() <<"AFTER";
        qDebug() <<userList->size();
        userList=NULL;


    QSqlQuery query;
    QString queryText;

    //MISS AREA AND FACILITY ID UNSURE YET


    //the main insert script
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    queryText = "INSERT INTO user (username, password,permissionLvl)"
                " VALUES (:name, :password, :type)";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    query.prepare(queryText);

    //binding the variables from the form to the query
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    query.bindValue(":name", userName);
    query.bindValue(":password", password);
    query.bindValue(":type", type);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    query.exec(); //executing the query
}
    userName="";
    password="";
    type="";
///    id =-1;
}

void AddUserCtrl::setName(QString aName)
{
    userName = aName;
}

void AddUserCtrl::setPassword(QString aPassword)
{
    password = aPassword;
}

void AddUserCtrl::setType(QString aType)
{
    type =aType;
}

/*
void AddUserCtrl::setId(int anId)
{
    id=anId;
}
*/

void AddUserCtrl::setList(QList<User *> *aUserList)
{
    userList=aUserList;
}
