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

    void on_buttonBox_accepted();

private:
    Ui::setAlarm *ui;
signals:

    void alarmSetSignal(Clock c);
};

#endif // SETALARM_H
