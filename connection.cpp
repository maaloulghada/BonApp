#include "connection.h"

Connection::Connection()
{

}

bool Connection::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("ahmed");
    db.setPassword("esprit20");
    if(db.open()) test = true;
    return test;
}




void Connection::closeConnection(){db.close();}







