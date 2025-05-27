#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
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
	}
	void compareWith(Cleaner& other) const {
		cout << "Сравнение " << name << " и " << other.name << ":\n";
		cout << "Мощность: " << power << "Вт vs " << other.power << "Вт\n";
		cout << "Шум: " << noise << "дБ vs " << other.noise << "дБ\n";
		cout << "Цена: " << price << "руб vs " << other.price << "руб\n";
		if (power > other.power) cout << name << " мощнее\n";
		else cout << other.name << " мощнее\n";
		if (price < other.price) cout << name << " дешевле\n";
		else cout << other.name << " дешевле\n";
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

Cleaner::Cleaner(string n) {
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

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	Cleaner firs("СЫР");
	Cleaner sec("ПИР");
	Cleaner th("МИР");
	cout << "Бренд " << firs.getName() << ": " << firs.getBrend() << endl;
	firs.setBrend("ГЕНЕРАЛ");
	cout << "Новый бренд: " << firs.getBrend() << endl;
	sec.get_info();
	cout << "Является ли " << sec.getName() << " Премиальным? : " << sec.isPremium() << endl;
	th.compareWith(sec);
	th.cost();

}
