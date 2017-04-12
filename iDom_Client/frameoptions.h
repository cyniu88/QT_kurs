#ifndef FRAMEOPTIONS_H
#define FRAMEOPTIONS_H

#include <QFrame>

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

signals:
    s_sendCommandList(QStringList list);
private slots:
    void on_textEditCommandList_textChanged();
    void on_okbutton_clicked();
};

#endif // FRAMEOPTIONS_H
