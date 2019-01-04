#include "Bscore.h"
#include "utilisateur.h"

Bscore::Bscore(): T(){
}

Utilisateur Bscore::getI(int i)const{
  return T[i];
}

void Bscore::addScore(const Utilisateur &p, int i){
  T[i]= p;
}

string Bscore::getNom(int i)const{
  return T[i].getN();
}

int Bscore::getScore(int i)const{
  return T[i].getS();
}
