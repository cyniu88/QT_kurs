#ifndef DATA_H
#define DATA_H

#include <QString>

struct USER_S{
    int id = 0;
    QString family = "NULL";
    QString name = "NULL";
    QString surname = "NULL";
    QString telephone = "NULL";
    QString print(){
        QString s;
        s = "id: ";
        s.append(this->id);
        s.append( " name: ");
        s.append( this->name);
        s.append( " surname: ");
        s.append( this->surname);
        s.append(" telephone: ");
        s.append( this->telephone);
        return s;
    }
//    USER_S(int id, QString name, QString surname, QString telephone){
//        this->id = id;
//        this->name = name;
//        this->surname = surname;
//        this->telephone = telephone;
//    }
};

#endif
