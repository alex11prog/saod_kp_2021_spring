
#include "clients.h"
#include "take_return.h"
struct clients
{
	string num_VU; // номер водительского удостоверения
	string FIO; // Фамилия имя отчество
	string passport;
	string address;
	clients* Left; //УКАЗАТЕЛИ на соседние ветви
	clients* Right;
	short int h;// высота поддерева
};
struct take_return
{
	string num_VU; // номер водительского удостоверения
	string grn; // гос регистрационный номер
	string mark; // марка авто 
	string date_of_issue; // дата выдачи
	string return_date; // дата возврата
	take_return* next;
};
// функция сравнения номеров ВУ
bool comparison(string num_VU, string num_VU_root) {
	bool right = false; // если направо 1 если налево 0
	for (int i = 0; i < 12; i++) {
		if (i != 2 && i != 5) {
			if (num_VU[i] > num_VU_root[i]) {
				right = true;
				break;
			}
			else if (num_VU[i] < num_VU_root[i]) {
				break;
			}
		}
	}
	return right;
}

void search_cl(clients* client, string num_VU, clients*& search_client) {
	if (client) {
		if (client->num_VU == num_VU) {
			search_client = client;
			return;
		}
		else if (comparison(num_VU, client->num_VU)) { //Если оно больше того, что в этой ветке 
			if (client->Right) {
				search_cl(client->Right, num_VU, search_client);
			}
			else {
				search_client = NULL;
				return;
			}
		}
		else
		{
			if (client->Left) {
				search_cl(client->Left, num_VU, search_client);
			}
			else {
				search_client = NULL;
				return;
			}
		}
	}
	else return;
}

//Функция внесения данных
void Add(clients* add_client, clients*& client)
{
	//Если ветки не существует
	if (!client)
	{ //создадим ее и зададим в нее данные
		client = new clients;
		client->num_VU = add_client->num_VU;
		client->FIO = add_client->FIO;
		client->passport = add_client->passport;
		client->address = add_client->address;
		client->Left = add_client->Left;
		client->Right = add_client->Right;
		client->h = add_client->h;
		return;
	}
	else //Иначе сверим вносимое
		if (comparison(add_client->num_VU, client->num_VU))
		{ //Если оно больше того, что в этой ветке - добавим вправо
			Add(add_client, client->Right);
			if (client->Right) {
				if (client->Right->h == client->h) client->h++;
			}
		}
		else if (add_client->num_VU == client->num_VU) {
			return;
		}
		else
		{ //Иначе в ветку слева
			Add(add_client, client->Left);
			if (client->Left) {
				if (client->Left->h == client->h) client->h++;
			}
		};
}

//Функция вывода дерева
int tabs = 0; //Для создания отступов
void print_client(clients* client)
{
	if (!client) return; //Если ветки не существует - выходим. Выводить нечего
	tabs += 5; //Иначе увеличим счетчик рекурсивно вызванных процедур
	//Который будет считать нам отступы для красивого вывода

	print_client(client->Right);//Выведем ветку и ее подветки справа

	for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы
	cout << client->num_VU << " " << client->FIO << endl; //Данные этой ветки

	print_client(client->Left); //Выведем ветку и ее подветки слева

	tabs -= 5; //После уменьшим кол-во отступов
	return;
}

// функция вычисления баланс фактора
int bf(clients* client)
{
	short int h_right = 0, h_left = 0;
	if (client->Right) {
		h_right = client->Right->h;
	}
	if (client->Left) {
		h_left = client->Left->h;
	}
	return h_right - h_left;
}

// восстановление правильного значения высоты
void fixheight(clients*& client)
{
	short int h_right = 0, h_left = 0;
	if (client->Right) {
		h_right = client->Right->h;
	}
	if (client->Left) {
		h_left = client->Left->h;
	}
	if (h_right > h_left) {
		client->h = h_right + 1;
	}
	else {
		client->h = h_left + 1;
	}
}

clients* rotateright(clients* client) // правый поворот 
{
	clients* q = client->Left;
	client->Left = q->Right;
	q->Right = client;
	fixheight(client);
	fixheight(q);
	return q;
}

clients* rotateleft(clients* client) // левый поворот 
{
	clients* p = client->Right;
	client->Right = p->Left;
	p->Left = client;
	fixheight(client);
	fixheight(p);
	return p;
}

clients* balance(clients* client) // балансировка дерева
{
	if (client) {
		fixheight(client);
		if (bf(client) >= 2)
		{
			if (bf(client->Right) < 0)
				client->Right = rotateright(client->Right);
			return rotateleft(client);
		}
		if (bf(client) <= -2)
		{
			if (bf(client->Left) > 0)
				client->Left = rotateleft(client->Left);
			return rotateright(client);
		}
	}
	return client; // балансировка не нужна
}

void balance_all(clients*& client) {
	if (!client)    return;    //Если дерева нет, выходим
	balance_all(client->Left); //Обошли левое поддерево   
	balance_all(client->Right); //Обошли правое поддерево
	client = balance(client);
}

void Add_balance(clients* add_client, clients*& Root, short int& H) {
	Add(add_client, Root);
	if (Root->h != H) {
		balance_all(Root);
		H = Root->h;
	}
}

void print_all_clients(clients* client) {
	if (!client)    return;    //Если дерева нет, выходим

	print_all_clients(client->Left); //Обошли левое поддерево 
	cout << "\t" << client->num_VU << "\t" << client->FIO << endl;
	print_all_clients(client->Right); //Обошли правое поддерево
}

clients* del_elem(clients*& client, string num_VU) {
	if (!client)
		return client;

	if (num_VU == client->num_VU) {

		clients* tmp;
		if (client->Right == NULL)
			tmp = client->Left;
		else {

			clients* ptr = client->Right;
			if (ptr->Left == NULL) {
				ptr->Left = client->Left;
				tmp = ptr;
			}
			else {

				clients* pmin = ptr->Left;
				while (pmin->Left != NULL) {
					ptr = pmin;
					pmin = ptr->Left;
				}
				ptr->Left = pmin->Right;
				ptr = balance(ptr);
				pmin->Left = client->Left;
				pmin->Right = client->Right;
				tmp = pmin;
			}
		}

		delete client;
		tmp = balance(tmp);
		return tmp;
	}
	else if (comparison(num_VU, client->num_VU)) {
		client->Right = del_elem(client->Right, num_VU);
	}
	else {
		client->Left = del_elem(client->Left, num_VU);
	}
	client = balance(client);
	return client;
}

void del_check_H(clients*& Root, string num_VU, short int& H) {
	Root = del_elem(Root, num_VU);
	if (Root) {
		if (Root->h != H) {
			balance_all(Root);
			H = Root->h;
		}
	}
	else {
		H = 0;
	}
}

bool sym_true(unsigned char sym ) {
	if (sym == 192 || sym == 194 || sym == 197 || sym == 202 ||
		sym == 204 || sym == 205 || sym == 206 || sym == 208 ||
		sym == 209 || sym == 210 || sym == 211 || sym == 213) return true;
	else return false;
}

bool check_num_VU(string num_VU) {
	if (num_VU.length() == 12 && num_VU[0] >= 48 && num_VU[0] <= 57 &&
		num_VU[1] >= 48 && num_VU[1] <= 57 &&
		num_VU[2] == ' ' &&
		sym_true(num_VU[3]) &&
		sym_true(num_VU[4]) &&
		num_VU[5] == ' ' &&
		num_VU[6] >= 48 && num_VU[6] <= 57 &&
		num_VU[7] >= 48 && num_VU[7] <= 57 &&
		num_VU[8] >= 48 && num_VU[8] <= 57 &&
		num_VU[9] >= 48 && num_VU[9] <= 57 &&
		num_VU[10] >= 48 && num_VU[10] <= 57 &&
		num_VU[11] >= 48 && num_VU[11] <= 57) return true;
	else return false;
}

bool check_passport(string passport) {
	bool check = true;
	if (passport.length() == 10) {
		for (int i = 0; i < 10; i++) {
			if (passport[i] < 48 || passport[i] > 57) {
				check = false;
				break;
			}
		}
	}
	else {
		check = false;
	}
	return check;
}

void del_except_t_r(clients*& Root, short int& H, take_return* head)
 {
	take_return* node = head;
	if (!head) {
		FreeTree(Root);
		Root = NULL;
		H = 0;
	}
	else {
		clients* new_root = NULL;
		clients* search_client;
		short int H2 = 0;
		while (node) {
			search_cl(Root, node->num_VU, search_client);
			Add_balance(search_client, new_root, H2);
			node = node->next;
		}
		FreeTree(Root);
		Root = new_root;
		H = H2;
	}
}

void print_client_complete(clients* client){
	cout << "\tНомер водительского удостоверения" << endl;
	cout << "\t" << client->num_VU << endl;
	cout << "\tФамилия, Имя, Отчество" << endl; 
	cout << "\t" << client->FIO << endl;
	cout << "\tПаспортные данные" << endl;
	cout << "\t" << client->passport << endl;
	cout << "\tАдрес" << endl;
	cout << "\t" << client->address << endl;
}

bool contain_fragment(string str, string fragment){
	int len_str = str.length(), len_fragment = fragment.length();
	int len_fr = 0;
	if (len_str >= len_fragment) {
		for (int i = 0; i <= len_str - len_fragment; i++) {
			len_fr = 0;
			for (int f = 0; f < len_fragment; f++) {
				if (str[i + f] == fragment[f]) {
					len_fr += 1;
					if (len_fr == len_fragment) {
						return true;
					}
				}
				else break;
			}
		}
	}
	return false;
}

void search_fragment(clients* client, string fragment, bool& header) {
	if (!client)    return;    //Если дерева нет, выходим
	search_fragment(client->Left, fragment, header); //Обошли левое поддерево   
	search_fragment(client->Right, fragment, header); //Обошли правое поддерево
	if (contain_fragment(client->FIO, fragment) || contain_fragment(client->address, fragment)) {
		if (!header) {
			cout << "\tНомер ВУ\tФИО, адрес" << endl;
			header = true;
		}
		cout << "\t" << client->num_VU << "\t" << client->FIO << " " << client->address << endl;
	}
}

void FreeTree(clients* client)
{
	if (!client) return;
	FreeTree(client->Left);
	FreeTree(client->Right);
	delete client;
	return;
}
