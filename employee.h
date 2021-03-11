#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class employee
{
public:
    employee();
    employee(int,QString,int,QString,int,QString);

    int get_cin();
    QString get_fullname();
    int get_age();
    QString get_email();
    int get_phone();
    QString get_address();

    //functions
    bool add();
    bool remove(int);
    bool modify();
    QSqlQueryModel * show();

private:
    QString fullname, email, address;
    int age, cin, phone;
};

#endif // EMPLOYEE_H
