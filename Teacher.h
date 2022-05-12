#pragma once
#include"Common.h"

//позволяет выбрать действие для учителя
void spaceForTeacher(vector<Students>& pupils, Accounts account, vector<Accounts>& accounts);
//позволяет учителю добавить ученика
void addStudent(vector<Students>& pupils, Accounts account);
//позволяет выбрать действие в журнале
void journal(vector<Students>& pupils, Accounts account);
//показывает журнал с учениками
void showJournal(vector<Students> pupils, Accounts account);
//позволяет ввести отметки/зачёты/незачёты
void inputMarksOrOffsets(vector<Students>& pupils, Accounts account);
//позволяет отсортировать журнал со студентами по среднему баллу
void sort_avr_ball_student(vector<Students>& pupils);
//позволяет удалить студента из вектора 
void deleteStudent(vector<Students>& pupils, Accounts account);
//позволяет учителю редактировать данные студента
void redactStudent(vector<Students>& pupils, Accounts account);
//выводит студентов с незачётами или отметками ниже 4
void showStudentsWithDebts(vector<Students> pupils, Accounts account);
//выводит информацию о студенте по его номеру
void showOneStudent(vector<Students> pupils, int i);
//считает средний балл группы студентов
int countGroupAvrMark(vector<Students> pupils);