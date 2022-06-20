#pragma once
#include <iostream>
#include <string>
using namespace std;

struct clients;
struct take_return;

// функция сравнения номеров ВУ
bool comparison(string num_VU, string num_VU_root);
// поиск клиента по номеру ВУ
void search_cl(clients* client, string num_VU, clients*& search_client);
	
//Функция добавления клиента без балансировки
void Add(clients* add_client, clients*& client);

//Функция вывода дерева

void print_client(clients* client);

// функция вычисления баланс фактора
int bf(clients* client);

// восстановление правильного значения высоты
void fixheight(clients*& client);
// правый поворот
clients* rotateright(clients* client);
// левый поворот
clients* rotateleft(clients* client);
//балансировка
clients* balance(clients* client);
// отбалансировать все дерево
void balance_all(clients*& client);
// добавить клиента с последующей балансировкой
void Add_balance(clients* add_client, clients*& Root, short int& H);
// вывести всех клиентов
void print_all_clients(clients* client);
// удалить клиента без проверки на высоту
clients* del_elem(clients*& client, string num_VU);
// удалить клиента с проверкой на изменение высоты дерева
void del_check_H(clients*& Root, string num_VU, short int& H);
// проверка на допустимые символы
bool sym_true(unsigned char sym);
// проверка на корректное значение номера ВУ
bool check_num_VU(string num_VU);
// проверка на корректное значение номера паспорта
bool check_passport(string passport);
// удалить всех клиентов, кроме тех кому выдан автомобиль
void del_except_t_r(clients*& Root, short int& H, take_return* head);
// вывод информации о клиенте
void print_client_complete(clients* client);
// поиск фрагмента в строке
bool contain_fragment(string str, string fragment);
// поиск по фрагментам фио или адреса
void search_fragment(clients* client, string fragment, bool& header);
// полная очистка динамической памяти бинарного дерева
void FreeTree(clients* client);

