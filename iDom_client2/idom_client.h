#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class iDom_client; }
QT_END_NAMESPACE

class iDom_client : public QMainWindow
{
    Q_OBJECT

public:
    iDom_client(QWidget *parent = nullptr);
    ~iDom_client();

private:
    Ui::iDom_client *ui;
};
#endif // IDOM_CLIENT_H
