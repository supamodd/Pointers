#pragma once

int** pop_row_back(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, int cols);
int** erase_row(int** arr, int& rows, int cols, int index);

int** pop_col_back(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);
int** erase_col(int** arr, int rows, int& cols, int index);