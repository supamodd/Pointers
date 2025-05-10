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

int** push_row_back(int** arr, int& rows, const int cols);

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
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
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