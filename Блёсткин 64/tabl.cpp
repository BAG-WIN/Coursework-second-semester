//#include "Header.h"
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
	stream << '№';
	stream << setw(12) << "товар";
	stream << setw(12) << "страна";
	stream << setw(10) << "объём"; 
	stream << setw(19) << "цена за единицу";
	stream << setw(7) << "Метка" << setw(3) << '|' << endl;
	stream << setw(64) << '|' << endl << FinishL;
	return stream;
}
ostream& FinishL(ostream& stream)
{
	stream << setfill('-') << setw(64) << '|' << setfill(' ');
	return stream;
}
ostream& FinishL2(ostream& stream)
{
	stream << setfill('-') << setw(40) << '|' << setfill(' ');
	return stream;
}
ostream& shapka2(ostream& stream)
{
	setlocale(LC_ALL, "Russian");
	stream << endl << FinishL2 << endl;
	stream << '№';
	stream << setw(12) << "страна";
	stream << setw(12) << "объём";
	stream << setw(12) << "цена"; 
	stream << setw(3) << '|' << endl;
	stream << setw(40) << '|';
	stream << endl << FinishL2;
	return stream;
}
