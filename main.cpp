#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test = c.createConnection();

    MainWindow w;

    if(test){
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"), QObject::tr("connection successful.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database not open"), QObject::tr("connection failed.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
