#ifndef __TABBRIQUES__H
#define __TABBRIQUES__H
#include "brique.h"
#define NMAX 20
class Tableaubriques {
private:
  Brique br[NMAX];
  int   nb_briques;


 public:

  Tableaubriques();
  void print(WINDOW *w);
  void print2(int i, WINDOW *w, int x, int y, char c);
  void addBrique(const Brique &b);
  int getBriqueY(int);
  int getBriqueX(int);
  int getNbrbrique();
  void setNbbrique(int);
  void briqueerase(int i, WINDOW *w, int x, int y, char c);
  void supbrique(int i);
  void setBriqueY(int i, int x);


};


#endif
