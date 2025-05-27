#pragma comment(linker, "/STACK:4000000000")
#include <iostream>

#include <fstream>
#include <vector>
using namespace std;

void showmas(vector<int>& ptr, int len) {

	for (int i = 0; i < len; i++)
	{
		cout << ptr[i] << " ";
	};
	cout << endl;
}

void s1(vector<int>& ptrmas, int length) {
	for (int i = 1; i < length; i++)
	{
		int per = ptrmas[i];
		int tt = i - 1;
		while (tt >= 0 and per < ptrmas[tt]) {
			ptrmas[tt + 1] = ptrmas[tt];
			tt--;
		}
		ptrmas[tt + 1] = per;

	}

}

int tempfun(vector<int>& ptrarr, int low, int high) {
	int elem = ptrarr[high];
	int j = low - 1;
	for (int i = low; i < high; i++)
	{
		if (ptrarr[i] <= elem) {
			j++;
			swap(ptrarr[i], ptrarr[j]);
		}
	}
	swap(ptrarr[j + 1], ptrarr[high]);

	return j + 1;
}

void s2(vector<int>& ptrarr, int low, int len) {
	if (low < len) {
		int per = tempfun(ptrarr, low, len);
		s2(ptrarr, low, per - 1);
		s2(ptrarr, per + 1, len);
	}

}




int getmax(vector<int>& ptrarr, int len) {
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		max = (max < ptrarr[i]) ? ptrarr[i] : max;
	};
	return max;

}
void s1_3(vector<int>& ptrarr, int length, int e) {
	int count[10] = { 0 };
	vector<int> out(length);
	for (int i = 0; i < length; i++)
	{
		count[ptrarr[i] / e % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = length - 1; i >= 0; i--)
	{
		out[count[(ptrarr[i] / e) % 10] - 1] = ptrarr[i];
		count[(ptrarr[i] / e) % 10]--;
	}
	for (int i = 0; i < length; i++)
	{
		ptrarr[i] = out[i];
	}
}



void s3(vector<int>& ptrarr, int len) {
	int max = getmax(ptrarr, len);
	for (int i = 1; max / i > 0; i *= 10)
	{
		s1_3(ptrarr, len, i);
	}

}

void task(vector<int>& ptrarr, int len) {

	cout << "Метод вставки" << endl;
	clock_t start = clock();
	vector<int> mas = ptrarr;
	s1(mas, len);
	clock_t end = clock();
	float time = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Метод вставки - завершен, время: " << time << endl;
	cout << "Метод быстрой сортировки" << endl;
	start = clock();
	mas = ptrarr;
	s2(mas, 0, len - 1);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Метод быстрой сортировки - завершен, время: " << time << endl;

	cout << "Метод сортировки десятками" << endl;
	start = clock();
	mas = ptrarr;
	s3(mas, len);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Метод сортировки десятками - завершен, время: " << time << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int len = 100000;
	vector<int> normal(len);
	vector<int> loos(len);
	vector<int> vic(len);
	for (int i = 0; i < 100000; i++)
	{
		vic[i] = i + 1;
		loos[len - i - 1] = i + 1;
		normal[i] = (rand() % 35000 + 1);
	}

	cout << "Нормальный случай: " << endl;
	task(normal, len);
	cout << "Лучший случай: " << endl;
	task(vic, len);
	cout << "Худший случай: " << endl;
	task(loos, len);




}