#ifndef PILOTWINDOW_H
#define PILOTWINDOW_H

#include <QMainWindow>
#include <QTouchEvent>
#include <QtEvents>
#include <QScroller>
namespace Ui {
class pilotWindow;
}

class pilotWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool autoReturnGaz   = true;
    bool autoReturnSkret = true;
    double *test;
  //  QTouchEvent event;
  //  bool sceneEvent(QTouchEvent *e);
protected:
void touchEvent(QTouchEvent *ev);
public:
    explicit pilotWindow(QWidget *parent = 0);
    ~pilotWindow();

private slots:
    void on_reset_clicked();

    void on_gaz_valueChanged(int value);




    void on_skret_valueChanged(int value);

    void on_skret_sliderReleased();

    void on_gaz_sliderReleased();

    void on_checkBoxPower_toggled(bool checked);

    void on_checkBoxWheel_toggled(bool checked);

private:
    Ui::pilotWindow *ui;
};

#endif // PILOTWINDOW_H
