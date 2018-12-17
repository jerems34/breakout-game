#include "utilisateur.h"
#include <string>
using namespace std;


Utilisateur::Utilisateur(string n, int score):nom(n), s(score){

}

string Utilisateur::getN() const{
  return nom;
}

int Utilisateur::getS() const{
  return s;
}

void Utilisateur::setS(int x){
  s=x;
}
