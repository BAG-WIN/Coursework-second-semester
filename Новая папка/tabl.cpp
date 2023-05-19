#include "Header.h"
#include <iomanip>
using namespace std;

ostream& FinishL(ostream& stream);
ostream& FinishL2(ostream& stream);
ostream& shapka(ostream& stream);
ostream& shapka2(ostream& stream);

ostream& shapka(ostream& stream)
{
	setlocale(LC_ALL, "Russian");
	stream << endl << FinishL << endl;
	stream << setw(2) << '№';
	stream << setw(12) << "товар";
	stream << setw(12) << "страна";
	stream << setw(12) << "объём"; 
	stream << setw(17) << "цена за единицу";
	stream << setw(7) << "Метка" << setw(3) << '|' << endl;
	stream << setw(65) << '|' << endl << FinishL;
	return stream;
}
ostream& FinishL(ostream& stream)
{
	stream << setfill('-') << setw(65) << '|' << setfill(' ');
	return stream;
}
ostream& FinishL2(ostream& stream)
{
	stream << setfill('-') << setw(67) << '|' << setfill(' ');
	return stream;
}
ostream& shapka2(ostream& stream)
{
	setlocale(LC_ALL, "Russian");
	stream << endl << FinishL2 << endl;
	stream << setw(2) << '№';
	stream << setw(12) << "страна";
	stream << setw(14) << "общий объём";
	stream << setw(12) << "общая цена"; 
	stream << setw(10) << "лучший";
	stream << setw(14) << "прибыль";
	stream << setw(3) << '|' << endl;
	stream << setw(50) << "товар";
	stream << setw(14) << "с товара" << setw(3
	) << '|';
	stream << endl << FinishL2;
	return stream;
}
