#pragma once
#include<iostream>
using namespace std;

struct Vector
{
	float x[100];
	int n;
};
void NhapVector(Vector *v);
void XuatVector(Vector *v);
Vector *CongHaiVector(Vector *v1, Vector *v2);
Vector *NhanVectorVoiSo(Vector *v, int r);