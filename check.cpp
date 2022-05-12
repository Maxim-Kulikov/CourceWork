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
	cout << "Придумайте логин (от 5 символов): ";
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

	cout << "Придумайте пороль (8 и более символов): ";
	while (1)
	{
		num = 0, letter = 0, symbols = 0;

		if (i > 13)
			do {
				a[i] = _getch();
			} while (a[i] != 8 and a[i] != 13);
		else a[i] = _getch();
		system("cls");

		cout << "Придумайте пороль (8 и более символов): ";

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

		if (i < 5) cout << "Слишком короткий пороль!";
		else {
			if (num != 0 and (letter == 0 and symbols == 0)) cout << "Слишком простой пороль, добавьте буквы и << . >> или << _ >>";
			else
				if ((num != 0 and letter != 0) and symbols == 0) cout << "Простой пороль, добавьте << . >> или << _ >>";
				else
					if (num == 0 and (letter != 0 and symbols != 0)) cout << "Простой пороль, добавьте цифры";
					else
						if ((num != 0 and symbols != 0) and letter == 0) cout << "Простой пороль, добавьте буквы";
						else
							if (symbols != 0 and (num == 0 and letter == 0)) cout << "Слишком простой пороль, добавьте буквы и цифры!";
							else
								if (letter != 0 and (num == 0 and symbols == 0)) cout << "Слишком простой пороль, добавьте цифры и << . >> или << _ >>";
								else
									cout << "Прекрасный пороль!";
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
			cout << "Некорректный ввод, слишком много символов или есть символы кроме цифр, повторите: ";
		}
	}
}
void check_birth(int& x)
{
	while (1)
	{
		check_input(x);
		if (!(x > 1950 and x < 2005)) cout << "Скорее всего вы ошиблись с возрастом! Повторите: ";
		else break;
	}
}
string enterRole() {
	system("cls");
	int a;

	cout << "Введите кто вы (1 - Учитель/2 - Ученик): ";

	while (1) {
		check_input(a);
		if (a == 1 or a == 2) break;
	}

	switch (a) {
	case 1: return "учитель";
	case 2: return "ученик";
	}

}
string enterOffset() {
	char a;

	cout << "1 - зачёт\n2 - незачёт\n0 - Отмена" << endl;
	do {
		a = _getch();
	} while (a != '1' and a != '2' and a != '0');

	if (a == '1') return "зачёт";
	if (a == '2') return "незачёт";
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
		if (!(s[0] >= 'А' and s[0] <= 'Я'))continue;
		if (i > 0 and (s[i] >= 'А' and s[i] <= 'Я')) continue;
		if (!((s[i] >= 'А' and s[i] <= 'Я') or (s[i] >= 'а' and s[i] <= 'я') or s[i] == 'ё')) continue;
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