#include "take_return.h"

struct take_return
{
	string num_VU; // номер водительского удостоверени€
	string grn; // гос регистрационный номер
	string mark; // марка авто 
	string date_of_issue; // дата выдачи
	string return_date; // дата возврата
	take_return* next;
};

void add_t_r(take_return*& head, take_return* t_r, int& kol_t_r)
{
	take_return* node = new take_return;
	node->num_VU = t_r->num_VU;
	node->grn = t_r->grn;
	node->mark = t_r->mark;
	node->date_of_issue = t_r->date_of_issue;
	node->return_date = t_r->return_date;
	node->next = head;
	head = node;
	kol_t_r++;
	sort_t_r(head, kol_t_r);
}

void del_all_t_r(take_return*& head, int& kol_t_r)
{
	take_return* node;
	while (head != NULL) {

		node = head;
		head = head->next;
		delete node;
	}
	kol_t_r = 0;
}

bool del_t_r(take_return*& head, string grn, int& kol_t_r) {
	take_return* node = head;
	if (head) {
		if (head->grn == grn) {
			head = head->next;
			delete node;
			kol_t_r -= 1;
			return true;
		}
		else {
			while (node->next != NULL) {
				if (node->next->grn == grn) {
					take_return* del = node->next;
					node->next = node->next->next;
					delete del;
					kol_t_r -= 1;
					return true;
				}
				node = node->next;
			}
		}
	}
	return false;
}

void print_all_t_r(take_return* head) {
	cout << endl;
	take_return* node = head;
	if (head) {
		cout << "√ос.–ег.Ќомер | Ќомер ¬”     | ћарка                | ƒата выдачи | ƒата возврата" << endl;
	}
	while (node){
		printf("%-13s", node->grn.c_str());
		cout << " | ";
		printf("%-12s", node->num_VU.c_str());
		cout << " | ";
		printf("%-20s", node->mark.c_str());
		cout << " | ";
		printf("%-11s", node->date_of_issue.c_str());
		cout << " | ";
		cout << node->return_date.c_str();
		cout << endl;
		node = node->next;
	}
}

take_return* search_tr(take_return* head, string grn_VU) {
	take_return* node = head;
	while (node) {
		if (node->grn == grn_VU || node->num_VU == grn_VU) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

void print_cars_of_client(take_return* head, string VU) {
	take_return* node = head;
	while (node) {
		if (node->num_VU == VU) {
			cout << "јвтомобиль с номером: " << node->grn << endl;
		}
		node = node->next;
	}
}

void sort_t_r(take_return*& head, int kol_t_r) {
	take_return* node = head;
	take_return**** L = new take_return * **[2];
	L[0] = new take_return * *[10];
	L[1] = new take_return * *[10];
	for (int i = 0; i < 10; i++) {
		L[0][i] = new take_return * [kol_t_r];
		L[1][i] = new take_return * [kol_t_r];
		for (int j = 0; j < kol_t_r; j++) {
			L[0][i][j] = NULL;
			L[1][i][j] = NULL;
		}
	}

	int x = 0, y = 0, x_2 = 0, y_2 = 0; // координаты числа в матрице

	while(node) {
		y = node->grn[8] - 48;
		x = 0;
		while (L[0][y][x] != NULL && x < kol_t_r) {
			x++;
		}
		L[0][y][x] = node;
		node = node->next;
	}
	/*
	cout << "8" << endl;
	//////// вывод матрицы L_1
	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[0][y][x]) {
				cout << "\t" << L[0][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[0][y][x] != NULL && x < kol_t_r) {
			y_2 = L[0][y][x]->grn[7] - 48;
			x_2 = 0;
			while (L[1][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[1][y_2][x_2] = L[0][y][x];
			x++;
		}
	}
	/*
	cout << "7" << endl;
	////////// вывод матрицы L_2

	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[1][y][x]) {
				cout << "\t" << L[1][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 1
		for (int j = 0; j < kol_t_r; j++) {
			L[0][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[1][y][x] != NULL && x < kol_t_r) {
			y_2 = (unsigned char(L[1][y][x]->grn[5]) - 192) % 10;
			x_2 = 0;
			while (L[0][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[0][y_2][x_2] = L[1][y][x];
			x++;
		}
	}
	/*
	cout << "5" << endl;
	//////// вывод матрицы L_1
	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[0][y][x]) {
				cout << "\t" << L[0][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 2
		for (int j = 0; j < kol_t_r; j++) {
			L[1][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[0][y][x] != NULL && x < kol_t_r) {
			y_2 = (unsigned char(L[0][y][x]->grn[5]) - 192) / 10;
			x_2 = 0;
			while (L[1][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[1][y_2][x_2] = L[0][y][x];
			x++;
		}
	}
	/*
	cout << "5" << endl;
	////////// вывод матрицы L_2
	
	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[1][y][x]) {
				cout << "\t" << L[1][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 1
		for (int j = 0; j < kol_t_r; j++) {
			L[0][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[1][y][x] != NULL && x < kol_t_r) {
			y_2 = (unsigned char(L[1][y][x]->grn[4]) - 192) % 10;
			x_2 = 0;
			while (L[0][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[0][y_2][x_2] = L[1][y][x];
			x++;
		}
	}
	/*
	cout << "4" << endl;
	//////// вывод матрицы L_1
	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[0][y][x]) {
				cout << "\t" << L[0][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 2
		for (int j = 0; j < kol_t_r; j++) {
			L[1][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[0][y][x] != NULL && x < kol_t_r) {
			y_2 = (unsigned char(L[0][y][x]->grn[4]) - 192) / 10;
			x_2 = 0;
			while (L[1][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[1][y_2][x_2] = L[0][y][x];
			x++;
		}
	}
	/*
	cout << "4" << endl;
	////////// вывод матрицы L_2

	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[1][y][x]) {
				cout << "\t" << L[1][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 1
		for (int j = 0; j < kol_t_r; j++) {
			L[0][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[1][y][x] != NULL && x < kol_t_r) {
			y_2 = L[1][y][x]->grn[3] - 48;
			x_2 = 0;
			while (L[0][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[0][y_2][x_2] = L[1][y][x];
			x++;
		}
	}
	/*
	cout << "3" << endl;
	//////// вывод матрицы L_1
	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[0][y][x]) {
				cout << "\t" << L[0][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 2
		for (int j = 0; j < kol_t_r; j++) {
			L[1][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[0][y][x] != NULL && x < kol_t_r) {
			y_2 = L[0][y][x]->grn[2] - 48;
			x_2 = 0;
			while (L[1][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[1][y_2][x_2] = L[0][y][x];
			x++;
		}
	}
	/*
	cout << "2" << endl;
	////////// вывод матрицы L_2

	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[1][y][x]) {
				cout << "\t" << L[1][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 1
		for (int j = 0; j < kol_t_r; j++) {
			L[0][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[1][y][x] != NULL && x < kol_t_r) {
			y_2 = L[1][y][x]->grn[1] - 48;
			x_2 = 0;
			while (L[0][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[0][y_2][x_2] = L[1][y][x];
			x++;
		}
	}
	/*
	cout << "1" << endl;
	//////// вывод матрицы L_1
	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[0][y][x]) {
				cout << "\t" << L[0][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 2
		for (int j = 0; j < kol_t_r; j++) {
			L[1][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[0][y][x] != NULL && x < kol_t_r) {
			y_2 = (unsigned char(L[0][y][x]->grn[0]) - 192) % 10;
			x_2 = 0;
			while (L[1][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[1][y_2][x_2] = L[0][y][x];
			x++;
		}
	}
	/*
	cout << "0" << endl;
	////////// вывод матрицы L_2

	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[1][y][x]) {
				cout << "\t" << L[1][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	for (int i = 0; i < 10; i++) { // обнуление матрицы 1
		for (int j = 0; j < kol_t_r; j++) {
			L[0][i][j] = NULL;
		}
	}

	for (int y = 0; y < 10; y++) {
		x = x_2 = y_2 = 0;
		while (L[1][y][x] != NULL && x < kol_t_r) {
			y_2 = (unsigned char(L[1][y][x]->grn[0]) - 192) / 10;
			x_2 = 0;
			while (L[0][y_2][x_2] != NULL && x_2 < kol_t_r) {
				x_2++;
			}
			L[0][y_2][x_2] = L[1][y][x];
			x++;
		}
	}
	/*
	cout << "0" << endl;
	//////// вывод матрицы L_1
	cout << endl;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < kol_t_r; x++) {
			if (L[0][y][x]) {
				cout << "\t" << L[0][y][x]->grn;
			}
			else cout << "\t0\t";
		}
		cout << endl;
	}
	cout << endl;
	*/
	head = NULL;
	for (int y = 9; y >= 0; y--) { 
		for (int x = kol_t_r - 1; x >= 0; x--) {
			if (L[0][y][x]) {
				L[0][y][x]->next = head;
				head = L[0][y][x];
			}
		}
	}
	

	for (int i = 0; i < 10; i++) {
		delete[] L[0][i];
		delete[] L[1][i];
	}

	delete[] L[0];
	delete[] L[1];
	delete[] L;
}

bool correct_date(string date, long long& unix_time) {
	if (date.length() == 10) {
		if (date[0] >= 48 && date[0] <= 51 &&
			date[1] >= 48 && date[1] <= 57 &&
			date[2] == 46 &&
			date[3] >= 48 && date[3] <= 49 &&
			date[4] >= 48 && date[4] <= 57 &&
			date[5] == 46 &&
			date[6] >= 50 && date[6] <= 57 &&
			date[7] >= 48 && date[7] <= 57 &&
			date[8] >= 48 && date[8] <= 57 &&
			date[9] >= 48 && date[9] <= 57) 
		{
			time_t tm = 0;
			struct tm* dt = localtime(&tm);
			int mday, mon, year;
			mday = (date[0] - 48) * 10 + date[1] - 48;
			dt->tm_mday = mday;
			mon = (date[3] - 48) * 10 + date[4] - 49;
			dt->tm_mon = mon;
			year = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + (date[9] - 48) - 1900;
			dt->tm_year = year;
			dt->tm_hour = 0;
			dt->tm_min = 0;
			dt->tm_sec = 0;
			tm = mktime(dt);
			unix_time = tm;
			if (year == dt->tm_year &&
				mon == dt->tm_mon &&
				mday == dt->tm_mday) {
				return true;
			}
		}
	}
	return false;
}
