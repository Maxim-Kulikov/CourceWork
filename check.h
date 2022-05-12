#pragma once
#include<iostream>
#include<string>
#include"Hash/Hash/sha256.h"

using namespace std;

// �������, �� ����������� ������� ������ �� ���� int
void check_input(int& number);
// �������, �� ����������� ������� ��� �������� ��� ��������� �� 1950 �� 2004
void check_birth(int& x);
// �������, ������������ ��������� ��������� �����
string createLogin();
// �������, ������������ �������� �����
string enterLogin();
// �������, ������������ ��������� ��������� ������
string createPassword();
// �������, ������������ �������� ������
string enterPassword();
// �������, ������������ ��������� ���� ���� �������/�������
string enterRole();
// �������, ������������ ��������� ���� �����/�������
string enterOffset();
// �������, ������������ �������� ���� �������/���/��������
string enterFIO();
// �������, ������������ ������� ���� ����� ������ �� 6 ����
string enterGroup();
// ������� ��������� ����
string generateSalt(); 
// ������� ������������ ������ ��������
string getSymbolsForSalt(); 
// �������, ������������ ������������ ������
string hashPassword(string& password, string salt); 


