#ifndef EYE_H
#define EYE_H

#include <QMainWindow>
#include <QSvgWidget>
namespace Ui {
class eye;
}

class eye : public QMainWindow
{
    Q_OBJECT

public:
    explicit eye(QWidget *parent = 0);
    ~eye();

    QSvgWidget k ;

    QByteArray obraz;

private:
    Ui::eye *ui;
};

#endif // EYE_H
