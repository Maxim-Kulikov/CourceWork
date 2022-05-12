#include"Common.h"

void redactYourAccount(Accounts& account, vector<Accounts>& accounts) {
	int x, num = getNumOfAccount(accounts, account.log);

	do {
		system("cls");
		showOneAccount(accounts, num);
		cout << endl;

		switch (x = menuOfRedactionOfYourAccount()) {
		case 0:
			break;
		case 1:
			accounts[num].log = createLogin();
			break;
		case 2: system("cls");
			accounts[num].password = createPassword();
			accounts[num].password = hashPassword(accounts[num].password, accounts[num].salt);
			break;
		case 3:
			cout << "\n        |||\n        VVV\n\nВведите фамилию: ";
			accounts[num].sureName = enterFIO();
			break;
		case 4:
			cout << "\n        |||\n        VVV\nВведите имя: ";
			accounts[num].name = enterFIO();
			break;
		case 5:
			cout << "\n        |||\n        VVV\nВведите отчество: ";
			accounts[num].patronymic = enterFIO();
			break;
		case 6:
			cout << "\n        |||\n        VVV\nВведите год рождения: ";
			check_birth(accounts[num].birthYear);
			break;
		}
		account = accounts[num];
		cout << "\n        |||\n        VVV\n1 - Продолжить редактирование       Другая цифра - ВЫЙТИ ";
		check_input(x);

	} while (x == 1);
}
void showOneAccount(vector<Accounts> accounts, int i) {
	cout << "___________________________________" << endl;
	cout << "|Логин:       |" << setw(19) << accounts[i].log << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
	cout << "|Фамилия:     |" << setw(19) << accounts[i].sureName << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
	cout << "|Имя:         |" << setw(19) << accounts[i].name << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
	cout << "|Отчество:    |" << setw(19) << accounts[i].patronymic << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
	cout << "|Год рождения:|" << setw(19) << accounts[i].birthYear << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
	cout << "|Роль:        |" << setw(19) << accounts[i].role << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
	if (accounts[i].group != "-") { cout << "|Группа:      |             "; for (int j = 0; accounts[i].group[j] != '.'; j++) cout << accounts[i].group[j]; cout << "|\n"; }
	else cout << "|Группа:      |" << setw(19) << accounts[i].group << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
	cout << "|Статус:      |" << setw(19) << accounts[i].access << "|" << endl;
	cout << "|-------------|-------------------|" << endl;
}
void deleteGroupForAccounts(vector<Accounts>& v, string group) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].group == group) v[i].group = "-";
	}
}
int symbolsIntoMark() {
	char a[3];
	int i = 0;

	while (1) {
		a[i] = _getch();

		if (a[i] == 13) break;
		if (i > 1 and a[i] != 8 and a[i] != 13) continue;
		if (a[i] == ' ') continue;
		if (a[i] == 8 and i > 0) { cout << "\b \b"; i--; continue; }
		if (!(a[i] >= '0' and a[i] <= '9')) continue;
		if ((a[i - 1] == '0' or (a[i - 1] >= '2' and a[i - 1] <= '9')) and a[i] != 8 and a[i] != 13) continue;
		if (a[i - 1] == '1' and a[i] != 8 and a[i] != 13 and a[i] != '0') continue;
		cout << a[i];
		i++;
	}
	a[i] = '\0';

	if (a[0] == '1' and a[1] == '0') return 10;
	else return a[0] - 48;

}
int getNumOfAccount(vector<Accounts> v, string log) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].log == log) {
			return i;
		}
	}
	return -1;
}
double countAvrMark(vector<Students> pupils, int i) {
	return (pupils[i].englishMark + pupils[i].historyMark + pupils[i].mathMark + pupils[i].physicMark + pupils[i].programmingMark) / 5.;
}
bool exit_or_not()
{
	int a;
	do
	{
		cout << "\n1 - ПРОДОЛЖИТЬ          0 - ВЫХОД ";
		check_input(a);
		cout << endl;
	} while (a != 1 and a != 0);
	if (a == 1) { system("cls"); return true; }
	if (a == 0)
	{
		system("cls");
		return false;
	}
}
int getStuctures(string file_path) {
	ofstream fadd(file_path, ios::app);
	if (!fadd.is_open()) fadd << "";
	fadd.close();

	ifstream file(file_path, ios::in);
	int number_of_strings = 0;
	if (file.is_open()) {

		while (file.ignore(256, '\n'))
			number_of_strings++;

	}
	file.close();
	return number_of_strings;
}
void del(vector<Students>& v, int index_delete) {
	index_delete--;
	v.erase(v.begin() + index_delete);
}
void del(vector<Accounts>& v, int index_delete) {
	index_delete--;
	v.erase(v.begin() + index_delete);
}
void readFileOFAccounts(vector<Accounts>& accounts, string FILE) {
	ifstream fin(FILE, ios::in);
	if (fin.is_open()) {
		while (!fin.eof()) {
			Accounts t;
			fin >> t.log;
			fin >> t.password;
			fin >> t.salt;
			fin >> t.role;
			fin >> t.sureName;
			fin >> t.name;
			fin >> t.patronymic;
			fin >> t.birthYear;
			fin >> t.group;
			fin >> t.access;
			accounts.push_back(t);
		}
	}
	fin.close();

	if (accounts.empty()) {
		Accounts t;
		t.log = "admin";
		t.salt = generateSalt();
		t.password = sha256(sha256("admin" + t.salt) + sha256("admin"));
		t.role = "администратор";
		t.sureName = "-";
		t.name = "-";
		t.patronymic = "-";
		t.birthYear = 0;
		t.group = "-";
		t.access = 1;
		accounts.push_back(t);
	}
}
void writeInFileAccounts(vector<Accounts> accounts, string FILE) {
	ofstream fout(FILE, ios::out);
	//sort(accounts.begin(), accounts.end(), [](const Accounts& a, const Accounts& b) { return a.log < b.log; });
	for (int i = 0; i < accounts.size(); i++) {
		fout << accounts[i].log << " "
			<< accounts[i].password << " "
			<< accounts[i].salt << " "
			<< accounts[i].role << " "
			<< accounts[i].sureName << " "
			<< accounts[i].name << " "
			<< accounts[i].patronymic << " "
			<< accounts[i].birthYear << " "
			<< accounts[i].group << " "
			<< accounts[i].access;

		if (i < accounts.size() - 1) fout << endl;
	}
	fout.close();
}
void readFileOfGroups(string FILE, vector <string>& groups) {
	ifstream fin(FILE, ios::in);
	if (fin.is_open()) {
		while (!fin.eof()) {
			string a;
			fin >> a;
			if (a.size() != 0) groups.push_back(a);
		}
	}
	fin.close();
}
void writeInFileGroups(string FILE, vector <string> groups) {
	ofstream fout(FILE, ios::out);
	for (int i = 0; i < groups.size(); i++) {
		fout << groups[i];
		if (i < groups.size() - 1) fout << endl;
	}
	fout.close();
}
void readFileOfStudents(vector<Students>& pupils, string FILE) {
	ifstream fin(FILE, ios::in);
	if (!pupils.empty())pupils.clear();
	if (fin.is_open()) {
		while (!fin.eof()) {
			Students t;
			fin >> t.sureName;
			fin >> t.name;
			fin >> t.patronymic;
			fin >> t.birthYear;
			fin >> t.group;
			fin >> t.physicMark;
			fin >> t.mathMark;
			fin >> t.programmingMark;
			fin >> t.englishMark;
			fin >> t.historyMark;
			fin >> t.physicalEdOffset;
			fin >> t.polyticOffset;
			fin >> t.chemistryOffset;
			fin >> t.biologyOffset;
			fin >> t.belOffset;
			if (t.sureName.size() != 0) pupils.push_back(t);
		}
	}
	fin.close();
}
void writeInFileStudents(vector<Students> pupils, string FILE) {
	ofstream fout(FILE, ios::out);
	for (int i = 0; i < pupils.size(); i++) {
		fout << pupils[i].sureName << " " <<
			pupils[i].name << " " <<
			pupils[i].patronymic << " " <<
			pupils[i].birthYear << " " <<
			pupils[i].group << " " <<
			pupils[i].physicMark << " " <<
			pupils[i].mathMark << " " <<
			pupils[i].programmingMark << " " <<
			pupils[i].englishMark << " " <<
			pupils[i].historyMark << " " <<
			pupils[i].physicalEdOffset << " " <<
			pupils[i].polyticOffset << " " <<
			pupils[i].chemistryOffset << " " <<
			pupils[i].biologyOffset << " " <<
			pupils[i].belOffset;

		if (i < pupils.size() - 1) fout << endl;
	}
	fout.close();
}
int countDebts(vector<Students> pupils, int i) {
	int num = 0;

	if (pupils[i].physicalEdOffset == "незачёт") num++;
	if (pupils[i].polyticOffset == "незачёт") num++;
	if (pupils[i].chemistryOffset == "незачёт") num++;
	if (pupils[i].biologyOffset == "незачёт") num++;
	if (pupils[i].belOffset == "незачёт") num++;

	return num;
}
int countDebts(Students pupils) {
	int num = 0;

	if (pupils.physicalEdOffset == "незачёт") num++;
	if (pupils.polyticOffset == "незачёт") num++;
	if (pupils.chemistryOffset == "незачёт") num++;
	if (pupils.biologyOffset == "незачёт") num++;
	if (pupils.belOffset == "незачёт") num++;

	return num;
}