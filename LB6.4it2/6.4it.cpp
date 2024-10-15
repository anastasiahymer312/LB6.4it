#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>

using namespace std;

void createArray(double* arr, int size, double min, double max) {
    for (int i = 0; i < size; i++) {
        arr[i] = (max - min) * rand() / RAND_MAX + min;
    }
}

void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(10) << arr[i];
    }
    cout << endl;
}

static double sumOddIndex(double* arr, int size) {
    double sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

static double sumBetweenNegatives(double* arr, int size) {
    int a = -1, b = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (a == -1) a = i;
            b = i;
        }
    }

    if (a != -1 && b != -1 && a < b) {
        double sum = 0;
        for (int i = a + 1; i < b; i++) {
            sum += arr[i];
        }
        return sum;
    }
    return 0;
}

static int compressArray(double* arr, int size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (abs(arr[i]) > 1) {
            arr[newSize++] = arr[i];
        }
    }

    for (int i = newSize; i < size; i++) {
        arr[i] = 0;
    }

    return newSize;
}

int main() {
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    cout << "Введіть розмір масиву (SIZE): ";
    cin >> size;

    double* arr = new double[size];
    createArray(arr, size, -20, 20);

    cout << "Початковий масив: ";
    printArray(arr, size);

    cout << "Сума елементів з непарними номерами: " << sumOddIndex(arr, size) << endl;
    cout << "Сума елементів між першим і останнім від’ємними елементами: " << sumBetweenNegatives(arr, size) << endl;

    int newSize = compressArray(arr, size);
    cout << "Стиснутий масив: ";
    printArray(arr, newSize);

    delete[] arr;
    return 0;
}
