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

private:
    Ui::iDom_Client *ui;
};

#endif // IDOM_CLIENT_H
