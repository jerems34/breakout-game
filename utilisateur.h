#ifndef UTILISATEUR__H
#define UTILISATEUR__H
#include <iostream>
#include <string>
using namespace std;

class Utilisateur{
private:
  int s, vie;

public:
  string nom;
  Utilisateur(string n, int score, int v);
  Utilisateur(string n, int score);
  Utilisateur(); 
  string getN() const;
  int getS() const;
  int getVie() const;
  void setS(int x);
  void setVie(int v);


};

#endif
