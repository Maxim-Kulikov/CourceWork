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

//��������� ��������
struct Accounts {
	//�����
	string log;
	//������
	string password;
	//���� ��� �����������
	string salt;
	//���� (�������������/�������/������)
	string role;
	//��������
	string patronymic;
	//���
	string name;
	//�������
	string sureName;
	//��� ��������
	int birthYear;
	//������
	string group;
	//������ (1 - �������� / 0 - ��������)
	int access;
};
//��������� ��������
struct Students {
	//��������
	string patronymic;
	//���
	string name;
	//�������
	string sureName;
	//��� ��������
	int birthYear;
	//������
	string group;
	//������ �� ������
	int physicMark;
	//������ �� ����������
	int mathMark;
	//������ �� ����������������
	int programmingMark;
	//������ �� �����������
	int englishMark;
	//������ �� �������
	int historyMark;
	//�����/������� �� �����������
	string physicalEdOffset;
	//�����/������� �� �����������
	string polyticOffset;
	//�����/������� �� �����
	string chemistryOffset;
	//�����/������� �� ��������
	string biologyOffset;
	//�����/������� �� ������������ �����
	string belOffset;
	double avrMark = 0;
};

//��������� ������������� ���� �������
void redactYourAccount(Accounts& account, vector<Accounts>& accounts);
//������� ���������� �� �������� �� ��� ������
void showOneAccount(vector <Accounts> accounts, int i);
//������ �������� ������ � �������� �� "-" � ������, ���� ������ ��������� � �������, ���������� � �������� ���������
void deleteGroupForAccounts(vector<Accounts>& v, string group);
//���������� ������ � �����
int symbolsIntoMark();
//���������� ����� �������� �� ��� ������
int getNumOfAccount(vector<Accounts> v, string log);
//������� ������� ���� ��� ���� ������� i-�� ��������
double countAvrMark(vector<Students> pupils, int i);
// ������������� �����: ����������/�����
bool exit_or_not();
//���������� ���������� ����� � �����
int getStuctures(string file_path);
//������� ������� �� ������� ���������
void del(vector<Students>& v, int index_delete);
//������� ������� �� ������� ���������
void del(vector<Accounts>& v, int index_delete);
//������� ������ �� ����� ������� ���������
void readFileOFAccounts(vector<Accounts>& accounts, string);
//������� ������ � ���� ������� ���������
void writeInFileAccounts(vector<Accounts> accounts, string FILE);
//������� ������ �� ����� ������� ������
void readFileOfGroups(string FILE, vector <string>& groups);
//������� ������ � ���� ������ ������
void writeInFileGroups(string FILE, vector <string> groups);
//������� ������ �� ����� ������� ���������
void readFileOfStudents(vector<Students>& pupils, string File);
//������� ������ � ���� ������� ���������
void writeInFileStudents(vector<Students> pupils, string FILE);
//������� ���������� ������ � ��������
int countDebts(vector<Students> pupils, int i);
//������� ���������� ������ � ��������
int countDebts(Students pupils);