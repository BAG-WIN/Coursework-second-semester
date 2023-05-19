#include "Header.h"

// глобальные переменные
char fname[20] = "file1.bin";
int len = sizeof(Product); 

char menu()
{
	setlocale(LC_ALL, "Russian");
	cout << endl << "\n\t1-> Добавить запись"
		<< endl << "\t2-> Чтение всех записей"
		<< endl << "\t3-> Чтение записи с N номером"
		<< endl << "\t4-> Пометить на удаление"
		<< endl << "\t5-> Снять пометку на удаление"
		<< endl << "\t6-> Удалить выбранную запись"
		<< endl << "\t7-> Список стран"
		<< endl << "\t0-> EXIT" << endl;
	char s;
	cout << "\n\t-> ";
	cin >> s;
	return s;
}

void main()
{
	fstream p(fname, ios::app); // объявление указателя для записи в конец файла
	setlocale(LC_ALL, "Russian"); // вывод букв кириллицы

	if (p) // проверка файла на существование
	{
		p.close();
		p.open(fname, ios::in | ios::out | ios::ate | // in - открытие, out - запись
			ios::binary); // :: - область видимости
	}
	int n;
	do
	{
		char s = menu();
		switch (s)
		{
		case '1':
			cout << "Введите кол-во записей: ";
			cin >> n;
			writeNzap(p, n);
			break;
		case '2':
			readAll(p);
			_getch();
			break;
		case '3':
			int nom;
			cout << "\nВведите номер записи: ";
			cin >> nom;
			readN(p, nom);
			_getch();
			break;
		case '4':
			int a;
			char name[10];
			cout << "\n\tВведите наименование товара: ";
			cin >> name;
			a = metkaDel(p, name);
			break;
		case '5':
			UNmetkaDel(p);
			system("cls");
			break;
		case '6':
			Delete(p);
			cout << ("\n\tDone!");
			break;
		case '7':
			spiski(p);
			break;
		case '0':
			p.close();
			exit(0);
		}
	} while (1);
	p.close();
	system("pause");
}

/*Министерство торговли маленькой африканской страны заказало программу обработки
экспортируемых товаров. В файле о каждом из товаров заводится запись следующего
содержания: наименование товара, страна, куда экспортируется, объем поставляемой
партии в штуках, цена единицы товара. Программа составляет список стран, куда
экспортируется каждый из экспортируемых товаров, с указанием общего объема экспорта
и общей стоимости. Программа называет товар, который приносит наибольший доход в
казну государства.*/



	    