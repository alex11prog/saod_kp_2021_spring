#include "cars.h"
struct cars
{
	string grn; // гос регистрационный номер
	string mark; // марка авто 
	string color;
	int year;
	bool have;// имеется ли в наличии
	bool rem;
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
bool search_car(cars* hash_table, string grn, cars& search_car, int table_size) {
	int attempt = 0; // номер попытки
	int val = 0;
	while (attempt < 5) {
		val = hash_function(grn, attempt, table_size);
		if (hash_table[val].grn == "") {
			return false;
		}
		else if (hash_table[val].grn == grn) {
			search_car = hash_table[val];
			return true;
		}
		else {
			attempt += 1;
		}
	}
	return false;
}

int get_pos(cars* hash_table, string grn, int table_size) {
	int attempt = 0; // номер попытки
	int val = 0;
	while (attempt < 5) {
		val = hash_function(grn, attempt, table_size);
		if (hash_table[val].grn == "") {
			return 0;
		}
		else if (hash_table[val].grn == grn) {
			return val;
		}
		else {
			attempt += 1;
		}
	}
	return 0;
}

void search_mark(cars* hash_table, string mark, int table_size, take_return* head) {
	bool header = false;
	take_return* node = head;
	cars srch_car;
	while (node) {
		if (node->mark == mark) {
			if (!header) {
				cout << "Позиция | Гос.Рег.Номер | Марка                | Цвет                 | Год выпуска | В наличии | В ремонте" << endl;
				header = true;
			}
			search_car(hash_table, node->grn, srch_car, table_size);
			printf("%-7d", get_pos(hash_table, node->grn, table_size));
			cout << " | ";
			printf("%-13s", srch_car.grn.c_str());
			cout << " | ";
			printf("%-20s", srch_car.mark.c_str());
			cout << " | ";
			printf("%-20s", srch_car.color.c_str());
			cout << " | ";
			printf("%-11d", srch_car.year);
			cout << " | ";
			if (srch_car.have) {
				printf("%-9s", "Да");
			}
			else printf("%-9s", "Нет");
			cout << " | ";
			if (srch_car.rem) {
				cout << "Да" << endl;
			}
			else cout << "Нет" << endl;
		}
		node = node->next;
	}
	for (int i = 0; i < table_size; i++) {
		if (hash_table[i].mark == mark) {
			if (hash_table[i].have || hash_table[i].rem) {
				if (!header) {
					cout << "Позиция | Гос.Рег.Номер | Марка                | Цвет                 | Год выпуска | В наличии | В ремонте" << endl;
					header = true;
				}
				printf("%-7d", i);
				cout << " | ";
				printf("%-13s", hash_table[i].grn.c_str());
				cout << " | ";
				printf("%-20s", hash_table[i].mark.c_str());
				cout << " | ";
				printf("%-20s", hash_table[i].color.c_str());
				cout << " | ";
				printf("%-11d", hash_table[i].year);
				cout << " | ";
				if (hash_table[i].have) {
					printf("%-9s", "Да");
				}
				else printf("%-9s", "Нет");
				cout << " | ";
				if (hash_table[i].rem) {
					cout << "Да" << endl;
				}
				else cout << "Нет" << endl;
			}
		}
	}
	if (!header) cout << "Совпадений не найдено" << endl;
}

void print_car(cars car) {
	cout << "Гос.Рег.Номер | Марка                | Цвет                 | Год выпуска | В наличии | В ремонте" << endl;
	printf("%-13s", car.grn.c_str());
	cout << " | ";
	printf("%-20s", car.mark.c_str());
	cout << " | ";
	printf("%-20s", car.color.c_str());
	cout << " | ";
	printf("%-11d", car.year);
	cout << " | ";
	if (car.have) {
		printf("%-9s", "Да");
	}
	else printf("%-9s", "Нет");
	cout << " | ";
	if (car.rem) {
		cout << "Да" << endl;
	}
	else cout << "Нет" << endl;
}

void print_cars(cars* hash_table, int table_size, int count_cars) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int kol_cars = 0;
	if (count_cars > 0) {
		cout << "Размер таблицы: " << table_size << "\tКоличество автомобилей: " << count_cars << endl;
		cout << "Позиция | Гос.Рег.Номер | Марка                | Цвет                 | Год выпуска | В наличии | В ремонте" << endl;	
		for (int i = 0; i < table_size; i++) {
			if ((hash_table[i].grn != "" && hash_table[i].grn != "0")) {
				printf("%-7d", i);
				cout << " | ";
				printf("%-13s", hash_table[i].grn.c_str());
				cout << " | ";
				printf("%-20s", hash_table[i].mark.c_str());
				cout << " | ";
				printf("%-20s", hash_table[i].color.c_str());
				cout << " | ";
				printf("%-11d", hash_table[i].year);
				cout << " | ";
				if (hash_table[i].have) {
					printf("%-9s", "Да");
				}
				else printf("%-9s", "Нет");
				cout << " | ";
				if (hash_table[i].rem) {
					cout << "Да" << endl;
				}
				else cout << "Нет" << endl;
				kol_cars += 1;
			}
			if (kol_cars == count_cars) break;
		}
		
	}
}

int hash_function(string key, int n, int table_size) {
	return ((int(unsigned char(key[0])) * int(unsigned char(key[0]))
		+ int(unsigned char(key[1])) * int(unsigned char(key[1])) * 2
		+ int(unsigned char(key[2])) * int(unsigned char(key[2])) * 3
		+ int(unsigned char(key[3])) * int(unsigned char(key[3])) * 4
		+ int(unsigned char(key[4])) * int(unsigned char(key[4])) * 5
		+ int(unsigned char(key[5])) * int(unsigned char(key[5])) * 6
		+ int(unsigned char(key[7])) * int(unsigned char(key[7])) * 7
		+ int(unsigned char(key[8])) * int(unsigned char(key[8])) * 8
		- 497664) + table_size/3 * n) % table_size;
}

void rehash(cars* (&hash_table), int& table_size) {
	cars* old_buf = new cars[table_size];
	for (int i = 0; i < table_size; i++) {
		old_buf[i] = hash_table[i];
	}
	int old_size = table_size;
	bool success = true;

	do {
		success = true;
		table_size *= 2;
		hash_table = new cars [table_size];
		for (int i = 0; i < table_size; i++) {
			hash_table[i].grn = "";
		}
		for (int i = 0; i < old_size; i++) {
			if (old_buf[i].grn != "" && old_buf[i].grn != "0") {
				success = add_car(old_buf[i], hash_table, table_size);
			}
			if (!success) break;

		}
	} while (!success);

	delete[] old_buf;
}

void add_car_check(cars car, cars* (&hash_table), int& table_size, int& count_cars) {
	bool success = false;
	while (!success) {
		success = add_car(car, hash_table, table_size);
		if (!success) {
			rehash(hash_table, table_size);
		}
	}
	count_cars += 1;
}

bool add_car(cars car, cars* (&hash_table), int table_size) {
	int attempt = 0; // номер попытки
	int val = 0;
	while (attempt < 5) {
		val = hash_function(car.grn, attempt, table_size);
		if (hash_table[val].grn == "" || hash_table[val].grn == "0") {
			hash_table[val].grn = car.grn;
			hash_table[val].mark = car.mark;
			hash_table[val].color = car.color;
			hash_table[val].year = car.year;
			hash_table[val].have = car.have;
			hash_table[val].rem = car.rem;
			return true;
		}
		else {
			attempt += 1;
		}
	}
	return false;
}

bool sym_car(unsigned char sym) {
	if (sym == 192 || sym == 194 || sym == 197 || sym == 202 ||
		sym == 204 || sym == 205 || sym == 206 || sym == 208 ||
		sym == 209 || sym == 210 || sym == 211 || sym == 213) return true;
	else return false;
}

bool check_grn(string grn) {
	if (grn.length() == 9 && 
		sym_car(grn[0]) &&
		grn[1] >= 48 && grn[1] <= 57 &&
		grn[2] >= 48 && grn[2] <= 57 &&
		grn[3] >= 48 && grn[3] <= 57 &&
		sym_car(grn[4]) &&
		sym_car(grn[5]) &&
		grn[6] == '-' &&
		grn[7] >= 48 && grn[7] <= 57 &&
		grn[8] >= 48 && grn[8] <= 57) return true;
	else return false;
}

bool check_year(string year, int wYear) {

	if (year.length() == 4) {
		if (year[0] >= 48 && year[0] <= 57 &&
			year[1] >= 48 && year[1] <= 57 &&
			year[2] >= 48 && year[2] <= 57 &&
			year[3] >= 48 && year[3] <= 57) {
			int Y = stoi(year);
			if (Y >= 1800 && Y <= wYear) return true;
		}
	}
	return false;
}

void del_car(cars* (&hash_table), string grn, int table_size, int& count_cars) {
	int val = 0;
	int attempt = 0; // номер попытки
	val = hash_function(grn, attempt, table_size);
	if (hash_table[val].grn == "") {
		return;
	}
	else if (hash_table[val].grn == grn) {
		hash_table[val].grn = "0";
		count_cars -= 1;
	}
	else {
		while (hash_table[val].grn != grn && attempt < 5) {
			attempt++;
			val = hash_function(grn, attempt, table_size);
		}
		if (hash_table[val].grn == grn) {
			hash_table[val].grn = "0";
			count_cars -= 1;
		}
	}
}

void del_car_have(cars* (&hash_table), int& table_size, int& count_cars) {

	cars* hash_table_old = new cars[table_size];
	for (int i = 0; i < table_size; i++) {
		hash_table_old[i] = hash_table[i];
	}
	int table_size_old = table_size;
	table_size = 10;
	count_cars = 0;
	hash_table = new cars[table_size];
	for (int i = 0; i < table_size_old; i++) {
		if (!hash_table_old[i].have) {
			add_car_check(hash_table_old[i], hash_table, table_size, count_cars);
		}
	}
	delete[] hash_table_old;
}

void reg_send_rem(cars* hash_table, string grn, int table_size) {
	int attempt = 0; // номер попытки
	int val = 0;
	while (attempt < 5) {
		val = hash_function(grn, attempt, table_size);
		if (hash_table[val].grn == "") {
			return;
		}
		else if (hash_table[val].grn == grn) {
			if (!hash_table[val].have) {
				if (hash_table[val].rem) {
					system("cls"); // очистка консоли
					cout << "Автомобиль с данным регистрационном номером уже в ремонте" << endl;
					break;
				}
				else {
					system("cls"); // очистка консоли
					cout << "Ошибка регистрации" << endl;
					cout << "Автомобиль с данным регистрационным номером выдан клиенту" << endl;
					break;
				}
			}
			else {
				hash_table[val].rem = true;
				hash_table[val].have = false;
				system("cls"); // очистка консоли
				cout << "Регистрация отправки автомобиля в ремонт выполнена успешно" << endl;
				break;
			}
		}
		else {
			attempt += 1;
		}
	}
}

void reg_get_rem(cars* hash_table, string grn, int table_size) {
	int attempt = 0; // номер попытки
	int val = 0;
	while (attempt < 5) {
		val = hash_function(grn, attempt, table_size);
		if (hash_table[val].grn == "") {
			return;
		}
		else if (hash_table[val].grn == grn) {
			if (hash_table[val].have) {
				system("cls"); // очистка консоли
				cout << "Данный автомобиль не в ремонте, он имеется в наличии" << endl;
				break;
			}
			else {
				if (hash_table[val].rem) {
					hash_table[val].rem = false;
					hash_table[val].have = true;
					system("cls"); // очистка консоли
					cout << "Регистрация прибытия автомобиля из ремонта выполнена успешно" << endl;
					break;
				}
				else {
					system("cls"); // очистка консоли
					cout << "Ошибка регистрации прибытия автомобиля из ремонта" << endl;
					cout << "Данный автомобиль выдан клиенту" << endl;
					break;
				}
			}
		}
		else {
			attempt += 1;
		}
	}
}

void reg_take_car(cars* hash_table, string grn, int table_size) {
	int attempt = 0; // номер попытки
	int val = 0;
	while (attempt < 5) {
		val = hash_function(grn, attempt, table_size);
		if (hash_table[val].grn == "") {
			return;
		}
		else if (hash_table[val].grn == grn) {
			if (hash_table[val].have) {
				hash_table[val].have = false;
				break;
			}
		}
		else {
			attempt += 1;
		}
	}
}

void reg_return_car(cars* hash_table, string grn, int table_size) {
	int attempt = 0; // номер попытки
	int val = 0;
	while (attempt < 5) {
		val = hash_function(grn, attempt, table_size);
		if (hash_table[val].grn == "") {
			return;
		}
		else if (hash_table[val].grn == grn) {
			if (!hash_table[val].have) {
				hash_table[val].have = true;
				break;
			}
		}
		else {
			attempt += 1;
		}
	}
}