#include "tabBriques.h"
#include "brique.h"
#include "balle.h"
#include <exception>
#include <iostream>
using namespace std;
Tableaubriques::Tableaubriques() : br(), nb_briques(0) {}


void Tableaubriques::addBrique(const Brique &b) {
  if (nb_briques == NMAX) {
   terminate();   
  }
   else {
    br[nb_briques] = b;
    nb_briques++;    
  }
}


void Tableaubriques::print(WINDOW *w){
    for (int i = 0; i < nb_briques; i++) {
    br[i].print(w);
    }
}

// bool Tableaubriques::getCollisionbriqueX(Balle &b){
//   bool collision=false;
//   for(int i=0;i<nb_briques;i++){
//     if(b.getX()==br[i].getX || b.getY()==br[i].getY){
//       collision=true;directiony*=-1;
//     }else directiony*=1;
//   }
//   return collision;
// }
    
  

int Tableaubriques::getBriqueY(int i){
  return br[i].getY();
}
