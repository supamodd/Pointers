#include<iostream>
#include"dd_push.h"
using namespace std;

int** push_row_back(int** arr, int& rows, const int cols)
{
    //(1) Создаем буферный массив указателей нужного размера:
    int** buffer = new int* [rows + 1];

    //(2) Копируем адреса строк в буферный массив указателей:
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i];
    }

    //(3)Удаляем исходный массив указателей:
    delete[] arr;


    //(4) Создаем добавляемую строку, и записываем ее адрес в массив указателей:
    buffer[rows] = new int[cols] {};

    //(5) При добавлении в массив строки, количество его строк увеличивается на 1:
    rows++;

    //(6) Возвращаем новый массив на место вызова:
    return buffer;
}

int** push_row_front(int** arr, int& rows, int cols)
{
    int** new_arr = new int* [rows + 1];
    new_arr[0] = new int[cols] {};
    for (int i = 0; i < rows; i++)
    {
        new_arr[i + 1] = arr[i];
    }
    rows++;
    delete[] arr;
    arr = nullptr;
    return new_arr;
}

int** insert_row(int** arr, int& rows, int cols, int index)
{
    int** new_arr = new int* [rows + 1];
    for (int i = 0, j = 0; i < rows + 1; i++)
    {
        if (i == index)
        {
            new_arr[i] = new int[cols] {};
        }
        else
        {
            new_arr[i] = arr[j];
            j++;
        }

    }
    rows++;
    delete[] arr;
    arr = nullptr;
    return new_arr;
}

int** push_col_back(int** arr, int rows, int& cols)
{
    cols++;  // Увеличиваем cols

    // Выделяем новый массив
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new int[cols] {}; // Выделяем память под строку
        for (int j = 0; j < cols - 1; ++j)
        { //Копируем старые значения
            new_arr[i][j] = arr[i][j];
        }
    }
    // Освобождаем память, выделенную под старый массив
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;


    return new_arr;
}

int** push_col_front(int** arr, int rows, int& cols)
{
    cols++;  // Увеличиваем cols

    // Выделяем новый массив
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new int[cols] {}; // Выделяем память под строку
        new_arr[i][0] = 0; // Заполняем первый столбец нулями

        for (int j = 0; j < cols - 1; ++j)
        {
            new_arr[i][j + 1] = arr[i][j];
        }
    }
    // Освобождаем память, выделенную под старый массив
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;


    return new_arr;
}

int** insert_col(int** arr, int rows, int& cols, int index)
{
    cols++;  // Увеличиваем cols

    // Выделяем новый массив
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new int[cols] {}; // Выделяем память под строку

        for (int j = 0, k = 0; j < cols; ++j)
        { //Копируем старые значения
            if (j == index) {
                new_arr[i][j] = 0;  // Заполняем столбец в нужном индексе нулями
            }
            else {
                new_arr[i][j] = arr[i][k];
                k++;
            }
        }
    }
    // Освобождаем память, выделенную под старый массив
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return new_arr;
}
