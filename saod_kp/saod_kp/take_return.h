#pragma once.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct take_return;
// �������� ���������� � ������
void add_t_r(take_return*& head, take_return* t_r, int& kol_t_r);
// �������� ���� ���������� � ������
void del_all_t_r(take_return*& head, int& kol_t_r);
// �������� ������ � ������ ���������� �������
bool del_t_r(take_return*& head, string grn, int& kol_t_r);
// ����� ���� ���������� � ������
void print_all_t_r(take_return* head);
// ����� �� ��� ���� ��
take_return* search_tr(take_return* head, string grn_VU);
// �������� �������� ����������� � �������
void print_cars_of_client(take_return* head, string VU);
// ���������� ������
void sort_t_r(take_return*& head, int kol_t_r);
// �������� �� ���������� �������� ����
bool correct_date(string date, long long& unix_time);