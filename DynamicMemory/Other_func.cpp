#include<iostream>
#include"Other_func.h"
using namespace std;

int** Allocate(int rows, int cols) 
{
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        arr[i] = new int[cols] {};
    }
    return arr;
}

void Clear(int** arr, int rows) 
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;
}