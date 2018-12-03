#ifndef BALLE__H
#define BALLE__H
#include "window.h"
#include "raquette.h"
#include "brique.h"
class Balle {
 private:
  
  size_t x,y;
  int velocity;
  char b;
  int size;


 public:

  Balle(int x,int y,int velocity,char b,int size);

  //Acesseurs en lecture
  
  int getX()const;
  int getY()const;
  int getVelocity()const;
  int getChB()const;

  //Accesseurs en écriture

  void setX(int i);
  void setY(int i);
  void setVelocity(int i);
  void setChB(char c);

  //Affichage

  void print(WINDOW *w,int x,int y);
  void erase(WINDOW *w,int x,int y);
  void moveBallx(WINDOW *w,Raquette &raq);
  void moveBally(WINDOW *win,Raquette &raq,Brique &br);
  void setColors(WINDOW *w,Color c);


    
};

#endif
