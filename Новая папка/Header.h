#include <conio.h> 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

extern int len;
extern char fname[20]; // переменная, имя файла

struct Product // структура, записывающая информацию для одного товара
{
	char title[11]; // наименование товара (без пробелов)
	char country[11]; // страна экспорта (без пробелов)
	int volume; // объем поставляемой партии в штуках
	double price; // цена единицы товара
	char metka[2]; // метка
};

ostream& FinishL(ostream& stream);
ostream& FinishL2(ostream& stream);
ostream& shapka(ostream& stream);
ostream& shapka2(ostream& stream);
void write(char* fname1, Product zap, int num = 0);
void print(Product zap, int i);
void print2(Product zap, int i, int volum_p, double price_p, double max_p);
Product vvod();
void writeNzap(int n);
fstream& read(Product& zap, int num = 0);
void readAll();
void readN(int N);
int metkaDel(char* shifr);
void UNmetkaDel();
void spiski();
int Delete();
