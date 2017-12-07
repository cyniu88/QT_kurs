#ifndef SETALARM_H
#define SETALARM_H

#include <QDialog>
#include "../libs/useful/useful.h"


namespace Ui {
class setAlarm;
}

class setAlarm : public QDialog
{
    Q_OBJECT

    Clock timeAlarm;
public:
    explicit setAlarm(QWidget *parent = 0);
    ~setAlarm();

private slots:
    void on_b_hourUp_clicked();

    void on_b_hourDown_clicked();

    void on_b_minutesUp_clicked();

    void on_b_minutesDown_clicked();

    void on_b_ok_clicked();

private:
    Ui::setAlarm *ui;

    void displayHour(int h);
    void displayMinutes(int min);
signals:
    void messageInfo(QString tit, QString msg);
    void alarmSetSignal(Clock c);
};

#endif // SETALARM_H
