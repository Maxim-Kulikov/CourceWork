#include"Student.h"

void spaceForStudent(vector<Students>& pupils, Accounts& account, vector<Accounts>& accounts) {
	int k = 1;

	do {
		system("cls");
		readFileOfStudents(pupils, account.group);
		switch (menuForPupil()) {
		case 1: showOneStudentToHim(pupils, account);
			system("pause");
			break;
		case 2:
			redactYourAccount(account, accounts);
			break;
		case 0: k = 0;
		}
		writeInFileStudents(pupils, account.group);
	} while (k != 0);
}
void showOneStudentToHim(vector<Students>& pupils, Accounts account) {
	string FIO;
	int i = -1;
	system("cls");
	for (int j = 0; j < pupils.size(); j++) {
		if (account.sureName == pupils[j].sureName and account.name == pupils[j].name and account.patronymic == pupils[j].patronymic) {
			i = j;
			break;
		}
	}
	if (i != -1) {
		cout << "________________________________________________________________________________________________________________________________________________" << endl;
		cout << "| Ф.И.О                              |Физика  | Матем. | Прогр. | Ин.яз. | История| Физ-ра | Полит. | Химия  | Биолог.| Бел.яз |Ср.балл| Долги |" << endl;
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
	else cout << "Вас ещё нету в журнале!" << endl;
}
