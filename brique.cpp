#include "brique.h"
#include <ncurses.h>

Brique::Brique(): x(0),y(0){}
Brique::Brique(int _x,int _y,int _size,char _c): x(_x),y(_y),size(_size),c(_c) {}
int Brique::getX()const { return x; }
int Brique::getY()const { return y; }
int Brique::getSize()const{ return size;}
void Brique::setX(int n){  x=n; }
void Brique::setY(int n){  y=n; }
void Brique::print(WINDOW *w)const{

  std::string b(size,c);



      wattron(w,COLOR_PAIR(BWHITE));
      mvwprintw(w,y,x,b.c_str());
      wattroff(w,COLOR_PAIR(BWHITE));
      wrefresh(w);
      refresh();

    }

void Brique::erase(WINDOW *w)const{
  std::string s(size,' ');
  mvwprintw(w,y,x,s.c_str());
  wrefresh(w);
  refresh();
}
