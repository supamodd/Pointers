#pragma once

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, int cols, int index);

int** push_col_back(int** arr, int rows, int& cols);
int** push_col_front(int** arr, int rows, int& cols);
int** insert_col(int** arr, int rows, int& cols, int index);
