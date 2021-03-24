#ifndef COMMANDEC_H
#define COMMANDEC_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class commandeC
{
public:
    commandeC();
    commandeC(QString,QString,int,int);
    QString get_id();
    QString get_namegat();
    int get_somme();
    int get_quantc();
    bool add_commande();
    //func
    QSqlQueryModel * showc();
    bool removec(int);
    bool modifyc();
private:
    QString ID,GATEAUXNAME;
    int SOMME,QUANTC;
};

#endif // COMMANDEC_H
