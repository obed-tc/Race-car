#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void gotoxy(int x, int y)
{
    COORD dwPos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwPos);
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void printBanner()
{
    cout << "..####....####...#####...#####...######..#####....####.." << endl;
    cout << ".##..##..##..##..##..##..##..##..##......##..##..##..##." << endl;
    cout << ".##......######..#####...#####...####....#####...######." << endl;
    cout << ".##..##..##..##..##..##..##..##..##......##..##..##..##." << endl;
    cout << "..####...##..##..##..##..##..##..######..##..##..##..##." << endl;
    cout << "                                                        " << endl;
    cout << "        Create By @obed-tc                " << endl;
}

void getNames(string &Car1, string &Car2)
{
    gotoxy(20, 15);
    cout << "INGRESE NOMBRE DE PARTICIPANTES" << endl;
    gotoxy(15, 16);
    cout << "Participante 1: ";
    getline(cin, Car1);
    gotoxy(15, 17);
    cout << "Participante 2: ";
    getline(cin, Car2);

    gotoxy(25, 18);
    cout << "Iniciando carrera...: " << endl;
    gotoxy(28, 19);
    cout << Car1 << " VS " << Car2 << endl;
}

void drawTrack(int startX, int startY)
{
    const char *trackLines[] = {
        "|----------------------------------------------------------------------------|----|",
        "|                                                                           /|#####",
        "|                                                                            |     ",
        "|                                                                            |#####",
        "|                                                                            |     ",
        "|--------------------------------------------------------------------------- |#####",
        "|                                                                            |     ",
        "|                                                                            |#####",
        "|                                                                            |     ",
        "|                                                                           /|#####",
        "|                                                                            |     ",
        "|                                                                            |#####",
        "|----------------------------------------------------------------------------|-----|"};

    for (int i = 0; i < 11; ++i)
    {
        gotoxy(startX, startY + i);
        cout << trackLines[i];
    }
}

void drawCar(int position, int line, int color)
{
    const char *carLines[] = {
        "    ____      ",
        " __/  |_\\_    ",
        "|  _     _``-.",
        "'-(_)---(_)--'"};

    setColor(color);
    for (int i = 0; i < 4; ++i)
    {
        gotoxy(position, line + i);
        cout << carLines[i];
    }
    setColor(7);
}

void printName(int position, int line, const string &name)
{
    gotoxy(position + 4, line + 2);
    cout << name;
}

void race(const string &Car1, const string &Car2)
{
    int car1Pos = 1, car2Pos = 1;

    srand(static_cast<unsigned int>(time(0)));

    while (car1Pos < 80 && car2Pos < 80)
    {
        Sleep(100);

        car1Pos += rand() % 3;
        car2Pos += rand() % 3;

        for (int i = 11; i <= 19; ++i)
        {
            gotoxy(2, i);
            cout << string(80, ' ');
        }

        drawCar(car1Pos, 11, 12);
        printName(car1Pos, 11, Car1);
        drawCar(car2Pos, 16, 9);
        printName(car2Pos, 16, Car2);

        if (car1Pos >= 68)
        {
            gotoxy(60, 21);
            cout << Car1 << " GANADOR!!!!" << endl;
            break;
        }
        else if (car2Pos >= 68)
        {
            gotoxy(60, 21);
            cout << Car2 << " GANADOR!!!!" << endl;
            break;
        }
    }
}

int main()
{
    printBanner();
    string Car1, Car2;
    getNames(Car1, Car2);

    int startX = 1, startY = 10;
    drawTrack(startX, startY);

    race(Car1, Car2);

    system("pause");
    return 0;
}
