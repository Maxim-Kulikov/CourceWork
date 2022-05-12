#include"Main.h"

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector <Accounts> accounts;
	vector <Students> pupils;
	vector <string> groups;

	int n = getStuctures(A);
	accounts.reserve(n);

	n = getStuctures(FILES);
	groups.reserve(n);

	readFileOfGroups(FILES, groups);
	readFileOFAccounts(accounts, A);
	enterOrCreate(accounts, pupils, groups);
	writeInFileAccounts(accounts, A);
	writeInFileGroups(FILES, groups);

	return 0;
}

void enterOrCreate(vector<Accounts>& accounts, vector<Students>& pupils, vector <string>& groups) {
	int k = 1;
	do {
		switch (firstMenu()) {
		case 1: enterAs_(accounts, pupils, groups);
			break;
		case 2: createAccount(accounts, A, groups);
			break;
		case 0: k = 0;
			break;
		default: cout << "������!" << endl;
		}
	} while (k != 0);
	cout << endl;
	cout << "����� ��������!" << endl;
}
void enterAs_(vector<Accounts>& accounts, vector<Students>& pupils, vector <string>& groups) {
	system("cls");
	int a;
	Accounts account = autorization(accounts);

	if (account.role == "�������������") a = 1;
	else if (account.role == "�������") a = 2;
	else if (account.role == "������") a = 3;
	else a = 0;

	switch (a) {
	case 1: spaceForAdmin(accounts, groups);
		break;
	case 2: spaceForTeacher(pupils, account, accounts);
		break;
	case 3: spaceForStudent(pupils, account, accounts);
		break;
	case 0:
		break;
	}
}
Accounts autorization(vector<Accounts> accounts) {
	system("cls");
	string login;
	string password;
	Accounts a;

	cout << "������� �����: ";
	login = enterLogin();

	cout << "������� ������: ";
	password = enterPassword();

	for (int i = 0; i < accounts.size(); i++) {
		if (login == accounts[i].log and hashPassword(password, accounts[i].salt) == accounts[i].password) {
			if (accounts[i].access == 0) {
				cout << "\n��������� ���� ������������� ������� ��� ��� ������!\n" << endl;
				cout << endl;
				system("pause");
				return a;
			}
			return accounts[i];
		}
	}

	cout << "\n�������� ����� ��� ������!\n" << endl;
	cout << endl;
	system("pause");
	return a;
}
void createAccount(vector<Accounts>& accounts, string FILE, vector <string> groups)
{
	int g, k;
	bool flag = true;

	system("cls");
	k = 0;

	Accounts t;

	t.log = createLogin();
	t.salt = generateSalt();
	t.password = createPassword();
	t.password = hashPassword(t.password, t.salt);


	for (int i = 0; i < accounts.size(); i++) {
		if (t.log == accounts[i].log) {
			k++; break;
		}
	}

	if (k == 0) {
		t.role = enterRole();
		system("cls");
		cout << "������� ���� �������: ";
		t.sureName = enterFIO();
		cout << "\n������� ���: ";
		t.name = enterFIO();
		cout << "\n������� ��������: ";
		t.patronymic = enterFIO();
		cout << "\n������� ��� ��������: ";
		check_birth(t.birthYear);

		if (t.role == "�������" or t.role == "������") {
			cout << "������� ����� ����� ������\n";
			showGroups(groups);
			while (flag) {
				cout << "\n>>> ";
				t.group = enterGroup() + ".txt";
				for (int i = 0; i < groups.size(); i++) if (t.group == groups[i]) flag = false;
			}
		}
		t.access = 0;
		accounts.push_back(t);
		cout << "\n��������� ���� ������������� ������� ��� ��� ������!\n" << endl;
	}
	else cout << "\n������������ � ����� ������� ��� ����������!\n" << endl;
	system("pause");
}
