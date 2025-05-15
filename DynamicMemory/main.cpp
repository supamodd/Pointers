#include<iostream>
using namespace std;
#include"FillRand.h"
#include"Print.h"
#include"One_d.h"
#include"dd_push.h"
#include"dd_pop.h"
#include"Other_func.h"


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
    setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1


    int n;
    cout << "Введите размер массива: "; cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);
    Print(arr, n);
    arr = push_front(arr, n, 100);
    cout << "добавления элемента в начало: " << endl;
    Print(arr, n);

    arr = insert(arr, n, 2, 200);
    cout << "добавление значения по указанному индексу: " << endl;
    Print(arr, n);

    arr = pop_back(arr, n);
    cout << "Последний удаленный элемент: " << endl;
    Print(arr, n);

    arr = pop_front(arr, n);
    cout << "Нулевой элемент: " << endl;
    Print(arr, n);

    arr = erase(arr, n, 1);
    cout << "удаление элемента массива по указанному индексу: " << endl;
    Print(arr, n);
    delete[] arr;
    //Memory leak
#endif DYNAMIC_MEMORY_1

    int rows;
    int cols;
    cout << "Введите количество строк: "; cin >> rows;
    cout << "Введите количество элементов строк "; cin >> cols;

    //(1) Создаем массив указателей:
    int** arr = new int* [rows];
    //(2) Выделяем память под строки двумерного динамического массива:
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    FillRand(arr, rows, cols);
    Print(arr, rows, cols);

    arr = push_row_back(arr, rows, cols);
    Print(arr, rows, cols);

    arr = push_row_front(arr, rows, cols);
    cout << "Добавлена строка в начало " << endl;
    Print(arr, rows, cols);

    arr = insert_row(arr, rows, cols, 2);
    cout << "Добавлена строка по индексу: " << endl;
    Print(arr, rows, cols);

    arr = push_col_back(arr, rows, cols);
    cout << "Добавлен столбец в конец" << endl;
    Print(arr, rows, cols);

    arr = push_col_front(arr, rows, cols);
    cout << "Добавлен столбец в начало" << endl;
    Print(arr, rows, cols);

    arr = insert_col(arr, rows, cols, 2);
    cout << "Добавлен столбец в середину" << endl;
    Print(arr, rows, cols);

    arr = pop_row_back(arr, rows, cols);
    cout << "Удалена последняя строка" << endl;
    Print(arr, rows, cols);
    
    arr = pop_row_front(arr, rows, cols);
    cout << "Удалена первая строка" << endl;
    Print(arr, rows, cols);
    
    arr = erase_row(arr, rows, cols, 2);
    cout << "Удалена строка по индексу" << endl;
    Print(arr, rows, cols);
    
    arr = pop_col_back(arr, rows, cols);
    cout << "Удален последний столбец" << endl;
    Print(arr, rows, cols);
    
    arr = pop_col_front(arr, rows, cols);
    cout << "Удален первый столбец" << endl;
    Print(arr, rows, cols);
    
    arr = erase_col(arr, rows, cols, 2);
    cout << "Удален столбец по индексу" << endl;
    Print(arr, rows, cols);
    
    Clear(arr, rows);
}