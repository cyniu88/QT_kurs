#ifndef WWWSHOWWINDOW_H
#define WWWSHOWWINDOW_H

#include <QMainWindow>
#ifdef Q_OS_WIN
#include <QAxWidget>
#endif
namespace Ui {
class wwwShowWindow;
}

class wwwShowWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit wwwShowWindow(QWidget *parent = 0);
    ~wwwShowWindow();
#ifdef Q_OS_WIN
    QAxWidget  axWidgetTemperature;
    QAxWidget *axWidgetTemperaturePTR = &axWidgetTemperature;
#endif
private slots:
    void on_pushButton_clicked();

private:
    Ui::wwwShowWindow *ui;
};

#endif // WWWSHOWWINDOW_H
