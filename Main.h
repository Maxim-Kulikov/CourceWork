#pragma once
#include"Common.h"
#include"Admin.h"
#include"Teacher.h"
#include"Student.h"

//����� ��������� ����� ������ � ������ ���������� ���������, ������� ��������� ����, ��� ���������� ����������� ������� ���� ���������
Accounts autorization(vector<Accounts> accounts);
//��������� �������������� ��� ������� �������
void enterOrCreate(vector <Accounts>& accounts, vector<Students>& pupils, vector <string>& groups);
//����� ����������� ���������� ����, � ��������� ��������������� ����� �������� 
void enterAs_(vector<Accounts>& accounts, vector<Students>& pupils, vector <string>& groups);
//��������� ������� �������
void createAccount(vector<Accounts>& accounts, string FILE, vector <string> groups);
//���������� �������� �����, ����������� �������� �����
const string FILES = "FILES.txt";
//���������� �������� �����, ����������� ������ �� ���������
const string A = "Accounts.txt";

