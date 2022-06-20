#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct cars;
struct take_return;
// поиск автомобиля по ГРН
bool search_car(cars* hash_table, string grn, cars& search_car, int table_size);
// получение позиции автомобиля в хеш таблице
int get_pos(cars* hash_table, string grn, int table_size);
// поиск автомобиля по марке
void search_mark(cars* hash_table, string mark, int table_size, take_return* head);
// вывод информации об автомобиле
void print_car(cars car);
// вывод информации о всех автомобилях
void print_cars(cars* hash_table, int table_size, int count_cars);

int hash_function(string key, int n, int table_size);
// рехеширование
void rehash(cars* (&hash_table), int& table_size);
// добавить автомобиль с возможностью рехеширования и расширения таблицы
void add_car_check(cars car, cars* (&hash_table), int& table_size, int& count_cars);
// добавить автомобиль в хеш таблицу
bool add_car(cars car, cars* (&hash_table), int table_size);
// проверка на допустимые символы
bool sym_car(unsigned char sym);
// проверка на корректность ГРН
bool check_grn(string grn);
// проверка года
bool check_year(string year, int wYear);
//удаление автомобиля
void del_car(cars* (&hash_table), string grn, int table_size, int& count_cars);
//уделение всех автомобилей, которые есть в наличии
void del_car_have(cars* (&hash_table), int& table_size, int& count_cars);
// регистрация отправки на ремонт
void reg_send_rem(cars* hash_table, string grn, int table_size);
// реистрация прибытия из ремонта
void reg_get_rem(cars* hash_table, string grn, int table_size);
// регистрация выдачи автомобиля клиенту
void reg_take_car(cars* hash_table, string grn, int table_size);
// регистрация возврата автомобиля от клиента
void reg_return_car(cars* hash_table, string grn, int table_size);