#ifndef SETALARM_H
#define SETALARM_H

#include <QDialog>
#include "../libs/useful/useful.h"
#include "variable.h"

namespace Ui {
class setAlarm;
}

class  setAlarm: public QDialog
{
    Q_OBJECT
    iDom_CONFIG *m_config;
    Clock timeAlarm;
public:
    explicit setAlarm(iDom_CONFIG *config, QWidget *parent = 0);
    ~setAlarm();

private slots:
    void on_b_hourUp_clicked();

    void on_b_hourDown_clicked();

    void on_b_minutesUp_clicked();

    void on_b_minutesDown_clicked();

    void on_b_ok_clicked();

private:
    Ui::setAlarm *ui;
public:
    void displayHour(int h);
    void displayMinutes(int min);
signals:
    void messageInfo(QString tit, QString msg);
    void alarmSetSignal(Clock c);
};

#endif // SETALARM_H
