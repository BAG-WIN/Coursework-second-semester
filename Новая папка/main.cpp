/*������������ �������� ��������� ����������� ������ �������� ��������� ���������
�������������� �������. � ����� � ������ �� ������� ��������� ������ ����������
����������: ������������ ������, ������, ���� ��������������, ����� ������������
������ � ������, ���� ������� ������. ��������� ���������� ������ �����, ����
�������������� ������ �� �������������� �������, � ��������� ������ ������ ��������
� ����� ���������. ��������� �������� �����, ������� �������� ���������� ����� �
����� �����������.*/
#include "Header.h"

// ���������� ����������
char fname[20];
int len = sizeof(Product); 

char menu()
{
	setlocale(LC_ALL, "Russian");
	cout << endl << "\n\t1-> �������� ������"
		<< endl << "\t2-> ������ ���� �������"
		<< endl << "\t3-> ������ ������ � N �������"
		<< endl << "\t4-> �������� �� ��������"
		<< endl << "\t5-> ����� ������� �� ��������"
		<< endl << "\t6-> ������� ��������� ������"
		<< endl << "\t7-> ������ �����"
		<< endl << "\t0-> EXIT" << endl;
	char s;
	cout << "\n\t-> ";
	cin >> s;
	return s;
}

void main()
{
	setlocale(LC_ALL, "Russian"); // ����� ���� ���������
	cout << "������� ��� �����:\n";
	cin >> fname;
	int n;
	do
	{
		char s = menu();
		switch (s)
		{
		case '1':
			cout << "������� ���-�� �������: ";
			cin >> n;
			writeNzap(n);
			break;
		case '2':
			readAll();
			_getch();
			break;
		case '3':
			int nom;
			cout << "\n������� ����� ������: ";
			cin >> nom;
			readN(nom);
			_getch();
			break;
		case '4':
			int a;
			char name[10];
			cout << "\n\t������� ������������ ������: ";
			cin >> name;
			a = metkaDel(name);
			break;
		case '5':
			UNmetkaDel();
			system("cls");
			break;
		case '6':
			Delete();
			cout << ("\n\tDone!");
			break;
		case '7':
			spiski();
			break;
		case '0':
			exit(0);
		}
	} while (1);
	system("pause");
}    