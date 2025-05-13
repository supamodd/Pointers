#include<iostream>
#include"Print.h"
using namespace std;

#define tab "\t"
#define delimiter "\n---------------------------------------------\n";


void Print(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << tab;
    }
    cout << delimiter;
}

void Print(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << tab;
        }
        cout << endl;
    }
    cout << delimiter;
}