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
	stream << setw(2) << '�';
	stream << setw(12) << "�����";
	stream << setw(12) << "������";
	stream << setw(12) << "�����"; 
	stream << setw(17) << "���� �� �������";
	stream << setw(7) << "�����" << setw(3) << '|' << endl;
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
	stream << setw(2) << '�';
	stream << setw(12) << "������";
	stream << setw(14) << "����� �����";
	stream << setw(12) << "����� ����"; 
	stream << setw(10) << "������";
	stream << setw(14) << "�������";
	stream << setw(3) << '|' << endl;
	stream << setw(50) << "�����";
	stream << setw(14) << "� ������" << setw(3
	) << '|';
	stream << endl << FinishL2;
	return stream;
}
