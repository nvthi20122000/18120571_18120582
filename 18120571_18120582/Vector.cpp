#include"Vector.h"

void NhapVector(Vector *v)
{
	cout << "Nhap so chieu cua vector: ";
	cin >> v->n;
	for (int i = 0; i < v->n; i++)
	{
		cout << "v[" << i << "]= ";
		cin >> v->x[i];
	}
}
void XuatVector(Vector *v)
{
	if (v == NULL) return;
	for (int i = 0; i < v->n; i++)
	{
		cout << v->x[i] << "\t";
	}
}
Vector* CongHaiVector(Vector *v1, Vector *v2)
{
	Vector *t = new Vector;
	t->n = v1->n;
	if (v1->n != v2->n) {
		cout << "Khong the cong hai vector do so chieu khac nhau.";
		return NULL;
	}
	for (int i = 0; i < v1->n; i++)
	{
		t->x[i] = v1->x[i] + v2->x[i];
	}
	return t;
}
Vector *NhanVectorVoiSo(Vector *v, int r)
{
	Vector *t = new Vector;
	t->n = v->n;
	for (int i = 0; i < v->n; i++)
	{
		t->x[i] = v->x[i] * r;
	}
	return t;
}