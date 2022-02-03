#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h> 
#include "processing.h"

int main() {
	system("chcp 1251"); //��� ������ ���������
	int** Matrx = NULL;
	int cols = 0;
	int rows = 0;
	int BigExit = 1; //�������� ��� ������� ����� ������ � ������� ����� �������� ���� � ����� ��������
	while (BigExit) {
		printf("��� ������� �������?\n");
		printf("1.���� ������\n2.����� ������\n3.��������� ������\n0.�����\n");
		int bigswitch;
		scanf("%d", &bigswitch);
		switch (bigswitch)
		{
		case 1:
		{
			int miniExit = 1;

			while (miniExit) {

				printf("���� ������?\n");
				printf("1.� ����������\n2.�� �����\n3.��������� ������\n0.�����\n");
				int miniswitch;
				scanf("%d", &miniswitch);
				switch (miniswitch)
				{
				case 1:
				{
					if (Matrx == NULL) {
						int exit = 1;
						while (exit) {
							printf("������� ����� �����?\n������� ����� ������� 0\n");
							scanf("%d", &rows);
							if (rows <= 0) {
								printf("���������� �����!\n");
							}
							else {
								exit = 0;
							}
						}
						exit = 1;
						while (exit) {
							printf("������� ����� ��������?\n������� ����� ������� 0\n");
							scanf("%d", &cols);
							if (cols <= 0) {
								printf("���������� �����!\n");
							}
							else {
								exit = 0;
							}
						}
						Matrx = initializationMatrx(rows, cols);
						printf("������� �����\n");
						for (int i = 0; i < rows; i++) {
							for (int j = 0; j < cols; j++) {
								scanf("%d", &Matrx[i][j]);
							}
						}
						printMatrx(Matrx, rows, cols);
					}
					else {
						printf("������� ��� ����������!\n");
					}
					break;
				}
				case 2:
				{
					if (Matrx == NULL) {
						FILE* in;
						if ((in = fopen("test.bin", "r")) != NULL)
						{
							fread(&rows, sizeof(int), 1, in);
							fread(&cols, sizeof(int), 1, in);
							Matrx = initializationMatrx(rows, cols);
							for (int i = 0; i < rows; i++) {
									fread(Matrx[i], sizeof(int), cols, in);
								
							}
							fclose(in);
						}
						else printf("\n������ �������� ����� ��� ������!\n");
						printMatrx(Matrx, rows, cols);
						
					}
					else {
						printf("������� ��� ����������!\n");
					}
					break;
				}
				case 3:
				{
					if (Matrx == NULL) {
						srand(time(NULL));
						cols = (rand() % 10) + 1;
						rows = (rand() % 10) + 1;
						int exit = 1;
						Matrx = initializationMatrx(rows, cols);
						for (int i = 0; i < rows; i++) {
							for (int j = 0; j < cols; j++) {
								Matrx[i][j] = -100 + (rand() % 200);
							}
						}
						printMatrx(Matrx, rows, cols);
					}
					else {
						printf("������� ��� ����������!\n");
					}
					break;
				}
				case 0:
				{
					miniExit = 0;
					system("cls"); //������� �������
					break;
				}
				default:
					printf("���������� �����!\n"); //���� ����� ����� �������� �� ������ ����
					break;
				}
			}
			break;
		}
		case 2:
		{
			if (Matrx != NULL) {

				int miniexit = 1;

				while (miniexit) {
					printf("1.������ � �������\n2.����� � ����\n0.�����\n");
					int miniswitch;
					scanf("%d", &miniswitch);
					switch (miniswitch)
					{
					case 1:
					{
						printMatrx(Matrx, rows, cols);
						break;
					}
					case 2:
					{
						Save(Matrx, rows, cols);
						break;
					}
					case 0:
					{
						miniexit = 0;
						system("cls");
						break;
					}
					default:
						printf("���������� �����!\n");
						break;
					}
				}
			}
			else {
				printf("�������� ������!\n");
			}
			break;
		}
		case 3:
		{
			if (Matrx != NULL) {
				printMatrx(Matrx, rows, cols);
				int miniexit = 1;

				while (miniexit) {
					printf("1.�������� ������\n2.�������� �������\n3.������� ������\n4.������� �������\n5.���������� �� ����� ������������ ��������\n0.�����\n");
					int miniswitch;
					scanf("%d", &miniswitch);
					switch (miniswitch)
					{
					case 1:
					{
						
						
						int ind;
						int miniminiexit = 1;
						while (miniminiexit) {
							printf("������� ������ ������, ���� ������ �������� ����� ������(�� 0...%d)", rows - 1);
							scanf("%d", &ind);
							if (ind < 0 || ind > (rows - 1)) {
								printf("���������� �����!\n");
							}
							else
							{
								miniminiexit = 0;
								
							}
						}
						Matrx = insertRow(Matrx, rows, cols, ind);
						rows++;
						printf("������� ����� �������� ��� ������ - %d\n", ind);
						printf("���������� ����� �������� ������ ���� = %d\n", cols);
						for (int j = 0; j < cols; j++) {
							scanf("%d", &Matrx[ind][j]);
						}
						printMatrx(Matrx, rows, cols);
						break;
					}
					case 2:
					{
						
						int ind;
						int miniminiexit = 1;
						while (miniminiexit) {
							printf("������� ������ �������, ���� ������ �������� ����� �������(�� 0...%d)", cols - 1);
							scanf("%d", &ind);
							if (ind < 0 || ind >(cols - 1)) {
								printf("���������� �����!\n");
							}
							else
							{
								miniminiexit = 0;
							}
						}
						Matrx = insertCol(Matrx, rows, cols, ind);
						cols++;
						printf("������� ����� �������� ��� ������ - %d\n", ind);
						printf("���������� ����� �������� ������ ���� = %d\n", rows);
						for (int j = 0; j < rows; j++) {
							scanf("%d", &Matrx[rows][ind]);
						}
						printMatrx(Matrx, rows, cols);
						break;
					}
					case 3:
					{
						
						int ind;
						int miniminiexit = 1;
						while (miniminiexit) {
							printf("������� ������ ������, ������� ������ �������(�� 0...%d)", rows - 1);
							scanf("%d", &ind);
							if (ind < 0 || ind >(rows - 1)) {
								printf("���������� �����!\n");
							}
							else
							{
								miniminiexit = 0;
							}
						}
						if (rows == 1) {
							freeMatrx(Matrx, rows);
							Matrx = NULL;
							cols = 0;
							rows = 0;
							miniexit = 0;
						}
						else {
							Matrx = delteRow(Matrx, rows, cols, ind);
							rows--;
							printMatrx(Matrx, rows, cols);
						}
					
						break;
					}
					case 4: 
					{
						int ind;
						int miniminiexit = 1;
						while (miniminiexit) {
							printf("������� ������ c������, ������� ������ �������(�� 0...%d)", cols - 1);
							scanf("%d", &ind);
							if (ind < 0 || ind >(cols - 1)) {
								printf("���������� �����!\n");
							}
							else
							{
								miniminiexit = 0;
							}
						}
						if (cols == 1) {
							freeMatrx(Matrx, rows);
							Matrx = NULL;
							rows = 0;
							cols = 0;
							miniexit = 0;
						}
						else {
							Matrx = delCol(Matrx, rows, cols, ind);
							cols--;
							printMatrx(Matrx, rows, cols);
						}
						break;
					}
					case 5:
					{
						SortByMin(Matrx, rows, cols);
						break;
					}
					case 0:
					{
						miniexit = 0;
						system("cls");
						break;
					}
					default:
						printf("���������� �����!\n");
						break;
					}
				}
			}
			else {
				printf("������������ ������!\n");
			}
			break;
		}
		case 0:
		{
			printf("����������!\n");
			if(Matrx != NULL)
				freeMatrx(Matrx, rows);
			BigExit = 0;
			break;
		}
		default:
			printf("���������� �����!\n"); //���� ����� ����� �������� �� ������ ����
			break;
		}
	}
	return 0;
}