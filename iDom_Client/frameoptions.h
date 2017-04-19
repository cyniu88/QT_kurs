#ifndef FRAMEOPTIONS_H
#define FRAMEOPTIONS_H

#include <QFrame>
#include "../libs/config_files/config_files.h"

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

    void setCommandList(QStringList commandList);
    QStringList getCommandList();

private:
    Ui::FrameOptions *ui;
    config_Files configFile;

signals:
    void s_sendCommandList(QStringList list);
private slots:
    void on_textEditCommandList_textChanged();
    void on_okbutton_clicked();
    void on_applyButton_clicked();
};

#endif // FRAMEOPTIONS_H
