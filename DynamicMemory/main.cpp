#include<iostream>
using namespace std;

template<typename T>void FillRand(T arr[], const int n);
template<typename T>void FillRand(T** arr, const int rows, const int cols);
template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);
template<typename T>T* push_front(T* arr, int& n, T value);
template<typename T>T* insert(T* arr, int& n, int index, T value);
template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T* pop_front(T* arr, int& n);
template<typename T>T* erase(T* arr, int& n, int index);

template<typename T>T** Allocate(int rows, int cols);
template<typename T>void Clear(T** arr, int rows);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, int cols);
template<typename T>T** insert_row(T** arr, int& rows, int cols, int index);

template<typename T>T** push_col_back(T** arr, int rows, int& cols);
template<typename T>T** push_col_front(T** arr, int rows, int& cols);
template<typename T>T** insert_col(T** arr, int rows, int& cols, int index);

template<typename T>T** pop_row_back(T** arr, int& rows, int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, int cols);
template<typename T>T** erase_row(T** arr, int& rows, int cols, int index);

template<typename T>T** pop_col_back(T** arr, int rows, int& cols);
template<typename T>T** pop_col_front(T** arr, int rows, int& cols);
template<typename T>T** erase_col(T** arr, int rows, int& cols, int index);

#define tab "\t"
#define delimiter "\n----------------------------------------------\n";

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
    /*for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;*/
}

template<typename T>void FillRand(T arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

template<typename T>void FillRand(T** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

template<typename T>void Print(T arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << tab;
    }
    cout << delimiter;
}

template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* push_front(T* arr, int& n, T value)
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

template<typename T>T* insert(T* arr, int& n, int index, T value)
{
    T* new_arr = new T[n + 1];
    for (int i = 0, j = 0; i < n + 1; i++)
    {
        if (i == index)
        {
            new_arr[i] = value;
        }
        else 
        {
            new_arr[i] = arr[j];
            j++;
        }
    }
    delete[] arr;
    arr = nullptr;
    n++;
    return new_arr;
}

template<typename T>T* pop_back(T* arr, int& n)
{
    T* new_arr = new T[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    n--;
    return new_arr;
}

template<typename T>T* pop_front(T* arr, int& n)
{
    T* new_arr = new T[n - 1];
    for (int i = 1; i < n; i++)
    {
        new_arr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    n--;
    return new_arr;
}

template<typename T>T* erase(T* arr, int& n, int index)
{
    T* new_arr = new T[n - 1];
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

template<typename T>T** Allocate(int rows, int cols)
{
    T** arr = new T* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols] {};
    }
    return arr;
}

template<typename T>void Clear(T** arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

template<typename T>
void copyArray(T* dest, T* src, int size) {
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

template<typename T>
T** push_row_back(T** arr, int& rows, const int cols) {
    T** new_arr = new T * [rows + 1];  // ???????? ?????? ??? ?????? ?????????? ??????? ???????
    for (int i = 0; i < rows; ++i) {
        new_arr[i] = arr[i];  // ???????? ???????? ?? ??????
    }

    new_arr[rows] = new T[cols]{};  // ???????? ?????? ??? ?????? ??????????? ??????

    rows++;  // ?????????? ?????????? ?????

    delete[] arr;  // ??????????? ??????
    return new_arr;
}
template<typename T>
T** push_row_front(T** arr, int& rows, int cols)
{
    T** new_arr = new T * [rows + 1];
    new_arr[0] = new T[cols]{};
    for (int i = 0; i < rows; i++)
    {
        new_arr[i + 1] = arr[i];
    }
    rows++;
    delete[] arr;
    return new_arr;
}
template<typename T>
T** insert_row(T** arr, int& rows, int cols, int index)
{
    T** new_arr = new T * [rows + 1];
    for (int i = 0, j = 0; i < rows + 1; i++)
    {
        if (i == index)
        {
            new_arr[i] = new T[cols]{};
        }
        else
        {
            new_arr[i] = arr[j];
            j++;
        }

    }
    rows++;
    delete[] arr;

    return new_arr;
}
template<typename T>
T** push_col_back(T** arr, int rows, int& cols)
{
    cols++;  // ??????????? cols

    // ???????? ????? ??????
    T** new_arr = new T * [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new int[cols] {}; // ???????? ?????? ??? ??????
        for (int j = 0; j < cols - 1; ++j)
        { //???????? ?????? ????????
            new_arr[i][j] = arr[i][j];
        }
    }
    // ??????????? ??????, ?????????? ??? ?????? ??????
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;


    return new_arr;
}

template<typename T>
T** push_col_front(T** arr, int rows, int& cols)
{
    int new_cols = cols + 1;

    // Create a new array
    T** new_arr = new T * [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new T[new_cols]{};  // ???????? ?????? ??? ??????
        new_arr[i][0] = 0; // Set the new element to 0
        for (int j = 0; j < cols; ++j)
        {
            new_arr[i][j + 1] = arr[i][j];
        }
    }

    // Free memory allocated for the old array
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;


    cols = new_cols;
    return new_arr;
}

template<typename T>
T** insert_col(T** arr, int rows, int& cols, int index)
{
    int new_cols = cols + 1;

    // Create a new array
    T** new_arr = new T * [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new T[new_cols]{}; // ???????? ?????? ??? ??????

        for (int j = 0, k = 0; j < new_cols; ++j)
        { //Copy the content array
            if (j == index) {
                new_arr[i][j] = 0;  // Insert the new element in the specified index
            }
            else {
                new_arr[i][j] = arr[i][k];
                k++;
            }
        }
    }
    // Free memory allocated for the old array
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    cols = new_cols;
    return new_arr;
}

template<typename T>
T** pop_row_back(T** arr, int& rows, int cols)
{
    T** new_arr = new T * [rows - 1];
    for (int i = 0; i < rows - 1; i++)
    {
        new_arr[i] = arr[i]; //???????? ?????? ? ??????.
    }
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }

    delete[] arr;
    rows--;
    return new_arr;
}

template<typename T>
T** pop_row_front(T** arr, int& rows, int cols)
{
    T** new_arr = new T * [rows - 1];
    for (int i = 1; i < rows; i++)
    {
        new_arr[i - 1] = arr[i]; //???????? ?????? ? ??????.
    }
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }

    delete[] arr;
    rows--;
    return new_arr;
}

template<typename T>
T** erase_row(T** arr, int& rows, int cols, int index)
{
    T** new_arr = new T * [rows - 1];
    int k = 0; // ?????? ??? ?????? ???????
    for (int i = 0; i < rows; ++i)
    {
        if (i == index)
        {

            continue;
        }
        new_arr[k] = arr[i]; // ???????? ????????? ?? ??????
        k++;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    rows--;

    return new_arr;
}

template<typename T>
T** pop_col_back(T** arr, int rows, int& cols)
{
    //??????? ????? ??????
    T** new_arr = new T * [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new T[cols - 1]{}; // ???????? ?????? ??? ??????

        for (int j = 0; j < cols - 1; j++)
        {
            new_arr[i][j] = arr[i][j];

        }


    }for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;


    cols--;

    return new_arr;
}

template<typename T>
T** pop_col_front(T** arr, int rows, int& cols)
{
    //??????? ????? ??????
    T** new_arr = new T * [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new T[cols - 1]{}; // ???????? ?????? ??? ??????

        for (int j = 1; j < cols; j++)
        {
            new_arr[i][j - 1] = arr[i][j];
        }
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;

    }
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;


    cols--;

    return new_arr;
}

template<typename T>
T** erase_col(T** arr, int rows, int& cols, int index)
{
    //??????? ????? ??????
    T** new_arr = new T * [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new T[cols - 1]{}; // ???????? ?????? ??? ??????

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

    cols--;
    return new_arr;
}