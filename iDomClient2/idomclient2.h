#ifndef IDOMCLIENT2_H
#define IDOMCLIENT2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class iDomClient2; }
QT_END_NAMESPACE

class iDomClient2 : public QMainWindow
{
    Q_OBJECT

public:
    iDomClient2(QWidget *parent = nullptr);
    ~iDomClient2();

private:
    Ui::iDomClient2 *ui;
};
#endif // IDOMCLIENT2_H
