#ifndef TRAININGTHREAD_H
#define TRAININGTHREAD_H

#include <QThread>
#include <QMessageBox>
#include <QObject>

#include "../FANN-test/fann-src/floatfann.h"
#include "../FANN-test/fann-src/fann_cpp.h"

#include "types.h"

class trainingThread : public QThread
{
    Q_OBJECT
public:

    trainingThread(NET_CONF * ptr);
    ~trainingThread() = default;

    void run() final;

    NET_CONF* netConfigPTR;

   static int print_callback(FANN::neural_net &net, FANN::training_data &train,
                              unsigned int max_epochs, unsigned int epochs_between_reports,
                              float desired_error, unsigned int epochs, void *user_data);
    void train();
signals:

    void updateProgressBar(int i);
    void updateLog(QString s);
    void trainingDone();
};

#endif // TRAININGTHREAD_H
