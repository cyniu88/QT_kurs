#ifndef MYQPLAINTEXTEDIT_H
#define MYQPLAINTEXTEDIT_H
#include <QPlainTextEdit>

class myQPlainTextEdit :    public QPlainTextEdit
{
    // Q_OBJECT
public:

    explicit myQPlainTextEdit(QObject *parent = 0) { this->setAttribute(Qt::WA_AcceptTouchEvents);};
    bool event(QEvent *e){
        qDebug() << "!!!!!!!!!\n   dupaaaaa  " << e->type() << " \n\n";
           return  QPlainTextEdit::event(e);
    };

};
#endif // MYQPLAINTEXTEDIT_H
