#ifndef STATISTICS_H
#define STATISTICS_H

#include <QApplication>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "data.h"

using namespace std;

class Statistics{
  public:
        vector<record> dane;
        int dataFrom; //index pierwszego recordu zakresu zainteresowania
        int dataAt; //index ostatniego recordu zakresu zainteresowania


        Statistics(string file, QString &mess);
        ~Statistics();

        bool setDataFrom( tm &dataFrom) ;
        bool setDataAt( tm &dataAt) ;

        int getRecordIndex(tm &time);
        record* getRecord(tm &time);
        record* getRecord(int id);

        vector<record> getDane();

        template <class T>
        T getMax(int mode);
        template <class T>
        T getMin(int mode);

        float getMean(int);
        float getMedian(int);
        float getStandardDeviation(int);
        tm* stringToTm(string data);

        long tmToLong(tm &data);
        long tmToLong(int index);
        double tmToDouble(int index);

        tm secondsToTm(double m);

    private:
        int stoi_my(string s);
        float stof_my(string s);
        void displayData(tm &dataFrom, string name);
        void displayRecord(record &r, string name);
        bool firstIsLater(const tm &first, const tm &second);
        bool fileExists(const string& name);

};

#endif // STATISTICS_H
