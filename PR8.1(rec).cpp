#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// Рекурсивна функція для підрахунку кількості входжень трійки 'n?o'
int Count(char* str, int i) {
    if (strlen(str) < 3)
        return 0;

    if (str[i + 1] != '\0') {
        if (str[i - 1] == 'n' && str[i + 1] == 'o')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }
    else {
        return 0;
    }
}

// Рекурсивна функція для заміни кожної трійки 'n?o' на '**'
char* Change(char* dest, const char* str, char* t, int i) {
    if (str[i + 2] != '\0') {
        if (str[i] == 'n' && str[i + 2] == 'o') {
            strcat(t, "**");
            return Change(dest, str, t + 2, i + 3); // Пропускаємо трійку
        }
        else {
            *t++ = str[i++]; // Копіюємо символ
            *t = '\0'; // Завершуємо рядок
            return Change(dest, str, t, i); // Продовжуємо
        }
    }
    else {
        *t++ = str[i++]; // Копіюємо останній символ
        *t++ = str[i++]; // Копіюємо ще один символ
        *t = '\0'; // Завершуємо рядок
        return dest; // Повертаємо результат
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 1) << " groups of 'n?o'" << endl;

    char* dest1 = new char[201]; // Збільшуємо розмір для модифікованого рядка
    dest1[0] = '\0'; // Ініціалізація рядка
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0); // Виклик функції зміни рядка

    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1; // Звільнення пам'яті
    return 0;
}
