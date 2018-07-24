#ifndef FANN_GUI_H
#define FANN_GUI_H

#include <QMainWindow>
#include "../FANN-test/fann-src/floatfann.h"
#include "../FANN-test/fann-src/fann_cpp.h"

namespace Ui {
class fann_GUI;
}

class fann_GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit fann_GUI(QWidget *parent = nullptr);
    ~fann_GUI();

    static int print_callback(FANN::neural_net &net, FANN::training_data &train,
        unsigned int max_epochs, unsigned int epochs_between_reports,
        float desired_error, unsigned int epochs, void *user_data);
    void train();


private slots:
    void on_b_startTrain_clicked();

    void on_trainingData_textChanged();

    void on_b_save_trainData_clicked();

    void on_b_OK_clicked();

private:
    Ui::fann_GUI *ui;

    QString trainingDataPatch = "training.data";
};

#endif // FANN_GUI_H
