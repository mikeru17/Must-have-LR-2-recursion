#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

const string TASK1_DESCRIPT = "Задача 1.\nНапишите программу, которая выводила бы в консоль n-ое число из ряда Фибоначчи. n – аргумент функции, обозначающий порядковый номер числа в последовательности. Функция обязательно должна быть рекурсивной, а следом напишите ещё одну с той же целью, но с использованием любого из циклов, что со счетчиком(for), или с пред- и постусловием(while).\n\n";
const string TASK2_DESCRIPT = "Задача 2.\nНапишите программу, которая при помощи ввода с клавиатуры заполняет массив строк из 5 элементов, а затем, принимая в качестве ввода с клавиатуры ещё одно число, ни в коем случае не большее чем число строк в массиве.\n\n";
const string TASK3_DESCRIPT = "Задача 3.\nНарисуйте фрактал Минковского и кривую Коха в консоли на языке C++\n\n";
const int COUNT = 5;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

// Задача 1 (с помощью рекурсии).
int GetFibonachiRowElementByNumberUsingRecursion(int number) {
    // Базовый случай, задающий условие последнего вызова в стеке.
    if (number == 1)
    {
        return 0;
    }

    // Также базовый случай.
    if (number == 2)
    {
        return 1;
    }

    return GetFibonachiRowElementByNumberUsingRecursion(number - 1) + GetFibonachiRowElementByNumberUsingRecursion(number - 2);
}

// Задача 1 (с помощью цикла for).
int GetFibonachiRowElementByNumberUsingForLoop(int number) {  
    if (number == 1)
    {
        return 0;
    }

    if (number == 2)
    {
        return 1;
    }

    if (number >= 3)
    {
        int elements[3];
        elements[0] = 0;
        elements[1] = 1;
        for (int i = 1; i < number - 1; i++)
        {
            // Каждый последующий элемент ряда Фибоначчи равен сумме двух предыдущих.
            elements[2] = elements[0] + elements[1];
            // Двигаем элементы для нахождения следующего элемента последовательности.
            elements[0] = elements[1];
            elements[1] = elements[2];
        }

        return elements[2];
    }
}

// Задача 2 (с помощью рекурсии).
string ShowFirstElementsUsingRecursion(string* str, int count) {
    // Базовый случай, задающий условие последнего вызова в стеке.
    if (count == 1)
    {
        return str[0];
    }
    else
    {
        return str[count - 1] + "  " + ShowFirstElementsUsingRecursion(str, count - 1);
    }
}

// Задача 2 (с помощью цикла while).
string ShowFirstElementsUsingWhileLoop(string* arr, int count) {
    string generalString;
    while (count > 0)
    {
        generalString += arr[count - 1];
        generalString += "  ";
        count--;
    }

    return generalString;
}

// Методы для задачи 3.
void Up(float& x, float& y, int& reachX, int& reachY)
{
    reachY -= 10;
    for (y; y > reachY; y -= 0.05)
    {
        SetPixel(hdc, x, y, RGB(255, 255, 255));
    }
}

void Down(float& x, float& y, int& reachX, int& reachY)
{
    reachY += 10;
    for (y; y < reachY; y += 0.05)
    {
        SetPixel(hdc, x, y, RGB(255, 255, 255));
    }
}

void Left(float& x, float& y, int& reachX, int& reachY)
{
    reachX -= 10;
    for (x; x > reachX; x -= 0.05)
    {
        SetPixel(hdc, x, y, RGB(255, 255, 255));
    }
}

void Right(float& x, float& y, int& reachX, int& reachY)
{
    reachX += 10;
    for (x; x < reachX; x += 0.05)
    {
        SetPixel(hdc, x, y, RGB(255, 255, 255));
    }
}

void Up1(float& x, float& y, int& reachX, int& reachY)
{
    Up(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    Up(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    Up(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    Up(x, y, reachX, reachY);
}

void Down1(float& x, float& y, int& reachX, int& reachY)
{
    Down(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    Down(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    Down(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    Down(x, y, reachX, reachY);
}

void Left1(float& x, float& y, int& reachX, int& reachY)
{
    Left(x, y, reachX, reachY);
    Up(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    Down(x, y, reachX, reachY);
    Down(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    Up(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
}

void Right1Milkovsky(float& x, float& y, int& reachX, int& reachY)
{
    Right(x, y, reachX, reachY);
    Down(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    Up(x, y, reachX, reachY);
    Up(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    Down(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
}

void Up2(float& x, float& y, int& reachX, int& reachY)
{
    Up1(x, y, reachX, reachY);
    Right1Milkovsky(x, y, reachX, reachY);
    Up1(x, y, reachX, reachY);
    Left1(x, y, reachX, reachY);
    Left1(x, y, reachX, reachY);
    Up1(x, y, reachX, reachY);
    Right1Milkovsky(x, y, reachX, reachY);
    Up1(x, y, reachX, reachY);
}

void Down2(float& x, float& y, int& reachX, int& reachY)
{
    Down1(x, y, reachX, reachY);
    Left1(x, y, reachX, reachY);
    Down1(x, y, reachX, reachY);
    Right1Milkovsky(x, y, reachX, reachY);
    Right1Milkovsky(x, y, reachX, reachY);
    Down1(x, y, reachX, reachY);
    Left1(x, y, reachX, reachY);
    Down1(x, y, reachX, reachY);
}

void Left2(float& x, float& y, int& reachX, int& reachY)
{
    Left1(x, y, reachX, reachY);
    Up1(x, y, reachX, reachY);
    Left1(x, y, reachX, reachY);
    Down1(x, y, reachX, reachY);
    Down1(x, y, reachX, reachY);
    Left1(x, y, reachX, reachY);
    Up1(x, y, reachX, reachY);
    Left1(x, y, reachX, reachY);
}

void Right2(float& x, float& y, int& reachX, int& reachY)
{
    Right1Milkovsky(x, y, reachX, reachY);
    Down1(x, y, reachX, reachY);
    Right1Milkovsky(x, y, reachX, reachY);
    Up1(x, y, reachX, reachY);
    Up1(x, y, reachX, reachY);
    Right1Milkovsky(x, y, reachX, reachY);
    Down1(x, y, reachX, reachY);
    Right1Milkovsky(x, y, reachX, reachY);
}

// ---------------------------------------------
// K = 2.
void DrawMinkovskyFractal() {
    float x = 300, y = 100;
    int reachX = 300, reachY = 100;

    Right2(x, y, reachX, reachY);
    Down2(x, y, reachX, reachY);
    Left2(x, y, reachX, reachY);
    Up2(x, y, reachX, reachY);

    cin.ignore();
}
// ---------------------------------------------

void RightUp(float& x, float& y, int& reachX, int& reachY)
{
    reachX += 10;
    reachY -= 10;
    for (x, y; x < reachX; x += 0.05, y -= 0.05)
        SetPixel(hdc, x, y, RGB(255, 255, 255));
}

void RightDown(float& x, float& y, int& reachX, int& reachY)
{
    reachX += 10;
    reachY += 10;
    for (x, y; x < reachX; x += 0.05, y += 0.05)
        SetPixel(hdc, x, y, RGB(255, 255, 255));
}

void LeftUp(float& x, float& y, int& reachX, int& reachY)
{
    reachX -= 10;
    reachY -= 10;
    for (x, y; x > reachX; x -= 0.05, y -= 0.05)
        SetPixel(hdc, x, y, RGB(255, 255, 255));
}

void LeftDown(float& x, float& y, int& reachX, int& reachY)
{
    reachX -= 10;
    reachY += 10;
    for (x, y; x > reachX; x -= 0.05, y += 0.05)
        SetPixel(hdc, x, y, RGB(255, 255, 255));
}

void Right1Koch(float& x, float& y, int& reachX, int& reachY)
{
    Right(x, y, reachX, reachY);
    RightUp(x, y, reachX, reachY);
    RightDown(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
}

void RightUp1(float& x, float& y, int& reachX, int& reachY)
{
    RightUp(x, y, reachX, reachY);
    LeftUp(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    RightUp(x, y, reachX, reachY);
}

void RightDown1(float& x, float& y, int& reachX, int& reachY)
{
    RightDown(x, y, reachX, reachY);
    Right(x, y, reachX, reachY);
    LeftDown(x, y, reachX, reachY);
    RightDown(x, y, reachX, reachY);
}

void LeftUp1(float& x, float& y, int& reachX, int& reachY)
{
    LeftUp(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    RightUp(x, y, reachX, reachY);
    LeftUp(x, y, reachX, reachY);
}

void LeftDown1(float& x, float& y, int& reachX, int& reachY)
{
    LeftDown(x, y, reachX, reachY);
    RightDown(x, y, reachX, reachY);
    Left(x, y, reachX, reachY);
    LeftDown(x, y, reachX, reachY);
}

void Right2Koch(float& x, float& y, int& reachX, int& reachY)
{
    Right1Koch(x, y, reachX, reachY);
    RightUp1(x, y, reachX, reachY);
    RightDown1(x, y, reachX, reachY);
    Right1Koch(x, y, reachX, reachY);
}

void RightUp2(float& x, float& y, int& reachX, int& reachY)
{
    RightUp1(x, y, reachX, reachY);
    LeftUp1(x, y, reachX, reachY);
    Right1Koch(x, y, reachX, reachY);
    RightUp1(x, y, reachX, reachY);
}

void RightDown_2(float& x, float& y, int& reachX, int& reachY)
{
    RightDown1(x, y, reachX, reachY);
    Right1Koch(x, y, reachX, reachY);
    LeftDown1(x, y, reachX, reachY);
    RightDown1(x, y, reachX, reachY);
}

// ---------------------------------------------
// K = 2.
void DrawKochCurve() {
    float x = 300, y = 100;
    int reachX = 300, reachY = 100;
    Right2(x, y, reachX, reachY);
    RightUp2(x, y, reachX, reachY);
    RightDown_2(x, y, reachX, reachY);
    Right2Koch(x, y, reachX, reachY);

    cin.ignore();
}
// ---------------------------------------------

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "----- Обязательная ЛР-2 начала выполнение! -----\n\n";
    int userChoice;
    // Главное меню для перехода между задачами.
    do
    {
        cout << "----- Главное меню -----\n";
        cout << "Что вы хотите сделать?\nНа выбор есть 4 варианта:\n";
        cout << "1 - Задача 1\n2 - Задача 2\n3 - Задача 3\n0 - Выход\n\nВведите номер вашего выбора: ";
        cin >> userChoice;
        cout << "\n";

        // Объявляем необходимые переменные.
        int counter, fibonachiElement, number;
        string strings[COUNT], firstElements;
        switch (userChoice)
        {
        case 1:
            cout << TASK1_DESCRIPT;
            counter = 1;

            while (counter <= 2)
            {
                cout << "-------- Работает метод ";
                if (counter == 1)
                {
                    cout << "GetFibonachiRowElementByNumberUsingRecursion";
                }
                else if (counter == 2)
                {
                    cout << "GetFibonachiRowElementByNumberUsingForLoop";
                }
                cout << " --------\n";

                cout << "Введите порядковый номер элемента в ряде Фибоначчи: ";
                // Ввод с проверкой.
                do
                {
                    cin >> number;
                    if (number < 1)
                    {
                        cout << "Порядковый номер не может быть меньше 1! Пожалуйста, повторите попытку: ";
                    }
                } while (number < 1);

                if (counter == 1)
                {
                    fibonachiElement = GetFibonachiRowElementByNumberUsingRecursion(number);
                }
                else if (counter == 2)
                {
                    fibonachiElement = GetFibonachiRowElementByNumberUsingForLoop(number);
                }
                cout << number << "-й элемент ряда Фибоначчи: " << fibonachiElement << "\n\n";

                counter++;
            }

            break;
        case 2:
            cout << TASK2_DESCRIPT;
            counter = 1;

            cout << "Ввод массива строк из 5 элементов...\n";
            for (int i = 0; i < COUNT; i++)
            {
                cout << "Введите " << i << "-й элемент: ";
                cin >> strings[i];
            }

            int count;
            cout << "\nВведите кол-во первых элементов массива строк, которые нужно вывести: ";
            // Ввод с проверкой.
            do
            {
                cin >> count;
                if (count < 1 || count > COUNT)
                {
                    cout << "Кол-во не может быть меньше 1 или больше " << COUNT << "! Пожалуйста, повторите попытку: ";
                }
            } while (count < 1 || count > COUNT);

            while (counter <= 2)
            {
                cout << "\n-------- Работает метод ";
                if (counter == 1)
                {
                    cout << "ShowFirstElementsUsingRecursion --------\n";
                    firstElements = ShowFirstElementsUsingRecursion(strings, count);
                }
                else if (counter == 2)
                {
                    cout << "ShowFirstElementsUsingWhileLoop --------\n";
                    firstElements = ShowFirstElementsUsingWhileLoop(strings, count);
                }

                cout << "Первые " << count << " элемента массива строк (от последнего к первому):\n" << firstElements << "\n";
                counter++;
            }

            break;
        case 3:
            cout << TASK3_DESCRIPT;
            DrawMinkovskyFractal();
            DrawKochCurve();
            break;
        case 0:
            cout << "Выбран вариант выхода из программы. Программа завершается...\n\n";
            break;
        default:
            cout << "Введен некорректный номер. Пожалуйста, повторите попытку";
            break;
        }

        if (userChoice != 0)
        {
            cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
        }
    } while (userChoice != 0);

    system("pause");
    return 0;
}
