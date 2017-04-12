#ifndef FRAMEOPTIONS_H
#define FRAMEOPTIONS_H

#include <QFrame>

namespace Ui {
class FrameOptions;
}

class FrameOptions : public QFrame
{
    Q_OBJECT

public:
    explicit FrameOptions(QWidget *parent = 0);
    ~FrameOptions();

private:
    Ui::FrameOptions *ui;
};

#endif // FRAMEOPTIONS_H
