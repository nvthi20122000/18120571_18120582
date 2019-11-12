#pragma once
#include<iostream>
#include<math.h>
using namespace std;

struct Matrix
{
	float m[100][100];
	int d;
	int c;
};
void NhapMaTran(Matrix *mt);
void XuatMaTran(Matrix *mt);
void HoanViDongTD(Matrix *mt, int a, int b);
Matrix *newMatrix(Matrix *mt, int a, int b);
float DinhThuc(Matrix *mt);
Matrix *NghichDao(Matrix *mt);
Matrix *adj(Matrix *mt);
Matrix *Tich(Matrix *mt1,Matrix *mt2);
int Hang(Matrix *mt);
void HePTTuyenTinh(Matrix *mt,Matrix *ng);
