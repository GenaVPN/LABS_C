#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int search1(vector<int>& arr, int target) {
	for (int i = 0; i < arr.size(); i++)
	{
		if (target == arr[i]) return i;
	}
	return -1;
}


void sort_in_bin(vector<int>& ptrmas, int length) {
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

int binar(vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}


int binar2(vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (target >= arr[left] && arr[right] >= target && left <= right) {

		int pos = ((right - left) * (target - arr[left])) / (arr[right] - arr[left]) + left;

		if (target == arr[pos]) return pos;
		else if (arr[pos] < target)
		{
			left = pos + 1;
		}
		else
		{
			right = pos - 1;
		}
	}
	return -1;
}

void UI(vector<int>& arr, int target) {
	int ind = search1(arr, target);
	if (ind == -1)
	{
		cout << "Ёлемент не найден (ѕоследовательный поиск)\n";

	}
	else
	{
		cout << "Ёлемент найден (ѕоследовательный поиск) по индексу: " << ind << ". «начение: " << arr[ind] << endl;
	}

	ind = binar(arr, target);


	if (ind == -1)
	{
		cout << "Ёлемент не найден (Ѕинарный поиск)\n";

	}
	else
	{
		cout << "Ёлемент найден (Ѕинарный поиск) по индексу: " << ind << ". «начение: " << arr[ind] << endl;
	}


	ind = binar2(arr, target);

	if (ind == -1)
	{
		cout << "Ёлемент не найден (»нтерпол€ционный поиск)\n";

	}
	else
	{
		cout << "Ёлемент найден (»нтерпол€ционный поиск) по индексу: " << ind << ". «начение: " << arr[ind] << endl;
	}
}

void show(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	vector <int> mas;
	srand(time(0));
	for (int i = 0; i < 1000; i++)
	{
		int b = rand() % 1000;
		mas.push_back(b);
	}
	setlocale(LC_ALL, "rus");
	sort_in_bin(mas, mas.size());
	UI(mas, 733);
}
