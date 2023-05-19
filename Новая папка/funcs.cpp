#include "Header.h"

void write(char* fname1, Product zap, int num)
{
	fstream p(fname1, ios::app); // создание потока
	if (p) // проверка файла на существование
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
	cout << "\nВведите наименование товара:\n";
	cin >> new_zap.title;
	cout << "Введите страну, куда товар экпортируется:\n";
	cin >> new_zap.country;
	cout << "Введите число - объем поставляемой партии в штуках:\n";
	cin >> new_zap.volume;
	cout << "Выберите число - цену за единицу товара:\n";
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
	else cout << endl << "Такой записи нет";
	_getch();
	p.close();
}

// меняет метку выбранной записи с '+' на '-' 
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

// меняет все метки с '-' на '+'
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

// удаляет все помеченные записи
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

// функция max_profit вычисляет максимальную прибыль 
// от продажи всей партии товара по заданной цене
// среди всех товаров
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
	double max_price = 0, p_price; // max_price - максимальная прибыль, p_price - прибыль от данного товара
	for (int i = 1; read(zap, i); i++) // цикл проходит по всем записям
	{
		p_price = zap.volume * zap.price; // прибыль для данного товара
		if (p_price > max_price && (strcmp(zap.country, country) == 0 || f)) // находим новую максимальную прибыль
		{
			max_price = p_price; // запоминаем новую максимальную прибыль
		}
	}
	p.close();
	return max_price;
}

// функция all_profit считает общий объём экпортируемых
// товаров и общую стоимость экспортируемых товаров
// для конкретной страны. Функция считает не все запросы в файле, а только те,
// которые начинаются с заданного номера i
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
		if (strcmp(zap.country, country) == 0) // проверка страны
		{
			sum += zap.volume;
			price += zap.price * zap.volume;
		}
	}
	p.close();
	return sum;
}


// функция find_title находит товар, который приносит 
// наибольший доход в казну государства, т.е. имеет наибольшую
// прибыль. Функция может считать как все запросы, так и только те,
// которые направленны в конкретную страну
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
		// проверка на страну
		if (strcmp(zap.country, country) == 0 || f)
		{
			p_price = zap.volume * zap.price;
			// проверка на максимальную прибыль
			if (p_price == max_p) 
			{
				print2(zap, kol, volume_p, price_p, max_p);
				kol++; // увеличение номера на единицу
			}
		}
	}
	p.close();
}

// функция spiski составляет список стран, куда
// экспортируется каждый из экспортируемых товаров, с указанием общего 
// объема экспорта и общей стоимости, а также выводит самый прибыльный товар
// среди всех экспортируемых товаров
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
		volume_max = all_profit(zap.country, price_p, 1); // подсчёт общего объема начиная с первого запроса
		volume_p = all_profit(zap.country, price_p, i); // подсчёт общего объма начиная с i-го запроса
		if (volume_max == volume_p) // проверка того, что данный запрос первый, включающий в себя данную страну, и что 
			// данная страна ещё не была включена в список
		{
			max_p = max_profit(zap.country);
			find_title(zap.country, kol, volume_p, price_p, max_p);
		}
		max_p_all = max_profit(zap.country, true);
		if (zap.volume * zap.price == max_p_all)
			strcpy_s(best_title, zap.title);
	}
	cout << endl << FinishL2 << endl;
	cout << "Товар, который приносит наибольший доход в казну государства, это: " 
		<< best_title << ", приносит прибыль в размере: " << max_p_all;
	p.close();
}