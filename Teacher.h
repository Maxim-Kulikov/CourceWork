#pragma once
#include"Common.h"

//��������� ������� �������� ��� �������
void spaceForTeacher(vector<Students>& pupils, Accounts account, vector<Accounts>& accounts);
//��������� ������� �������� �������
void addStudent(vector<Students>& pupils, Accounts account);
//��������� ������� �������� � �������
void journal(vector<Students>& pupils, Accounts account);
//���������� ������ � ���������
void showJournal(vector<Students> pupils, Accounts account);
//��������� ������ �������/������/��������
void inputMarksOrOffsets(vector<Students>& pupils, Accounts account);
//��������� ������������� ������ �� ���������� �� �������� �����
void sort_avr_ball_student(vector<Students>& pupils);
//��������� ������� �������� �� ������� 
void deleteStudent(vector<Students>& pupils, Accounts account);
//��������� ������� ������������� ������ ��������
void redactStudent(vector<Students>& pupils, Accounts account);
//������� ��������� � ���������� ��� ��������� ���� 4
void showStudentsWithDebts(vector<Students> pupils, Accounts account);
//������� ���������� � �������� �� ��� ������
void showOneStudent(vector<Students> pupils, int i);
//������� ������� ���� ������ ���������
int countGroupAvrMark(vector<Students> pupils);