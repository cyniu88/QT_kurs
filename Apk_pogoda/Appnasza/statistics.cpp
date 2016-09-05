#include "statistics.h"
#include "data.h"

/***********************************
w konstruktorze czytamy z pliku "feeds.csv" wszystkie dane jakie są.
***********************************/

Statistics::Statistics(std::string file, QString &mess){

    std::ifstream plik;
    std::string temp, line;
     plik.open( file.c_str());
   // if (fileExists("feeds.csv")){
    if (plik.is_open()){
        mess = "ok";

        getline( plik, temp ,'\n'); //wywalamy linijke pierwsza
        //for( int i = 0; plik.eof() != 1; i ){
        while(getline(plik, line)){
            stringstream lineStream(line);

            getline( lineStream, temp, ',' );

            dane.push_back(record());
            //getline( plik, temp, ',' );

            if(temp.size() < 1) {
                continue;
            }

            dane[dane.size()-1].data = *stringToTm(temp);
            getline( lineStream, temp, ',' );
            dane[dane.size()-1].id=stoi_my(temp);

            getline( lineStream, temp, ',');
            dane[dane.size()-1].degreesI=stof_my(temp);

            getline( lineStream, temp, ',');
            dane[dane.size()-1].smog=stoi_my(temp);

            getline( lineStream, temp, '\n');
            dane[dane.size()-1].degreesO=stof_my(temp);

            //*****sprawdzenie poprawnosci danych****//*
            if((dane[dane.size()-1].degreesI < -100) || (dane[dane.size()-1].degreesO < -100)){
                dane.pop_back();
                cout<<"zly odczyt temperatury - wywalam rekord nr "<<dane.size()<< endl;
            }

    }

    plik.close();
    dataFrom = 0;
    dataAt = dane.size()-1;
    cout<<"dataFromLong: "<<tmToLong(dataFrom)<<endl;
    cout<<"dataAtLong: "<<tmToLong(dataAt)<<endl;
/*********wyswietlanie vectora***********/
/*
    for( int i = 0; i < dane.size() ; i++ )
    {
        cout << dane[ i ].data.tm_year << "-";
        cout << (dane[ i ].data.tm_mon+1) << "-";
        cout << dane[ i ].data.tm_mday << " ";
        cout << dane[ i ].data.tm_hour << ":";
        cout << dane[ i ].data.tm_min << ":";
        cout << dane[ i ].data.tm_sec << " ";
        cout << dane[ i ].id << " ";
        cout << dane[ i ].degreesI << " ";
        cout << dane[ i ].smog << " ";
        cout << dane[ i ].degreesO << "\n";
    }
*/
    }else
        mess = "error";
}

Statistics::~Statistics(){

}

bool Statistics::fileExists(const std::string& name){
    std::ifstream f(name.c_str());
    return f.good();
}

/******setDataFrom/setDataAt*************************
Zapamietuje pierwszy/ostatni id (int) zakresu zainteresowania

*****************************************************/
bool Statistics::setDataFrom( tm &dataFrom){
    int tempId = getRecordIndex(dataFrom);
    if(tempId == -1) return false;
    this->dataFrom=tempId;
    return true;
}
bool Statistics::setDataAt( tm &dataAt){
    int tempId = getRecordIndex(dataAt);
    if(tempId == -1) return false;
    this->dataAt=tempId;
    return true;
}
/*************************************************
zwraca index recordu w Vectorze, ktory wystepuje bezposrednio po time
lub -1 gdy time jest z poza zakresu najmniejszej i najwiekszej daty w Vectorze
***************************************************/
int Statistics::getRecordIndex(tm &time){
    if((!firstIsLater(time,dane[0].data)) || (firstIsLater(time,dane[dane.size()-1].data))){ //z poza naszego zakresu dat
        return -1;
    }
    int i=0;
    while((i < dane.size()) & (firstIsLater(time,dane[i++].data))); //co sie stanie jak time bedzie starsze tylko od ostatniego rekordu?
//konczy sie petlic gdy dojdzie do konca lub ogarniemy ktora data w naszym Vectorze jest pozniejsza od time
    if(i > dane.size()){ //nie znalazl czegos takiego
        return -1;
    }
    i--;
//teraz i wskazuje nam indeks pierwszego elementu Vectora, ktory ma date pozniejsza od time. nie musi byc ta sama!
    return i;
}

/***********opis funkcji getRecord(tm &time)****************
zwraca wskaznik na record na ktory wystepuje najblizej PO time
zwraca wskaznik na record o id=-1 gdy time jest z poza pierwszej i ostatniej daty!
*************************************************************/
record* Statistics::getRecord(tm &time){
    if((!firstIsLater(time,dane[0].data)) || (firstIsLater(time,dane[dane.size()-1].data))){ //z poza naszego zakresu dat
        record* res = new record;
        res->id=-1;
        return res;
    }
    int i=0;
    while((i < dane.size()) & (firstIsLater(time,dane[i++].data)));
//konczy sie petlic gdy dojdzie do konca lub ogarniemy ktora data w naszym Vectorze jest pozniejsza od time
    if(i > dane.size()){ //nie znalazl czegos takiego
        record* res = new record;
        res->id=-1;
        return res;
    }
    i--;
//teraz i wskazuje nam indeks pierwszego elementu Vectora, ktory ma date pozniejsza od time. nie musi byc ta sama!
    return &dane[i];
}

/***************opis funkcji getRecord(int id)***************
zwraca wskaznik na record o podanym id.
jesli nie ma takiego recordu z takim id - zwraca racord o id=-1
*************************************************************/
record* Statistics::getRecord(int id){
    for(int i = 0 ; i < dane.size()-1; i++){
            if(dane[i].id = id) return &dane[i];
    }
    record *res = new record;
    res->id=-1;
    return res;
}

vector<record> Statistics::getDane(){
    return dane;
}

/*******************************************************************
//mode=0 -> smog mode=1-<DegreesI mode=2-<DegreesO  mode=3->id
nalezy podac typ szablonowy zgodny z typem pola w strukturze
np. dla getMax(0) nalezy podac int
jesli wywolamy getMax<int>(2) to sparsuje floata do inta (odcina po przecinku liczby)
gdy mode bedzie niewlasciwy zwracamy wartosc 777
********************************************************************/

float Statistics::getMean(int mode){
    switch(mode){
    case 0:
        {
            int meanSmog=0;
            for(int i=dataFrom; i<=dataAt; i++){
                meanSmog+= dane[i].smog;
            }
            return  (1.*meanSmog/((dataAt-dataFrom)+1));
            break;
        }

    case 1:
        {
            float mean=0;
            for(int i=dataFrom; i<=dataAt; i++){
                mean+= dane[i].degreesI;
            }
            return  (mean/((dataAt-dataFrom)+1));
            break;
        }

      case 2:
          {
            float mean=0;
            for(int i=dataFrom; i<=dataAt; i++){
                mean+= dane[i].degreesO;
            }
            return  (mean/((dataAt-dataFrom)+1));
            break;
          }

    default:
        return  -777;
    }
}
float Statistics::getMedian(int mode){
    switch(mode){
    case 0:
        {
            float median=0;
            int tab[(dataAt-dataFrom)+1];
            for(int k=0; k<=dataAt-dataFrom; k++){
                    tab[k]=dane[k+dataFrom].smog;
                }
            sort(tab, tab+(dataAt-dataFrom)+1);
            if(((dataAt-dataFrom)+1)%2==0){
                median= 1.*(tab[(((dataAt-dataFrom)+1-2)/2)] +tab[(((dataAt-dataFrom)+1)/2)])/2;
            }
            else{
                median= 1.*tab[(((dataAt-dataFrom)+1-1)/2)];
            }
            return median;
            break;
        }
    case 1:
        {
            float median=0;
            float tab[(dataAt-dataFrom)+1];
            for(int k=0; k<=dataAt-dataFrom; k++){
                    tab[k]=dane[k+dataFrom].degreesI;
                }
            sort(tab, tab+(dataAt-dataFrom)+1);
            if(((dataAt-dataFrom)+1)%2==0){
                median= (tab[(((dataAt-dataFrom)+1-2)/2)] +tab[(((dataAt-dataFrom)+1)/2)])/2;
            }
            else{
                median= tab[(((dataAt-dataFrom)+1-1)/2)];
            }
            return median;
            break;
        }
    case 2:
       {
            float median=0;
            float tab[(dataAt-dataFrom)+1];
            for(int k=0; k<=dataAt-dataFrom; k++){
                    tab[k]=dane[k+dataFrom].degreesO;
                }
            sort(tab, tab+(dataAt-dataFrom)+1);
            if(((dataAt-dataFrom)+1)%2==0){
                median= (tab[(((dataAt-dataFrom)+1-2)/2)] +tab[(((dataAt-dataFrom)+1)/2)])/2;
            }
            else{
                median= tab[(((dataAt-dataFrom)+1-1)/2)];
            }
            return median;
            break;
        }

    default:
        return  -777;
 }
}
float Statistics::getStandardDeviation(int mode){
    switch(mode){
    case 0:
        {
            float dev=0;
            int tab[(dataAt-dataFrom)+1];
            for(int k=0; k<=dataAt-dataFrom; k++){
                    tab[k]=dane[k+dataFrom].smog;
                    dev+=pow((1.*tab[k]-getMean(mode)),2);
                }
            return  sqrt((dev/((dataAt-dataFrom)+1)));
            break;
        }
    case 1:
        {
            float dev=0;
            float tab[(dataAt-dataFrom)+1];
            for(int k=0; k<=dataAt-dataFrom; k++){
                    tab[k]=dane[k+dataFrom].degreesI;
                    dev+=pow((tab[k]-getMean(mode)),2);
                }
            return  sqrt((dev/((dataAt-dataFrom)+1)));
            break;
        }

    case 2:
        {
            float dev=0;
            float tab[(dataAt-dataFrom)+1];
            for(int k=0; k<=dataAt-dataFrom; k++){
                    tab[k]=dane[k+dataFrom].degreesO;
                    dev+=pow((tab[k]-getMean(mode)),2);
                }
            return  sqrt((dev/((dataAt-dataFrom)+1)));
            break;
        }
    default:
        return  -777;

}
}

template <class T>
T Statistics::getMax(int mode){
    if(mode == 0){
        T max = dane[0].smog;
        for(int i = 1; i < dane.size(); i++){
            if(dane[i].smog > max) max = dane[i].smog;
        }
        return max;
    }else if(mode == 1){
        T max = dane[0].degreesI;
        for(int i = 1; i < dane.size(); i++){
            if(dane[i].degreesI > max) max = dane[i].degreesI;
        }
        return max;
    }else if(mode == 2){
        T max = dane[0].degreesO;
        for(int i = 1; i < dane.size(); i++){
            if(dane[i].degreesO > max) max = dane[i].degreesO;
        }
        return max;
    }else if(mode == 3){
        return dane[dane.size()-1].id;
    }else{
        return 777;
    }
}

template <class T>
T Statistics::getMin(int mode){
    if(mode == 0){
        T max = dane[0].smog;
        for(int i = 1; i < dane.size(); i++){
            if(dane[i].smog < max) max = dane[i].smog;
        }
        return max;
    }else if(mode == 1){
        T max = dane[0].degreesI;
        for(int i = 1; i < dane.size(); i++){
            if(dane[i].degreesI < max) max = dane[i].degreesI;
        }
        return max;
    }else if(mode == 2){
        T max = dane[0].degreesO;
        for(int i = 1; i < dane.size(); i++){
            if(dane[i].degreesO < max) max = dane[i].degreesO;
        }
        return max;
    }else if(mode == 3){
        return dane[0].id;
    }else{
        return 777;
    }
}

int Statistics::stoi_my(std::string s){
    int x;
    stringstream ss(s.c_str());
    ss >> x;
    return x;
}

float Statistics::stof_my(std::string s){
    float x;
    stringstream ss(s.c_str());
    ss >> x;
    return x;
}

long Statistics::tmToLong(tm &data){
    tm my_tm = data;
    my_tm.tm_year -= 1900;
    return mktime(&my_tm);
}

long Statistics::tmToLong(int index){
    tm my_tm = dane[index].data;
    my_tm.tm_year -= 1900;
    return mktime(&my_tm);
}

double Statistics::tmToDouble(int index){
    tm my_tm = dane[index].data;
    my_tm.tm_year -= 1900;
    return (double)mktime(&my_tm);
}

tm Statistics::secondsToTm(double m){
    time_t arg = (time_t)m;
    struct tm tim;
    tim = *localtime(&arg);
    tim.tm_year += 1900;
    //tim.tm_hour -= 1;
    //cout<<tim.tm_hour<<":"<<tim.tm_min<<endl;
    return tim;
}

//2016-05-14 14:53:57
tm* Statistics::stringToTm(string data){
    tm* res = new tm;
    res->tm_year = stoi_my(data.substr(0,4));
    res->tm_mon = (stoi_my(data.substr(5,2))-1);
    res->tm_mday = stoi_my(data.substr(8,2));
    res->tm_hour = stoi_my(data.substr(11,2));
    res->tm_min = stoi_my(data.substr(14,2));
    res->tm_sec = stoi_my(data.substr(17,2));
    return res;
}

void Statistics::displayData(tm &dataFrom, string name){
    cout << name << ": ";
    cout << dataFrom.tm_year << "-";
    cout << (dataFrom.tm_mon+1) << "-";
    cout << dataFrom.tm_mday << " ";
    cout << dataFrom.tm_hour << ":";
    cout << dataFrom.tm_min << ":";
    cout << dataFrom.tm_sec << " " << endl;
}

void Statistics::displayRecord(record &r, string name){
    cout <<"Record " << name << ": ";
    cout << r.id <<" "<< r.degreesI <<" "<< r.id <<" "<< r.degreesO <<" ";
    displayData(r.data, "DATA");
}

bool Statistics::firstIsLater(const tm &first, const tm &second){
    if(first.tm_year > second.tm_year)return true;
    if(first.tm_year < second.tm_year)return false;

    if(first.tm_mon > second.tm_mon) return true;
    if(first.tm_mon < second.tm_mon) return false;

    if(first.tm_mday > second.tm_mday) return true;
    if(first.tm_mday < second.tm_mday) return false;

    if(first.tm_hour > second.tm_hour) return true;
    if(first.tm_hour < second.tm_hour) return false;

    if(first.tm_min > second.tm_min) return true;
    if(first.tm_min < second.tm_min) return false;

    if(first.tm_sec > second.tm_sec) return true;
    if(first.tm_sec < second.tm_sec) return false;
    return false;
}
