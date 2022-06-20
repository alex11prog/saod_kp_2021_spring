#pragma once
#include <iostream>
#include <string>
using namespace std;

struct clients;
struct take_return;

// ������� ��������� ������� ��
bool comparison(string num_VU, string num_VU_root);
// ����� ������� �� ������ ��
void search_cl(clients* client, string num_VU, clients*& search_client);
	
//������� ���������� ������� ��� ������������
void Add(clients* add_client, clients*& client);

//������� ������ ������

void print_client(clients* client);

// ������� ���������� ������ �������
int bf(clients* client);

// �������������� ����������� �������� ������
void fixheight(clients*& client);
// ������ �������
clients* rotateright(clients* client);
// ����� �������
clients* rotateleft(clients* client);
//������������
clients* balance(clients* client);
// ��������������� ��� ������
void balance_all(clients*& client);
// �������� ������� � ����������� �������������
void Add_balance(clients* add_client, clients*& Root, short int& H);
// ������� ���� ��������
void print_all_clients(clients* client);
// ������� ������� ��� �������� �� ������
clients* del_elem(clients*& client, string num_VU);
// ������� ������� � ��������� �� ��������� ������ ������
void del_check_H(clients*& Root, string num_VU, short int& H);
// �������� �� ���������� �������
bool sym_true(unsigned char sym);
// �������� �� ���������� �������� ������ ��
bool check_num_VU(string num_VU);
// �������� �� ���������� �������� ������ ��������
bool check_passport(string passport);
// ������� ���� ��������, ����� ��� ���� ����� ����������
void del_except_t_r(clients*& Root, short int& H, take_return* head);
// ����� ���������� � �������
void print_client_complete(clients* client);
// ����� ��������� � ������
bool contain_fragment(string str, string fragment);
// ����� �� ���������� ��� ��� ������
void search_fragment(clients* client, string fragment, bool& header);
// ������ ������� ������������ ������ ��������� ������
void FreeTree(clients* client);

