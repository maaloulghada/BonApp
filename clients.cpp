#include "clients.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTableWidget>
#include <QSqlRecord>
#include <map>
#include <QMessageBox>
using namespace std;
clients::clients()
{

}

clients::clients(QString nom, QString adresse, int id, QString prenom, QString email, QString tel)
{

}

QString clients::get_nom(){return nom;}
QString clients::get_adresse(){return adresse;}
int clients::get_id(){return id;}
QString clients::get_prenom(){return prenom;}
QString clients::get_email(){return email;}
QString clients::get_tel(){return tel;}

bool clients::addClient(){
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID, NOM, PRENOM, ADRESSE, EMAIL, TEL)"
                  "VALUES(:ID, :NOM, :PRENOM, :ADRESSE, :EMAIL, :TEL)");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":ADRESSE",adresse);
    query.bindValue(":EMAIL",email);
    query.bindValue(":TEL",tel);
    return query.exec();
}



bool clients::addClientToDB(QString id, QString nom, QString prenom, QString adresse, QString email, QString tel){
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID, NOM, PRENOM, ADRESSE, EMAIL, TEL)"
                  "VALUES(:ID, :NOM, :PRENOM, :ADRESSE, :EMAIL, :TEL)");
    query.bindValue(":ID",id);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":ADRESSE",adresse);
    query.bindValue(":EMAIL",email);
    query.bindValue(":TEL",tel);
    bool result = query.exec();




    return result;
}

void clients::processClientTable(QTableWidget* clientsTable)
{

    QSqlQuery query("SELECT ID, NOM, PRENOM, ADRESSE, EMAIL, TEL FROM CLIENT");
    clientsTable->clear();

    int numberOfRows = 0;
    if(query.last())
    {
        numberOfRows =  query.at() + 1;
        query.first();
        query.previous();
    }

    clientsTable->setRowCount(numberOfRows);

    int columns = query.record().count();
    QSqlRecord record = query.record();
    clientsTable->setColumnCount(columns);
    QStringList columnsNames = QStringList();
    for(int s=0;s<columns;s++)
    {
        columnsNames<<record.fieldName(s);
    }
    clientsTable->setHorizontalHeaderLabels(columnsNames);
    int row = 0;
    while (query.next()) {
        for(int column = 0; column < columns; column++)
        {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(column).toString());
            if(column == 0)
            {
                auto flags = item->flags();

                flags.setFlag(Qt::ItemIsEditable, false);
                item->setFlags(flags);

            }
            clientsTable->setItem(row, column, item);

        }
        row++;

     }


}



void clients::deleteSelectedCoupons(QTableWidget * couponsTable)
{

    map<QString,bool> toDelete;

    foreach(QTableWidgetItem* item,  couponsTable->selectedItems())
    {
        toDelete[couponsTable->item(item->row(),0)->text()] = true;
    }
    map<QString,bool>::iterator it;

    for(it=toDelete.begin(); it!=toDelete.end(); ++it){
            QSqlQuery query;
            query.prepare("DELETE FROM COUPON WHERE ID = :ID");
            query.bindValue(":ID", it->first);
            query.exec();
          //cout << it->first << " => " << it->second << '\n';
       }
    processClientTable(couponsTable);
    string aaa = std::to_string(toDelete.size()) + " Coupons deleted successfully";
    QMessageBox::information(nullptr, QObject::tr("Coupons Deleted"),
                      QObject::tr(aaa.c_str()), QMessageBox::Ok);



}
void clients::deleteSelectedClients(QTableWidget * clientsTable)
{

    map<QString,bool> toDelete;

    foreach(QTableWidgetItem* item, clientsTable->selectedItems())
    {
        toDelete[clientsTable->item(item->row(),0)->text()] = true;
    }
    map<QString,bool>::iterator it;

    for(it=toDelete.begin(); it!=toDelete.end(); ++it){
            QSqlQuery query;
            query.prepare("DELETE FROM CLIENT WHERE ID = :ID");
            query.bindValue(":ID", it->first);
            query.exec();
          //cout << it->first << " => " << it->second << '\n';
       }
    processClientTable(clientsTable);
    string aaa = std::to_string(toDelete.size()) + " Clients deleted successfully";
    QMessageBox::information(nullptr, QObject::tr("Clients Deleted"),
                      QObject::tr(aaa.c_str()), QMessageBox::Ok);



}

void clients::processCouponTable(QTableWidget* couponsTable)
{




    QSqlQuery query("SELECT ID, CODE, STARTDATE, ENDDATE, CONTRAINTS, USES FROM COUPONS");
    couponsTable->clear();


    int numberOfRows = 0;
    if(query.last())
    {
        numberOfRows =  query.at() + 1;
        query.first();
        query.previous();
    }


    couponsTable->setRowCount(numberOfRows);
    int columns = query.record().count();
    QSqlRecord record = query.record();
    couponsTable->setColumnCount(columns);
    QStringList columnsNames = QStringList();
    for(int s=0;s<columns;s++)
    {
        columnsNames<<record.fieldName(s);
    }
    couponsTable->setHorizontalHeaderLabels(columnsNames);
    int row = 0;

    while (query.next()) {
        for(int column = 0; column < columns; column++)
        {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(column).toString());
            if(column == 0)
            {
                auto flags = item->flags();

                flags.setFlag(Qt::ItemIsEditable, false);
                item->setFlags(flags);

            }

            couponsTable->setItem(row, column, item);
        }
        row++;

     }
}


bool clients::remove(QString id)
{
QSqlQuery query;
query.prepare("DELETE FROM EMPLOYEE WHERE ID = :ID");
query.bindValue(":ID", id);
return    query.exec();
}

bool clients::modify(){
    QSqlQuery query;

    return query.exec();
}


void changeSelectedClientCell(QTableWidget* clientsTable,int row, int column)
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET NOM= :NOM, PRENOM= :PRENOM, ADRESSE= :ADRESSE, TEL= :TEL WHERE ID= :ID");

    query.bindValue(":ID",clientsTable->item(row,0)->text());
    query.bindValue(":NOM",clientsTable->item(row,1)->text());
    query.bindValue(":PRENOM",clientsTable->item(row,2)->text());
    query.bindValue(":ADRESSE",clientsTable->item(row,3)->text());
    query.bindValue(":EMAIL",clientsTable->item(row,4)->text());
    query.bindValue(":TEL",clientsTable->item(row,5)->text());

    query.exec();
}
