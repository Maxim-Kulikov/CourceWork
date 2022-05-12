#include<conio.h>
#include"check.h"

string getSymbolsForSalt()
{
	string symbols;
	symbols.reserve(62);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	int i = 0;
	for (int k = 0; k < 26; k++)
	{
		symbols.push_back(little_letter++);
		symbols.push_back(big_letter++);
		if (k < 10) symbols.push_back(number++);
	}

	return symbols;
}
string generateSalt()
{
	string symbols = getSymbolsForSalt();
	srand(time(NULL));

	string salt;
	salt.reserve(16);

	for (int i = 0; i < 16; i++)
	{
		salt.push_back(symbols[rand() % 62]);
	}

	return salt;
}
string createLogin()
{
	system("cls");
	cout << "���������� ����� (�� 5 ��������): ";
	char login[20];
	int i = 0;
	while (1) {

		if (i > 18)
			do {
				login[i] = _getch();
			} while (login[i] != 8 and login[i] != 13);
		else login[i] = _getch();

		if (login[i] == 13 and i > 4) break;
		if (login[i] == 8 and i > 0) { cout << "\b \b"; i--; continue; }
		if (!((login[i] >= 'A' and login[i] <= 'Z') or (login[i] >= 'a' and login[i] <= 'z') or (login[i] >= '0' and login[i] <= '9') or login[i] == '.' or login[i] == '_'))continue;

		cout << login[i];
		i++;
	}
	login[i] = '\0';

	string res = login;

	return res;
}
string enterLogin() {
	char login[20];
	int i = 0;
	while (1) {

		if (i > 18)
			do {
				login[i] = _getch();
			} while (login[i] != 8 and login[i] != 13);
		else login[i] = _getch();

		if (login[i] == 13 and i > 0) break;
		if (login[i] == 8 and i > 0) { cout << "\b \b"; i--; continue; }
		if (!((login[i] >= 'A' and login[i] <= 'Z') or (login[i] >= 'a' and login[i] <= 'z') or (login[i] >= '0' and login[i] <= '9') or login[i] == '.' or login[i] == '_'))continue;

		cout << login[i];
		i++;
	}
	login[i] = '\0';
	cout << endl;
	string res = login;

	return res;
}
string createPassword()
{
	system("cls");
	char a[15];
	int i = 0, num = 0, letter = 0, symbols = 0;

	cout << "���������� ������ (8 � ����� ��������): ";
	while (1)
	{
		num = 0, letter = 0, symbols = 0;

		if (i > 13)
			do {
				a[i] = _getch();
			} while (a[i] != 8 and a[i] != 13);
		else a[i] = _getch();
		system("cls");

		cout << "���������� ������ (8 � ����� ��������): ";

		for (int j = 0; j < i; j++)  cout << "*";

		for (int j = 0; j <= i; j++)
		{
			if ((a[j] >= 'A' and a[j] <= 'Z') or (a[j] >= 'a' and a[j] <= 'z')) letter++;
			if ((a[j] >= '0' and a[j] <= '9')) num++;
			if (a[j] == '.' or a[j] == '_')symbols++;
		}

		if (a[i] == 13 and num != 0 and letter != 0 and symbols != 0 and i >= 8) break;
		if (a[i] == 8 and i > 0) { cout << "\b \b"; i--; continue; }
		if (a[i] == ' ')continue;
		if (!((a[i] >= 'A' and a[i] <= 'Z') or (a[i] >= 'a' and a[i] <= 'z') or (a[i] >= '0' and a[i] <= '9') or a[i] == '.' or a[i] == '_'))continue;

		cout << "*" << endl;

		if (i < 5) cout << "������� �������� ������!";
		else {
			if (num != 0 and (letter == 0 and symbols == 0)) cout << "������� ������� ������, �������� ����� � << . >> ��� << _ >>";
			else
				if ((num != 0 and letter != 0) and symbols == 0) cout << "������� ������, �������� << . >> ��� << _ >>";
				else
					if (num == 0 and (letter != 0 and symbols != 0)) cout << "������� ������, �������� �����";
					else
						if ((num != 0 and symbols != 0) and letter == 0) cout << "������� ������, �������� �����";
						else
							if (symbols != 0 and (num == 0 and letter == 0)) cout << "������� ������� ������, �������� ����� � �����!";
							else
								if (letter != 0 and (num == 0 and symbols == 0)) cout << "������� ������� ������, �������� ����� � << . >> ��� << _ >>";
								else
									cout << "���������� ������!";
		}
		i++;
	}
	a[i] = '\0';
	cout << endl;

	return a;
}
string enterPassword() {
	char a[15];
	int i = 0;
	
	while (1) {

		if (i > 13)
			do {
				a[i] = _getch();
			} while (a[i] != 8 and a[i] != 13);
		else a[i] = _getch();
		
		if (a[i] == 13)break;
		if (a[i] == 8 and i > 0) { cout << "\b \b"; i--; continue; }
		if (a[i] == ' ')continue;
		if (!((a[i] >= 'A' and a[i] <= 'Z') or (a[i] >= 'a' and a[i] <= 'z') or (a[i] >= '0' and a[i] <= '9') or a[i] == '.' or a[i] == '_'))continue;

		cout << "*";
		i++;
	}
	a[i] = '\0';
	cout << endl;

	return a;
}
void check_input(int& number)
{

	while (1)
	{
		cin >> number;
		if (cin.get() == '\n') break;
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "������������ ����, ������� ����� �������� ��� ���� ������� ����� ����, ���������: ";
		}
	}
}
void check_birth(int& x)
{
	while (1)
	{
		check_input(x);
		if (!(x > 1950 and x < 2005)) cout << "������ ����� �� �������� � ���������! ���������: ";
		else break;
	}
}
string enterRole() {
	system("cls");
	int a;

	cout << "������� ��� �� (1 - �������/2 - ������): ";

	while (1) {
		check_input(a);
		if (a == 1 or a == 2) break;
	}

	switch (a) {
	case 1: return "�������";
	case 2: return "������";
	}

}
string enterOffset() {
	char a;

	cout << "1 - �����\n2 - �������\n0 - ������" << endl;
	do {
		a = _getch();
	} while (a != '1' and a != '2' and a != '0');

	if (a == '1') return "�����";
	if (a == '2') return "�������";
	if (a == '0') return "-";
}
string enterFIO()
{
	int i = 0;
	char s[20];
	while (1)
	{
		if (i > 13)
			do {
				s[i] = _getch();
			} while (s[i] != 8 and s[i] != 13);
		else s[i] = _getch();

		if (s[0] == '-' and i == 0) {
			cout << s[0];
			i++;
			continue;
		}
		if (s[i] == 13 and i != 0) break;
		if (s[i] == 8 and i > 0) { cout << "\b \b"; i--; continue; }
		if (!(s[0] >= '�' and s[0] <= '�'))continue;
		if (i > 0 and (s[i] >= '�' and s[i] <= '�')) continue;
		if (!((s[i] >= '�' and s[i] <= '�') or (s[i] >= '�' and s[i] <= '�') or s[i] == '�')) continue;
		if (s[i] == ' ')continue;
		cout << s[i];
		i++;
	}
	s[i] = '\0';
	string res = s;
	return res;
}
string enterGroup() {
	char group[7];
	int i = 0;

	while (1) {
		if (i > 5)
			do {
				group[i] = _getch();
			} while (group[i] != 8 and group[i] != 13);
		else group[i] = _getch();

		if (i > 5 and group[i] == 13) break;
		if (group[i] == 8 and i > 0) { cout << "\b \b"; i--; continue; }
		if (!(group[i] >= '0' and group[i] <= '9')) continue;


		cout << group[i];
		i++;
	}

	group[i] = '\0';
	return group;
} 
string hashPassword(string& password, string salt) {
	return password = sha256(sha256(password + salt) + sha256(password));
}