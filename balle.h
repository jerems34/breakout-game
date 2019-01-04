#ifndef BALLE__H
#define BALLE__H
#include "window.h"
#include "brique.h"
#include "raquette.h"
#include "tabBriques.h"
#include "utilisateur.h"

class Balle {
 private:

  size_t x,y;
  int velocity;
  char b;
  int size;
  int directionx, directiony;


 public:

  Balle(int x,int y,int velocity,char b,int size);

  //Acesseurs en lecture

  int getX()const;
  int getY()const;
  int getVelocity()const;
  int getChB()const;
  int getDirectionx()const;
  int getDirectiony()const;

  //Accesseurs en écriture

  void setX(int i);
  void setY(int i);
  void setVelocity(int i);
  void setChB(char c);
  void setDirectionx(int a);
  void setDirectiony(int b);

  //Affichage

  void print(WINDOW *w,int x,int y);
  void erase(WINDOW *w,int x,int y);
  int moveBally(WINDOW *win,Raquette &raq, Tableaubriques T,Utilisateur &pseudo);
  void setColors(WINDOW *w,Color c);



};

#endif
