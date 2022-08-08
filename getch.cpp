#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string>

void left();
void right();
void up();
void down();
void gotoxy(int x, int y)
{
    HANDLE hConsole;
    COORD cursorLoc;
    std::cout.flush();
    cursorLoc.X = x;
    cursorLoc.Y = y;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, cursorLoc);
}
char x;
char A = 'O';
int X, Y;

int main()
{
    X = 0;
    Y = 0;
     std::cout << "Press any key to start";
    getch();
    system("cls");
    gotoxy(X, Y);
    std::cout << A;
    x=getch();
    do
    {
    switch(x)
    {
        case 'w': up();
        break;
        case 'a': left();
        break;
        case 's': down();
        break;
        case 'd': right();
        break;
        default:std::cout<<"no such option";
    }
    }while(x!='n');
}
void left()
{
    char a;

    while (!(a = getch()))
    {
        if (X <= 0)
        {
            system("cls");
            std::cout << "Game over \n";
            exit(0);
        }
        X--;
        gotoxy(X, Y);
        std::cout << A;
        Sleep(500);
        system("cls");
    }

    x= a;
    // break;
}

void right()
{
    char a;
    while (!(a = getch()))
    {
        if (X >= 10)
        {
            system("cls");
            std::cout << "Game over \n";
            exit(0);
        }
        X++;
        gotoxy(X, Y);
        std::cout << A;
        Sleep(500);
        system("cls");
    }

    x= a;
}

void up()
{
    char a;
    while (!(a = getch()))
    {
        if (Y <= 0)
        {
            system("cls");
            std::cout << "Game over \n";
            exit(0);
        }
        Y--;
        gotoxy(X, Y);
        std::cout << A;
        Sleep(500);
        system("cls");
    }

    x= a;
}

void down()
{
    char a;
    while (!(a = getch()))
    {
        if (Y >= 10)
        {
            system("cls");
            std::cout << "Game over \n";
            exit(0);
        }
        Y++;
        gotoxy(X, Y);
        std::cout << A;
        Sleep(500);
        system("cls");
    }

    x= a;
}

/*
int main()
{
   
    X = 0;
    Y = 0;
    const int map = 10 * 10;
    std::cout << "Press any key to start";
    getch();
    system("cls");
    gotoxy(X, Y);
    std::cout << A;
    //Sleep(2000);
    do
    {   // system("cls");
        // Sleep(500);
        x = getch();
        system("cls");
        Sleep(500);
        /*
        switch (x)
        {
        case 'w':

            if (Y <= 0)
            {
                system("cls");
                std::cout << "Game Over \n";
            }
            else
            {
                Y--;
                gotoxy(X, Y);
            }
            std::cout << A;
            break;
        case 'a':

            if (X <= 0)
            {
                system("cls");
                std::cout << "Game over \n";
                exit(0);
            }
            else
            {
                X--;
                gotoxy(X, Y);
            }
            std::cout << A;
            break;

        case 's':
            if (Y >= 10)
            {
                system("cls");
                std::cout << "Game Over \n";
                exit(0);
            }
            else
            {
                Y++;
                gotoxy(X, Y);
            }
            std::cout << A;
            break;
        case 'd':
            if (X >= 10)
            {
                system("cls");
                std::cout << "Game Over \n";
                exit(0);
            }
            else
            {
                X++;
                gotoxy(X, Y);
            }
            std::cout << A;
            break;
        default:
            "No such  option";
        }
        
      
    } while (x != 'n');
}
*/