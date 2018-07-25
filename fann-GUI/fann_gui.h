#ifndef FANN_GUI_H
#define FANN_GUI_H

#include <QMainWindow>
#include "../FANN-test/fann-src/floatfann.h"
#include "../FANN-test/fann-src/fann_cpp.h"

#include "types.h"
#include "trainingthread.h"
#include "string.h"

namespace Ui {
class fann_GUI;
}

class fann_GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit fann_GUI(QWidget *parent = nullptr);
    ~fann_GUI();
    NET_CONF netConfig;
    trainingThread* trainingT;

private slots:
    void on_b_startTrain_clicked();

    void on_trainingData_textChanged();

    void on_b_save_trainData_clicked();

    void on_b_OK_clicked();

private:
    Ui::fann_GUI *ui;

    QString trainingDataPatch = "training.data";

public slots:
    void updateLog(QString s);
    void updateProgressBar(int i);
    void trainingDone();
};

#endif // FANN_GUI_H
