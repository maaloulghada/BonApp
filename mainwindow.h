#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <employee.h>
#include <gateauxc.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_goToOrders_clicked();

    void on_goToProducts_clicked();

    void on_goToStock_clicked();

    void on_goToClient_clicked();

    void on_goToEmployee_clicked();

    void on_back_1_clicked();

    void on_back_2_clicked();

    void on_back_3_clicked();

    void on_back_4_clicked();

    void on_back_5_clicked();

    void on_addProduct_clicked();

    void on_showProducts_clicked();

    void on_back_6_clicked();

    void on_back_7_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_3_clicked();

    void on_back_8_clicked();

    void on_back_9_clicked();

    void on_toolButton_save_2_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_11_clicked();

    void on_toolButton_modify_clicked();

    void on_back_10_clicked();

    void on_toolButton_save_clicked();

    void on_addProduct_2_clicked();
    
    void on_showProducts_2_clicked();
    
    void on_toolButton_delete_clicked();

    void on_toolButton_savemod_clicked();

    void on_GatTab_activated(const QModelIndex &index);

   // void on_pushButton_2_clicked();

    //void on_pushButton_clicked();

    //void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    //louay doc
    employee tableEmployee;
    //ghada doc
    gateauxC tabGateaux;
};
#endif // MAINWINDOW_H
