#include <QDebug>
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
{  //TODO
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
}
