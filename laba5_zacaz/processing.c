#define _CRT_SECURE_NO_WARNINGS
#include "processing.h"

int** insertRow(int** matr, int rows, int cols,  int ins_i)
{
    int** tmp = initializationMatrx(rows + 1, cols);
   
    for (int i = 0; i < ins_i; i++) {
        for (int j = 0; j < cols; j++) {
            tmp[i][j] = matr[i][j];
        }
    }
    for (int i = ins_i; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tmp[i+1][j] = matr[i][j];
        }
    }
    freeMatrx(matr, rows);
    
    matr = tmp;
    return matr;
}

int** delteRow(int** matr, int rows, int cols, int del_i) {
    int** tmp = initializationMatrx(rows - 1, cols);
    

    for (int i = 0; i < del_i; i++) {
        for (int j = 0; j < cols; j++) {
            tmp[i][j] = matr[i][j];
        }
    }
    for (int i = (del_i+1); i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tmp[i-1][j] = matr[i][j];
        }
    }
    freeMatrx(matr, rows);
    matr = tmp;
    return matr;
}

int** insertCol(int** matr, int rows, int cols, int ins_j) {
    int** tmp = initializationMatrx(rows, cols + 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < ins_j; j++) {
            tmp[i][j] = matr[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = ins_j; j < cols; j++) {
            tmp[i][j + 1] = matr[i][j];
        }
    }
    freeMatrx(matr, rows);
    matr = tmp;
    return matr;
}

int** delCol(int** matr, int rows, int cols, int del_j) {
    int** tmp = initializationMatrx(rows, cols - 1);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < del_j; j++) {
            tmp[i][j] = matr[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = (del_j + 1); j < cols; j++) {
            tmp[i][j - 1] = matr[i][j];
        } 
    }
    freeMatrx(matr, rows);
    matr = tmp;
    return matr;
}

int** initializationMatrx(int rows, int cols) {
    int** matr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matr[i] = (int*)malloc(cols * sizeof(int));
    }
    return matr;
}

void freeMatrx(int** matr, int rows)
{
    for (int i = 0; i < rows; i++) {
        free(matr[i]);
    }
    free(matr);
}

void printMatrx(int** matr, int rows, int cols)
{
    if (matr != NULL) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matr[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Выводить нечего!\n");
    }
}

void Save(int** matr, int rows, int cols)
{
    FILE* out;
    if ((out = fopen("test.bin", "w")) != NULL)
    {
        fwrite(&rows, sizeof(int), 1, out);
        fwrite(&cols, sizeof(int), 1, out);
        for (int i = 0; i < rows; i++) {

            fwrite(matr[i], sizeof(int), cols, out);
        }
        fclose(out);
    }
    else printf("\nОшибка открытия файла для записи!\n");
}


void SortByMin(int** matr, int rows, int cols) {
    int** tmp = NULL;
    int* ind_i_min = (int*)malloc(rows*sizeof(int));
   
    for (int i = 0; i < rows; i++) {
        int min = 1000000;
        for (int j = 0; j < cols; j++) {
            if (min > matr[i][j]) {
                min = matr[i][j];
                ind_i_min[i] = j;
            }
        }
    }
    
    int left = 0, right = rows-1;
    int flag = 1;
    for (int i = 0; i < rows; i++) {
        while ((left < right) && flag > 0)
        {
            flag = 0;
            for (int i = left; i < right; i++)
            {
                if (matr[i][ind_i_min[i]] < matr[i + 1][ind_i_min[i + 1]])
                {
                    Swap(matr, i, i + 1);
                    flag = 1;
                }
            }
            right--;
            for (int i = right; i > left; i--)
            {
                if (matr[i - 1][ind_i_min[i - 1]] < matr[i][ind_i_min[i]])
                {
                    Swap(matr, i, i - 1);
                    flag = 1;
                }
            }
            left++;
        }
    }
    free(ind_i_min);
}

void Swap(int** matr, int ind1, int ind2) {
    int* tmp = matr[ind1];
    matr[ind1] = matr[ind2];
    matr[ind2] = tmp;
}
