#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <cctype>
#include <limits>
using namespace std;

char CharInputValidation(char ch, string s);
int InputValidation(int num, string s);
int PositiveInputValidation(int num, string s);
int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int N = 50;
    int k, m, buk = 0, n = 0, choice = 0, choice1 = 0;
    char cch, ch, arr[N];
    char* arr1 = new char[1];
    unsigned seed = time(0);
    srand(seed);
    bool b = false;
    do
    {
        n = PositiveInputValidation(n, "Введите количество букв в одномерном массиве: ");
        arr1 = new char[n];
        b = true;
        cout << "Выберите тип заполнения массива:\n"
            "1. Вручную.\n"
            "2. Рандомно.\n";
        choice = InputValidation(choice, "\nВаш выбор: ");
        if (choice == 1)
        {
            cout << "Заполнение массива буквами:\n";
            for (int i = 0; i < n; i++)
            {
                arr1[i] = CharInputValidation(arr[i], "Введите элемент массива: ");
            }
            cout << "\nИзначальный массив:\n";
            for (int i = 0; i < n; i++)
            {
                cout << arr1[i] << " ";
            }
            "\n";
            b = false;
        }
        else
        {
            if (choice == 2)
            {
                cout << "Какие буквы будут в массиве 1 - заглавные 2 - строчные";
                buk = InputValidation(buk, "\nВаш выбор: ");
                if (buk == 1)
                {
                    cout << "Полученный одномерный массив:\n";
                    for (int i = 0; i < n; i++)
                    {
                        arr1[i] = 'А' + rand() % 33;
                        cout << arr1[i] << " ";
                    }
                    "\n";
                    b = false;
                }
                else
                {
                    if (buk == 2)
                    {
                        cout << "Полученный одномерный массив:\n";
                        for (int i = 0; i < n; i++)
                        {
                            arr1[i] = 'а' + rand() % 33;
                            cout << arr1[i] << " ";
                        }
                        "\n";
                        b = false;
                    }
                    else
                    {
                        cout << "\nОшибка. Неверный тип заполнения.\n";
                        b = true;
                    }
                }
            }
            else
            {
                cout << "\nОшибка. Неверный тип заполнения.\n";
                b = true;
            }
        }
    } while (b);
    // Поиск последней гласной буквы
    int lastVowelIndex = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        char lowercaseChar = tolower(arr1[i]); // Приведение к строчной букве для сравнения
        if (lowercaseChar == 'а' || lowercaseChar == 'А' || lowercaseChar == 'у' || lowercaseChar == 'У'
            || lowercaseChar == 'о' || lowercaseChar == 'О' || lowercaseChar == 'ы' || lowercaseChar == 'Ы'
            || lowercaseChar == 'и' || lowercaseChar == 'И' || lowercaseChar == 'э' || lowercaseChar == 'Э'
            || lowercaseChar == 'я' || lowercaseChar == 'Я' || lowercaseChar == 'ю' || lowercaseChar == 'Ю'
            || lowercaseChar == 'ё' || lowercaseChar == 'Ё' || lowercaseChar == 'е' || lowercaseChar == 'е')
        {
            lastVowelIndex = i;
            break;
        }
    }

    // Удаление последней гласной буквы
    if (lastVowelIndex != -1)
    {
        for (int i = lastVowelIndex; i < n - 1; i++)
        {
            arr1[i] = arr1[i + 1];
        }
        n--; // Уменьшение размера массива
        cout << "\nМассив после удаления последней гласной буквы:\n";
        for (int i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "\nВ массиве нет гласных букв.\n";
    }
}
char CharInputValidation(char ch, string s)
{
    bool b = false;
    do {
        b = false;
        cout << s;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), 'n');
            cout << "Ошибка ввода!n";
            b = true;
        }
    } while (b);
    return ch;
}
int InputValidation(int num, string s)
{
    bool b = false;
    do {
        b = false;
        cout << s;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Ошибка ввода!\n";
            b = true;
        }
    } while (b);
    return num;
}
int PositiveInputValidation(int num, string s)
{
    do {
        num = InputValidation(num, s);
        if (num < 1)
        {
            cout << "Ошибка. Введено отрицательно число или 0\n";
        }
    } while (num < 1);
    return num;
}
