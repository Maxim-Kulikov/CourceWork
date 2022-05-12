#pragma once
#include<iostream>
#include<string>
#include"Hash/Hash/sha256.h"

using namespace std;

// функция, не позволяющая вводить данные не типа int
void check_input(int& number);
// функция, не позволяющая вводить год рождения вне диапазона от 1950 до 2004
void check_birth(int& x);
// функция, возвращающая корректно созданный логин
string createLogin();
// функция, возвращающая введённый логин
string enterLogin();
// функция, возвращающая корректно созданный пороль
string createPassword();
// функция, возвращающая введённый пороль
string enterPassword();
// функция, возвращающая выбранную вами роль учителя/ученика
string enterRole();
// функция, возвращающая вабранный вами зачёт/незачёт
string enterOffset();
// функция, возвращающая введённое вами фамилию/имя/отчество
string enterFIO();
// функция, возвращающая ввёдённый вами номер группы из 6 цифр
string enterGroup();
// функция генерации соли
string generateSalt(); 
// функция формирования набора символов
string getSymbolsForSalt(); 
// функция, возвращающая хэшированный пороль
string hashPassword(string& password, string salt); 


