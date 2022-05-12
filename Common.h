#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include <cstdlib>
#include<Windows.h>
#include<vector>
#include<iomanip>
#include "check.h"
#include<algorithm>
#include"Hash/Hash/sha256.h"
#include<ctime>
#include"menu.h"
#include<stdio.h>

//Структура аккаунта
struct Accounts {
	//Логин
	string log;
	//Пороль
	string password;
	//Соль для хэширования
	string salt;
	//Роль (администратор/учитель/ученик)
	string role;
	//Отчество
	string patronymic;
	//Имя
	string name;
	//Фамилия
	string sureName;
	//Год рождения
	int birthYear;
	//Группа
	string group;
	//Доступ (1 - Разрешён / 0 - Запрещён)
	int access;
};
//Структура студента
struct Students {
	//Отчество
	string patronymic;
	//Имя
	string name;
	//Фамилия
	string sureName;
	//Год рождения
	int birthYear;
	//Группа
	string group;
	//Оценка по физике
	int physicMark;
	//Оценка по математике
	int mathMark;
	//Оценка по программированию
	int programmingMark;
	//Оценка по английскому
	int englishMark;
	//Оценка по истории
	int historyMark;
	//Зачёт/незачёт по физкультуре
	string physicalEdOffset;
	//Зачёт/незачёт по политологии
	string polyticOffset;
	//Зачёт/незачёт по химии
	string chemistryOffset;
	//Зачёт/незачёт по биологии
	string biologyOffset;
	//Зачёт/незачёт по белорусскому языку
	string belOffset;
	double avrMark = 0;
};

//позволяет редактировать свой аккаунт
void redactYourAccount(Accounts& account, vector<Accounts>& accounts);
//выводит информацию об аккаунте по его номеру
void showOneAccount(vector <Accounts> accounts, int i);
//меняет значение группы у аккаунта на "-" в случае, если группа совпадает с группой, переданной в качестве параметра
void deleteGroupForAccounts(vector<Accounts>& v, string group);
//превращает строку в число
int symbolsIntoMark();
//возвращает номер аккаунта по его логину
int getNumOfAccount(vector<Accounts> v, string log);
//считает средний балл для всех отметок i-го студента
double countAvrMark(vector<Students> pupils, int i);
// предоставляет выбор: продолжить/выйти
bool exit_or_not();
//возвращает количество строк в файле
int getStuctures(string file_path);
//удаляет элемент из вектора студентов
void del(vector<Students>& v, int index_delete);
//удаляет элемент из вектора аккаунтов
void del(vector<Accounts>& v, int index_delete);
//функция чтения из файла вектора аккаунтов
void readFileOFAccounts(vector<Accounts>& accounts, string);
//функция записи в файл вектора аккаунтов
void writeInFileAccounts(vector<Accounts> accounts, string FILE);
//функция чтения из файла вектора группы
void readFileOfGroups(string FILE, vector <string>& groups);
//функция записи в файл вектор группы
void writeInFileGroups(string FILE, vector <string> groups);
//функция чтения из файла вектора студентов
void readFileOfStudents(vector<Students>& pupils, string File);
//функция записи в файл вектора студентов
void writeInFileStudents(vector<Students> pupils, string FILE);
//считает количество долгов у студента
int countDebts(vector<Students> pupils, int i);
//считает количество долгов у студента
int countDebts(Students pupils);