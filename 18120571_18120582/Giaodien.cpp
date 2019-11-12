#include"Giaodien.h"

void Menu()
{
	system("cls");
	cout << "############################" << endl;
	cout << "#****       MATH      *****#" << endl;
	cout << "############################" << endl;
	cout << "# 1.Ham bool.              #" << endl;
	cout << "# 2.Vector.                #" << endl;
	cout << "# 3.Matrix.                #" << endl;
	cout << "# 4.Exit.                  #" << endl;
	cout << "############################" << endl;

	int choose;
	do
	{
		cout << "\nVui long nhap lua chon cua ban vao: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			MenuBoole();

		};
		break;
		case 2:
		{
			MenuVector();

		};
		break;
		case 3:
		{
			MenuMatrix();
		};
		break;
		case 4:
		{
			break;
		}
		}
	} while (choose >= 1 && choose < 4);
}
void MenuVector()
{
	system("cls");
	cout << "#######################################" << endl;
	cout << "#****            VECTOR           ****#" << endl;
	cout << "#######################################" << endl;
	cout << "# 1.Cong hai vector.                  #" << endl;
	cout << "# 2.Nhan vector voi mot so thuc.      #" << endl;
	cout << "# 3.Tro lai trang dau.                #" << endl;
	cout << "# 4.Thoat khoi chuong trinh.          #" << endl;
	cout << "#######################################" << endl;
	int choose;
	do
	{
		cout << "\nVui long nhap lua chon cua ban vao: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			Vector* b = new Vector;
			Vector* c = new Vector;
			NhapVector(b);
			NhapVector(c);
			cout << "\nKet qua: ";
			XuatVector(CongHaiVector(b, c));
			delete b;
			delete c;

		};
		break;
		case 2:
		{
			Vector* b = new Vector;
			float x;
			cout << "\nNhap so thuc x: ";
			cin >> x;
			NhapVector(b);
			cout << "\nKet qua: ";
			XuatVector(NhanVectorVoiSo(b, x));
			delete b;
		};
		break;
		case 3:
		{
			Menu();
		};
		break;
		case 4:
		{
			break;
		}
		}
	} while (choose >= 1 && choose < 4);

}

void MenuMatrix()
{
	system("cls");
	cout << "##################################################" << endl;
	cout << "#****                 MATRIX                 ****#" << endl;
	cout << "##################################################" << endl;
	cout << "# 1.Tim dinh thuc ma tran.                       #" << endl;
	cout << "# 2.Tim ma tran nghich dao.                      #" << endl;
	cout << "# 3.Tinh tich hai ma tran.                       #" << endl;
	cout << "# 4.Tim hang cua ma tran.                        #" << endl;
	cout << "# 5.Tim he phuong trinh tuyen tinh cua ma tran.  #" << endl;
	cout << "# 6.Quay lai trang dau.                          #" << endl;
	cout << "# 7.Thoat khoi chuong trinh.                     #" << endl;
	cout << "##################################################" << endl;

	int choose;
	do
	{
		cout << "\nVui long nhap lua chon cua ban vao: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			Matrix* a = new Matrix;

			NhapMaTran(a);
			cout << "Dinh thuc cua ma tran: ";
			cout << DinhThuc(a);



		};
		break;
		case 2:
		{
			Matrix* a = new Matrix;
			NhapMaTran(a);
			cout << "\nMa tran nghich dao vua nhap la: \n";
			XuatMaTran(NghichDao(a));
			delete a;

		};
		break;
		case 3:
		{
			Matrix* a = new Matrix;
			Matrix* b = new Matrix;
			NhapMaTran(a);
			NhapMaTran(b);
			cout << "\nTich hai ma tran:\n ";
			XuatMaTran(Tich(a, b));
			delete a;
			delete b;
		};
		break;
		case 4:
		{
			Matrix* a = new Matrix;
			NhapMaTran(a);
			cout << "\nHang cua ma tran vua nhap la: " << Hang(a);
			delete a;
		};
		break;
		case 5:
		{
			Matrix* a = new Matrix;
			Matrix* b = new Matrix;
			cout << "\nHe phuong trinh tuyen tinh: ";
			HePTTuyenTinh(a, b);
			delete a;
			delete b;
		};
		break;
		case 6:
		{
			Menu();
		};
		break;
		case 7:
		{
			break;
		}
		}
	} while (choose >= 1 && choose < 7);
}
void MenuBoole()
{
	system("cls");
	cout << "#######################################" << endl;
	cout << "#****            BOOLE            ****#" << endl;
	cout << "#######################################" << endl;
	cout << "# 1.Ve karnaugh.                      #" << endl;
	cout << "# 2.Rut gon ham bool.                 #" << endl;
	cout << "# 3.Tro lai trang dau.                #" << endl;
	cout << "# 4.Thoat khoi chuong trinh.          #" << endl;
	cout << "#######################################" << endl;
	int choose;
	do
	{
		cout << "\nVui long nhap lua chon cua ban vao: ";
		cin.ignore();
		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			char s[255];
			int a[16];
			int n;
			nhap_ham(s);
			vi_tri(s, a, n);
			cout << "\nKet qua: \n";
			ve_karnaugh(a, n);

		};
		break;
		case 2:
		{
			cout << "con update.";

		};
		break;
		case 3:
		{
			Menu();
		};
		break;
		case 4:
		{
			break;
		}
		}
	} while (choose >= 1 && choose < 4);

}
