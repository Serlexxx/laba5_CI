#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int** insertRow(int** matr, int rows, int cols, int ins_i);

int** delteRow(int** matr, int rows, int cols, int del_i);

int** insertCol(int** matr, int rows, int cols, int ins_j);

int** delCol(int** matr, int rows, int cols, int del_j);

void Save(int** matr, int rows, int cols);

int** initializationMatrx(int rows, int cols);

void SortByMin(int** matr, int rows, int cols);

void Swap(int** matr, int ind1, int ind2);

void freeMatrx(int** A, int rows);

void printMatrx(int** matr, int rows, int cols);

