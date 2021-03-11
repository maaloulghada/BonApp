#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include"gateauxc.h"
#include"commandec.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goToOrders_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_goToProducts_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_goToStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_goToClient_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_back_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addProduct_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_showProducts_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->GatTab->setModel(tabGateaux.show());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select ID from GATEAUX"));
    ui->comboBox_id->setModel(mod);
}

void MainWindow::on_back_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_back_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_back_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_back_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

//START EMPLOYEE PART

void MainWindow::on_goToEmployee_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_toolButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_toolButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select CIN from EMPLOYEE"));
    ui->comboBox_2->setModel(mod);
}

void MainWindow::on_back_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

//show employees

void MainWindow::on_toolButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->empTable->setModel(tableEmployee.show());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select CIN from EMPLOYEE"));
    ui->comboBox->setModel(mod);
}

//add employee

void MainWindow::on_toolButton_save_2_clicked()
{
    int cin= ui->lineEdit_cin->text().toInt();
    QString fullname= ui->lineEdit_fullname->text();
    int age= ui->lineEdit_age->text().toInt();
    QString email= ui->lineEdit_email->text();
    int phone= ui->lineEdit_phone->text().toInt();
    QString address= ui->lineEdit_address->text();

    int x=0;

    string str_cin = to_string(cin);
    string str_phone = to_string(phone);
    string m = email.toStdString();

    if (str_cin.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("CIN must contain 8 numbers"), QMessageBox::Ok);
              x++;
    }

    else if (fullname=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Name can't be empty"), QMessageBox::Ok);
              x++;
    }

    else if (age<18 || age>35)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Age must be between 18 and 35"), QMessageBox::Ok);
              x++;
    }

    else if (m.find("@gmail.com")== std:: string::npos)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Email must end with @gmail.com"), QMessageBox::Ok);
              x++;
    }

    else if (str_phone.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Phone number must be composed of 8 numbers"), QMessageBox::Ok);
              x++;
    }

    else if (address=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Address can't be empty"), QMessageBox::Ok);
              x++;
    }

    else if(x==0)
    {
    employee e(cin,fullname,age,email,phone,address);
    bool toTest =e.add();
    if(toTest)
    {
        QMessageBox::information(nullptr, QObject::tr("Adding Employee"),
                          QObject::tr("Employee added successfully"), QMessageBox::Ok);
    }
    ui->lineEdit_cin->clear();
    ui->lineEdit_fullname->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_address->clear();
    ui->stackedWidget->setCurrentIndex(7);
    }
}

//delete employee

void MainWindow::on_toolButton_10_clicked()
{
    int cin = ui->comboBox->currentText().toInt();
    tableEmployee.remove(cin);
    ui->empTable->setModel(tableEmployee.show());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select CIN from EMPLOYEE"));
    ui->comboBox->setModel(mod);
}

//modify employee

void MainWindow::on_toolButton_modify_clicked()
{
    int cin = ui->comboBox_2->currentText().toInt();
    QString fullname= ui->lineEdit_fullname_m->text();
    int age= ui->lineEdit_age_m->text().toInt();
    QString email= ui->lineEdit_email_m->text();
    int phone= ui->lineEdit_phone_m->text().toInt();
    QString address= ui->lineEdit_address_m->text();

    int x=0;

    string str_phone = to_string(phone);
    string m = email.toStdString();

    if (fullname=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Name can't be empty"), QMessageBox::Ok);
              x++;
    }

    else if (age<18 || age>35)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Age must be between 18 and 35"), QMessageBox::Ok);
              x++;
    }

    else if (m.find("@gmail.com")== std:: string::npos)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Email must end with @gmail.com"), QMessageBox::Ok);
              x++;
    }

    else if (str_phone.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Phone number must be composed of 8 numbers"), QMessageBox::Ok);
              x++;
    }

    else if (address=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Address can't be empty"), QMessageBox::Ok);
              x++;
    }

    else if(x==0)
    {
    employee e(cin,fullname,age,email,phone,address);
    bool toTest =e.modify();
    if(toTest)
    {
        QMessageBox::information(nullptr, QObject::tr("Editing Employee"),
                          QObject::tr("Employee's info edited successfully"), QMessageBox::Ok);
    }
    ui->lineEdit_fullname_m->clear();
    ui->lineEdit_age_m->clear();
    ui->lineEdit_email_m->clear();
    ui->lineEdit_phone_m->clear();
    ui->lineEdit_address_m->clear();
    ui->stackedWidget->setCurrentIndex(7);
    }
}

//END EMPLOYEE PART

void MainWindow::on_addProduct_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_showProducts_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

//Gateaux part

void MainWindow::on_toolButton_save_clicked()
{
    QString ID= ui->lineEdit_id->text();
    QString NAME= ui->lineEdit_name->text();
    int QUANTITY= ui->spinBox_quantity->text().toInt();
    int PRICE= ui->lineEdit_price->text().toInt();


        int x=0;
        if (x==0)
        {
            gateauxC g(ID,NAME,QUANTITY,PRICE);
            bool toTest=g.add_gateaux();

        if(toTest)
        {
            QMessageBox::information(nullptr, QObject::tr("Adding Product"),
                              QObject::tr("Product added successfully"), QMessageBox::Ok);
        }
        ui->lineEdit_name->clear();
        ui->lineEdit_id->clear();
        ui->spinBox_quantity->clear();
        ui->lineEdit_price->clear();
        ui->stackedWidget->setCurrentIndex(2);
        }

}

void MainWindow::on_toolButton_delete_clicked()
{
    int id = ui->comboBox_id->currentText().toInt();
    tabGateaux.remove(id);
    ui->GatTab->setModel(tabGateaux.show());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select ID from GATEAUX"));
    ui->comboBox_id->setModel(mod);
}



void MainWindow::on_toolButton_savemod_clicked()
{
    QString ID = ui->lineEdit_id_3->text();
    QString NAME= ui->lineEdit_name_3->text();
    int QUANTITY= ui->spinBox_quantity_3->text().toInt();
    int PRICE= ui->lineEdit_price_3->text().toInt();

    int x=0;
    if (x==0)
    {
     gateauxC g(ID,NAME,QUANTITY,PRICE);
    bool toTest =g.modify();
    if(toTest)
    {
        QMessageBox::information(nullptr, QObject::tr("Editing Product"),
                          QObject::tr("Product's info edited successfully"), QMessageBox::Ok);
    }
    ui->lineEdit_name_3->clear();
    ui->spinBox_quantity_3->clear();
    ui->lineEdit_price_3->clear();
    ui->stackedWidget->setCurrentIndex(4);
    ui->GatTab->setModel(tabGateaux.show());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select ID from GATEAUX"));
    }
}

void MainWindow::on_GatTab_activated(const QModelIndex &index)
{
    QString val=ui->GatTab->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM GATEAUX WHERE ID = '"+val+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->stackedWidget->setCurrentIndex(15);
                ui->lineEdit_id_3->setText(query.value(0).toString());
                ui->lineEdit_name_3->setText(query.value(1).toString());
                ui->spinBox_quantity_3->setValue(query.value(2).toInt());
                ui->lineEdit_price_3->setText(query.value(3).toString());
            }
        }
}
/*
void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
    tablecommande.remove(id);
    ui->tableC->setModel(tablecommande.show());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select CIN from EMPLOYEE"));
    ui->comboBox->setModel(mod);
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery(("select NAME from GATEAUX"));
    QString ID= ui->lineEdit_idc->text();
    ui->comboBox_name->setModel(mod);
    int SOMME= ui->lineEdit_somme->text().toInt();


        int x=0;
        if (x==0)
        {
            commandeC cc(ID,GATEAUXNAME,SOMME);
            bool toTest=cc.add_commande();

        if(toTest)
        {
            QMessageBox::information(nullptr, QObject::tr("Adding Order"),
                              QObject::tr("Order added successfully"), QMessageBox::Ok);
        }
        ui->lineEdit_idc->clear();
        ui->lineEdit_somme->clear();
        ui->comboBox_name->clear();
        ui->stackedWidget->setCurrentIndex(1);
        }
}
*/
