#ifndef KINIACYNIA_H
#define KINIACYNIA_H

#include <QMainWindow>

namespace Ui {
class KiniaCynia;
}

class KiniaCynia : public QMainWindow
{
    Q_OBJECT

public:
    explicit KiniaCynia(QWidget *parent = 0);
    ~KiniaCynia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::KiniaCynia *ui;
};

#endif // KINIACYNIA_H
