#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<string.h>
#include<cstdlib>
#include<iostream>
#include<conio.h>
#include <iomanip>
#include<ctime>
#include <vector> 
#include <algorithm>
#include<time.h>
using namespace std;
void swap(int* a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}
bool NextSet(int* a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false; 
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1; 
    while (l < r)
        swap(a, l++, r--);
    return true;
}
void Print(int* a, int n)  
{
    static int num = 1; 
    cout.width(3); 
    cout << num++ << ": ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    const int N = (int)1e5 + 1;
    string str;
    int idx = 0;
    int n=0, * a;
    cout << "N = ";
    cin >> str;
    a = new int[N];
    for (int i = 0; i < str.length(); i++) {
        a[idx] = str[i] - '0';
        idx++;
        n++;
    }
    sort(a, a + idx);
    
    Print(a, n);
    while (NextSet(a, n))
        Print(a, n);
    cin.get(); cin.get();
    return 0;
}