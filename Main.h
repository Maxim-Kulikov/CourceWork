#pragma once
#include"Common.h"
#include"Admin.h"
#include"Teacher.h"
#include"Student.h"

//после успешного ввода логина и порол€ возвращает структуру, котора€ выполнила вход, дл€ дальнейшей манипул€ции данными этой структуры
Accounts autorization(vector<Accounts> accounts);
//позвол€ет авторизоватьс€ или создать аккаунт
void enterOrCreate(vector <Accounts>& accounts, vector<Students>& pupils, vector <string>& groups);
//после авторизации определ€ет роль, и открывает соответствующий набор действий 
void enterAs_(vector<Accounts>& accounts, vector<Students>& pupils, vector <string>& groups);
//позвол€ет создать аккаунт
void createAccount(vector<Accounts>& accounts, string FILE, vector <string> groups);
//переменна€ названи€ файла, содержащего названи€ групп
const string FILES = "FILES.txt";
//переменна€ названи€ файла, содержащего данные об аккаунтах
const string A = "Accounts.txt";

