#include "Header.h"

void write(char* fname1, Product zap, int num)
{
	fstream p(fname1, ios::app); // �������� ������
	if (p) // �������� ����� �� �������������
	{
		p.close();
		p.open(fname1, ios::in | ios::out | ios::ate | 
			ios::binary);
	}
	if (num)
	{
		p.seekg((num - 1) * len, ios::beg);
	}
	p.write((char*)&zap, len);
	p.close();
}

void print(Product zap, int i)
{
	cout << endl << setw(2) << i ;
	cout << setw(12) << zap.title;
	cout << setw(12) << zap.country;
	cout << setw(12) << zap.volume;
	cout << setw(17) << zap.price;
	cout << setw(5) << zap.metka << setw(5) << '|';
}

void print2(Product zap, int i, int volum_p, double price_p, double max_p)
{
	cout << endl << setw(2) << i;
	cout << setw(12) << zap.country;
	cout << setw(12) << volum_p;
	cout << setw(12) << price_p;
	cout << setw(12) << zap.title;
	cout << setw(12) << max_p << setw(5) << '|';
}

Product vvod()
{
	Product new_zap;
	cout << "\n������� ������������ ������:\n";
	cin >> new_zap.title;
	cout << "������� ������, ���� ����� �������������:\n";
	cin >> new_zap.country;
	cout << "������� ����� - ����� ������������ ������ � ������:\n";
	cin >> new_zap.volume;
	cout << "�������� ����� - ���� �� ������� ������:\n";
	cin >> new_zap.price;
	strcpy_s(new_zap.metka, "+");
	return new_zap;
}

void writeNzap(int n)
{
	fstream p(fname, ios::app); 
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate | 
			ios::binary);
	}
	for (int i = 0; i < n; i++)
	{
		Product zap;
		zap = vvod();
		write(fname, zap);
	}
	p.close();
}

fstream& read(Product& zap, int num)
{
	fstream p(fname, ios::app); 
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary); 
	}
	if (num)
	{
		p.seekg((num - 1) * len, ios::beg);
		p.read((char*)&zap, len);
	}
	p.close();
	return p;
}

void readAll()
{
	fstream p(fname, ios::app); 
	if (p) 
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary); 
	}
	p.seekg(0, ios::beg);
	Product zap;
	cout << shapka;
	for (int i = 1; read(zap, i); i++)
		print(zap, i);
	cout << endl << FinishL;
	p.close();
}

void readN(int N)
{
	fstream p(fname, ios::app); 
	if (p) 
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	p.seekg(0, ios::beg);
	Product zap;
	if (read(zap, N))
	{
		cout << shapka;
		print(zap, N);
		cout << endl << FinishL;
	}
	else cout << endl << "����� ������ ���";
	_getch();
	p.close();
}

// ������ ����� ��������� ������ � '+' �� '-' 
int metkaDel(char* title)
{
	fstream p(fname, ios::app);
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	Product zap;
	p.seekg(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(zap, i); i++)
	{
		if (strcmp(zap.title, title) == 0)
		{
			strcpy_s(zap.metka, "-");
			write(fname, zap, i);
			kol++;
		}
	}
	p.close();
	return kol;
}

// ������ ��� ����� � '-' �� '+'
void UNmetkaDel()
{
	fstream p(fname, ios::app);
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	Product zap;
	p.seekg(0, ios::beg);
	for (int i = 1; read(zap, i); i++)
	{
		if (strcmp(zap.metka, "-") == 0)
		{
			strcpy_s(zap.metka, "+");
			write(fname, zap, i);
		}
	}
	_getch();
	p.close();
}

// ������� ��� ���������� ������
int Delete()
{
	fstream p(fname, ios::app);
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	char fname1[10] = "temp.bin";
	fstream p1(fname1, ios::app);
	if (p1)
	{
		p1.close();
		p1.open(fname1, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	Product zap;
	p.seekg(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(zap, i); i++)
	{
		if (strcmp(zap.metka, "+") == 0)
		{
			write(fname1, zap);
			kol++;
		}
	}
	p.close();
	p1.close();
	remove(fname);
	rename("temp.bin", fname);
	return kol;
}

// ������� max_profit ��������� ������������ ������� 
// �� ������� ���� ������ ������ �� �������� ����
// ����� ���� �������
double max_profit(char country[], bool f = false) 
{
	fstream p(fname, ios::app);
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	Product zap;
	p.seekg(0, ios::beg);
	double max_price = 0, p_price; // max_price - ������������ �������, p_price - ������� �� ������� ������
	for (int i = 1; read(zap, i); i++) // ���� �������� �� ���� �������
	{
		p_price = zap.volume * zap.price; // ������� ��� ������� ������
		if (p_price > max_price && (strcmp(zap.country, country) == 0 || f)) // ������� ����� ������������ �������
		{
			max_price = p_price; // ���������� ����� ������������ �������
		}
	}
	p.close();
	return max_price;
}

// ������� all_profit ������� ����� ����� �������������
// ������� � ����� ��������� �������������� �������
// ��� ���������� ������. ������� ������� �� ��� ������� � �����, � ������ ��,
// ������� ���������� � ��������� ������ i
int all_profit(char country[], double& price, int i)
{
	fstream p(fname, ios::app);
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	Product zap;
	p.seekg(0, ios::beg);
	int sum = 0;
	price = 0;
	for (int j = i; read(zap, j); j++)
	{
		if (strcmp(zap.country, country) == 0) // �������� ������
		{
			sum += zap.volume;
			price += zap.price * zap.volume;
		}
	}
	p.close();
	return sum;
}


// ������� find_title ������� �����, ������� �������� 
// ���������� ����� � ����� �����������, �.�. ����� ����������
// �������. ������� ����� ������� ��� ��� �������, ��� � ������ ��,
// ������� ����������� � ���������� ������
void find_title(char country[], int& kol, int volume_p, double price_p, double max_p, bool f = false)
{
	fstream p(fname, ios::app);
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	Product zap;
	p.seekg(0, ios::beg);
	double p_price;
	for (int i = 1; read(zap, i); i++)
	{
		// �������� �� ������
		if (strcmp(zap.country, country) == 0 || f)
		{
			p_price = zap.volume * zap.price;
			// �������� �� ������������ �������
			if (p_price == max_p) 
			{
				print2(zap, kol, volume_p, price_p, max_p);
				kol++; // ���������� ������ �� �������
			}
		}
	}
	p.close();
}

// ������� spiski ���������� ������ �����, ����
// �������������� ������ �� �������������� �������, � ��������� ������ 
// ������ �������� � ����� ���������, � ����� ������� ����� ���������� �����
// ����� ���� �������������� �������
void spiski()
{
	fstream p(fname, ios::app);
	if (p)
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate |
			ios::binary);
	}
	Product zap;
	cout << shapka2;
	p.seekg(0, ios::beg);
	double max_p, price_p, max_p_all;
	int volume_p, volume_max, kol = 1;
	char best_title[11];
	for (int i = 1; read(zap, i); i++)
	{
		volume_max = all_profit(zap.country, price_p, 1); // ������� ������ ������ ������� � ������� �������
		volume_p = all_profit(zap.country, price_p, i); // ������� ������ ����� ������� � i-�� �������
		if (volume_max == volume_p) // �������� ����, ��� ������ ������ ������, ���������� � ���� ������ ������, � ��� 
			// ������ ������ ��� �� ���� �������� � ������
		{
			max_p = max_profit(zap.country);
			find_title(zap.country, kol, volume_p, price_p, max_p);
		}
		max_p_all = max_profit(zap.country, true);
		if (zap.volume * zap.price == max_p_all)
			strcpy_s(best_title, zap.title);
	}
	cout << endl << FinishL2 << endl;
	cout << "�����, ������� �������� ���������� ����� � ����� �����������, ���: " 
		<< best_title << ", �������� ������� � �������: " << max_p_all;
	p.close();
}