#include "utilisateur.h"


class Bscore{
private:
  Utilisateur T[5];

public:
  Bscore();
  Utilisateur getI(int i)const;
  void addScore(const Utilisateur &p, int i);
  string getNom(int i)const;
  int getScore(int i)const;



};
