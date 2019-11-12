#include"Boole.h"


void nhap_ham(char s[])
{
	cout << "Luu y: ham bool phai co cac phan tu co 4 bien, neu be hon phai tach ra, khong duoc co khoang trong.\nHam bool o day dung cac bien x,y,z,t,x',y',z',t'.\n";
	cout << "Nhap ham boole:";
	cin >> s;
}

void xuat_ham(char s[])
{
	cout << s;
}

int tim_vi_tri(char s[])
{
	int a;
	if (strcmp(s, "x'yzt'") == 0) a = 0;
	else if (strcmp(s, "xyzt'") == 0) a = 1;
	else if (strcmp(s, "x'yzt'") == 0) a = 2;
	else if (strcmp(s, "x'y'zt'") == 0) a = 3;
	else if (strcmp(s, "xy'zt") == 0) a = 4;
	else if (strcmp(s, "xyzt") == 0) a = 5;
	else if (strcmp(s, "x'yzt") == 0) a = 6;
	else if (strcmp(s, "x'y'zt") == 0) a = 7;
	else if (strcmp(s, "xy'z't") == 0) a = 8;
	else if (strcmp(s, "xyz't") == 0) a = 9;
	else if (strcmp(s, "x'yz't") == 0) a = 10;
	else if (strcmp(s, "x'y'z't") == 0) a = 11;
	else if (strcmp(s, "xy'z't'") == 0) a = 12;
	else if (strcmp(s, "xyz't'") == 0) a = 13;
	else if (strcmp(s, "x'yz't'") == 0) a = 14;
	else if (strcmp(s, "x'y'z't'") == 0) a = 15;
	else
	{
		cout << "\nNhap ham bi sai.";
		return -1;
	}
	return a;
}

void vi_tri(char s[], int b[], int &n)
{
	int vt = 0;
	char *p;
	char *nextp;
	int a[16];
	p = strtok_s(s,"v",&nextp);
	while (p != NULL)
	{
		a[vt] = tim_vi_tri(p);
		p = strtok_s(NULL, "v",&nextp);
		vt++;
	}
	n = vt;
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	sort_vi_tri(b, n);
}
void sort_vi_tri(int a[], int &n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i + 1] == a[i])
		{
			for (int j = i + 1; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			a[n - 1] = NULL;
			n--;
		}
	}
}
void ve_karnaugh(int a[], int n)
{
	int kt=0;
	for (int i = 0; i < 16; i++)
	{
		if (a[kt] == i)
		{
			cout << "+";
			kt++;
		}
		else cout << "x";
		cout << " ";
		if ((i + 1) % 4 == 0) cout << endl;
	}
}