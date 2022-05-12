#include"Admin.h"

void spaceForAdmin(vector<Accounts>& accounts, vector <string>& groups) {
	int k = 1;
	do {
		system("cls");
		switch (menuForAdmin()) {
		case 1:
			system("cls");
			showAllAccounts(accounts);
			system("pause");
			break;
		case 2: allowAccess(accounts);
			break;
		case 3: redactAccountByAdmin(accounts, groups);
			system("pause");
			break;
		case 4: createAccountByAdmin(accounts, groups);
			break;
		case 5: deleteAccount(accounts);
			break;
		case 6:
			system("cls");
			createGroup(groups);
			break;
		case 7:
			system("cls");
			if (groups.empty()) {
				cout << "Вы ещё не создавали группы!\n\n";
				system("pause");
			}
			else {
				showGroups(groups);
				deleteGroup(groups, accounts);
			}

			break;
		case 0: k = 0;
		}
	} while (k != 0);
}
void deleteAccount(vector<Accounts>& accounts) {
	system("cls");

	int a = menuOfDelete();
	int num;

	system("cls");

	switch (a) {
	case 0:
		break;
	case 1:
		num = getNumOfAccountWithLog(accounts);
		if (num != -1) deleteAccountByAdmin(accounts, num);
		break;
	case 2:
		num = getNumOfAccount(accounts);
		if (num != -1) deleteAccountByAdmin(accounts, num);
	}

	system("pause");
}
void createAccountByAdmin(vector<Accounts>& accounts, vector <string> groups) {
	system("cls");
	int a;
	bool flag = true;
	Accounts t;

	cout << "Придумайте логин: "; t.log = enterLogin();
	for (int i = 0; i < accounts.size(); i++) if (t.log == accounts[i].log) flag = false;
	if (!flag) cout << "\n    Пользователь с таким логином уже существует!\n";
	else {
		cout << "\nПридумайте пороль: ";  t.password = enterPassword();
		t.salt = generateSalt();
		t.password = hashPassword(t.password, t.salt);
		t.group = "-";

		cout << "\nВыберите роль\n1 - администратор\n2 - учитель\n3 - ученик\nВведите: ";
		do {
			check_input(a);
		} while (!(a >= 1 and a <= 3));
		if (a == 1) t.role = "администратор";
		if (a == 2) t.role = "учитель";
		if (a == 3) t.role = "ученик";
		cout << "\nВведите фамилию: "; t.sureName = enterFIO();
		cout << "\nВведите имя: "; t.name = enterFIO();
		cout << "\nВведите отчество: "; t.patronymic = enterFIO();
		cout << "\nВведите год рождения: "; check_birth(t.birthYear);
		if (t.role == "учитель" or t.role == "ученик") {
			if (groups.empty()) t.group = "-";
			else {
				cout << "Введите номер вашей группы\n";
				showGroups(groups);
				while (flag) {
					cout << ">>> ";
					t.group = enterGroup() + ".txt";
					for (int i = 0; i < groups.size(); i++) if (t.group == groups[i]) flag = false;
					cout << endl;
				}
			}
		}
		t.access = 1;
		accounts.push_back(t);
	}
	cout << endl;
	system("pause");
}
void allowAccess(vector<Accounts>& accounts) {
	int a, b, c;
	system("cls");
	cout << "1 - Найти аккаунт по логину\n2 - Найти аккаунт по номеру\n0 - ВЫЙТИ" << endl;
	do {
		cout << "Введите: ";
		check_input(a);
	} while (!(a >= 0 and a <= 2));

	switch (a) {
	case 1: allowAccessWithLog(accounts);
		break;
	case 2: allowAccessWithNum(accounts);
	}
}
void allowAccessWithLog(vector<Accounts>& accounts) {
	string login;
	int n = -1, a, k;

	do {
		system("cls");
		n = getNumOfAccountWithLog(accounts);
		if (n == -1) cout << "Пользователя с таким логином не существует!" << endl;
		else if (accounts[n - 1].log == "admin") cout << "Главному админу доступ всегда разрешён!" << endl;
		else {
			system("cls");
			showOneAccount(accounts, n - 1);
			cout << endl;

			cout << "        |||\n        VVV\n\n1 - Разрешить доступ   0 - Запретить доступ\nВведите: ";

			do {
				check_input(a);
			} while (!(a >= 0 and a <= 1));

			accounts[n - 1].access = a;
		}
		cout << "\n\nХотите продолжить редактировать доступ?\n\n        |||\n        VVV\n";
		k = exit_or_not();
	} while (k != 0);
}
void allowAccessWithNum(vector<Accounts>& accounts) {
	int n = -1, a, k, choose;
	do {
		system("cls");
		cout << "1 | Аккаунты с открытым доступом\n2 | Аккаунты с закрытым\n0 | ВЫЙТИ\n\nВведите > ";

		do {
			check_input(choose);
		} while (!(choose >= 0 and choose <= 2));

		system("cls");
		if (choose != 0) {
			if (choose == 2) choose = 0;
			for (int i = 0; i < accounts.size(); i++) {
				if (accounts[i].access == choose) {
					cout << i + 1 << "-й пользователь" << endl;
					showOneAccount(accounts, i);
					cout << endl;
				}
			}

			do {
				cout << "0 | ВЫЙТИ\nВведите номер пользователя из этого списка: ";
				check_input(n);
			} while (!(n >= 0 and n <= accounts.size()));

			if (n != 0) {
				system("cls");
				if (accounts[n - 1].role == "администратор") cout << "Вы не можете заблокировать доступ Администратору!" << endl;
				else {
					showOneAccount(accounts, n - 1);
					cout << endl;

					cout << "1 - Разрешить доступ   0 - Запретить доступ\nВведите: ";
					do {
						check_input(a);
					} while (!(a >= 0 and a <= 1));

					accounts[n - 1].access = a;
				}
				cout << "\nХотите продолжить редактировать доступ? ";
				k = exit_or_not();
			}
			else k = 0;
		}
		else k = 0;
	} while (k != 0);
}
void showAllAccounts(vector<Accounts> accounts) {
	for (int i = 0; i < accounts.size(); i++) {
		showOneAccount(accounts, i);
		cout << endl;
	}
}
void redactAccountByAdmin(vector<Accounts>& accounts, vector <string> groups) {
	int a, num;
	bool flag = true;

	system("cls");
	a = findByNumberOrByLogin();

	switch (a) {
	case 0: num = -1;
		break;
	case 1: num = getNumOfAccountWithLog(accounts);
		break;
	case 2: num = getNumOfAccount(accounts);
	}

	system("cls");
	if (num != -1) {
		showOneAccount(accounts, num - 1);
	
		a = menuOFRedactionOfAccountByAdmin();
		switch (a) {
		case 0:
			break;
		case 1: if (accounts[num - 1].log == "admin") cout << "Вы не можете редактировать логин главному администратору!\n\n";
			  else {
				cout << "\nВведите новый логин: ";
				accounts[num - 1].log = createLogin();
		}
			break;
		case 2: cout << "\nВведите новый пороль: ";
			accounts[num - 1].password = enterPassword();
			accounts[num - 1].salt = generateSalt();
			accounts[num-1].password = hashPassword(accounts[num - 1].password, accounts[num - 1].salt);
			break;
		case 3:
			if (groups.empty()) cout << "\nВы ещё не создавали группы!\n";
			else {
				cout << "\nВведите новый номер группы\n";
				showGroups(groups);
				while (flag) {
					cout << ">>> ";
					accounts[num - 1].group = enterGroup() + ".txt";;
					for (int i = 0; i < groups.size(); i++) if (accounts[num - 1].group == groups[i]) flag = false;
				}
			}
		}
	}
	cout << endl;
}
int getNumOfAccount(vector<Accounts> accounts) {
	int a;

	system("cls");
	for (int i = 0; i < accounts.size(); i++) {
		cout << i + 1 << "-й пользователь" << endl;
		showOneAccount(accounts, i);
		cout << endl;
	}
	cout << "\n0 - ВЫЙТИ\nВведите номер существующего аккаунта: ";

	do {
		check_input(a);
	} while (!(a >= 0 and a <= accounts.size()));

	if (a != 0) return a;
	else return -1;
}
int getNumOfAccountWithLog(vector<Accounts> accounts) {
	string log;

	system("cls");
	cout << "Введите логин: ";
	log = enterLogin();

	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i].log == log) {
			return i + 1;
		}
	}
	return -1;
}
void deleteAccountByAdmin(vector<Accounts>& accounts, int num) {
	system("cls");
	int a;

	if (num != -1) {
		showOneAccount(accounts, num - 1);
		cout << endl;

		if (accounts[num - 1].role == "администратор" and accounts[num - 1].log == "admin") cout << "Вы не можете удалить главного АДМИНА!\n" << endl;
		else {
			cout << "ВЫ УВЕРЕНЫ?  (1 - ДА / 0 - НЕТ)\n>>> ";
			do {
				check_input(a);
			} while (a != 1 and a != 0);
			if (a == 1) {
				del(accounts, num);
				cout << "\nУдаление прошло успешно!" << endl;
			}
		}
	}
	else cout << "\nТакого аккаунта не существует!" << endl;
}
void createGroup(vector <string>& groups) {
	string group;
	cout << "-------------------------------------------\n";
	cout << "|            Создание группы              |\n";
	cout << "|-----------------------------------------|\n";
	cout << "|Введите 6-ти значный номер группы: ";
	group = enterGroup();
	cout << "|\n|-----------------------------------------|\n";
	cout << "         Группа успешно создана!          \n\n";

	groups.push_back(group + ".txt");
	system("pause");
}
void deleteGroup(vector <string>& groups, vector<Accounts>& accounts) {
	string group;
	bool flag = false;
	int k = 0, a = 0;

	cout << "-------------------------------------------\n";
	cout << "|            Удаление группы              |\n";
	cout << "|-----------------------------------------|\n";
	cout << "|Введите 6-ти значный номер группы: ";
	group = enterGroup() + ".txt";
	cout << "|\n|-----------------------------------------|\n";

	for (int i = 0; i < groups.size(); i++) {
		if (group == groups[i]) {
			k = i;
			flag = true;
		}
	}
	if (flag == true) {
		cout << "\n           Вы уверены, что хотите удалить эту группу? (1 - ДА/ 0 - НЕТ)\n>>> ";
		do {
			check_input(a);
		} while (a != 1 and a != 0);
		if (a == 1) {
			deleteGroupForAccounts(accounts, groups[k]);
			groups.erase(groups.begin() + k);
		}
		else cout << "\n           ОТМЕНЕНО!\n\n";
	}
	else cout << "     \nВы ошиблись с выбором группы!\n\n";
	system("pause");
} //надо удалить файл
void showGroups(vector <string> groups) {
	cout << "--------------------\n";
	cout << "|   Список групп   |\n";
	cout << "|------------------|\n";
	for (int i = 0; i < groups.size(); i++) {
		cout << "|      ";
		for (int j = 0; groups[i][j] != '.'; j++) cout << groups[i][j];
		cout << "      |\n|------------------|\n";
	}
}
