#include "rsa.h"
#include <iostream>

using namespace std;

int main(void)
{
    Rsa rsa;
    Key key = rsa.produce_keys();

//    key.pkey = 681532377;
//    key.ekey = 5046722;
//    key.dkey = 5064656;
    cout << "pkey: " << key.pkey << endl;
    cout << "ekey: " << key.ekey << endl;
    cout << "dkey: " << key.dkey << endl;
    long msg;
    char ge;
    cout << "wpisz wiadomosc:  " << endl;
    cin >> ge;
    msg = ge;
    long msg_des = rsa.endecrypt(msg, key.ekey, key.pkey);
    cout << " zakodowana: " << msg_des << endl;
    msg_des = rsa.endecrypt(msg_des, key.dkey, key.pkey);
    cout << "po odkodowaniu: " << (char)msg_des << endl;
    return 0;
}
