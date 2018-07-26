#ifndef FANN_GUI_H
#define FANN_GUI_H

#include <QMainWindow>
#include <QSpinBox>

#include <vector>

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

    void on_b_loadTrainingData_clicked();

    void on_b_saveNetfile_clicked();

    void on_b_loadNet_clicked();

    void on_b_logClear_clicked();

    void on_net_type_currentTextChanged(const QString &arg1);

    void on_num_layers_valueChanged(int arg1);

private:
    Ui::fann_GUI *ui;

    QString trainingDataPatch = "training.data";
    std::vector < QSpinBox*> lV;

    void loadTrainingDataFromFile();
    void updateParamiterFromFileDataTraining();
    void setTrainingAlgorythm();
    bool updateLeyersVectorAndValidate();

public slots:
    void updateLog(QString s);
    void updateProgressBar(int i);
    void trainingDone();
};

#endif // FANN_GUI_H
