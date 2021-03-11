#include "produit.h"

produit::produit( int quantite_ingredient,int id_ingrediant,QString nom_ingredient,QString date_exp;)
{
    this->id_ingrediant=id_ingrediant;
    this->quantite_ingredient=quantite_ingredient;
    this->nom_ingredient=nom_ingredient;
    this->date_exp=date_exp;
}
bool produit::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_materiel);
    QString res2 = QString::number(nb_materiel);
    query.prepare("insert into materiel(id_materiel,nom_materiel,nb_materiel,date_entr)""values(:id_materiel,:nom_materiel,:nb_materiel,:date_entr)");
   query.bindValue(":id_materiel",res);
   query.bindValue(":nom_materiel",nom_materiel);
   query.bindValue(":nb_materiel",res2);
   query.bindValue(":date_entr",date_entr);
   return query.exec();
}
QSqlQueryModel * materiel::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from materiel");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_materiel"));

model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_materiel"));

model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_entr"));

model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_materiel"));
return model;
}
bool materiel::supprimer(int id_materiel)
{
QSqlQuery query;
QString res = QString::number(id_materiel);
query.prepare("Delete from materiel where id_materiel= :id_materiel");
query.bindValue(":id_materiel",res);
return query.exec();
}
