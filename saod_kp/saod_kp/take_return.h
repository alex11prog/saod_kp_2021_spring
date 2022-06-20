#pragma once.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct take_return;
// добавить информацию о выдаче
void add_t_r(take_return*& head, take_return* t_r, int& kol_t_r);
// удаление всей информации о выдаче
void del_all_t_r(take_return*& head, int& kol_t_r);
// удаление записи о выдаче автомобиля клиенту
bool del_t_r(take_return*& head, string grn, int& kol_t_r);
// вывод всей информации о выдаче
void print_all_t_r(take_return* head);
// поиск по ГРН либо ВУ
take_return* search_tr(take_return* head, string grn_VU);
// просмотр выданных автомобилей у клиента
void print_cars_of_client(take_return* head, string VU);
// сортировка списка
void sort_t_r(take_return*& head, int kol_t_r);
// проверка на корректное значение даты
bool correct_date(string date, long long& unix_time);