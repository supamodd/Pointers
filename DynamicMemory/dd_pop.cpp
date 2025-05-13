#include<iostream>
#include"dd_pop.h"
using namespace std;

int** pop_row_back(int** arr, int& rows, int cols)
{
    int** new_arr = new int* [rows - 1];
    for (int i = 0; i < rows - 1; i++)
    {
        new_arr[i] = arr[i]; //Копируем память в массив.
    }


    delete[] arr;
    rows--;
    return new_arr;
}

int** pop_row_front(int** arr, int& rows, int cols)
{
    int** new_arr = new int* [rows - 1];
    for (int i = 1; i < rows; i++)
    {
        new_arr[i - 1] = arr[i]; //Копируем память в массив.
    }

    delete[] arr;
    rows--;
    return new_arr;
}

int** erase_row(int** arr, int& rows, int cols, int index)
{
    int** new_arr = new int* [rows - 1];
    int k = 0; // Индекс для нового массива
    for (int i = 0; i < rows; ++i)
    {
        if (i == index)
        {

            continue;
        }
        new_arr[k] = arr[i]; // Копируем указатель на строку
        k++;
    }


    delete[] arr; // Освобождаем память под старый массив
    rows--;

    return new_arr;
}

int** pop_col_back(int** arr, int rows, int& cols)
{
    //Создаем новый массив
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[cols - 1] {}; // Выделяем память под строку

        for (int j = 0; j < cols - 1; j++)
        {
            new_arr[i][j] = arr[i][j];

        }
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    cols--;

    return new_arr;
}

int** pop_col_front(int** arr, int rows, int& cols)
{
    //Создаем новый массив
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[cols - 1] {}; // Выделяем память под строку

        for (int j = 1; j < cols; j++)
        {
            new_arr[i][j - 1] = arr[i][j];
        }
        delete[] arr[i];

    }
    delete[] arr;
    arr = nullptr;


    cols--;

    return new_arr;
}

int** erase_col(int** arr, int rows, int& cols, int index)
{
    //Создаем новый массив
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[cols - 1] {}; // Выделяем память под строку

        for (int j = 0, k = 0; j < cols; j++)
        {
            if (j == index)
            {
                continue;
            }
            else
            {
                new_arr[i][k] = arr[i][j];
                k++;
            }
        }
        delete[] arr[i];

    }
    delete[] arr;
    arr = nullptr;


    cols--;
    return new_arr;
}