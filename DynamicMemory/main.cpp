#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int index, int value);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
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

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " \t";
	}
	cout << endl;
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

int* pop_back(int* arr, int& n) {
    if (n == 0) {
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
    if (n == 0) {
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
    if (n == 0) {
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