#include <QDebug>
#include <QSettings>
#include "frameoptions.h"
#include "ui_frameoptions.h"

FrameOptions::FrameOptions(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameOptions)
{
    ui->setupUi(this);
}

FrameOptions::~FrameOptions()
{
    delete ui;
}

void FrameOptions::setConfigFile(iDom_CONFIG *config)
{
    this->config=config;
    QSettings settings("cyniu", "iDom");

    ui->encryptCheckBox->setChecked(settings.value("encrypted").toBool());

}

void FrameOptions::setCommandList(QStringList commandList)
{
    this->commandList = commandList;
    ui->textEditCommandList->setText(this->commandList.join('\n'));
}

QStringList FrameOptions::getCommandList()
{
    return this->commandList;
}

void FrameOptions::on_textEditCommandList_textChanged()
{
    commandList.clear();
    commandList = ui->textEditCommandList->toPlainText().split("\n");
    commandList.removeLast();
}

void FrameOptions::on_okbutton_clicked()
{
    on_applyButton_clicked();
}

void FrameOptions::on_applyButton_clicked()
{
    emit s_sendCommandList(getCommandList());
    configFile.writeToFile("config","command.cfg",ui->textEditCommandList->toPlainText().toStdString());
}

void FrameOptions::on_fontSize_currentIndexChanged()
{
    emit s_fontSize(ui->fontSize->currentText());
}

void FrameOptions::on_pushButton_clicked()
{

}

void FrameOptions::on_encryptCheckBox_stateChanged(int arg1)
{
    if (arg1 == 2)
    {
        config->encrypted=true;
    }
    else
    {
        config->encrypted=false;
    }
    QSettings settings("cyniu", "iDom");
    settings.setValue("encrypted", config->encrypted);
}
