#include "tabBriques.h"
#include "brique.h"
#include <iostream>
using namespace std;
Tableaubriques::Tableaubriques() : br(), nb_briques(0) {}


void Tableaubriques::addBrique(const Brique &b) {
  if(nb_briques != NMAX){
    br[nb_briques]=b;
    nb_briques++;
  }
}

void Tableaubriques::print(WINDOW *w){
    for (int i = 0; i < nb_briques; i++) {
      br[i].print(w, br[i].getX(), br[i].getY(), ' ');
    }
}

void Tableaubriques::print2(int i, WINDOW *w, int x, int y, char c){
  br[i].print(w, br[i].getX(), br[i].getY(), ' ');

}

void Tableaubriques::setBriqueY(int i, int x){
  br[i].setY(x);
}

int Tableaubriques::getBriqueY(int i){
  return br[i].getY();
}

int Tableaubriques::getBriqueX(int i){
  return br[i].getX();
}

int Tableaubriques::getNbrbrique(){
  return nb_briques;
}

void Tableaubriques::setNbbrique(int i){
  nb_briques=i;
}

void Tableaubriques::briqueerase(int i, WINDOW *w, int x, int y, char c){
  br[i].erase(w, x, y, c);
}

void Tableaubriques::supbrique(int i){
  br[i].setX(12);
  br[i].setY(0);
}
