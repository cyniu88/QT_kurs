#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "../libs/android_functions/android_interface/android_interface.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    android_interface droid;

private slots:
    void on_b_sms_clicked();

    void on_put_text_textChanged();

    void on_b_prepareData_clicked();

private:
    Ui::MainWindow *ui;

    QVector<USER_S> userVecotr;
    QVector<USER_S> userVecotrCopy;

    void sendSMS(int i, int max, QString numer, QString msg);

};
#endif // MAINWINDOW_H
