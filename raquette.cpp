#include "raquette.h"
#include "window.h"
#include <ncurses.h>
#include <string>

Raquette::Raquette(int _x,int _y,int _size,char _c): x(_x),y(_y),size(_size),c(_c) {}
int Raquette::getX()const { return x; }
int Raquette::getY()const { return y; }
int Raquette::getSize()const{ return size;}
void Raquette::setX(int n){  x=n; }
void Raquette::setY(int n){  y=n; }
void Raquette::print(WINDOW *w)const{
  std::string raq(size,c);
  wattron(w,COLOR_PAIR(WRED));
  mvwprintw(w,y,x,raq.c_str());
  wattroff(w,COLOR_PAIR(WRED));
  wrefresh(w);
  refresh();  
}
void Raquette::erase(WINDOW *w)const{
  std::string s(size,' ');
  mvwprintw(w,y,x,s.c_str());
  wrefresh(w);
  refresh();
}
void Raquette::setColors(WINDOW *w,Color c)const{
  std::string z(size,' ');
  wattron(w,COLOR_PAIR(c));
  mvwprintw(w,y,x,z.c_str());
  wattroff(w,COLOR_PAIR(c));
  wrefresh(w);
  refresh();
}
//void Raquette::getColors(){ return }
  


