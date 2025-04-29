#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int Evens(const int arr[], int n);
int Odds(const int arr[], int n);

// Функция Split
void Split(const int arr[], int n, int*& even, int& evenSize, int*& odd, int& oddSize) 
{
    evenSize = 0;
    oddSize = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] % 2 == 0) 
        {
            even[evenSize++] = arr[i];  // Заполняем even и увеличиваем размер
        }
        else 
        {
            odd[oddSize++] = arr[i];    // Заполняем odd и увеличиваем размер
        }
    }
}


void main() {
    setlocale(LC_ALL, ""); // Для корректного отображения кириллицы

    int n;
    cout << "Введите размер массива: ";  cin >> n;
    int* arr = new int[n];
    FillRand(arr, n);      
    cout << "Исходный массив: ";
    Print(arr, n);         
    int evenSize = Evens(arr, n);
    int oddSize = Odds(arr, n);
    int* even = new int[evenSize];
    int* odd = new int[oddSize];
    Split(arr, n, even, evenSize, odd, oddSize);
    cout << "Четные числа: ";
    Print(even, evenSize);
    cout << "Нечетные числа: ";
    Print(odd, oddSize);

    delete[] arr;   
    delete[] even;   
    delete[] odd;   
    arr = nullptr;
    even = nullptr;
    odd = nullptr;  // обнулитьь указатели
}


void FillRand(int arr[], const int n) 
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 100;
    }
}

void Print(int arr[], const int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Вспомогательная функция для подсчета количества четных элементов
int Evens(const int arr[], int n) 
{
    int count = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] % 2 == 0) 
        {
            count++;
        }
    }
    return count;
}

// Вспомогательная функция для подсчета количества нечетных элементов
int Odds(const int arr[], int n) 
{
    int count = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] % 2 != 0) 
        {
            count++;
        }
    }
    return count;
}