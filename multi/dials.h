#ifndef DIALS_H
#define DIALS_H

#include <QMainWindow>

namespace Ui {
class dials;
}

class dials : public QMainWindow
{
    Q_OBJECT

public:
    explicit dials(QWidget *parent = 0);
    ~dials();

private:
    Ui::dials *ui;
};

#endif // DIALS_H
