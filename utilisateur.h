#include <iostream>
#include <string>
using namespace std;

class Utilisateur{
private:
  int s;

public:
  string nom;
  Utilisateur(string n, int score);
  string getN() const;
  int getS() const;
  void setS(int x);

};
