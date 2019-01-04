#include "balle.h"
#include "window.h"
#include <string>
#include <ncurses.h>
#include <unistd.h>
#define DELAY 40000

Balle::Balle(int _x,int _y,int _velocity,char _b,int _size): x(_x),y(_y),velocity(_velocity),b(_b),size(_size) {}

int Balle::getX()const { return x; }
int Balle::getY()const { return y; }
int Balle::getVelocity()const{ return velocity;}
int Balle::getChB()const { return b;}
int Balle::getDirectionx()const{ return directionx; }
int Balle::getDirectiony()const{ return directiony; }

void Balle::setX(int i){  x=i; }
void Balle::setY(int i){  y=i; }
void Balle::setVelocity(int i) { usleep(i); }
void Balle::setChB(char c){ b=c; }
void Balle::setDirectionx(int b){ directionx=b; }
void Balle::setDirectiony(int a){ directiony=a;}

void Balle::erase(WINDOW *w,int x,int y){
     std::string s(2,' ');
     mvwprintw(w,y,x,s.c_str());
     wrefresh(w);
     refresh();

     mvwprintw(w,y-1,x,s.c_str());
     wrefresh(w);
     refresh();
     mvwprintw(w,y+1,x,s.c_str());
     wrefresh(w);
     refresh();

     mvwprintw(w,y,x+1,s.c_str());
     wrefresh(w);
     refresh();

     mvwprintw(w,y,x-1,s.c_str());
     wrefresh(w);
     refresh();

     mvwprintw(w,y+1,x-1,s.c_str());
     wrefresh(w);
     refresh();
     mvwprintw(w,y-1,x-1,s.c_str());
     wrefresh(w);
     refresh();


      mvwprintw(w,y+2,x,s.c_str());
     wrefresh(w);
     refresh();
     mvwprintw(w,y-2,x,s.c_str());
     wrefresh(w);
     refresh();

}
void Balle::print(WINDOW *w,int x,int y){

 std::string s(size,b);
  wattron(w,A_BOLD);
  mvwprintw(w,y,x,s.c_str());
  wattroff(w,A_BOLD);
  wrefresh(w);
  refresh();
}

int Balle::moveBally(WINDOW *w,Raquette &raq,Tableaubriques T,Utilisateur &pseudo){
   directiony=-1;//on initialise les direction à -1 déjà
   directionx=-1;
   int next_y, ch,  max_y, next_x, max_x;//next_y sert a savoir quelle sera le prochain x et y, et max_y/x c'est la hauteur max de la zone de jeux
   getmaxyx(w,max_y,max_x);

    while( (ch = getch())!='p')
    {
      usleep(DELAY);
      erase(w,x,y);
     std::string s(size,b);
     mvwprintw(w,y,x,s.c_str());
     raq.print(w);

      wrefresh(w);
      refresh();


      //MOUVEMENT
      next_x =x+directionx;
      next_y =y+directiony;
      if(next_y<0){
           directiony*=-1;
        }else{
          x+=directionx;
          y+=directiony;
          wrefresh(w);
      	  refresh();
        }
      if(next_x<0){
          directionx*=-1;


        }
      if(next_x>max_x){
        directionx*=-1;
      }
      if(next_y > raq.getY()+2){
        erase(w,x, y);
        x=raq.getX()+6;
        y=raq.getY()-1;
        pseudo.setVie(pseudo.getVie()-1);
        return -1;
        ch = ' ';


      }

      //REBOND RAQUETTE
      if ((y==raq.getY()) && (x>raq.getX()+2) && (x<=raq.getX()+4)) {
	       directiony*=-1;
         	y+=directiony;
      }
      if ((y==raq.getY()) && (x>raq.getX()+6) && (x<=raq.getX()+raq.getSize()-2)){
	       directiony*=-1;
         	y+=directiony;
      }



      //REBOND SUR LES ANGLES
      if ((y==raq.getY()) && (x>=raq.getX()) && (x<=raq.getX()+2)) {
	       directiony*=-1;
         directionx*=-1;
         	y+=directiony;
          x+=directionx;
      }
      if ((y==raq.getY()) && (x>=raq.getX()+raq.getSize()-2) && (x<=raq.getX()+raq.getSize())){
	       directiony*=-1;
         directionx*=-1;
         x+=directionx;
         	y+=directiony;
      }

      //REBOND SUR LE MILIEUX
      if ((y==raq.getY()) && x>raq.getX()+4 && x<raq.getX()+6){
        directionx*=0;
        directiony*=-1;
        y+=directiony;

      }

      //REBOND SUR LES BRIQUES
      for (int i = 0; i < T.getNbrbrique(); i++) {
        if(y==T.getBriqueY(i) && (x>=T.getBriqueX(i)) && (x<=T.getBriqueX(i)+9)){
          pseudo.setS(pseudo.getS()+1);
          T.briqueerase(i, w, T.getBriqueX(i), T.getBriqueY(i), ' ');
        	directiony*=-1;
           	y+=directiony;
            T.supbrique(i);
            T.setNbbrique(T.getNbrbrique()-1);

        }
        if(next_x==T.getBriqueX(i)+9 && next_y==T.getBriqueY(i)+7){
          pseudo.setS(pseudo.getS()+1);
          T.briqueerase(i, w, T.getBriqueX(i), T.getBriqueY(i), ' ');

            directionx*=-1;
            T.supbrique(i);
            T.setNbbrique(T.getNbrbrique()-1);

          }
         if (next_x==T.getBriqueX(i) && next_y==T.getBriqueY(i)){
           pseudo.setS(pseudo.getS()+1);
           T.briqueerase(i, w, T.getBriqueX(i), T.getBriqueY(i), ' ');

         	directionx*=-1;
          T.supbrique(i);
          T.setNbbrique(T.getNbrbrique()-1);
         }

      }

      raq.movRaq(w);
      if(T.getNbrbrique()==0){
        return 1;
      }
  }
  return -1;


  }
