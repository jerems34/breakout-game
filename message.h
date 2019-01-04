#include "window.h"
#include <string>
using namespace std;

class Message{
private:
  int x, y;
  string mes;
  Color col;

public:
  Message(int x, int y);
  int getx()const;
  int getY()const;
  string getMessage()const;

  void setX(int a);
  void setY(int b);
  void setMessage(string m);
  void setMessage(int m);
  void print(WINDOW *w, int x, int y, string s, Color c);
  void print(WINDOW *w, int x, int y, int nbr, Color c);
  void print(WINDOW *w, int x, int y, char s, Color c);
};
