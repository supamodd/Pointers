#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int index, int value);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int index);

int** Allocate(int rows, int cols);
void Clear(int** arr, int rows);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, int cols, int index);

int** push_col_back(int** arr, int rows, int& cols);
int** push_col_front(int** arr, int rows, int& cols);
int** insert_col(int** arr, int rows, int& cols, int index);

int** pop_row_back(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, int cols);
int** erase_row(int** arr, int& rows, int cols, int index);

int** pop_col_back(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);
int** erase_col(int** arr, int rows, int& cols, int index);

#define tab "\t"
#define delimiter "\n---------------------------------------------\n";

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
    setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1


    int n;
    cout << "������� ������ �������: "; cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);
    Print(arr, n);
    arr = push_front(arr, n, 100);
    cout << "���������� �������� � ������: " << endl;
    Print(arr, n);

    arr = insert(arr, n, 2, 200);
    cout << "���������� �������� �� ���������� �������: " << endl;
    Print(arr, n);

    arr = pop_back(arr, n);
    cout << "��������� ��������� �������: " << endl;
    Print(arr, n);

    arr = pop_front(arr, n);
    cout << "������� �������: " << endl;
    Print(arr, n);

    arr = erase(arr, n, 1);
    cout << "�������� �������� ������� �� ���������� �������: " << endl;
    Print(arr, n);
    delete[] arr;
    //Memory leak
#endif DYNAMIC_MEMORY_1

    int rows;
    int cols;
    cout << "������� ���������� �����: "; cin >> rows;
    cout << "������� ���������� ��������� ����� "; cin >> cols;

    //(1) ������� ������ ����������:
    int** arr = new int* [rows];
    //(2) �������� ������ ��� ������ ���������� ������������� �������:
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    FillRand(arr, rows, cols);
    Print(arr, rows, cols);

    arr = push_row_back(arr, rows, cols);
    Print(arr, rows, cols);

    arr = push_row_front(arr, rows, cols);
    cout << "��������� ������ � ������ " << endl;
    Print(arr, rows, cols);

    arr = insert_row(arr, rows, cols, 2);
    cout << "��������� ������ �� �������: " << endl;
    Print(arr, rows, cols);

    arr = push_col_back(arr, rows, cols);
    cout << "�������� ������� � �����" << endl;
    Print(arr, rows, cols);

    arr = push_col_front(arr, rows, cols);
    cout << "�������� ������� � ������" << endl;
    Print(arr, rows, cols);

    arr = insert_col(arr, rows, cols, 2);
    cout << "�������� ������� � ��������" << endl;
    Print(arr, rows, cols);

    arr = pop_row_back(arr, rows, cols);
    cout << "������� ��������� ������" << endl;
    Print(arr, rows, cols);
    
    arr = pop_row_front(arr, rows, cols);
    cout << "������� ������ ������" << endl;
    Print(arr, rows, cols);
    
    arr = erase_row(arr, rows, cols, 2);
    cout << "������� ������ �� �������" << endl;
    Print(arr, rows, cols);
    
    
    arr = pop_col_back(arr, rows, cols);
    cout << "������ ��������� �������" << endl;
    Print(arr, rows, cols);
    
    arr = pop_col_front(arr, rows, cols);
    cout << "������ ������ �������" << endl;
    Print(arr, rows, cols);
    
    arr = erase_col(arr, rows, cols, 2);
    cout << "������ ������� �� �������" << endl;
    Print(arr, rows, cols);
    

    Clear(arr, rows);
    /*for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;*/
}

void FillRand(int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void FillRand(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

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
        cout << "������: ������ ��� ���������!" << endl;
        return arr; // ���������� �������� ������ ��� ���������
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
        cout << "������: ������ ����!" << endl;
        return arr; // ���������� �������� ������ ��� ���������
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
    if (n == 0) {
        cout << "������: ������ ����!" << endl;
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
    if (n == 0) {
        cout << "������: ������ ����!" << endl;
        return arr;
    }
    if (index < 0 || index >= n)
    {
        cout << "������: ������ ��� ���������!" << endl;
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

int** push_row_back(int** arr, int& rows, const int cols)
{
    //(1) ������� �������� ������ ���������� ������� �������:
    int** buffer = new int* [rows + 1];

    //(2) �������� ������ ����� � �������� ������ ����������:
    for (int i = 0; i < rows; i++)
    {
        buffer[i] = arr[i];
    }

    //(3)������� �������� ������ ����������:
    delete[] arr;


    //(4) ������� ����������� ������, � ���������� �� ����� � ������ ����������:
    buffer[rows] = new int[cols] {};

    //(5) ��� ���������� � ������ ������, ���������� ��� ����� ������������� �� 1:
    rows++;

    //(6) ���������� ����� ������ �� ����� ������:
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
    cols++;  // ����������� cols

    // �������� ����� ������
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new int[cols] {}; // �������� ������ ��� ������
        for (int j = 0; j < cols - 1; ++j)
        { //�������� ������ ��������
            new_arr[i][j] = arr[i][j];
        }
    }
    // ����������� ������, ���������� ��� ������ ������
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;


    return new_arr;
}

int** push_col_front(int** arr, int rows, int& cols)
{
    cols++;  // ����������� cols

    // �������� ����� ������
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new int[cols] {}; // �������� ������ ��� ������
        new_arr[i][0] = 0; // ��������� ������ ������� ������

        for (int j = 0; j < cols - 1; ++j)
        {
            new_arr[i][j + 1] = arr[i][j];
        }
    }
    // ����������� ������, ���������� ��� ������ ������
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;


    return new_arr;
}

int** insert_col(int** arr, int rows, int& cols, int index)
{
    cols++;  // ����������� cols

    // �������� ����� ������
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        new_arr[i] = new int[cols] {}; // �������� ������ ��� ������

        for (int j = 0, k = 0; j < cols; ++j)
        { //�������� ������ ��������
            if (j == index) {
                new_arr[i][j] = 0;  // ��������� ������� � ������ ������� ������
            }
            else {
                new_arr[i][j] = arr[i][k];
                k++;
            }
        }
    }
    // ����������� ������, ���������� ��� ������ ������
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return new_arr;
}

int** pop_row_back(int** arr, int& rows, int cols)
{
    int** new_arr = new int* [rows - 1];
    for (int i = 0; i < rows - 1; i++) 
    {
        new_arr[i] = arr[i]; //�������� ������ � ������.
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
        new_arr[i - 1] = arr[i]; //�������� ������ � ������.
    }

    delete[] arr;
    rows--;
    return new_arr;
}

int** erase_row(int** arr, int& rows, int cols, int index) 
{
    int** new_arr = new int* [rows - 1];
    int k = 0; // ������ ��� ������ �������
    for (int i = 0; i < rows; ++i) 
    {
        if (i == index)
        {

            continue;
        }
        new_arr[k] = arr[i]; // �������� ��������� �� ������
        k++;
    }


    delete[] arr; // ����������� ������ ��� ������ ������
    rows--;

    return new_arr;
}

int** pop_col_back(int** arr, int rows, int& cols)
{
    //������� ����� ������
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[cols - 1] {}; // �������� ������ ��� ������

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
    //������� ����� ������
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[cols - 1] {}; // �������� ������ ��� ������

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
    //������� ����� ������
    int** new_arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        new_arr[i] = new int[cols - 1] {}; // �������� ������ ��� ������

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