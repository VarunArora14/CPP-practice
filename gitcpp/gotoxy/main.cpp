#include<iostream>
#include <windows.h>

void gotoxy(int x,int y){
  HANDLE hConsole;
  COORD cursorLoc;
  std::cout.flush();
  cursorLoc.X = x;
  cursorLoc.Y = y;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsole, cursorLoc);
}

int main()
{
    std::cout<<"line1 \n";
    std::cout<<"line2 \n";
    gotoxy(10,0);
    std::cout<<"line3";
}
