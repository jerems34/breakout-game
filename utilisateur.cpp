#include "utilisateur.h"
#include <string>
using namespace std;


Utilisateur::Utilisateur(string n, int score, int v):nom(n), s(score), vie(v){

}

Utilisateur::Utilisateur(string n, int score): nom(n), s(score), vie(3){

}

Utilisateur::Utilisateur(): nom(""), s(0), vie(3){}

string Utilisateur::getN() const{
  return nom;
}

int Utilisateur::getS() const{
  return s;
}

int Utilisateur::getVie() const{
  return vie;
}

void Utilisateur::setS(int x){
  s=x;
}

void Utilisateur::setVie(int v){
  vie = v;
}
