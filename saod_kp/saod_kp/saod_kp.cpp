using namespace std;
#include <iostream>
#include <Windows.h>
#include <string>
#include "clients.h"
#include "cars.h"
#include "take_return.h"
struct clients
{
	string num_VU; // номер водительского удостоверения
	string FIO; // Фамилия имя отчество
	string passport;
	string address;
	clients* Left; //указатели на соседние ветви
	clients* Right;
	short int h;// высота поддерева
};
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

int menu_client() {
	int num = -1;
	bool err_write = false;
	string digit;
	cout << endl <<
		"1 - Регистрация нового клиента" << endl <<
		"2 - Снятие с обслуживания клиента" << endl <<
		"3 - Просмотр всех зарегистрированных клиентов" << endl <<
		"4 - Очистка данных о клиентах" << endl <<
		"5 - Поиск клиента по номеру водительского удостоверения (Полная информация о клиенте)" << endl <<
		"6 - Поиск клиента по фрагментам ФИО или адреса" << endl <<
		"0 - Выход в главное меню\nВыберите действие: " << endl;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> digit;
	int digit_lenght = digit.length();
	for (int i = 0; i < digit_lenght; i++) {
		if (digit[i] < 48 || digit[i] > 57) {
			err_write = true;
		}
	}
	if (!err_write) {
		num = stoi(digit);
	}
	while (cin.fail() || (num < 0) || (num > 6)) {
		cin.clear();
		cin.sync();
		cout << "Ошибка ввода, выберите действие: ";
		err_write = false;
		cin >> digit;
		digit_lenght = digit.length();
		for (int i = 0; i < digit_lenght; i++) {
			if (digit[i] < 48 || digit[i] > 57) {
				err_write = true;
			}
		}
		if (!err_write) {
			num = stoi(digit);
		}
	}
	return num;
}

int menu_cars() {
	int num = -1;
	bool err_write = false;
	string digit;
	cout << endl <<
		"1 - Добавление нового автомобиля" << endl <<
		"2 - Удаление сведений об автомобиле" << endl <<
		"3 - Просмотр всех имеющихся автомобилей" << endl <<
		"4 - Очистка данных об автомобилях" << endl <<
		"5 - Поиск автомобиля по государственному регистрационному номеру" << endl <<
		"6 - Поиск автомобиля по названию марки автомобиля" << endl <<
		"7 - Регистрация отправки автомобиля в ремонт" << endl <<
		"8 - Регистрация прибытия автомобиля из ремонта" << endl <<
		"0 - Выход в главное меню\nВыберите действие: " << endl;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> digit;
	int digit_lenght = digit.length();
	for (int i = 0; i < digit_lenght; i++) {
		if (digit[i] < 48 || digit[i] > 57) {
			err_write = true;
		}
	}
	if (!err_write) {
		num = stoi(digit);
	}
	while (cin.fail() || (num < 0) || (num > 8)) {
		cin.clear();
		cin.sync();
		cout << "Ошибка ввода, выберите действие: ";
		err_write = false;
		cin >> digit;
		digit_lenght = digit.length();
		for (int i = 0; i < digit_lenght; i++) {
			if (digit[i] < 48 || digit[i] > 57) {
				err_write = true;
			}
		}
		if (!err_write) {
			num = stoi(digit);
		}
	}
	return num;
}

int menu_t_r() {
	int num = -1;
	bool err_write = false;
	string digit;
	cout << endl <<
		"1 - Регистрация выдачи клиенту автомобиля на прокат" << endl <<
		"2 - Регистрация возврата автомобиля от клиента" << endl <<
		"3 - Просмотр всех выданных автомобилей" << endl <<
		"0 - Выход в главное меню\nВыберите действие: " << endl;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> digit;
	int digit_lenght = digit.length();
	for (int i = 0; i < digit_lenght; i++) {
		if (digit[i] < 48 || digit[i] > 57) {
			err_write = true;
		}
	}
	if (!err_write) {
		num = stoi(digit);
	}
	while (cin.fail() || (num < 0) || (num > 3)) {
		cin.clear();
		cin.sync();
		cout << "Ошибка ввода, выберите действие: ";
		err_write = false;
		cin >> digit;
		digit_lenght = digit.length();
		for (int i = 0; i < digit_lenght; i++) {
			if (digit[i] < 48 || digit[i] > 57) {
				err_write = true;
			}
		}
		if (!err_write) {
			num = stoi(digit);
		}
	}
	return num;
}

int menu() {
	int num = -1;
	bool err_write = false;
	string digit;
	cout << endl <<
		"Главное меню: " << endl << 
		"1 - Клиенты" << endl <<
		"2 - Автомобили" << endl <<
		"3 - Выдача и возврат" << endl <<
		"0 - Выход\nВыберите пункт меню: " << endl;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> digit;
	int digit_lenght = digit.length();
	for (int i = 0; i < digit_lenght; i++) {
		if (digit[i] < 48 || digit[i] > 57) {
			err_write = true;
		}
	}
	if (!err_write) {
		num = stoi(digit);
	}
	while (cin.fail() || (num < 0) || (num > 3)) {
		cin.clear();
		cin.sync();
		cout << "Ошибка ввода, выберите пункт меню: ";
		err_write = false;
		cin >> digit;
		digit_lenght = digit.length();
		for (int i = 0; i < digit_lenght; i++) {
			if (digit[i] < 48 || digit[i] > 57) {
				err_write = true;
			}
		}
		if (!err_write) {
			num = stoi(digit);
		}
	}
	return num;
}

void download_test(clients* client, clients*& Root, short int& H, cars car, cars* (&hash_table), int& table_size, int& count_cars) {
	client->num_VU = "00 АА 000000";
	client->FIO = "Иванов Иван Иванович";
	client->passport = "1234567890";
	client->address = "Город Москва, улица Сезам";
	client->Left = NULL;
	client->Right = NULL;
	client->h = 1;
	Add_balance(client, Root, H);
	client->num_VU = "59 АХ 123456";
	client->FIO = "Иванов Петр Петрович";
	client->passport = "1231231231";
	client->address = "Город Москва, улица Московская 1";
	Add_balance(client, Root, H);
	client->num_VU = "67 ТУ 113466";
	client->FIO = "Иванов Петр Петрович";
	client->passport = "1231231231";
	client->address = "Город Москва, улица Московская 1";
	Add_balance(client, Root, H);
	client->num_VU = "01 ВЕ 123123";
	client->FIO = "Сидоров Петр Петрович";
	client->passport = "2233445566";
	client->address = "Город Москва, улица Московская 10";
	Add_balance(client, Root, H);
	client->num_VU = "19 ММ 122112";
	client->FIO = "Петров Петр Петрович";
	client->passport = "1231231231";
	client->address = "Город Москва, улица Московская 1";
	Add_balance(client, Root, H);
	car.grn = "Е769СК-01";
	car.mark = "ВАЗ 2110";
	car.color = "Белый";
	car.year = 2000;
	car.have = true;
	car.rem = false;
	add_car_check(car, hash_table, table_size, count_cars);
	car.grn = "Х407АК-99";
	car.mark = "Газ";
	car.color = "Серый";
	car.year = 1999;
	add_car_check(car, hash_table, table_size, count_cars);
	car.grn = "А390РК-68";
	car.mark = "Тесла";
	car.color = "Бежевый";
	car.year = 2020;
	add_car_check(car, hash_table, table_size, count_cars);
	car.grn = "Т942СУ-20";
	car.mark = "Тесла";
	car.color = "Серебристый";
	car.year = 2021;
	add_car_check(car, hash_table, table_size, count_cars);
	car.grn = "А000АА-00";
	car.mark = "Тойота";
	car.color = "Черный";
	car.year = 2015;
	add_car_check(car, hash_table, table_size, count_cars);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	clients* Root = NULL;
	clients* client = new clients;
	clients* search_client = NULL; // указатель для поиска
	short int H = 0;// высота дерева клиентов
	string num_VU = "";
	string grn = "";
	string fragment = "";
	cars car;
	int table_size = 10, count_cars = 0; // размер таблицы и общее количество автомобилей
	int kol_t_r = 0; // количество выданных автомобилей
	cars* hash_table = new cars[table_size];
	for (int i = 0; i < table_size; i++) {
		hash_table[i].grn = "";
	}
	take_return* head = NULL;// указатель на начало списка 
	take_return* search_t_r = NULL; // указатель для поиска
	take_return* t_r = new take_return;
	string test = "";
	cout << "Для загрузки тестовых данных введите 1: ";
	getline(cin, test);
	if (test == "1") download_test(client, Root, H, car, hash_table, table_size, count_cars);
	system("cls"); // очистка консоли
	int n = menu(); //меню пользователя
	while (n != 0) {

		switch (n) {
			//клиенты
		case 1: {
			system("cls"); // очистка консоли
			int n_cl = menu_client();
			while (n_cl != 0) {

				switch (n_cl) {
					// добавить
				case 1: {
					system("cls"); // очистка консоли
					cout << "Регистрация нового клиента" << endl;
					cout << "Введите номер водительского удостоверения" << endl;
					cout << "строка формата \"RR AA NNNNNN\", где RR – код региона(цифры)" << endl;
					cout << "AA – серия(буквы из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х)" << endl;
					cout << "NNNNNN – порядковый номер удостоверения(цифры)" << endl;
					cout << "Код, серия и номер отделяются друг от друга пробелами " << endl;
					cout << "Для выхода в меню клиентов введите 0 " << endl;
					cout << "Введите номер водительского удостоверения: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, num_VU);
					if (num_VU == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}
					search_client = NULL;
					bool check_have_VU = check_num_VU(num_VU);
					if (check_have_VU) {
						search_cl(Root, num_VU, search_client);
					}

					while ((!check_have_VU || search_client) && num_VU != "0") {
						system("cls");
						cout << "Ошибка ввода!" << endl;
						if (search_client) {
							cout << "Клиент с данным номером водительского удостоверения уже зарегистрирован!" << endl;
						}
						cout << "Регистрация нового клиента" << endl;
						cout << "Введите номер водительского удостоверения" << endl;
						cout << "строка формата \"RR AA NNNNNN\", где RR – код региона(цифры)" << endl;
						cout << "AA – серия(буквы из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х)" << endl;
						cout << "NNNNNN – порядковый номер удостоверения(цифры)" << endl;
						cout << "Код, серия и номер отделяются друг от друга пробелами " << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Введите номер водительского удостоверения: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, num_VU);
						search_client = NULL;
						check_have_VU = check_num_VU(num_VU);
						if (check_have_VU) {
							search_cl(Root, num_VU, search_client);
						}
					}
					if (num_VU == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}
					client->num_VU = num_VU;
					system("cls");
					cout << "Для выхода в меню клиентов введите 0 " << endl;
					cout << "Номер водительского удостоверения: " << num_VU << endl;
					cout << "Введите ФИО клиента: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, client->FIO);
					if (client->FIO == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}
					while ((client->FIO.length() > 50 || client->FIO.length() == 0) && client->FIO != "0") {
						system("cls");
						cout << "Ошибка ввода!" << endl;
						cout << "ФИО не может быть пустым и должно содержать до 50 символов" << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Номер водительского удостоверения: " << num_VU << endl;
						cout << "Введите ФИО клиента: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, client->FIO);
					}
					if (client->FIO == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}
					system("cls");
					cout << "Для выхода в меню клиентов введите 0 " << endl;
					cout << "Номер водительского удостоверения: " << num_VU << endl;
					cout << "ФИО клиента: " << client->FIO << endl;
					cout << "Введите паспортные данные клиента, 10 цифр без пробела: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, client->passport);
					if (client->passport == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}
					while (!check_passport(client->passport) && client->passport != "0") {
						system("cls");
						cout << "Ошибка ввода!" << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Номер водительского удостоверения: " << num_VU << endl;
						cout << "ФИО клиента: " << client->FIO << endl;
						cout << "Введите паспортные данные клиента, 10 цифр без пробела: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, client->passport);
					}
					if (client->passport == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}
					system("cls");
					cout << "Для выхода в меню клиентов введите 0 " << endl;
					cout << "Номер водительского удостоверения: " << num_VU << endl;
					cout << "ФИО клиента: " << client->FIO << endl;
					cout << "Паспортные данные клиента: " << client->passport << endl;
					cout << "Введите адрес клиента: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, client->address);
					if (client->address == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}
					while ((client->address.length() > 150 || client->address.length() == 0) && client->address != "0") {
						system("cls");
						cout << "Ошибка ввода!" << endl;
						cout << "Адрес клиента не может быть пустым и должен содержать до 150 символов: " << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Номер водительского удостоверения: " << num_VU << endl;
						cout << "ФИО клиента: " << client->FIO << endl;
						cout << "Паспортные данные клиента: " << client->passport << endl;
						cout << "Введите адрес клиента: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, client->address);
					}
					if (client->address == "0") {
						system("cls");
						n_cl = menu_client();
						break;
					}

					client->Left = NULL;
					client->Right = NULL;
					client->h = 1;
					Add_balance(client, Root, H);
					system("cls");
					cout << "Данные успешно добавлены" << endl;
					cout << "Просмотр всех зарегистрированных клиентов" << endl;
					cout << "\tНомер ВУ\tФИО" << endl;
					print_all_clients(Root);
					cout << "Вывод бинарного дерева: " << endl;
					cout << "Высота дерева = " << H << endl;
					print_client(Root);
					system("pause");
					system("cls");
					n_cl = menu_client();
					break;
				}
					  // удалить
				case 2: {
					system("cls"); // очистка консоли
					if (H == 0) {
						cout << "База клиентов пуста" << endl;
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
					else {
						cout << "\tНомер ВУ\tФИО" << endl;
						print_all_clients(Root);
						cout << "Снятие с обслуживания клиента" << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Введите номер водительского удостоверения: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, num_VU);
						if (num_VU == "0") {
							system("cls");
							n_cl = menu_client();
							break;
						}
						search_client = NULL;
						bool check_have_VU = check_num_VU(num_VU);
						if (check_have_VU) {
							search_cl(Root, num_VU, search_client);
						}

						while ((!check_have_VU || !search_client) && num_VU != "0") {
							system("cls"); // очистка консоли
							cout << "Ошибка ввода!" << endl;
							if (!search_client && check_have_VU) {
								cout << "Клиент с данным номером водительского удостоверения не найден!" << endl;
							}
							cout << "Снятие с обслуживания клиента" << endl;
							cout << "Введите номер водительского удостоверения";
							cout << "строка формата RR AA NNNNNN, где RR – код региона(цифры)" << endl;
							cout << "AA – серия(буквы из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х)" << endl;
							cout << "NNNNNN – порядковый номер удостоверения(цифры)" << endl;
							cout << "Код, серия и номер отделяются друг от друга пробелами " << endl;
							cout << "\tНомер ВУ\tФИО" << endl;
							print_all_clients(Root);
							cout << "Для выхода в меню клиентов введите 0 " << endl;
							cout << "Введите номер водительского удостоверения: " << endl;
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, num_VU);
							search_client = NULL;
							check_have_VU = check_num_VU(num_VU);
							if (check_have_VU) {
								search_cl(Root, num_VU, search_client);
							}
						}
						if (num_VU == "0") {
							system("cls");
							n_cl = menu_client();
							break;
						}
						search_t_r = search_tr(head, num_VU);
						if (search_t_r) {
							cout << "Клиент не вернул: " << endl;
							print_cars_of_client(head, num_VU);
						}
						else {
							del_check_H(Root, num_VU, H);
							system("cls");
							cout << "Клиент с номером водительского удостоверения: " << num_VU << " снят с обслуживания!" << endl;
							if (H == 0) {
								cout << "База клиентов пуста" << endl;
							}
							else {
								cout << "Просмотр всех зарегистрированных клиентов" << endl;
								cout << "\tНомер ВУ\tФИО" << endl;
								print_all_clients(Root);
								cout << "Вывод бинарного дерева: " << endl;
								cout << "Высота дерева = " << H << endl;
								print_client(Root);
							}
						}
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
				}
					  // просмотр всех
				case 3: {
					system("cls"); // очистка консоли
					if (H == 0) {
						cout << "База клиентов пуста" << endl;
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
					else {
						cout << "Просмотр всех зарегистрированных клиентов" << endl;
						cout << "\tНомер ВУ\tФИО" << endl;
						print_all_clients(Root);
						cout << "Вывод бинарного дерева: " << endl;
						cout << "Высота дерева = " << H << endl;
						print_client(Root);
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}

				}
					  // очистка всех
				case 4: {
					system("cls"); // очистка консоли
					if (H == 0) {
						cout << "База клиентов пуста" << endl;
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
					else {
						string check = "";
						if (head) {
							cout << "Существуют клиенты, которым выдан автомобиль: " << endl;
							print_all_t_r(head);
							cout << "Подтвердите выбранное действие, введите 1" << endl;
							cout << "Для выхода в меню клиентов введите 0 " << endl;
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, check);
							if (check == "0") {
								system("cls");
								n_cl = menu_client();
								break;
							}
							if (check == "1") {
								del_except_t_r(Root, H, head);
								cout << "Данные об остальных клиентах очищены" << endl;
							}
						}
						else {
							cout << "Подтвердите выбранное действие, введите 1" << endl;
							cout << "Для выхода в меню клиентов введите 0 " << endl;
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, check);
							if (check == "0") {
								system("cls");
								n_cl = menu_client();
								break;
							}
							if (check == "1") {
								del_except_t_r(Root, H, head);
								cout << "Данные о клиентах очищены" << endl;
							}
						}
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
				}
				//Поиск клиента по номеру водительского удостоверения (Полная информация о клиенте)
				case 5: {
					system("cls"); // очистка консоли
					if (H == 0) {
						cout << "База клиентов пуста" << endl;
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
					else {
						cout << "Поиск клиента по номеру водительского удостоверения (Полная информация о клиенте)" << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Введите номер водительского удостоверения: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, num_VU);
						if (num_VU == "0") {
							system("cls");
							n_cl = menu_client();
							break;
						}
						search_client = NULL;
						bool check_have_VU = check_num_VU(num_VU);
						if (check_have_VU) {
							search_cl(Root, num_VU, search_client);
						}

						while ((!check_have_VU || !search_client) && num_VU != "0") {
							system("cls"); // очистка консоли
							if (!check_have_VU) cout << "Ошибка ввода!" << endl;
							if (!search_client && check_have_VU) {
								cout << "Клиент с данным номером водительского удостоверения не найден!" << endl;
							}
							cout << "Поиск клиента по номеру водительского удостоверения (Полная информация о клиенте)" << endl;
							cout << "Для выхода в меню клиентов введите 0 " << endl;
							cout << "Введите номер водительского удостоверения: ";
							cout << "строка формата RR AA NNNNNN, где RR – код региона(цифры)" << endl;
							cout << "AA – серия(буквы из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х)" << endl;
							cout << "NNNNNN – порядковый номер удостоверения(цифры)" << endl;
							cout << "Код, серия и номер отделяются друг от друга пробелами " << endl;
							cout << "Для выхода в меню клиентов введите 0 " << endl;
							cout << "Введите номер водительского удостоверения: " << endl;
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, num_VU);
							search_client = NULL;
							check_have_VU = check_num_VU(num_VU);
							if (check_have_VU) {
								search_cl(Root, num_VU, search_client);
							}
						}
						if (num_VU == "0") {
							system("cls");
							n_cl = menu_client();
							break;
						}
						print_client_complete(search_client);
						search_t_r = search_tr(head, num_VU);
						if (search_t_r) {
							cout << "Клиенту выдан: " << endl;
							print_cars_of_client(head, num_VU);
						}
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
				}
				// Поиск клиента по фрагментам ФИО или адреса
				case 6: {
					system("cls"); // очистка консоли
					if (H == 0) {
						cout << "База клиентов пуста" << endl;
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
					else {
						cout << "Поиск клиента по фрагментам ФИО или адреса" << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Введите фрагмент: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, fragment);
						if (fragment == "0") {
							system("cls");
							n_cl = menu_client();
							break;
						}
						while ((fragment.length() > 30 || fragment.length() == 0) && fragment != "0") {
							system("cls"); // очистка консоли
							cout << "Ошибка ввода!" << endl;
							cout << "Фрагмент не может быть пустым и должен содержать до 30 символов" << endl;
							cout << "Для выхода в меню автомобилей введите 0 " << endl;
							cout << "Введите фрагмент: " << endl;
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, fragment);
						}
						if (fragment == "0") {
							system("cls");
							n_cl = menu_client();
							break;
						}
						bool header = false;
						search_fragment(Root, fragment, header);
						if (!header) {
							cout << "Совпадений не найдено" << endl;
						}
						system("pause");
						system("cls");
						n_cl = menu_client();
						break;
					}
				}
				}
			}
			system("cls");
			n = menu(); //главное меню
			break;
		}
			  // автомобили
		case 2: {
			system("cls"); // очистка консоли
			int n_car = menu_cars();
			while (n_car != 0) {

				switch (n_car) {
					// Добавление нового автомобиля
				case 1: {
					system("cls"); // очистка консоли
					cout << "Добавление нового автомобиля" << endl;
					cout << "Введите государственный регистрационный номер" << endl;
					cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
					cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
					cout << "Для выхода в меню автомобилей введите 0 " << endl;
					cout << "Введите государственный регистрационный номер: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, grn);
					if (grn == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					};
					bool check_num_car = check_grn(grn);
					bool check_have_car = false;

					if (check_num_car) {
						check_have_car = search_car(hash_table, grn, car, table_size);
					}

					while ((check_have_car || !check_num_car) && grn != "0") {
						system("cls");
						cout << "Ошибка ввода!" << endl;
						if (check_have_car) {
							cout << "Автомобиль с данным государственным регистрационным номером уже зарегистрирован!" << endl;
						}
						cout << "Добавление нового автомобиля" << endl;
						cout << "Введите государственный регистрационный номер" << endl;
						cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
						cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
						cout << "Для выхода в меню автомобилей введите 0 " << endl;
						cout << "Введите государственный регистрационный номер: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, grn);
						check_have_car = false;
						check_num_car = check_grn(grn);
						if (check_num_car) {
							check_have_car = search_car(hash_table, grn, car, table_size);
						}
					}
					if (grn == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					}
					car.grn = grn;
					system("cls"); // очистка консоли
					cout << "Для выхода в меню автомобилей введите 0 " << endl;
					cout << "Государственный регистрационный номер: " << car.grn << endl;
					cout << "Введите марку автомобиля: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, car.mark);
					if (car.mark == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					}
					while ((car.mark.length() > 20 || car.mark.length() == 0) && car.mark != "0") {
						system("cls"); // очистка консоли
						cout << "Ошибка ввода!" << endl;
						cout << "Марка не может быть пустой и должна содержать до 20 символов" << endl;
						cout << "Для выхода в меню автомобилей введите 0 " << endl;
						cout << "Государственный регистрационный номер: " << car.grn << endl;
						cout << "Введите марку автомобиля: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, car.mark);
					}
					if (car.mark == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					}
					system("cls"); // очистка консоли
					cout << "Для выхода в меню автомобилей введите 0 " << endl;
					cout << "Государственный регистрационный номер: " << car.grn << endl;
					cout << "Марка автомобиля: " << car.mark << endl;
					cout << "Введите цвет автомобиля: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, car.color);
					if (car.color == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					}
					while ((car.color.length() > 20 || car.color.length() == 0) && car.color != "0") {
						system("cls"); // очистка консоли
						cout << "Ошибка ввода!" << endl;
						cout << "Цвет не может быть пустым и должен содержать до 20 символов" << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Государственный регистрационный номер: " << car.grn << endl;
						cout << "Марка автомобиля: " << car.mark << endl;
						cout << "Введите цвет автомобиля: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, car.color);
					}
					if (car.color == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					}
					system("cls"); // очистка консоли
					cout << "Для выхода в меню клиентов введите 0 " << endl;
					cout << "Государственный регистрационный номер: " << car.grn << endl;
					cout << "Марка автомобиля: " << car.mark << endl;
					cout << "Цвет автомобиля: " << car.color << endl;
					string year = "";
					SYSTEMTIME st;
					GetSystemTime(&st);
					int wYear = st.wYear;
					cout << "Введите год выпуска автомобиля: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, year);
					if (year == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					}
					bool true_year = check_year(year, wYear);
					while (!true_year && year != "0") {
						system("cls"); // очистка консоли
						cout << "Ошибка ввода!" << endl;
						cout << "Год может принимать значение от 1800 до " << wYear << endl;
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Государственный регистрационный номер: " << car.grn << endl;
						cout << "Марка автомобиля: " << car.mark << endl;
						cout << "Цвет автомобиля: " << car.color << endl;
						cout << "Введите год выпуска автомобиля: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, year);
						true_year = check_year(year, wYear);
					}
					if (year == "0") {
						system("cls");
						n_car = menu_cars();
						break;
					}
					car.year = stoi(year);
					car.have = true;
					car.rem = false;
					add_car_check(car, hash_table, table_size, count_cars);
					system("cls");
					cout << "Данные успешно добавлены" << endl;
					print_cars(hash_table, table_size, count_cars);
					system("pause");
					system("cls");
					n_car = menu_cars();
					break;
				}
					  // Удаление сведений об автомобиле
				case 2: {
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
					else {
						cout << "Удаление сведений об автомобиле" << endl;
						cout << "Для выхода в меню автомобилей введите 0" << endl;
						cout << "Введите государственный регистрационный номер: ";
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, grn);
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						bool check_num_car = check_grn(grn);
						bool check_have_car = false;

						if (check_num_car) {
							check_have_car = search_car(hash_table, grn, car, table_size);
						}

						while ((!check_have_car || !check_num_car) && grn != "0") {
							system("cls"); // очистка консоли
							cout << "Ошибка ввода!" << endl;
							if (!check_have_car && check_num_car) {
								cout << "Автомобиль с данным государственным регистрационным номером не найден!" << endl;
							}
							cout << "Удаление сведений об автомобиле" << endl;
							cout << "Введите государственный регистрационный номер" << endl;
							cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
							cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
							cout << "Для выхода в меню автомобилей введите 0" << endl;
							cout << "Введите государственный регистрационный номер: ";
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, grn);
							check_have_car = false;
							check_num_car = check_grn(grn);
							if (check_num_car) {
								check_have_car = search_car(hash_table, grn, car, table_size);
							}
						}
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						system("cls");
						if (!car.have) {
							cout << "Данного автомобиля нет в наличии" << endl;
							if (car.rem) {
								cout << "Автомобиль в ремонте" << endl;
							}
							search_t_r = search_tr(head, grn);
							if (search_t_r) {
								cout << "Автомобиль выдан клиенту с номером водительского удостоверения: " << search_t_r->num_VU << endl;
							}
						}
						else {
							del_car(hash_table, grn, table_size, count_cars);
							cout << "Сведения об втомобиле с государственным регистрационным номером: " << grn << " удалены!" << endl;
						}
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
				}
					  // Просмотр всех имеющихся автомобилей
				case 3: {
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
					else {
						cout << "Просмотр всех имеющихся автомобилей" << endl;
						print_cars(hash_table, table_size, count_cars);
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
				}
					  //Очистка данных об автомобилях
				case 4: {
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
					else {
						string check = "";
						cout << "Очистка данных об автомобилях" << endl;
						cout << "Подтвердите выбранное действие, введите 1" << endl;
						cout << "Для выхода в меню автомобилей введите 0 " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, check);
						if (check == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						if (check == "1") {
							del_car_have(hash_table, table_size, count_cars);
							if (count_cars) {
								cout << "Данные очищены кроме автомобилей, которых нет в наличии" << endl;
							}
							else cout << "Данные об автомобилях полностью очищены" << endl;
						}
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
				}
					  //Поиск автомобиля по государственному регистрационному номеру
				case 5:{
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
					else {
						cout << "Поиск автомобиля по государственному регистрационному номеру" << endl;
						cout << "Для выхода в меню автомобилей введите 0" << endl;
						cout << "Введите государственный регистрационный номер: ";
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, grn);
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						bool check_num_car = check_grn(grn);
						bool check_have_car = false;

						if (check_num_car) {
							check_have_car = search_car(hash_table, grn, car, table_size);
						}

						while ((!check_have_car || !check_num_car) && grn != "0") {
							system("cls"); // очистка консоли
							if (!check_num_car) cout << "Ошибка ввода!" << endl;
							if (!check_have_car && check_num_car) {
								cout << "Автомобиль с данным государственным регистрационным номером не найден!" << endl;
							}
							cout << "Поиск автомобиля по государственному регистрационному номеру" << endl;
							cout << "Введите государственный регистрационный номер" << endl;
							cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
							cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
							cout << "Для выхода в меню автомобилей введите 0" << endl;
							cout << "Введите государственный регистрационный номер: ";
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, grn);
							check_have_car = false;
							check_num_car = check_grn(grn);
							if (check_num_car) {
								check_have_car = search_car(hash_table, grn, car, table_size);
							}
						}
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						system("cls"); // очистка консоли
						print_car(car);
						search_t_r = search_tr(head, grn);
						if (search_t_r) {
							cout << "Автомобиль выдан клиенту с номером водительского удостоверения: " << search_t_r->num_VU << endl;
						}
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
						}
				
				}
					  //Поиск автомобиля по названию марки автомобиля
				case 6: {
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
					else {
						string mark = "";
						cout << "Поиск автомобиля по названию марки автомобиля" << endl;
						cout << "Для выхода в меню автомобилей введите 0" << endl;
						cout << "Введите марку автомобиля: ";
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, mark);
						if (mark == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						while ((mark.length() > 30 || mark.length() == 0) && mark != "0") {
							cout << "Ошибка ввода!" << endl;
							cout << "Марка не может быть пустой и должна содержать до 30 символов" << endl;
							cout << "Для выхода в меню автомобилей введите 0 " << endl;
							cout << "Введите марку автомобиля: " << endl;
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, mark);
						}
						if (mark == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						system("cls"); // очистка консоли
						search_mark(hash_table, mark, table_size, head);
						search_t_r = search_tr(head, grn);
						if (search_t_r) {
							cout << "Автомобиль выдан клиенту с номером водительского удостоверения: " << search_t_r->num_VU << endl;
						}
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
				}
					  //Регистрация отправки автомобиля в ремонт
				case 7: {
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
					else {
						cout << "Регистрация отправки автомобиля в ремонт" << endl;
						cout << "Для выхода в меню автомобилей введите 0" << endl;
						cout << "Введите государственный регистрационный номер: ";
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, grn);
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						bool check_num_car = check_grn(grn);
						bool check_have_car = false;

						if (check_num_car) {
							check_have_car = search_car(hash_table, grn, car, table_size);
						}

						while ((!check_have_car || !check_num_car) && grn != "0") {
							system("cls"); // очистка консоли
							if (!check_num_car) cout << "Ошибка ввода!" << endl;
							if (!check_have_car && check_num_car) {
								cout << "Автомобиль с данным государственным регистрационным номером не найден!" << endl;
							}
							cout << "Регистрация отправки автомобиля в ремонт" << endl;
							cout << "Введите государственный регистрационный номер" << endl;
							cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
							cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
							cout << "Для выхода в меню автомобилей введите 0" << endl;
							cout << "Введите государственный регистрационный номер: ";
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, grn);
							check_have_car = false;
							check_num_car = check_grn(grn);
							if (check_num_car) {
								check_have_car = search_car(hash_table, grn, car, table_size);
							}
						}
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						reg_send_rem(hash_table, grn, table_size);
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
				}
					  //Регистрация прибытия автомобиля из ремонта
				case 8: {
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
					else {
						cout << "Регистрация прибытия автомобиля из ремонта" << endl;
						cout << "Для выхода в меню автомобилей введите 0" << endl;
						cout << "Введите государственный регистрационный номер: ";
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, grn);
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						bool check_num_car = check_grn(grn);
						bool check_have_car = false;

						if (check_num_car) {
							check_have_car = search_car(hash_table, grn, car, table_size);
						}

						while ((!check_have_car || !check_num_car) && grn != "0") {
							system("cls"); // очистка консоли
							if (!check_num_car) cout << "Ошибка ввода!" << endl;
							if (!check_have_car && check_num_car) {
								cout << "Автомобиль с данным государственным регистрационным номером не найден!" << endl;
							}
							cout << "Регистрация прибытия автомобиля из ремонта" << endl;
							cout << "Введите государственный регистрационный номер" << endl;
							cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
							cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
							cout << "Для выхода в меню автомобилей введите 0" << endl;
							cout << "Введите государственный регистрационный номер: ";
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, grn);
							check_have_car = false;
							check_num_car = check_grn(grn);
							if (check_num_car) {
								check_have_car = search_car(hash_table, grn, car, table_size);
							}
						}
						if (grn == "0") {
							system("cls");
							n_car = menu_cars();
							break;
						}
						reg_get_rem(hash_table, grn, table_size);
						system("pause");
						system("cls");
						n_car = menu_cars();
						break;
					}
				}
				}
			}
			system("cls");
			n = menu(); //главное меню
			break;
		}
			  // выдача и возврат
		case 3: {
			system("cls"); // очистка консоли
			int n_t_r = menu_t_r();
			while (n_t_r != 0) {

				switch (n_t_r) {
					//выдача
				case 1: {
					system("cls"); // очистка консоли
					if (H == 0) {
						cout << "База клиентов пуста" << endl;
						system("pause");
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_t_r = menu_t_r();
						break;
					}

					cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
					cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
					cout << "Введите государственный регистрационный номер автомобиля: ";
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, grn);
					if (grn == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					bool check_num_car = check_grn(grn);
					bool check_have_car = false;
					if (check_num_car) {
						check_have_car = search_car(hash_table, grn, car, table_size);
					}

					while ((!check_have_car || !check_num_car) && grn != "0") {
						system("cls"); // очистка консоли
						cout << "Ошибка ввода!" << endl;
						if (!check_have_car && check_num_car) {
							cout << "Автомобиль с данным государственным регистрационным номером не найден!" << endl;
						}
						cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
						cout << "Введите государственный регистрационный номер автомобиля" << endl;
						cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
						cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
						cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
						cout << "Введите государственный регистрационный номер автомобиля: ";
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, grn);
						check_have_car = false;
						check_num_car = check_grn(grn);
						if (check_num_car) {
							check_have_car = search_car(hash_table, grn, car, table_size);
						}
					}
					if (grn == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					system("cls");
					if (!car.have) {
						cout << "Данного автомобиля нет в наличии" << endl;
						if (car.rem) {
							cout << "Автомобиль в ремонте" << endl;
						}
						search_t_r = search_tr(head, grn);
						if (search_t_r) {
							cout << "Данный втомобиль уже выдан клиенту с номером водительского удостоверения: " << search_t_r->num_VU << endl;
						}
						system("pause");
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					t_r->grn = grn;

					system("cls"); // очистка консоли
					cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
					cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
					cout << "Государственный регистрационный номер автомобиля: " << grn << endl;
					cout << "Введите номер водительского удостоверения клиента: " << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, num_VU);
					if (num_VU == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					search_client = NULL;
					bool check_have_VU = check_num_VU(num_VU);
					if (check_have_VU) {
						search_cl(Root, num_VU, search_client);
					}

					while ((!check_have_VU || !search_client) && num_VU != "0") {
						system("cls"); // очистка консоли
						cout << "Ошибка ввода!" << endl;
						if (!search_client && check_have_VU) {
							cout << "Клиент с данным номером водительского удостоверения не найден!" << endl;
						}
						cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
						cout << "Введите номер водительского удостоверения клиента";
						cout << "строка формата RR AA NNNNNN, где RR – код региона(цифры)" << endl;
						cout << "AA – серия(буквы из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х)" << endl;
						cout << "NNNNNN – порядковый номер удостоверения(цифры)" << endl;
						cout << "Код, серия и номер отделяются друг от друга пробелами " << endl;
						cout << "\tНомер ВУ\tФИО" << endl;
						print_all_clients(Root);
						cout << "Для выхода в меню клиентов введите 0 " << endl;
						cout << "Введите номер водительского удостоверения клиента: " << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, num_VU);
						search_client = NULL;
						check_have_VU = check_num_VU(num_VU);
						if (check_have_VU) {
							search_cl(Root, num_VU, search_client);
						}
					}
					if (num_VU == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					t_r->num_VU = num_VU;
					system("cls"); // очистка консоли

					string date = "";
					cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
					cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
					cout << "Государственный регистрационный номер автомобиля: " << grn << endl;
					cout << "Номер водительского удостоверения клиента:" << num_VU << endl;
					cout << "Введите дату выдачи в формате ДД.ММ.ГГГГ: ";
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> date;
					if (date == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					long long unix_time_begin = 0;
					while ((cin.fail() || !correct_date(date, unix_time_begin)) && date != "0") {
						system("cls"); // очистка консоли
						cin.clear();
						cin.sync();
						cout << "Ошибка ввода!" << endl;
						cout << "Некорректная дата" << endl;
						cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
						cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
						cout << "Государственный регистрационный номер автомобиля: " << grn << endl;
						cout << "Номер водительского удостоверения клиента:" << num_VU << endl;
						cout << "Введите дату выдачи в формате ДД.ММ.ГГГГ: ";
						cin >> date;
					}
					if (date == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					t_r->date_of_issue = date;
					system("cls"); // очистка консоли
					cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
					cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
					cout << "Государственный регистрационный номер автомобиля: " << grn << endl;
					cout << "Номер водительского удостоверения клиента:" << num_VU << endl;
					cout << "Дата выдачи: " << t_r->date_of_issue << endl;
					cout << "Автомобиль выдается на срок от одних суток до года" << endl;
					cout << "Введите дату возврата в формате ДД.ММ.ГГГГ: ";
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> date;
					if (date == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					long long unix_time_end = 0;
					bool check_date = correct_date(date, unix_time_end);
					while ((cin.fail() || !check_date || unix_time_begin + 86400 > unix_time_end || unix_time_begin + 31536000 < unix_time_end) && date != "0") {
						cin.clear();
						cin.sync();
						system("cls"); // очистка консоли
						cout << "Ошибка ввода!" << endl;
						cout << "Некорректная дата" << endl;
						cout << "Автомобиль выдается на срок от одних суток до года!" << endl;
						cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
						cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
						cout << "Государственный регистрационный номер автомобиля: " << grn << endl;
						cout << "Номер водительского удостоверения клиента:" << num_VU << endl;
						cout << "Дата выдачи: " << t_r->date_of_issue << endl;
						cout << "Введите дату возврата в формате ДД.ММ.ГГГГ: ";
						cin >> date;
						check_date = correct_date(date, unix_time_end);
					}
					if (date == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					t_r->return_date = date;

					reg_take_car(hash_table, grn, table_size); // зарегистрировать в хеш таблице
					t_r->mark = car.mark;
					add_t_r(head, t_r, kol_t_r);
					system("cls");
					cout << "Регистрация выдачи клиенту автомобиля на прокат успешно завершена" << endl;
					print_all_t_r(head);
					system("pause");
					system("cls");
					n_t_r = menu_t_r();
					break;
				}
					  //возврат
				case 2: {
					system("cls"); // очистка консоли
					if (H == 0) {
						cout << "База клиентов пуста" << endl;
						system("pause");
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					if (!head) {
						cout << "Отсутствуют выданные автомобили" << endl;
						system("pause");
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					cout << "Регистрация возврата автомобиля от клиента" << endl;
					cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
					cout << "Введите государственный регистрационный номер автомобиля: ";
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, grn);
					if (grn == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					bool check_num_car = check_grn(grn);
					bool check_have_car = false;
					if (check_num_car) {
						check_have_car = search_car(hash_table, grn, car, table_size);
					}

					while ((!check_have_car || !check_num_car) && grn != "0") {
						system("cls"); // очистка консоли
						cout << "Ошибка ввода!" << endl;
						if (!check_have_car && check_num_car) {
							cout << "Автомобиль с данным государственным регистрационным номером не найден!" << endl;
						}
						cout << "Регистрация выдачи клиенту автомобиля на прокат" << endl;
						cout << "Введите государственный регистрационный номер автомобиля" << endl;
						cout << "строка формата \"ANNNAA-NN\", где N –цифра" << endl;
						cout << "A – буква из следующего множества : А, В, Е, К, М, Н, О, Р, С, Т, У, Х" << endl;
						cout << "Для выхода в меню выдачи и возврата введите 0" << endl;
						cout << "Введите государственный регистрационный номер автомобиля: ";
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, grn);
						check_have_car = false;
						check_num_car = check_grn(grn);
						if (check_num_car) {
							check_have_car = search_car(hash_table, grn, car, table_size);
						}
					}
					if (grn == "0") {
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					system("cls");
					if (car.have) {
						cout << "Данный автомобиль имеется в наличии" << endl;
					}
					else {
						if (car.rem) {
							cout << "Автомобиль в ремонте" << endl;
						}
						else {
							search_t_r = search_tr(head, grn);
							if (search_t_r) {
								del_t_r(head, grn, kol_t_r);
								reg_return_car(hash_table, grn, table_size); // зарегистрировать в хеш таблице
								print_all_t_r(head);
							}
						}
					}
					cout << "Регистрация возврата автомобиля от клиента успешно завершена" << endl;
					system("pause");
					system("cls");
					n_t_r = menu_t_r();
					break;
				}
					  // просмотр всех выданных авто
				case 3: {
					system("cls"); // очистка консоли
					if (count_cars == 0) {
						cout << "База автомобилей пуста" << endl;
						system("pause");
						system("cls");
						n_t_r = menu_t_r();
						break;
					}
					else if (head) {
						cout << "Просмотр всех выданных автомобилей" << endl;
						print_all_t_r(head);
					}
					else {
						cout << "Отсутствуют выданнные автомобили" << endl;
					}
					system("pause");
					system("cls");
					n_t_r = menu_t_r();
					break;
				}
				}
			}
			system("cls");
			n = menu(); //главное меню
			break;
		}
		}
	}
	
	del_all_t_r(head, kol_t_r);
	delete[] hash_table;
	delete client;
	delete t_r;
	FreeTree(Root);	
	return 0;
}
