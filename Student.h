#pragma once
#include "Common.h"

//позволяет выбрать действие для студента
void spaceForStudent(vector<Students>& pupils, Accounts& account, vector<Accounts>& accounts);
//выводит информацию ученику о нём
void showOneStudentToHim(vector<Students>& pupils, Accounts account);
