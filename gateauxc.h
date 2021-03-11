#ifndef GATEAUXC_H
#define GATEAUXC_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class gateauxC
{
public:
    gateauxC();
    gateauxC(QString,QString,int,int);
    QString get_id();
    QString get_name();
    int get_quantity();
    int get_price();
    bool add_gateaux();
    //func
    QSqlQueryModel * show();
    bool remove(int);
    bool modify();

private:
    QString ID,NAME;
    int QUANTITY,PRICE;

};

#endif // GATEAUXC_H
