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


	arrrayData = new int[n];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		arrrayData[i] = tmp;
	}
	cout << endl;


	HANDLE hMinMax = CreateThread(nullptr, 0, min_max, (void*)n, 0, nullptr);
	if (hMinMax == NULL) {
		cerr << "Не удалось создать поток min_max\n";
		delete[] arrrayData;
		return 1;
	}


	HANDLE hAverage = CreateThread(nullptr, 0, average, (void*)n, 0, nullptr);
	if (hAverage == NULL) {
		cerr << "Не удалось создать поток average\n";
		CloseHandle(hMinMax);
		delete[] arrrayData;
		return 1;
	}

	WaitForSingleObject(hAverage, INFINITE);
	CloseHandle(hAverage);

	WaitForSingleObject(hMinMax, INFINITE);
	CloseHandle(hMinMax);


	cout << "\n\nМассив после форматирования: ";
	for (int i = 0; i < n; ++i) {
		if (arrrayData[i] == maxElement || arrrayData[i] == minElement) {
			arrrayData[i] = averageElement;
		}
		cout << arrrayData[i] << " ";
	}
	cout << '\n';


	delete[] arrrayData;
	arrrayData = nullptr;
	return 0;
}

