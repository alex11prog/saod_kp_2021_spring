#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct cars;
struct take_return;
// ����� ���������� �� ���
bool search_car(cars* hash_table, string grn, cars& search_car, int table_size);
// ��������� ������� ���������� � ��� �������
int get_pos(cars* hash_table, string grn, int table_size);
// ����� ���������� �� �����
void search_mark(cars* hash_table, string mark, int table_size, take_return* head);
// ����� ���������� �� ����������
void print_car(cars car);
// ����� ���������� � ���� �����������
void print_cars(cars* hash_table, int table_size, int count_cars);

int hash_function(string key, int n, int table_size);
// �������������
void rehash(cars* (&hash_table), int& table_size);
// �������� ���������� � ������������ ������������� � ���������� �������
void add_car_check(cars car, cars* (&hash_table), int& table_size, int& count_cars);
// �������� ���������� � ��� �������
bool add_car(cars car, cars* (&hash_table), int table_size);
// �������� �� ���������� �������
bool sym_car(unsigned char sym);
// �������� �� ������������ ���
bool check_grn(string grn);
// �������� ����
bool check_year(string year, int wYear);
//�������� ����������
void del_car(cars* (&hash_table), string grn, int table_size, int& count_cars);
//�������� ���� �����������, ������� ���� � �������
void del_car_have(cars* (&hash_table), int& table_size, int& count_cars);
// ����������� �������� �� ������
void reg_send_rem(cars* hash_table, string grn, int table_size);
// ���������� �������� �� �������
void reg_get_rem(cars* hash_table, string grn, int table_size);
// ����������� ������ ���������� �������
void reg_take_car(cars* hash_table, string grn, int table_size);
// ����������� �������� ���������� �� �������
void reg_return_car(cars* hash_table, string grn, int table_size);