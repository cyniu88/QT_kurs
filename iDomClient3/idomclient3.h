#ifndef IDOMCLIENT3_H
#define IDOMCLIENT3_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class iDomClient3; }
QT_END_NAMESPACE

class iDomClient3 : public QMainWindow
{
    Q_OBJECT

public:
    iDomClient3(QWidget *parent = nullptr);
    ~iDomClient3();

private:
    Ui::iDomClient3 *ui;
};
#endif // IDOMCLIENT3_H
