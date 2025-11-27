#include <iostream>
#include <limits>
#include "lab_9_2.h"

using namespace std;

// Макрос для виведення результату (лише для main.cpp)
#define PRINT_RESULT(label, value) cout << label << ": " << value << endl

int main() {
    cout << "Лабораторна робота 9.2. Обчислення Варіанту 14" << endl;

    double x, z;
    char repeat;

    do {
        cout << "\nВведіть значення x: ";
        if (!(cin >> x)) break;

        cout << "Введіть значення z: ";
        if (!(cin >> z)) break;

        double w = calculate_w(x, z);

        PRINT_RESULT("Результат w", w);

        cout << "\nПовторити виконання програми? (y/n): ";
        // Очищення буфера вводу
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!(cin >> repeat)) break;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}