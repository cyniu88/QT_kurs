#include <iostream>

using namespace std;



void crypt (string & toEncrypt, string key)
{
  unsigned int keySize = key.size();

  for (unsigned int i = 0; i < toEncrypt.size (); i++)
    {
      toEncrypt[i] ^= key[keySize];
      cout << key[keySize];

      if (keySize==0){
          keySize = key.size();
      }
      else{
      --keySize;
      }
    }

    cout << '!' << key.size();
}

int main ( )
{


\

  string key = "password";
  string msg = "sprzedam opla";
  crypt (msg, key);
  cout << "\nzaszyfrowany: " << msg << endl;
  crypt (msg, key);
  cout << "\nodszyfrowany: " << msg << endl;
  return 0;
}
