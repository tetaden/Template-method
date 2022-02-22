#pragma once // директива, необходимая для того, чтобы один и тот же  файл не подключался несколько раз
#include <iostream> //подключение заголовочного файла iostream
#include <string> //подключение библиотеки для рабботы со строками
using namespace std; // объявление пространства имен std
class IT //Создание класса IT
{ 
public:
    IT() {}; //Конструктор по умолчанию 
    IT(IT&a); // Прототип конструктора копирования
    string serv, date, cost, pr_cost; // объекты класса
    void Set(string, string, string, string); // Прототип для функции Set
};
IT::IT(IT& a) { // конструктор копирования 
    this->serv = a.serv;
    this->cost = a.cost;
    this->pr_cost = a.pr_cost;
    this->date = a.date;
}

void IT::Set(string serv, string cost, string date, string pr_cost) { // заполнение полей класса 
    this->cost = cost;
    this->serv = serv;
   
    this->date = date;
    this->pr_cost = pr_cost;
}