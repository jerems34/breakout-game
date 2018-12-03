#ifndef RAQUETTE__H
#define RAQUETTE__H
#include "window.h"

class Raquette {
 private:
  
  int x,y,size;
  char c;

 public:

  Raquette(int x,int y,int size,char c);

  //Accesseurs
 int getSize()const;
  int getX()const;
  int getY()const;
  void setX(int n);
  void setY(int n);

  //Méthodes

  void print(WINDOW *w)const;
  void erase(WINDOW *w)const;
  void move();
  void setColors(WINDOW *w,Color c)const;
};
#endif
