#include"Matrix.h"

void NhapMaTran(Matrix *mt)
{
	cout << "Nhap so dong cua ma tran: ";
	cin >> mt->d;
	cout << "Nhap so cot cua ma tran: ";
	cin >> mt->c;
	for (int i = 0; i < mt->d; i++)
		for (int j = 0; j < mt->c; j++)
		{
			cout << "\nGia tri tai dong " << i << ", cot " << j << " : ";
			cin >> mt->m[i][j];
		}
}
void XuatMaTran(Matrix *mt)
{
	if (mt == NULL) return;
	for (int i = 0; i < mt->d; i++)
	{
		for (int j = 0; j < mt->c; j++)
		{
			cout << mt->m[i][j] << "  ";
		}
		cout << endl;
	}
}
void HoanViDongTD(Matrix *mt, int a, int b)
{
	if (mt == NULL) return;
	for (int i = 0; i < mt->d; i++)
	{
		float dem;
		dem = mt->m[a][i];
		mt->m[a][i] = mt->m[b][i];
		mt->m[b][i] = -dem;
	}
}
float DinhThuc(Matrix *mt)
{
	int n = mt->d;
	Matrix *b1 = new Matrix;
	Matrix *b2 = new Matrix;
	b1->c = b1->d = b2->c = b2->d = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++)
		{
			b1->m[i][j] = mt->m[i][j];
			b2->m[i][j] = mt->m[i][j];
		}
	if (b2->m[0][0] == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (b2->m[i][0]) {
				HoanViDongTD(b1, i, 0);
				HoanViDongTD(b2, i, 0);
				break;
			}
		}
	}
	if (mt->c != mt->d)
	{
		cout << "\nKhong phai ma tran vuong.";
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (j != i)	b1->m[j][k] = mt->m[0][0] * mt->m[j][k] - mt->m[j][0] * mt->m[0][k];
					}
				}
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
					{
						b2->m[j][k] = b1->m[j][k];
					}
			}
			else
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (j != i)
						{
							b1->m[j][k] = (b2->m[i][i] * b2->m[j][k] - b2->m[j][i] * b2->m[i][k]) / b2->m[i-1][i-1];
						}
					}
				}
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
					{
						b2->m[j][k] = b1->m[j][k];
					}
			}
		}
	}
	return b2->m[n-1][n-1];
}
Matrix *NghichDao(Matrix *mt)
{
	int n = mt->d;
	float det = DinhThuc(mt);
	Matrix *ph = new Matrix;
	Matrix *phd = new Matrix;
	ph->c = phd->c = ph->d = phd->d = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++)
		{
			ph->m[i][j] = 0;
			phd->m[i][j] = 0;
		}
	for (int i = 0; i < n; i++)
	{
		ph->m[i][i] = 1;
		phd->m[i][i] = 1;
	}
	Matrix *b1 = new Matrix;
	Matrix *b2 = new Matrix;
	b1->c = b1->d = b2->c = b2->d = n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			b1->m[i][j] = mt->m[i][j];
			b2->m[i][j] = mt->m[i][j];
		}
	/*for (int i = 0; i < mt->c; i++)
		for (int j = 0; j < mt->c; j++)
		{
			Matrix *dem = new Matrix;
			dem->c = mt->c - 1;
			dem->d = mt->c - 1;
			for (int k = 0; k < dem->c; k++)
				for (int l = 0; l < dem->d; l++)
				{
					if (k == i || l == j) break;
					if ((k < i) && (l < j)) dem->m[k][l] = mt->m[k][l];
					if ((k < i) && (l > j)) dem->m[k][l] = mt->m[k+1][l];
					if ((k > i) && (l < j)) dem->m[k][l] = mt->m[k][l+1];
					if ((k > i) && (l > j)) dem->m[k][l] = mt->m[k + 1][l + 1];
				}
			ph->m[i][j] = pow(-1.0, (i + j + 2))*DinhThuc(dem);
		}*/
	if (det == 0)
	{
		cout << "\nKhong phai ma tran vuong.";
		Matrix *a = new Matrix;
		return a;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (j != i)
						{
							b1->m[j][k] = mt->m[0][0] * mt->m[j][k] - mt->m[j][0] * mt->m[0][k];
							ph->m[j][k] = mt->m[0][0] * phd->m[j][k] - mt->m[j][0] * phd->m[0][k];
						}
					}
				}
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
					{
						b2->m[j][k] = b1->m[j][k];
						phd->m[j][k] = ph->m[j][k];
					}
			}

			else
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (j != i)
						{
							b1->m[j][k] = (b2->m[i][i] * b2->m[j][k] - b2->m[j][i] * b2->m[i][k]) / b2->m[i - 1][i - 1];
							ph->m[j][k] = (b2->m[i][i] * phd->m[j][k] - b2->m[j][i] * phd->m[i][k]) / b2->m[i - 1][i - 1];
						}
					}
				}
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
					{
						b2->m[j][k] = b1->m[j][k];
						phd->m[j][k] = ph->m[j][k];
					}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			ph->m[i][j] /= det;
		}
	return ph;
}

Matrix *Tich(Matrix *mt1, Matrix *mt2)
{
	Matrix* t = new Matrix;
	t->d = mt1->d;
	t->c = mt2->c;
	for (int i = 0; i < t->d; i++)
		for (int j = 0; j < t->c; j++)
		{
			t->m[i][j] = 0;
		}
	if (mt1->c != mt2->d) {
		cout << "\nKhong the nhan hai ma tran nay.";
		Matrix *a = new Matrix;
		return a;
	}
	else
	{
		int i;
		for (i = 0; i < t->d; i++)
		{
			int j;
			for (j = 0; j < t->c; j++)
			{
				int k;
				float tong = 0;
				for (k = 0; k < mt1->c; k++)
				{
					tong += mt1->m[i][k] * mt2->m[k][j];
				}
				t->m[i][j]+= tong;
			}
		}
	}
	return t;
}
int Hang(Matrix *mt)
{
	int n,i;
	if (mt->c > mt->d) n = mt->d;
	else n = mt->c;
	int h = n;
	for (i = 0; i < n + 1; i++)
	{
		Matrix *dem = new Matrix;
		dem->c = dem->d = i;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
			{
				dem->m[j][k] = mt->m[j][k];
			}
		if (DinhThuc(dem) == 0) h--;
	}
	return h;
}

void HePTTuyenTinh(Matrix *mt, Matrix *ng)
{
	cout << "Nhap ma tran ben trai he phuong trinh(Chi co the tinh ma tran vuong): \n";
	NhapMaTran(mt);
	cout << "Nhap cot he so cua he phuong trinh(so cot = 1, so dong = so dong cua ma tran tren): \n";
	NhapMaTran(ng);
	while (ng->c != 1 && ng->d != mt->d)
	{
		cout << "Nhap bi sai, nhap lai: \n";
		NhapMaTran(ng);
	}
	Matrix *dem1 = new Matrix;
	
	mt = NghichDao(mt);
	ng = Tich(mt, ng);
	for (int i = 0; i < ng->d; i++)
	{
		cout << "x" << i << " = " << ng->m[i][0] << endl;
	}
}
