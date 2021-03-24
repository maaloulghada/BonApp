#include "commandec.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
commandeC::commandeC()
{
    ID="";
    GATEAUXNAME="";
    SOMME=0;
    QUANTC=0;
}

commandeC::commandeC(QString ID, QString GATEAUXNAME, int SOMME, int QUANTC)
{
    this->ID = ID;
    this->GATEAUXNAME = GATEAUXNAME;
    this->SOMME = SOMME;
    this->QUANTC = QUANTC;
}

QString commandeC::get_id()
{
    return ID;
}
QString commandeC::get_namegat()
{
    return GATEAUXNAME;
}
int commandeC::get_somme()
{
    return SOMME;
}
int commandeC::get_quantc()
{
    return QUANTC;
}

bool commandeC::add_commande()
{
    QSqlQuery query;
    query.prepare("INSERT INTO COMMANDE (ID,GATEAUXNAME,SOMME,QUANTC)"
                  "VALUES(:ID,:GATEAUXNAME,:SOMME,:QUANTC)");
    query.bindValue(":ID",ID);
    query.bindValue(":GATEAUXNAME",GATEAUXNAME);
    query.bindValue(":SOMME",SOMME);
    query.bindValue(":QUANTC",QUANTC);
    return    query.exec();
}
QSqlQueryModel * commandeC::showc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("GATEUXNAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SOMME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTC"));
        return model;
}
bool commandeC::removec(int id)
{
QSqlQuery query;
QString toSearch= QString::number(id);
query.prepare("DELETE FROM COMMANDE WHERE ID = :ID");
query.bindValue(":ID", toSearch);
return    query.exec();
}

bool commandeC::modifyc(){
    QSqlQuery query;
    query.prepare("UPDATE COMMANDE SET ID= :ID, GATEAUXNAME= :GATEAUXNAME, SOMME= :SOMME, QUANTC= :QUANTC WHERE ID= :ID");
    query.bindValue(":ID",ID);
    query.bindValue(":GATEAUXNAME",GATEAUXNAME);
    query.bindValue(":SOMME",SOMME);
    query.bindValue(":QUANTC",QUANTC);
    return query.exec();
}

