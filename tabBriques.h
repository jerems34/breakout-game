#ifndef __TABBRIQUES__H
#define __TABBRIQUES__H
#include "brique.h"
#include "balle.h"
#define NMAX 20
class Tableaubriques {
private:
  Brique br[NMAX];
  int   nb_briques;
  

 public:

  Tableaubriques();
 void print(WINDOW *w);
  void addBrique(const Brique &b);
  // bool getCollisonbriqueX( Balle &b);
int getBriqueY(int);


};










#endif
