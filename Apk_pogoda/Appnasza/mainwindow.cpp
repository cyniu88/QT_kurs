#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statistics.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    //getFile = false;
    //makePlot();
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::checkString(QString &temp, QChar character)
{
    if(temp.count("\"")%2==0) {
        // if(temp.size() == 0 && character != ',') // problem with line endings
        //  return;
        if(temp.startsWith(QChar('\"')) && temp.endsWith(QChar('\"'))) {
            temp.remove(QRegExp("^\""));
            temp.remove(QRegExp("\"$"));
        }
        // will probably fail if there are 4 or more double quotes
        temp.replace("\"\"", "\"");
        QStandardItem *item = new QStandardItem(temp);
        standardItemList.append(item);
        if(character != QChar(',')) {
            model->appendRow(standardItemList);
            standardItemList.clear();
        }
        temp.clear();
    }   else {
        temp.append(character);
    }
}

void MainWindow::on_action_Open_triggered()
{
    //model = new QStandardItemModel(this); //w konstruktorze
   // ui->tableView->setModel(model);
    std::string fileName = QFileDialog::getOpenFileName (this, "Open CSV file", QDir::currentPath(), "CSV (*.csv)").toStdString();
    //getFile = true;

    if (!fileName.empty()){
        QString message;
        stats = new Statistics(fileName, message);
        writeMessage(message);
        makePlot();

        ui->checkBox_I->setEnabled(true);
        ui->checkBox_O->setEnabled(true);
        ui->checkBox_Smog->setEnabled(true);
        ui->Draw_Button->setEnabled(true);
        ui->Clear_Button->setEnabled(true);
        ui->defaultRange->setEnabled(true);
        ui->statsdegreesI_Button->setEnabled(true);
        ui->statsdegreesO_Button->setEnabled(true);
        ui->statssmog_Button->setEnabled(true);
    }
}



 void MainWindow::makePlot()
 {
     ui->customPlot->plotLayout()->insertRow(0);
     ui->customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->customPlot, "Temperatura & SMOG\n na Szuwarach"));
     ui->customPlot->legend->setVisible(true);
     ui->customPlot->legend->setFont(QFont("Helvetica",9));
     ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop);

     ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
     double now = (double)stats->tmToLong(stats->getDane()[0].data);//QDateTime::currentDateTime().toTime_t();//tu wpisywac pierwsza date z pliku czy tam pierwsza do wyswietlenia
     //double last = 24*3600*10+ now;// w sekundach
     ui->customPlot->xAxis->setAutoTickStep(true);
    // QCPAxisRect *wideAxisRect = new QCPAxisRect(ui);

     ui->customPlot->addGraph();
     ui->customPlot->graph(0)->setPen(QPen(Qt::red));
     ui->customPlot->graph(0)->setName("temp. inside");
     ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));
     ui->customPlot->addGraph();
     ui->customPlot->graph(1)->setPen(QPen(Qt::blue));
     ui->customPlot->graph(1)->setName("temp. outside");
     ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));
     ui->customPlot->addGraph(ui->customPlot->xAxis, ui->customPlot->yAxis2);
     ui->customPlot->graph(2)->setPen(QPen(Qt::black));
     ui->customPlot->graph(2)->setName("smog");
     ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));

     QVector<double> x, ti, to, s;
     for (int i=0; i<stats->getDane().size()-1; ++i){
         //x.push_back((double)(i+1));
         x.push_back((double)stats->tmToLong(stats->getDane()[i].data));
         ti.push_back(stats->getDane()[i].degreesI);
         to.push_back(stats->getDane()[i].degreesO);
         s.push_back(stats->getDane()[i].smog);
     }
     data_from=(double)stats->tmToLong(stats->getDane()[stats->dataFrom].data);
     data_to=(double)stats->tmToLong(stats->getDane()[stats->dataAt].data);
     last=data_to;
     ui->customPlot->graph(0)->setData(x,ti);
     ui->customPlot->graph(1)->setData(x,to);
     ui->customPlot->graph(2)->setData(x,s);

     ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
     ui->customPlot->xAxis->setDateTimeFormat("hh:mm\ndd.MM.yyyy");
     ui->customPlot->yAxis2->setVisible(true);
     ui->customPlot->yAxis->setRange(0.0, 50.0);
     ui->customPlot->yAxis2->setRange(0.0, 400.0);
     ui->customPlot->xAxis->setRange(now, last);//xxxxxxxxxxxxxxxxxxxxxx

     ui->customPlot->xAxis->setLabel("Date");
     ui->customPlot->yAxis->setLabel("Temperatura (C)");
     ui->customPlot->yAxis2->setLabel("Smog (mg/m^3)");

     ui->customPlot->setInteraction(QCP::iRangeZoom, true);
     ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->xAxis->orientation());
     ui->customPlot->setInteraction(QCP::iRangeDrag, true);
     ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->xAxis->orientation());
     ui->customPlot->replot();
     ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

 }

    void MainWindow::writeMessage(QString mess){
    ui->label->setText(mess);
 }

void MainWindow::on_checkBox_I_clicked()
{
    if(ui->checkBox_I->isChecked()==false)
        ui->customPlot->graph(0)->setVisible(false);
    else
        ui->customPlot->graph(0)->setVisible(true);
        ui->customPlot->replot();
}

void MainWindow::on_checkBox_O_clicked()
{
    if(ui->checkBox_O->isChecked()==false)
        ui->customPlot->graph(1)->setVisible(false);
    else
        ui->customPlot->graph(1)->setVisible(true);
        ui->customPlot->replot();
}

void MainWindow::on_checkBox_Smog_clicked()
{
    if(ui->checkBox_Smog->isChecked()==false)
        ui->customPlot->graph(2)->setVisible(false);
    else
        ui->customPlot->graph(2)->setVisible(true);
        ui->customPlot->replot();
}

void MainWindow::on_Clear_Button_clicked()
{
    ui->customPlot->graph(0)->setVisible(false);
    ui->customPlot->graph(1)->setVisible(false);
    ui->customPlot->graph(2)->setVisible(false);
    ui->checkBox_I->setChecked(false);
    ui->checkBox_Smog->setChecked(false);
    ui->checkBox_O->setChecked(false);
    ui->customPlot->replot();
}

void MainWindow::on_Draw_Button_clicked()
{
    ui->customPlot->graph(0)->setVisible(true);
    ui->customPlot->graph(1)->setVisible(true);
    ui->customPlot->graph(2)->setVisible(true);
    ui->checkBox_I->setChecked(true);
    ui->checkBox_Smog->setChecked(true);
    ui->checkBox_O->setChecked(true);
    ui->customPlot->replot();
}

void MainWindow::on_defaultRange_clicked()
{
    data_from=(double)stats->tmToLong(stats->getDane()[0].data);
    data_to=last;

    stats->dataFrom=0;

    QDate begin{};
    begin.setDate(2016, 5, 14);
    QDate end{};
    end.setDate(2016, 8, 8);

    ui->dateTime_from->setDate(begin);
    ui->dateTime_to->setDate(end);
    ui->customPlot->xAxis->setRange(data_from, data_to);
    ui->customPlot->replot();

}

void MainWindow::on_dateTime_from_editingFinished()
{
    data_from =ui->dateTime_from->dateTime().toTime_t();
        ui->customPlot->xAxis->setRange(data_from, data_to);
        ui->customPlot->replot();
}

void MainWindow::on_dateTime_to_editingFinished()
{
    data_to =ui->dateTime_to->dateTime().toTime_t();
        ui->customPlot->xAxis->setRange(data_from, data_to);
        ui->customPlot->replot();

}

void MainWindow::on_statsdegreesI_Button_clicked()
{
    tm temp = stats->secondsToTm(ui->dateTime_from->dateTime().toTime_t());
    stats->setDataFrom(temp);
    tm temp2 = stats->secondsToTm(ui->dateTime_to->dateTime().toTime_t());
    stats->setDataAt(temp2);

    float a,b,c;
    a=stats->getMean(1);
    b=stats->getMedian(1);
    c=stats->getStandardDeviation(1);

    std::ostringstream buff, buff2, buff3;
    buff<<a;
    buff2<<b;
    buff3<<c;

    ui->meanvalue_Label->setText(QString(buff.str().c_str()));
    ui->medianvalue_Label->setText(QString(buff2.str().c_str()));
    ui->deviationvalue_Label->setText(QString(buff3.str().c_str()));
}

void MainWindow::on_statsdegreesO_Button_clicked()
{
    tm temp = stats->secondsToTm(ui->dateTime_from->dateTime().toTime_t());
    stats->setDataFrom(temp);
    tm temp2 = stats->secondsToTm(ui->dateTime_to->dateTime().toTime_t());
    stats->setDataAt(temp2);

    float a,b,c;
    a=stats->getMean(2);
    b=stats->getMedian(2);
    c=stats->getStandardDeviation(2);

    std::ostringstream buff, buff2, buff3;
    buff<<a;
    buff2<<b;
    buff3<<c;

    ui->meanvalue_Label->setText(QString(buff.str().c_str()));
    ui->medianvalue_Label->setText(QString(buff2.str().c_str()));
    ui->deviationvalue_Label->setText(QString(buff3.str().c_str()));
}

void MainWindow::on_statssmog_Button_clicked()
{
    tm temp = stats->secondsToTm(ui->dateTime_from->dateTime().toTime_t());
    stats->setDataFrom(temp);
    tm temp2 = stats->secondsToTm(ui->dateTime_to->dateTime().toTime_t());
    stats->setDataAt(temp2);

    float a,b,c;
    a=stats->getMean(0);
    b=stats->getMedian(0);
    c=stats->getStandardDeviation(0);

    std::ostringstream buff, buff2, buff3;
    buff<<a;
    buff2<<b;
    buff3<<c;

    ui->meanvalue_Label->setText(QString(buff.str().c_str()));
    ui->medianvalue_Label->setText(QString(buff2.str().c_str()));
    ui->deviationvalue_Label->setText(QString(buff3.str().c_str()));
}
