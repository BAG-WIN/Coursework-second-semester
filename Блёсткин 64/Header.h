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
void write(fstream& p, Product zap, int num = 0);
void print(Product zap, int i);
void print2(Product zap);
Product vvod();
void writeNzap(fstream& p, int n);
fstream& read(fstream& p, Product& zap, int num = 0);
void readAll(fstream& p);
//void izmenenie(fstream& p);
void readN(fstream& p, int N);
int metkaDel(fstream& p, char* shifr);
void UNmetkaDel(fstream& p);
void spiski(fstream& p);
int Delete(fstream& p);
