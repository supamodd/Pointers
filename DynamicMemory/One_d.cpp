#include<iostream>
#include"One_d.h"
using namespace std;

int* push_front(int* arr, int& n, int value)
{
    int* new_arr = new int[n + 1];
    new_arr[0] = value;
    for (int i = 0; i < n; i++)
    {
        new_arr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = nullptr;

    n++;
    return new_arr;
}

int* insert(int* arr, int& n, int index, int value)
{
    if (index < 0 || index > n)
    {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return arr; // Возвращаем исходный массив без изменений
    }

    int* new_arr = new int[n + 1];
    for (int i = 0, j = 0; i < n + 1; i++)
    {
        if (i == index)
        {
            new_arr[i] = value;
        }
        else {
            new_arr[i] = arr[j];
            j++;
        }
    }
    delete[] arr;
    arr = nullptr;
    n++;
    return new_arr;
}

int* pop_back(int* arr, int& n)
{
    if (n == 0)
    {
        cout << "Ошибка: Массив пуст!" << endl;
        return arr; // Возвращаем исходный массив без изменений
    }

    int* new_arr = new int[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    n--;
    return new_arr;
}

int* pop_front(int* arr, int& n)
{
    if (n == 0) 
    {
        cout << "Ошибка: Массив пуст!" << endl;
        return arr;
    }

    int* new_arr = new int[n - 1];
    for (int i = 1; i < n; i++)
    {
        new_arr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    n--;
    return new_arr;
}

int* erase(int* arr, int& n, int index)
{
    if (n == 0) 
    {
        cout << "Ошибка: Массив пуст!" << endl;
        return arr;
    }
    if (index < 0 || index >= n)
    {
        cout << "Ошибка: Индекс вне диапазона!" << endl;
        return arr;
    }

    int* new_arr = new int[n - 1];
    for (int i = 0, j = 0; i < n; i++)
    {
        if (i != index)
        {
            new_arr[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = nullptr;
    n--;
    return new_arr;
}
