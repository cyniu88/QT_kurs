#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H
#include <variable.h>
#include <QMainWindow>

namespace Ui {
class iDom_Client;
}

class iDom_Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit iDom_Client(iDom_CONFIG *config, QWidget *parent = 0);
    ~iDom_Client();

private slots:
    void on_EXITButton_released();

    void on_label_linkActivated(const QString &link);


    void on_disconnectButton_released();

    void on_lineEdit_editingFinished();

    void on_pushButton_released();

private:
    Ui::iDom_Client *ui;
    iDom_CONFIG *config;
};

#endif // IDOM_CLIENT_H
