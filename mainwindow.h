#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recette.h"

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
    void on_recettesBtn_clicked();

    void on_queueBtn_clicked();

    void on_rajouterBtn_clicked();

    void on_recettesTab_currentChanged(int index);

    void on_rsupprimerBtn_clicked();

private:
    Ui::MainWindow *ui;

    recette Rtmp;
};
#endif // MAINWINDOW_H
