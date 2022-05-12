#pragma once
#include"Common.h"

//позволяет выбрать действие для администратора
void spaceForAdmin(vector<Accounts>& accounts, vector <string>& groups);
//позволяет управлять доступом аккаунтов
void allowAccess(vector<Accounts>& accounts);
//позволяет найти аккаунт для управления доступом по логину
void allowAccessWithLog(vector<Accounts>& accounts);
//позволяет найти аккаунт для управления доступом по номеру
void allowAccessWithNum(vector<Accounts>& accounts);
//выводит информацию о всех аккаунтах
void showAllAccounts(vector<Accounts> accounts);
//выводит список всех аккаунтов и возвращает номер выбранного вами аккаунта
int getNumOfAccount(vector<Accounts> accounts);
//возвращает номер аккаунта при совпадние введённого вами логина и логина существующего аккаунта, иначе возвращает -1
int getNumOfAccountWithLog(vector<Accounts> accounts);
//позволяет редактировать админу аккаунты
void redactAccountByAdmin(vector<Accounts>& accounts, vector <string> groups);
//позволяет админу создать аккаунт
void createAccountByAdmin(vector<Accounts>& accounts, vector <string> groups);
//предоставляет админу возможность удалить аккаунт найдя его по номеру или по логину
void deleteAccount(vector<Accounts>& accounts);
//позволяет админу удалить аккаунт
void deleteAccountByAdmin(vector<Accounts>& accounts, int num);
//позволяет админу создать группу студентов
void createGroup(vector <string>& groups);
//позволяет админу удалить группу студентов
void deleteGroup(vector <string>& groups, vector<Accounts>& accounts);
//показывает существующие группы
void showGroups(vector <string> groups);
