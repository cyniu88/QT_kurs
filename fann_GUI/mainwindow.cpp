#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

//#include "C:/cyniu/PROGRAMOWANIE/libs/fann_lib/src/include/fann.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OKpushButton_clicked()
{

//         //    std::cout << "argument argc: " << argc << " pierwszy: "<< argv[1] << " drugi: " << argv[2] <<std::endl;
//        const unsigned int num_input = 4;
//        const unsigned int num_output = 1;
//        const unsigned int num_layers = 3;
//        const unsigned int num_neurons_hidden = 4;
//        const float desired_error = (const float) 0.0000001;
//        const unsigned int max_epochs = 500;
//        const unsigned int epochs_between_reports = 1 ;

//        struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

//        fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
//        fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

//        fann_train_on_file(ann, "fann.data", max_epochs, epochs_between_reports, desired_error);

//        fann_save(ann, "fann.net");

//        fann_destroy(ann);

//    qDebug() << "\n \ntest"  ;

//        fann_type *calc_out;
//        fann_type input[4];

//        struct fann *ann2  = fann_create_from_file("fann.net");

//        input[0] = 1;
//        input[1] = 1;
//        input[2] = 1;
//        input[3] = 1;
//        calc_out = fann_run(ann2, input);

//        qDebug("xor test (%f,%f) -> %f\n", input[0], input[1], calc_out[0]);
//        if (calc_out[0] > 0.5){
//            qDebug("play golf");
//        }
//        else {
//            qDebug("do not plaay golf!");
//        }
//        qDebug("\n");
//    fann_destroy(ann2);

    QStringList list = ui->textEdit->toPlainText().split('\n');

    QFile file("out.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
     QTextStream out(&file);

    for (QString n : list){
        while (n.size()<10) {
            n.append(' ');
        }
        qDebug() << "n " << n;
        for(auto i : n.toStdString()){
            out << static_cast<float>(i)/1000 << " ";
        }
        out << "\n" << "0 1 0" << "\n";
    }


static int counter = 0;
qDebug() << ++counter;
}

void MainWindow::on_pushButton_clicked()
{
    ui->OKpushButton->setChecked(!(ui->OKpushButton->isChecked()));
}
