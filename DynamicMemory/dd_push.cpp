#include<iostream>
#include"dd_push.h"
using namespace std;

int** push_row_back(int** arr, int& rows, int cols)
{
	//1)Выделяем память под массив указателей на rows + 1 строк:
	int** new_arr = new int* [rows + 1] {};
	//2)Копируем в новый массив все элементы из старого массива:
	for (int i = 0; i < rows; i++)
	{
		new_arr[i] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			new_arr[i][j] = arr[i][j];
		}
	}
	//3)Удаляем старый массив:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
	//4)Добавляем адрес новой строки в новый массив:
	new_arr[rows] = new int[cols] {};
	//5)После того как память была перераспределена, кол-во строк увеличилось на 1:
	rows++;
	//6)Возвращаем адрес нового массива:
	return new_arr;
}

int** push_row_front(int** arr, int& rows, int cols) 
{
	//1)Выделяем память под массив указателей на rows + 1 строк:
	int** new_arr = new int* [rows + 1] {};
	//2)Выделяем память под нулевую строку:
	new_arr[0] = new int[cols] {};
	//3)Копируем в новый массив все элементы из старого массива:
	for (int i = 0; i < rows; i++)
	{
		new_arr[i + 1] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			new_arr[i + 1][j] = arr[i][j];
		}
	}
	//4)Удаляем старый массив:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
	//5)После того как память была перераспределена, кол-во строк увеличилось на 1:
	rows++;
	//6)Возвращаем адрес нового массива:
	return new_arr;
}

int** insert_row(int** arr, int& rows, int cols, int index) 
{
	//2)Выделяем память под массив указателей на rows + 1 строк:
	int** new_arr = new int* [rows + 1] {};
	//3)Копируем в новый массив все элементы из старого массива:
	for (int i = 0; i < rows + 1; i++)
	{
		if (i == index)
		{
			new_arr[i] = new int[cols] {};
		}
		else if (i < index)
		{
			new_arr[i] = new int[cols] {};
			for (int j = 0; j < cols; j++)
			{
				new_arr[i][j] = arr[i][j];
			}
		}
		else
		{
			new_arr[i] = new int[cols] {};
			for (int j = 0; j < cols; j++)
			{
				new_arr[i][j] = arr[i - 1][j];
			}
		}
	}
	//4)Удаляем старый массив:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
	//5)После того как память была перераспределена, кол-во строк увеличилось на 1:
	rows++;
	//6)Возвращаем адрес нового массива:
	return new_arr;
}
int** push_col_back(int** arr, int rows, int& cols)
{
	int new_cols = cols + 1;

	int** new_arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		new_arr[i] = new int[new_cols] {}; 
		for (int j = 0; j < cols; j++) 
		{
			new_arr[i][j] = arr[i][j]; 
		}
		// new_arr[i][cols] = 0;

	}
	for (int i = 0; i < rows; i++) 
	{
		delete[] arr[i];
	}
	delete[] arr;

	cols = new_cols;
	return new_arr;
}

int** push_col_front(int** arr, int rows, int& cols) 
{
	int new_cols = cols + 1;

	int** new_arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		new_arr[i] = new int[new_cols] {}; 
		new_arr[i][0] = 0;
		for (int j = 0; j < cols; j++) 
		{
			new_arr[i][j + 1] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++) 
	{
		delete[] arr[i];
	}
	delete[] arr;

	cols = new_cols;
	return new_arr;
}

int** insert_col(int** arr, int rows, int& cols, int index) 
{
	int new_cols = cols + 1;
	int** new_arr = new int* [rows];
	for (int i = 0; i < rows; i++) 
	{
		new_arr[i] = new int[new_cols] {};
		for (int j = 0, k = 0; j < new_cols; j++) 
		{
			if (j == index) {
				new_arr[i][j] = 0;
			}
			else {
				new_arr[i][j] = arr[i][k];
				k++;
			}
		}
	}
	for (int i = 0; i < rows; i++) 
	{
		delete[] arr[i];
	}
	delete[] arr;

	cols = new_cols;
	return new_arr;
}
