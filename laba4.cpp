#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;


class Cleaner {
	int power;
	int price;
	int noise;
	string brend;
	string material;
	string version;
	string form;
	string name;

public:
	Cleaner(string n);
	~Cleaner();
	int getPower() { return power; }
	int getPrice() { return price; }
	int getNoise() { return noise; }
	string getName() { return name; }
	string getBrend() { return brend; }
	string getMaterial() { return material; }
	string getVersion() { return version; }
	string getForm() { return form; }
	void setPower(int p) {
		if (p > 0) power = p;
		else cout << "Ошибка: мощность должна быть > 0\n";
	}
	void setPrice(int p) {
		if (p > 0) price = p;
		else cout << "Ошибка: цена должна быть > 0\n";
	}
	void setNoise(int p) {
		if (p > 0) noise = p;
		else cout << "Ошибка: уровень шума должен быть > 0\n";
	}
	void setBrend(string b) { brend = b; }
	void setMaterial(string b) { material = b; }
	void setVersion(string b) { version = b; }
	void setForm(string b) { form = b; }
	void get_info() const {
		cout << "ИНФОРМАЦИЯ О " << name << endl;
		cout << "БРЕНД: " << brend << endl;
		cout << "МАТЕРИАЛ: " << material << endl;
		cout << "Версия: " << version << endl;
		cout << "Форма: " << form << endl;
		cout << "Мощность: " << power << endl;
		cout << "Цена: " << price << endl;
		cout << "Уровень шума: " << noise << endl;
		cout << "-----------------------------" << endl;
	}

	bool isPremium() {
		return price >= 50000 or brend == "DYSON";
	}


};

Cleaner::Cleaner(string n = "NONE") {
	string BREND[4] = { "ROBOROCK", "DREAME", "XIAOMI","DYSON" };
	string MATERIAL[4] = { "PLASTIC", "METAL", "ALUMINUM", "CARBON" };
	string VERSION[4] = { "PRO", "LITE", "STANDARD", "ULTIMATE" };
	string FORM[2] = { "КРУГ", "КВАДРАТ" };

	brend = BREND[rand() % 4];
	material = MATERIAL[rand() % 4];
	version = VERSION[rand() % 4];
	form = FORM[rand() % 2];
	power = rand() % (10000 - 3000) + 3000;
	noise = rand() % (71 - 20) + 20;
	price = rand() % (100000 - 10000 + 1) + 10000;
	name = n;
}

Cleaner::~Cleaner() {
	cout << name << " Уничтожен" << endl;
}



class ListNode;

class Node : public Cleaner {
	Node* next;
	Node* prev;
public:
	friend ListNode;

	Node(string data) :Cleaner(data) {
		this->next = NULL;
		this->prev = NULL;
	};
};

class ListNode
{
	Node* head, * tail;

public:
	ListNode() {
		head = tail = NULL;
	}
	~ListNode() {
		while (head != NULL) {
			Node* ptr = head;
			head = head->next;
			delete ptr;
		}
	}
	Node* add_front(string data) {
		Node* ptr = new Node(data);
		ptr->next = head;
		if (head != NULL)
		{
			head->prev = ptr;
		}
		if (tail == NULL)
		{
			tail = ptr;
		}
		head = ptr;
		return ptr;
	}
	Node* add_back(string data) {
		Node* ptr = new Node(data);
		ptr->prev = tail;
		if (tail != NULL)
		{
			tail->next = ptr;
		}
		if (head == NULL)
		{
			head = ptr;
		}
		tail = ptr;
		return ptr;
	}
	void pop_front() {
		if (head == NULL) return;

		Node* ptr = head->next;
		if (ptr != NULL)
		{
			ptr->prev = NULL;
		}
		else
		{
			tail = ptr;
		}
		delete head;
		head = ptr;
	}
	void pop_back() {
		if (tail == NULL) return;

		Node* ptr = tail->prev;
		if (ptr != NULL)
		{
			ptr->next = NULL;
		}
		else
		{
			head = ptr;
		}
		delete tail;
		tail = ptr;
	}

private:
	Node* getind(int index) {
		if (index < 0) return nullptr;
		Node* ptr = head;
		int count = 0;
		while (count != index) {
			if (ptr == NULL) return nullptr;
			ptr = ptr->next;
			count++;
		}
		return ptr;
	}
public:
	Node* operator [] (int index) {
		Node* ptr = getind(index);
		if (ptr == NULL)
		{
			cout << "Ошибка, такого элемента нет";
		}
		return ptr;


	}
	void del(int index) {
		Node* ptr = getind(index);
		if (ptr == NULL) return;
		if (ptr->next == NULL)
		{
			this->pop_back();
			return;
		}
		if (ptr->prev == NULL)
		{
			this->pop_front();
			return;
		}
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		delete ptr;
	}
	void see() {
		Node* ptr = head;
		int count = 0;
		while (ptr != NULL) {
			ptr->get_info();
			ptr = ptr->next;
			count++;
		}
	}

	//Функции подсчета статистики
	void get_info_brend() {
		cout << "Посчитать кол-во пылесосов каждого бренда\n";
		Node* ptr = head;
		if (ptr == NULL) return;
		int count_roborock = 0, count_dreame = 0, count_xiaomi = 0, count_dyson = 0;
		while (ptr != NULL) {

			if (ptr->getBrend() == "ROBOROCK") count_roborock++;
			else if (ptr->getBrend() == "DREAME") count_dreame++;
			else if (ptr->getBrend() == "XIAOMI") count_xiaomi++;
			else if (ptr->getBrend() == "DYSON") count_dyson++;
			ptr = ptr->next;
		}
		cout << "СТАТИСТИКА ПО БРЕНДАМ:\n";
		cout << "ROBOROCK: " << count_roborock << " шт.\n";
		cout << "DREAME: " << count_dreame << " шт.\n";
		cout << "XIAOMI: " << count_xiaomi << " шт.\n";
		cout << "DYSON: " << count_dyson << " шт.\n";
	}
	void get_models_by_price() {
		Node* ptr = head;
		if (ptr == NULL) return;
		int price = 0;
		cout << "Определить модели с ценой, меньшей чем n руб.\n";
		cout << "Введите число n: ";
		cin >> price;
		cout << "Модели, дешевле назначенной цены: " << endl;
		while (ptr != NULL) {
			if (ptr->getPrice() < price) ptr->get_info();
			ptr = ptr->next;
		}

	}
	void get_info_on_price() {
		Node* ptr = head;
		int count = 0, sum = 0;
		while (ptr != NULL) {
			sum += ptr->getPower();
			count++;
			ptr = ptr->next;
		}
		if (count == 0 or sum <= 0) {
			cout << "ERROR";
			return;
		}
		ptr = head;
		float sr_arif = (float)sum / count;
		int min_price = 110000;
		Node* pust = NULL;
		while (ptr != NULL) {
			if (ptr->getPower() > sr_arif and ptr->getPrice() < min_price)
			{
				min_price = ptr->getPrice();
				pust = ptr;
			}
			ptr = ptr->next;
		}
		if (pust == NULL)
		{
			cout << "Такого пылесоса не найдено" << endl;
			return;
		}
		cout << "Найти модель с мощностью, большей чем среднее арифметическое мощностей и по самой низкой цене" << endl;
		cout << "НАЙДЕННАЯ МОДЕЛЬ: " << endl;
		pust->get_info();
	}
	void most_quiet() {
		cout << "Самый тихий пылесос:\n";
		int q = 1000;
		Node* ptr = head;
		Node* pust = NULL;
		while (ptr != NULL) {
			if (ptr->getNoise() < q)
			{
				q = ptr->getNoise();
				pust = ptr;
			}
			ptr = ptr->next;
		}
		if (pust == NULL) return;
		pust->get_info();
	}
	void count_premiunm() {
		int ct = 0;
		Node* ptr = head;
		while (ptr != NULL) {
			if (ptr->isPremium()) ct++;
			ptr = ptr->next;
		}
		cout << "Кол-во премиальных пылесосов: " << ct << endl;
	}
};




int main()
{
	const int MENU_1 = 49;
	const int MENU_2 = 50;
	const int MENU_3 = 51;
	const int MENU_4 = 52;
	const int MENU_5 = 53;
	const int MENU_6 = 54;
	const int MENU_7 = 55;
	const int MENU_8 = 56;
	const int MENU_9 = 57;
	const int MENU_EXIT = 27;
	srand(time(0));
	setlocale(LC_ALL, "rus");
	ListNode A = ListNode();
	for (int i = 1; i <= 15; i++)
	{
		A.add_back("пылесос #" + to_string(i));
	}
	int req = 0;
	while (req != MENU_EXIT) {
		system("cls");
		cout << "  1. Добавить элемент в конец списка.\n";
		cout << "  2. Получить элемент списка по ind.\n";
		cout << "  3. Удалить элемент списка по ind.\n";
		cout << "  4. Показать весь список.\n";
		cout << "  5. Посчитать кол-во пылесосов каждого бренда.\n";
		cout << "  6. Определить модели с ценой, меньшей чем n руб.\n";
		cout << "  7. Найти модель с мощностью, большей чем среднее арифметическое мощностей и по самой низкой цене.\n";
		cout << "  8. Найти самую тихую модель.\n";
		cout << "  9. Посчитать кол-во премиальных пылесосов.\n";
		cout << "  ESC. Выход.\n";
		req = _getch();
		switch (req)
		{
		case MENU_1: {
			system("cls");
			string name;
			cout << "Введите имя пылесоса: ";
			cin >> name;
			A.add_back(name);
			cout << "Объект добавлен";
			_getch();
			break;
		}
		case MENU_2: {
			system("cls");
			int ind;
			cout << "Введите ind элемента, который хотите увидеть: ";
			cin >> ind;
			if (A[ind] != NULL) A[ind]->get_info();
			_getch();
			break;
		}
		case MENU_3: {
			system("cls");
			int ind;
			cout << "Введите ind элемента, который хотите удалить: ";
			cin >> ind;
			if (A[ind] != NULL) A.del(ind);
			_getch();
			break;
		}
		case MENU_4: {
			system("cls");
			A.see();
			_getch();
			break;
		}
		case MENU_5: {
			system("cls");
			A.get_info_brend();
			_getch();
			break;
		}
		case MENU_6: {
			system("cls");
			A.get_models_by_price();
			_getch();
			break;
		}
		case MENU_7: {
			system("cls");
			A.get_info_on_price();
			_getch();
			break;
		}
		case MENU_8: {
			system("cls");
			A.most_quiet();
			_getch();
			break;
		}
		case MENU_9: {
			system("cls");
			A.count_premiunm();
			_getch();
			break;

		}
		}
	}
}
