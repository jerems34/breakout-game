#include "message.h"
#include "window.h"
#include <string>
using namespace std;

Message::Message(int x, int y): x(x), y(y) {}

int Message::getx()const{ return x; }
int Message::getY()const{ return y; }
string Message::getMessage()const { return mes; }

void Message::setX(int a){ x= a; }
void Message::setY(int b){ y=b; }
void Message::setMessage(string m){ mes = m; }
void Message::setMessage(int m){ mes = to_string(m); }

void Message::print(WINDOW *w, int x, int y, string s, Color c){
  wattron(w,COLOR_PAIR(c));
  mvwprintw(w,y,x,s.c_str());
  wattroff(w,COLOR_PAIR(c));
  wrefresh(w);
  refresh();
}

void Message::print(WINDOW *w, int x, int y, char s, Color c){
  wattron(w,COLOR_PAIR(c));
  mvwaddch(w,y,x,s);
  wattroff(w,COLOR_PAIR(c));
  wrefresh(w);
  refresh();
}

void Message::print(WINDOW *w, int x, int y, int nbr, Color c){
  mes = to_string(nbr);
  wattron(w,COLOR_PAIR(c));
  mvwprintw(w,y,x,mes.c_str());
  wattroff(w,COLOR_PAIR(c));
  wrefresh(w);
  refresh();
}
