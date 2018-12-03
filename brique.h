#ifndef BRIQUE__H
#define BRIQUE__H
#include "window.h"
class Brique {
 private :
  int x,y,size;
  char c;

 public:

    Brique(int x,int y,int size,char c);

  //Accesseurs
 int getSize()const;
  int getX()const;
  int getY()const;
  void setX(int n);
  void setY(int n);

  //Méthodes

  void print(WINDOW *w)const;
  void erase(WINDOW *w)const;

};
#endif