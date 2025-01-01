#ifndef FRAMEOPTIONS_H
#define FRAMEOPTIONS_H

#include <QFrame>
#include "../libs/config_files/config_files.h"
#include "variable.h"
namespace Ui {
class FrameOptions;
}

class FrameOptions : public QFrame
{
    Q_OBJECT
    QStringList commandList;
public:
    explicit FrameOptions(QWidget *parent = 0);
    ~FrameOptions();
    void setConfigFile(iDom_CONFIG *config);
    void setCommandList(QStringList &commandList);
    QStringList getCommandList();

private:
    Ui::FrameOptions *ui;
    config_Files configFile;
    iDom_CONFIG *config;
signals:
    void s_sendCommandList(QStringList list);
    void s_fontSize(QString s);
private slots:
    void on_textEditCommandList_textChanged();
    void on_okbutton_clicked();
    void on_applyButton_clicked();
    void on_fontSize_currentIndexChanged(QString arg1);
    void on_encryptCheckBox_stateChanged(int arg1);

    void on_serverAddres_editingFinished();
};

#endif // FRAMEOPTIONS_H
