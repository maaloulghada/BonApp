#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recette.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_recettesBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_queueBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_rajouterBtn_clicked()
{
    int id = ui->rajouterIdTxt->text().toInt();
    QString nom = ui->rajouterNomTxt->text();
    int duree = ui->rajouterTime->time().second()+ui->rajouterTime->time().minute()*60+ui->rajouterTime->time().hour()*60*60;

    recette r(id,nom,duree);

    bool test = r.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\nClick Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Ajout non effectué\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_recettesTab_currentChanged(int index)
{
    if(index==1){
        ui->rafficherTable->setModel(Rtmp.afficher());
    }
}

void MainWindow::on_rsupprimerBtn_clicked()
{
    int id = ui->rsupprimerTxt->text().toInt();
    bool test = Rtmp.supprimer(id);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectué\nClick Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression non effectué\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}
