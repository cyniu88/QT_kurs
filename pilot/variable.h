#ifndef VARIABLE_H
#define VARIABLE_H
#include "functions.h"
#include <QStringList>

struct msg_s {
    int leftX = 0;
    int leftY = 0;
    int rightX   = 0;
    int rightY   = 0;
    bool lowBeam  = 0;
    bool highBeam = 0;
    bool stateC = 0;
    bool stateD = 0;
    int horiSlider = 0;
    QString getString(){
        std::string leftX_s = to_Std_string_4(leftX)   ;
        std::string leftY_s = to_Std_string_4(leftY)   ;
        std::string rightX_s = to_Std_string_4(rightX)   ;
        std::string rightY_s = to_Std_string_4(rightY)   ;
        std::string horiSlider_s = to_Std_string_4(horiSlider);

        return QString::fromStdString(leftX_s)+
                ":"+QString::fromStdString(leftY_s)+
                ":"+QString::fromStdString(rightX_s)+
                ":"+QString::fromStdString(rightY_s)+
                ":"+QString::number(lowBeam)+
                ":"+QString::number(highBeam)+
                ":"+QString::number(stateC)+
                ":"+QString::number(stateD)+
                ":"+QString::fromStdString(horiSlider_s)+"#";

    };


};

struct my_config{
    std::string addressIP;
    QStringList addressIpList;
    int port;
    bool goWhile = false;
    msg_s messageS;
};

#endif // VARIABLE_H
