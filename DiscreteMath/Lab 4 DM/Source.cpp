#include <iostream>
#include<string>
using namespace std;

int chislo = 0;
int r = 0;
string PoslChislo;

template <typename T>
string intToBin(T val)
{
    string bin;
    string BIN;

    bool meetOne = false;

    for (int i = sizeof(T) * 8 - 1; i >= 0; i--)
    {
        if (val & (1 << i))
        {
            meetOne = true;
            bin += '1';
        }
        else
        {
            if (meetOne)
            {
                bin += '0';
            }
        }

        
    }
    int nol = 0;
    nol = chislo - bin.size();
    for (int i = 0; i < nol; i++)
    {
        
        BIN += '0';
    }
    BIN += bin;
    return BIN;

}

template <typename T>
string PoslCh(T chislo)
{
    
    string bin;

    bool meetOne = false;

    for (int i = sizeof(T) * 8 - 1; i >= 0; i--)
    {
        if (chislo & (1 << i))
        {
            meetOne = true;
            bin += '1';
        }
        else
        {
            if (meetOne)
            {
                bin += '0';
            }
        }


    }
    
    return bin;
    
    r = bin.size();
   
}

int main()
{
    
    
    int val=0;
    cin >> chislo;
    int chislo1 = (chislo - 1) * 4;
    
    while (val != chislo1)
    {
        cout << intToBin(val) << endl;
        val++;
    }

    //cout << PoslCh(chislo1-1) << endl;
   
    return 0;

}
