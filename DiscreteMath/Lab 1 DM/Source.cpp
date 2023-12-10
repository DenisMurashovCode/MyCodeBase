#define _CRT_SECURE_NO_WARNINGS
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
typedef struct good {
    char name[20]; 
    int count; 
} good;

const int N = (int)1e5 + 1;
const int N1 = (int)1e5 + 1;

    
    string str;
    string str1;
    int a[N];
    int a1[N1];
    int idx = 0;
    int idx1 = 0;
    int C = 0;
    int C1 = 0;
    int AS[N];
    int AS1[N1];
    int z = 0;

    int arrayUnique(int* a, int);
    

    int arrayUnique(int* a, int size) 
    {
        for (int counter1 = 0; counter1 < size; counter1++)
        {
            for (int counter2 = counter1 + 1; counter2 < size; counter2++)
            {
                if (a[counter1] == a[counter2]) 
                {
                    for (int counter_shift = counter2; counter_shift < size - 1; counter_shift++)
                    {
                        
                        a[counter_shift] = a[counter_shift + 1];
                    }
                    size -= 1; 

                    if (a[counter1] == a[counter2]) 
                    {
                        counter2--;      
                    }
                }
            }
        }
        return size;
    }


void Mas1()
{
    cin >> str;
    if (str == "-")
    {
        a[idx] = ' ';
        //str = "";
        //return ;
    }
    else {


        for (int i = 0; i < str.length(); i++) {
            a[idx] = str[i] - '0';
            idx++;

        }
    }
}

void Mas2()
{
    cin >> str1;
    if (str1 == "-")
    {
        a1[idx1] = ' ';
    }
    else
    {
        for (int i = 0; i < str1.length(); i++) {
            a1[idx1] = str1[i] - '0';
            idx1++;
        }
    }
}

void PrintMas()
{
   
    cout << "Mas 1:      ";
    for (int counter1 = 0; counter1 < arrayUnique(a, idx); counter1++)
    {
        cout << a[counter1] << "  ";
        AS[C] = a[counter1];
        C++;
    }
    cout << endl;

    
    cout << "Mas 2:     ";
    for (int counter1 = 0; counter1 < arrayUnique(a1, idx1); counter1++)
    {
        cout << a1[counter1] << "  ";
        AS1[C1] = a1[counter1];
        C1++;
    }
    cout << endl;
}

void VhoshAB()
{
    
   
    for (int i = 0; i < C; i++)
    {
        cout << AS[i]<<' ';
    }
    cout << "\n";
    for (int i = 0; i < C1; i++)
    {
        cout << AS1[i]<<' ';
    }
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            if (AS[i] == AS1[j])
            {
                z++;
            }
            

        }
    }
    
    if (z < C)
    {
        cout << "\nА не входит в В\n";
    }
    if(z==C) {
        cout << "\nА входит в В\n";
    }
}

void Obedinenie()
{
    int* arr = (int*)malloc(sizeof(int) * (C + C1));
    for (int i = 0; i < C; i++) {
        arr[i] = AS[i];
       // cout << arr[i];
    }
    for (int i = 0; i < C1; i++)
    {
        arr[C + i] = AS1[i];
    }
    for (int i = 0; i < C + C1; i++)
    {
        cout << arr[i];
    }
    cout << '\n';
}

void Peres()
{

    int* arr = (int*)malloc(sizeof(int) * (C));
    

    
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            if (AS[i] == AS1[j])
            {
               
                    arr[i] = AS[i];
            }


        }
    }
    
    if (C > C1)
    {
        cout << "\nПустое множество\n";
    }
    if (C < C1) {
        for (int i = 0; i < C; i++)
        {
            cout << arr[i];
        }
    }
}

void Razn()
{
    int i, j, k;
    k = C;  

    for (i = 0; i < k; i++)

    {

        
        for (int i = 0; i < C; i++)
        {
            for (int j = 0; j < C1; j++)
            {
                if (AS[i] == AS1[j])
                {

                    k--;

                    for (j = i; j < k; j++)

                        AS[j] = AS[j + 1];

                    i--;
                }


            }
        }

        

    }
    


    
    if (k < C) {
        cout << "Otvet:" << endl;

        for (i = 0; i < k; i++)
        {
            cout << AS[i];
        }
    }
    if(k<C1) {
        cout << "\nПустое множество\n";
    }
   
}


void print_menu() {
    system("cls");  
    printf("What do you want to do?\n");
    printf("1. Ввести MasA\n");
    printf("2. Ввести MasB\n");
    printf("3. Вывести массивы\n");
    printf("4. Проверить вхождение\n");
    cout << "5. Объединение\n";
    cout << "6. Пересечение\n";
    cout << "7. Разность\n";
    printf("8. Exit\n");
    printf(">");
}

int get_variant(int count) {
    int variant;
    char s[100]; 
    scanf("%s", s); 

    
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: "); 
        scanf("%s", s); 
    }

    return variant;
}

int main() {

    
    setlocale(LC_ALL, "Russian");
    int variant; 
    int size = 0; 
    int capacity = 1; 

    good* goods = (good*)malloc(capacity * sizeof(good)); 

    do {

        print_menu(); 

        variant = get_variant(8); 

        switch (variant) {
        case 1:
            Mas1();
            break;

        case 2:
            Mas2();
            break;

        case 3:
            PrintMas();
            break;

        case 4:
            VhoshAB();
            break;
        case 5:
            Obedinenie();
            break;
        case 6:
            Peres();
            break;
        case 7:
            Razn();
            break;
        }

        if (variant != 8)
            system("pause"); 
    } while (variant != 8);

    return 0;
}




