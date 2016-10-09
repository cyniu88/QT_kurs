#ifndef VARIABLE_H
#define VARIABLE_H
#include "functions.h"
struct msg_s {
    int leftX;
    int leftY;
    int rightX;
    int rightY;
    int stateA;
    int stateB;
    int stateC;
    int stateD;
    QString getString(){
        std::string leftX_s = to_Std_string_4(leftX)   ;
        std::string leftY_s = to_Std_string_4(leftY)   ;
        std::string rightX_s = to_Std_string_4(rightX)   ;
        std::string rightY_s = to_Std_string_4(rightY)   ;

        return QString::fromStdString(leftX_s)+
                ":"+QString::fromStdString(leftY_s)+
                ":"+QString::fromStdString(rightX_s)+
                ":"+QString::fromStdString(rightY_s)+
                ":"+QString::number(stateA)+
                ":"+QString::number(stateB)+
                ":"+QString::number(stateC)+
                ":"+QString::number(stateD)+"#";
        //return QString::number(leftX)+":"+QString::number(leftY, )+":"+QString::number(rightX)+":"+QString::number(rightY)+":"+ QString::number(stateA)+":"+QString::number(stateB)+":"+QString::number(stateC)+":"+QString::number(stateD)+"#";

   };


};

struct my_config{
    std::string addressIP;
    int port;
    bool goWhile = false;
    msg_s messageS;
};

#endif // VARIABLE_H