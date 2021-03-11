#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiel.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(Mtmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_2_clicked()
{
  ui->stackedWidget ->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget ->setCurrentIndex(3);
}

void MainWindow::on_pushButton_4_clicked()
{
      ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget ->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->stackedWidget ->setCurrentIndex(2);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget ->setCurrentIndex(1);
}

void MainWindow::on_pushButton_12_clicked()
{
   ui->stackedWidget ->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
   ui->stackedWidget ->setCurrentIndex(4);
}

void MainWindow::on_pushButton_13_clicked()
{
  int id_materiel=ui->lineEdit_3 ->text().toInt();
int nb_materiel=ui->lineEdit_5 ->text().toInt();
QString nom_materiel=ui->lineEdit_4 ->text();
QString date_entr=ui->lineEdit_6 ->text();
materiel M( nb_materiel,id_materiel,nom_materiel,date_entr);
bool test=M.ajouter();
        if(test)
{  ui->tableView_2->setModel(Mtmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                           QObject::tr("ajout effectué\n"
                                       "click Cancel to exit"), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué\n"
                                                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_9_clicked()
{
     ui->stackedWidget ->setCurrentIndex(5);
}

void MainWindow::on_pushButton_16_clicked()
{
      ui->stackedWidget ->setCurrentIndex(3);
}

void MainWindow::on_pushButton_15_clicked()
{
   int id_materiel =ui->lineEdit_11 ->text().toInt();
   bool test=Mtmp.supprimer(id_materiel);
   if(test)
   {
        ui->tableView_2->setModel(Mtmp.afficher());
     QMessageBox::information(nullptr,QObject::tr("OK"),
             QObject::tr("Suppression effectué.\n"
                         "click Cancel to exit"), QMessageBox::Cancel);
   }
   QMessageBox::information(nullptr,QObject::tr("NOT OK"),
           QObject::tr("Suppression non effectué.\n"
                       "click Cancel to exit"),QMessageBox::Cancel);
}
