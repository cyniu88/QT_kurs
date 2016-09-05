#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QStandardItemModel>
#include <iostream>
#include "statistics.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void writeMessage(QString mess);
     double data_from, data_to, last;

private slots:
    void on_action_Open_triggered();
    void checkString(QString &temp, QChar character = 0);

    void makePlot();

    //    void drawLine(double now, int num, int r, int g, int b, std::string label, std::string fromFile);
    void on_checkBox_I_clicked();

    void on_checkBox_O_clicked();

    void on_checkBox_Smog_clicked();

    void on_Clear_Button_clicked();

    void on_Draw_Button_clicked();

    void on_defaultRange_clicked();

    void on_dateTime_from_editingFinished();

    void on_dateTime_to_editingFinished();

    //void on_actionReadme_triggered();

    void on_statsdegreesI_Button_clicked();

    void on_statsdegreesO_Button_clicked();

    void on_statssmog_Button_clicked();

private:
    Ui::MainWindow *ui;
    QList<QStringList> csv;
    QStandardItemModel *model;
    QList<QStandardItem*> standardItemList;
    Statistics *stats;

};

#endif // MAINWINDOW_H
