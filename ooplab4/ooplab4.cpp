// ooplab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

struct WORKER {
    double SALARY;
    int YEAR;
    string NAME;
    string POS;
};

void qstroclleng() {
    printf("Выбрано задание номер 1: Ввводите строки при запросе, последняя строка должна завершиться quit\n");
    int quitcounter=0;
    string otvet;
    while (quitcounter == 0) {
        cin >> otvet;
        cout << "\nСтрока\n" << otvet << "\nСодержит в себе: " << size(otvet) << " символов\n";
        if (otvet.substr(size(otvet)-4) == "quit") {
            quitcounter = 2;
            printf("\n Найдено вхождение quit в конце строки \n работа функции завершена");
        }
        else printf("Введите новую строку\n");
    }
}

int filequestionwrite() {
    cout << "Выполнение задания номер 2\n";
    ifstream input("input.txt"); // открытие файла на чтение
    if (!input.is_open()) { // проверка успешности открытия файла
        cout << "Ошибка открытия файла\n";
        return 1;
    }

    ofstream output("output.txt"); // открытие файла на запись
    if (!output.is_open()) { // проверка успешности открытия файла
        cout << "Ошибка открытия файла\n";
        return 1;
    }

    string line;
    while (getline(input, line)) { // чтение строк из файла
        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == '!') {
                line.insert(i, "?"); // вставка вопросительного знака перед восклицательным
                i++; // пропуск добавленного символа
            }
        }
        output << line << '\n'; // запись измененной строки в новый файл
    }

    input.close(); // закрытие файлов
    output.close();
    printf("Задание номер 2 выполненено файл output.txt сохранен в папке проекта\n");
}

void operationwithworker() {
    int stage, counter = 0, allportfoliostate;
    WORKER TABLE[10];
    printf("Введите строку содержащую данные о каждом работнике в следующем формате\n Оклад Год Фамилия Должность");
    for (int i = 0; i < 10; i++) {
        scanf("%lf %d %s %s", TABLE[i].SALARY, TABLE[i].YEAR, TABLE[i].NAME, TABLE[i].POS);
        cout << endl;
    }
    printf("Полученная таблица значений\nОклад\tГод\tФамилия\tДолжность\n");
    for (int i = 0; i < 10; i++) {
        printf("%lf\t%d\t%s\t%s\n", TABLE[i].SALARY, TABLE[i].YEAR, TABLE[i].NAME, TABLE[i].POS);
    }
    cout << "Введите год после которого нужно вывести данные о сотрудниках\n";
    cin >> stage;
    for (int i = 0; i < 10; i++) {
        if (TABLE[i].YEAR < stage) {
            printf("Сотрудник: %s\tСтаж:%d\n", TABLE[i].NAME, stage - TABLE[i].YEAR);
            counter++;
        }
        if (counter == 0) {
            cout << "В компании нет ни одного работника с таким стажем работы\n";
        }
    }
    if (counter != 0) {
        printf("Показать более подробные данные о сотрудниках удовлетворяющих условиям поиска\n1 - Да\n2 - Нет");
        cin >> allportfoliostate;
        if (allportfoliostate == 1) {
            for (int i = 0; i < 10; i++) {
                if (TABLE[i].YEAR < stage) {
                    printf("%lf\t%d\t%s\t%s\t%d\n", TABLE[i].SALARY, TABLE[i].YEAR, TABLE[i].NAME, TABLE[i].POS, stage - TABLE[i].YEAR);
                }
            }
        }
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    qstroclleng();
    filequestionwrite();
    operationwithworker();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
