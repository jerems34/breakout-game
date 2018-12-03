#include "brique.h"
#include <ncurses.h>


Brique::Brique(int _x,int _y,int _size,char _c): x(_x),y(_y),size(_size),c(_c) {}
int Brique::getX()const { return x; }
int Brique::getY()const { return y; }
int Brique::getSize()const{ return size;}
void Brique::setX(int n){  x=n; }
void Brique::setY(int n){  y=n; }
void Brique::print(WINDOW *w)const{
  int x;int y;
  std::string b(size,c);
  for(x=1;x<100;x++){
    for(y=1;y<20;y++){
    // int x=rand()%100+1;
  //  int y=rand()%20+1;
 
  wattron(w,COLOR_PAIR(BBLUE));
  mvwprintw(w,y,x,b.c_str());
  wattroff(w,COLOR_PAIR(BBLUE));
  wrefresh(w);
  refresh();
  x=x+rand()%5+2;
  y=y+rand()%3+1;
  }
  }
}
void Brique::erase(WINDOW *w)const{
  std::string s(size,' ');
  mvwprintw(w,y,x,s.c_str());
  wrefresh(w);
  refresh();
}
