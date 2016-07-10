#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H

#include <QMainWindow>
#include <QObject>
#include <QSensorReading>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDebug>
class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass(QObject *parent = 0)
        : QObject(parent)
    {
        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        if (source) {
            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                    this, SLOT(positionUpdated(QGeoPositionInfo)));
            source->startUpdates();
        }
    }

private slots:
    void positionUpdated(const QGeoPositionInfo &info)
    {
        qDebug() << "Position updated:" << info;
    }
};
namespace Ui {
class iDom_client;
}

class iDom_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit iDom_client(QWidget *parent = 0);
    ~iDom_client();

private slots:
    void on_progressBar_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_released();



    void on_swiatlo_clicked();

    void on_lineEdit_editingFinished();

    void on_pushButton_2_clicked();

private:
    Ui::iDom_client *ui;
    int i = 0;
};

#endif // IDOM_CLIENT_H
