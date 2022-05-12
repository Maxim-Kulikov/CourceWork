#include"Teacher.h"

void spaceForTeacher(vector<Students>& pupils, Accounts account, vector<Accounts>& accounts) {
	int k = 1;
	system("cls");
	readFileOfStudents(pupils, account.group);
	do
	{
		switch (menuForTeacher()) {
		case 1: if (account.group == "-") { cout << "\n������������� ��� �� ������ ������!\n" << endl; system("pause"); }
				else journal(pupils, account);
			break;
		case 2: redactYourAccount(account, accounts);
			break;
		case 0: k = 0;
		}
	} while (k != 0);
	writeInFileStudents(pupils, account.group);
}
void addStudent(vector<Students>& pupils, Accounts account) {
	bool flag = true;
	while (flag)
	{
		system("cls");
		Students t;
		cout << "������� ��� �������� (� ��������� ����)" << endl;
		cout << "�������: ";
		t.sureName = enterFIO();
		cout << "\n���: ";
		t.name = enterFIO();
		cout << "\n��������: ";
		t.patronymic = enterFIO();
		cout << "\n������� ��� ��������: ";
		check_birth(t.birthYear);
		t.group = account.group;
		t.physicMark = 0;
		t.mathMark = 0;
		t.programmingMark = 0;
		t.englishMark = 0;
		t.historyMark = 0;
		t.physicalEdOffset = "-";
		t.polyticOffset = "-";
		t.chemistryOffset = "-";
		t.biologyOffset = "-";
		t.belOffset = "-";
		pupils.push_back(t);
		cout << "\n������ ��� �������� ��������?\n" << endl;
		flag = exit_or_not();
	}
}
void journal(vector<Students>& pupils, Accounts account) {

	int k;

	do {
		system("cls");
		showJournal(pupils, account);
		cout << endl;
		k = menuForJournal();

		if (k != 0 and k != 1 and pupils.size() == 0) {
			cout << "\n������� �������� ��������!\n\n"; 
			system("pause");
			continue;
		}
		switch (k) {
		case 0:
			break;
		case 1: addStudent(pupils, account);
			break;
		case 2: deleteStudent(pupils, account);
			break;
		case 3: inputMarksOrOffsets(pupils, account);
			break;
		case 4: sort_avr_ball_student(pupils);
			break;
		case 5: sort(pupils.begin(), pupils.end(), [](const Students& a, const Students& b) { return a.sureName < b.sureName; });
			break;
		case 6: redactStudent(pupils, account);
			break;
		case 7: showStudentsWithDebts(pupils, account);
			break;
		case 8: sort(pupils.begin(), pupils.end(), [](const Students& a, const Students& b) {return countDebts(a) > countDebts(b); });
		}
	} while (k != 0);
}
void showJournal(vector<Students> pupils, Accounts account) {
	string FIO;

	cout << "________________________________________________________________________________________________________________________________________________" << endl;
	cout << "| ����� ������: "; for (int i = 0; account.group[i] != '.'; i++) cout << account.group[i]; cout << setw(38) << "| ������� ���� ������: ";
	if (pupils.size() != 0) { cout << countGroupAvrMark(pupils); cout << setw(83) << "|" << endl; }
	else cout << setw(84) << "|" << endl;
	cout << "|------------------------------------|---------------------------------------------------------------------------------------------------------|" << endl;
	cout << "| �.�.�                              | ������ | �����. | �����. | ��.��. | �������| ���-�� | �����. | �����  | ������.| ���.�� |��.����| ����� |" << endl;
	cout << "|------------------------------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------|-------|" << endl;
	for (int i = 0; i < pupils.size(); i++) {
		FIO = pupils[i].sureName + ' ' + pupils[i].name + ' ' + pupils[i].patronymic;
		cout << "|" << setw(2) << i + 1 << "." << setw(33) << FIO << "|"
			<< setw(8) << pupils[i].physicMark << "|"
			<< setw(8) << pupils[i].mathMark << "|"
			<< setw(8) << pupils[i].programmingMark << "|"
			<< setw(8) << pupils[i].englishMark << "|"
			<< setw(8) << pupils[i].historyMark << "|"
			<< setw(8) << pupils[i].physicalEdOffset << "|"
			<< setw(8) << pupils[i].polyticOffset << "|"
			<< setw(8) << pupils[i].chemistryOffset << "|"
			<< setw(8) << pupils[i].biologyOffset << "|"
			<< setw(8) << pupils[i].belOffset << "|"
			<< setw(7) << countAvrMark(pupils, i) << "|"
			<< setw(7) << countDebts(pupils, i) << "|" << endl;
		cout << "|------------------------------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------|-------|" << endl;
	}
}
void inputMarksOrOffsets(vector<Students>& pupils, Accounts account) {
	int n, n1, mark, k = 1;

	do {
		system("cls");
		showJournal(pupils, account);
		cout << "\n������� ����� �������, �������� ������ ��������� �������/�����: ";

		do {
			check_input(n);
		} while (!(n > 0 and n <= pupils.size()));

		do {
			system("cls");
			showOneStudent(pupils, n - 1);
			cout << endl;

			k = 1;
			n1 = menuForMarks();

			switch (n1) {
			case 0: k = 0; break;
			case 1: cout << "������� ������� �� ������: ";
				pupils[n - 1].physicMark = symbolsIntoMark();;
				break;
			case 2: cout << "������� ������� �� ����������: ";
				pupils[n - 1].mathMark = symbolsIntoMark();;
				break;
			case 3: cout << "������� ������� �� ����������������: ";
				pupils[n - 1].programmingMark = symbolsIntoMark();;
				break;
			case 4: cout << "������� ������� �� ��.��: ";
				pupils[n - 1].englishMark = symbolsIntoMark();;
				break;
			case 5: cout << "������� ������� �� �������: ";
				pupils[n - 1].historyMark = symbolsIntoMark();;
				break;
			case 6: cout << "\n������� �����/������� �� �����������\n";
				pupils[n - 1].physicalEdOffset = enterOffset();
				break;
			case 7: cout << "\n������� �����/������� �� �����������\n";
				pupils[n - 1].polyticOffset = enterOffset();
				break;
			case 8: cout << "\n������� �����/������� �� �����\n";
				pupils[n - 1].chemistryOffset = enterOffset();
				break;
			case 9: cout << "\n������� �����/������� �� ��������\n";
				pupils[n - 1].biologyOffset = enterOffset();
				break;
			case 10: cout << "\n������� �����/������� �� ���.��.\n";
				pupils[n - 1].belOffset = enterOffset();
				break;
			}
		} while (k != 0);
	} while (k != 0);
}
void sort_avr_ball_student(vector<Students>& pupils)
{
	for (int i = 0; i < pupils.size(); i++) pupils[i].avrMark = countAvrMark(pupils, i);
	int a;
	do
	{
		cout << "\n1 - ������������� �� �������� �������� �����     2 - ������������� �� ����������� �������� �����: ";
		check_input(a);
		cout << endl;
		switch (a)
		{
		case 1: sort(pupils.begin(), pupils.end(), [](const Students& a, const Students& b) { return a.avrMark > b.avrMark; });
			break;
		case 2: sort(pupils.begin(), pupils.end(), [](const Students& a, const Students& b) { return a.avrMark < b.avrMark; });
			break;
		default:
			system("cls");
			cout << "�������� �� ������������ ���������!" << endl;
		}
		cout << endl;
	} while (a != 1 and a != 2);
}
void deleteStudent(vector<Students>& pupils, Accounts account) {
	system("cls");

	showJournal(pupils, account);
	cout << endl;

	int num, a;
	cout << "������� ����� ��������, �������� ������ �������: ";
	do {
		check_input(num);
	} while (!(num >= 1 and num <= pupils.size()));

	cout << "\n�� �������, ��� ������ ������� �������� (" << pupils[num - 1].sureName << " " << pupils[num - 1].name << " " << pupils[num - 1].patronymic << ") ?\n\n     (1 - ��/ 0 - ��������) > ";
	do {
		check_input(a);
	} while (a != 1 and a != 0);

	if (a == 1) del(pupils, num);
}
void redactStudent(vector<Students>& pupils, Accounts account) {
	system("cls");
	showJournal(pupils, account);

	cout << "___________________________\n";
	cout << "|      ��������������     |\n";
	cout << "|-------------------------|\n";
	cout << "| ������� ����� ��������  |\n";
	cout << "|-------------------------|\n";
	cout << "| 0 - �����               |\n";
	cout << "|-------------------------|\n";

	int num;

	do {
		cout << "\n >>> ";
		check_input(num);
	} while (!(num >= 0 and num <= pupils.size()));

	if (num != 0) {
		bool flag = true;

		while (flag) {
			system("cls");
			showOneStudent(pupils, num - 1);
			switch (menuOfRedactionOfStudent()) {
			case 0:
				break;
			case 1:
				cout << "\n        |||\n        VVV\n\n������� �������: ";
				pupils[num - 1].sureName = enterFIO();
				break;
			case 2:
				cout << "\n        |||\n        VVV\n������� ���: ";
				pupils[num - 1].name = enterFIO();
				break;
			case 3:
				cout << "\n        |||\n        VVV\n������� ��������: ";
				pupils[num - 1].patronymic = enterFIO();
				break;
			case 4:
				cout << "\n        |||\n        VVV\n������� ��� ��������: ";
				check_birth(pupils[num - 1].birthYear);
				break;
			}
			cout << "\n        |||\n        VVV\n";
			flag = exit_or_not();
		}
	}
	cout << endl;
}
void showOneStudent(vector<Students> pupils, int i) {
	string FIO;
	cout << "________________________________________________________________________________________________________________________________________________" << endl;
	cout << "| �.�.�                              |������  | �����. | �����. | ��.��. | �������| ���-�� | �����. | �����  | ������.| ���.�� |��.����| ����� |" << endl;
	cout << "|------------------------------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------|-------|" << endl;
	FIO = pupils[i].sureName + ' ' + pupils[i].name + ' ' + pupils[i].patronymic;
	cout << "|" << setw(2) << i + 1 << "." << setw(33) << FIO << "|"
		<< setw(8) << pupils[i].physicMark << "|"
		<< setw(8) << pupils[i].mathMark << "|"
		<< setw(8) << pupils[i].programmingMark << "|"
		<< setw(8) << pupils[i].englishMark << "|"
		<< setw(8) << pupils[i].historyMark << "|"
		<< setw(8) << pupils[i].physicalEdOffset << "|"
		<< setw(8) << pupils[i].polyticOffset << "|"
		<< setw(8) << pupils[i].chemistryOffset << "|"
		<< setw(8) << pupils[i].biologyOffset << "|"
		<< setw(8) << pupils[i].belOffset << "|"
		<< setw(7) << countAvrMark(pupils, i) << "|" 
		<< setw(7) << countDebts(pupils, i) << "|" << endl;
	cout << "|------------------------------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------|-------|" << endl;
}
void showStudentsWithDebts(vector<Students> pupils, Accounts account) {
	system("cls");
	cout << "________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|                                                    �������� ������ "; for (int i = 0; account.group[i] != '.'; i++) cout << account.group[i]; cout << setw(69) << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
	for (int i = 0; i < pupils.size(); i++) {
		if (pupils[i].physicalEdOffset == "�������" or pupils[i].polyticOffset == "�������" or pupils[i].chemistryOffset == "�������" or pupils[i].biologyOffset == "�������" or pupils[i].belOffset == "�������") {
			showOneStudent(pupils, i);
		}
	}
	cout << endl;
	system("pause");
}
int countGroupAvrMark(vector<Students> pupils) {
	double s = 0;

	for (int i = 0; i < pupils.size(); i++) {
		s = s + countAvrMark(pupils, i);
	}

	return s / pupils.size();
}