#ifndef BALLE__H
#define BALLE__H
#include "window.h"
#include "brique.h"
#include "raquette.h"
#include "tabBriques.h"
class Balle {
 private:

  size_t x,y;
  int velocity, nbrbale=3;
  char b;
  int size;
  int directionx, directiony;


 public:

  Balle(int x,int y,int velocity,char b,int size, int nbrbale);

  //Acesseurs en lecture

  int getX()const;
  int getY()const;
  int getVelocity()const;
  int getChB()const;
  int getNbrballe()const;
  int getDirectionx()const;
  int getDirectiony()const;

  //Accesseurs en écriture

  void setX(int i);
  void setY(int i);
  void setVelocity(int i);
  void setChB(char c);
  void setNbrballe( int b);
  void setDirectionx(int a);
  void setDirectiony(int b);

  //Affichage

  void print(WINDOW *w,int x,int y);
  void erase(WINDOW *w,int x,int y);
  void moveBally(WINDOW *win,Raquette &raq);
  void setColors(WINDOW *w,Color c);



};

#endif
