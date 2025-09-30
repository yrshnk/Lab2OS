#include <iostream>
#include <windows.h>
#include "creating_threads.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");


	int n; int tmp;
	cout << "Введите размерность массива: ";
	if (!(cin >> n) || n <= 0) {
		cerr << "Неверный размер массива\n";
		return 1;
	}


	arr = new int[n];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		arr[i] = tmp;
	}
	cout << endl;



	WaitForSingleObject(hAverage, INFINITE);
	CloseHandle(hAverage);

	WaitForSingleObject(hMinMax, INFINITE);
	CloseHandle(hMinMax);


	cout << "\n\nМассив после форматирования: ";
	for (int i = 0; i < n; ++i) {
		if (arr[i] == maxElement || arr[i] == minElement) {
			arr[i] = averageElement;
		}
		cout << arr[i] << " ";
	}
	cout << '\n';


	delete[] arr;
	arr = nullptr;
	return 0;
}