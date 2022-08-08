#include<iostream>
#include <windows.h>
#include<stdlib.h>
#include<conio.h>

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
    gotoxy(10,10);
    std::cout<<"line3\n";
    gotoxy(20,20);
   //SetConsoleCursorPosition(20,20);
    std::cout<<"Hello \n";
}

const int X=50;
const int Y=50;
const int map_size=X*Y;
class snake
{
private:
  /* data */
  int len=1;
public:
  snake(/* args */);
  ~snake();
  int left();
  int right();
  int up();
  int down();
  int score();
  int food();
  int len();
  void start();
  void end();
};

snake::snake(/* args */)
{
}

snake::~snake()
{
}

int main()
{
  system("cls");

  std::cout<<"Press any key to start";
  _getch();
  system("cls");
  gotoxy(0,0);
 

}
