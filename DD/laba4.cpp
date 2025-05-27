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
	void compareWith(Cleaner& other) const {
		cout << "Сравнение " << name << " и " << other.name << ":\n";
		cout << "Мощность: " << power << "Вт vs " << other.power << "Вт\n";
		cout << "Шум: " << noise << "дБ vs " << other.noise << "дБ\n";
		cout << "Цена: " << price << "руб vs " << other.price << "руб\n";
		if (power > other.power) cout << name << " мощнее\n";
		else cout << other.name << " мощнее\n";
	}
	bool isPremium() {
		return price >= 50000 and brend == "DYSON";
	}
	float cost() {
		float price_year = power * 0.1;
		float full_cost = price_year + price;
		cout << "Полная цена " << name << ": " << endl;
		cout << "Стоимость покупки (" << price << ") + стоимость затрат на электроэнергию (" << price_year << ") = " << full_cost << endl;
		return full_cost;
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
		if (index < 0) return NULL;
		Node* ptr = head;
		int count = 0;
		while (count != index) {
			if (ptr == NULL) return NULL;
			ptr = ptr->next;
			count++;
		}
		return ptr;
	}
public:
	Node* operator [] (int index) {
		return getind(index);
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

};




int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	ListNode A = ListNode();
	for (int i = 1; i <= 10; i++)
	{
		A.add_back("пылесос #" + to_string(i));
	}
	A.see();

}
