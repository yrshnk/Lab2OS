#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

volatile int* arr;
volatile int minElement, maxElement, averageElement;

DWORD WINAPI min_max(LPVOID dim) {
    int n = (int)dim;
    minElement = arr[0];
    maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            Sleep(7);
        }

        if (arr[i] < minElement) {
            minElement = arr[i];
            Sleep(7);
        }
    }

    cout << "����������� ������� �������: " << minElement << endl;
    cout << "������������ ������� �������: " << maxElement << endl;

    return 1;
}

DWORD WINAPI average(LPVOID dim) {
    int n = (int)dim;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        Sleep(12);
    }

    averageElement = sum / n;
    cout << "������� �������������� ��������� �������: " << averageElement;

    return 1;
}