#pragma once
#include"Common.h"

//��������� ������� �������� ��� ��������������
void spaceForAdmin(vector<Accounts>& accounts, vector <string>& groups);
//��������� ��������� �������� ���������
void allowAccess(vector<Accounts>& accounts);
//��������� ����� ������� ��� ���������� �������� �� ������
void allowAccessWithLog(vector<Accounts>& accounts);
//��������� ����� ������� ��� ���������� �������� �� ������
void allowAccessWithNum(vector<Accounts>& accounts);
//������� ���������� � ���� ���������
void showAllAccounts(vector<Accounts> accounts);
//������� ������ ���� ��������� � ���������� ����� ���������� ���� ��������
int getNumOfAccount(vector<Accounts> accounts);
//���������� ����� �������� ��� ��������� ��������� ���� ������ � ������ ������������� ��������, ����� ���������� -1
int getNumOfAccountWithLog(vector<Accounts> accounts);
//��������� ������������� ������ ��������
void redactAccountByAdmin(vector<Accounts>& accounts, vector <string> groups);
//��������� ������ ������� �������
void createAccountByAdmin(vector<Accounts>& accounts, vector <string> groups);
//������������� ������ ����������� ������� ������� ����� ��� �� ������ ��� �� ������
void deleteAccount(vector<Accounts>& accounts);
//��������� ������ ������� �������
void deleteAccountByAdmin(vector<Accounts>& accounts, int num);
//��������� ������ ������� ������ ���������
void createGroup(vector <string>& groups);
//��������� ������ ������� ������ ���������
void deleteGroup(vector <string>& groups, vector<Accounts>& accounts);
//���������� ������������ ������
void showGroups(vector <string> groups);
