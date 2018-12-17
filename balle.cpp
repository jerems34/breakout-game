#include "balle.h"
#include "raquette.h"
#include <string>
#include "window.h"
#include <ncurses.h>
#include <unistd.h>
#include "brique.h"
#define DELAY 60000

Balle::Balle(int _x,int _y,int _velocity,char _b,int _size, int _nbrbale): x(_x),y(_y),velocity(_velocity),b(_b),size(_size), nbrbale(_nbrbale) {}

int Balle::getX()const { return x; }
int Balle::getY()const { return y; }
int Balle::getVelocity()const{ return velocity;}
int Balle::getChB()const { return b;}
int Balle::getNbrballe()const{ return nbrbale; }
int Balle::getDirectionx()const{ return directionx; }
int Balle::getDirectiony()const{ return directiony; }

void Balle::setX(int i){  x=i; }
void Balle::setY(int i){  y=i; }
void Balle::setVelocity(int i) { usleep(i); }
void Balle::setChB(char c){ b=c; }
void Balle::setNbrballe(int b){ nbrbale=b; }
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

void Balle::moveBally(WINDOW *w,Raquette &raq ){
   directiony=-1;
   directionx=-1;
   int next_y, ch, max_y=40, next_x, max_x=58;

   
    while( (ch = getch())!=' ')
    {
     
      erase(w,x,y);
     std::string s(size,b);
     mvwprintw(w,y,x,s.c_str());
     raq.print(w);

      wrefresh(w);
      refresh();
      //MOUVEMENT + RAQUETTE
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
      if(next_y > raq.getY()){
	erase(w,x,y);
        setNbrballe(nbrbale-1);
        x=raq.getX()+6;
        y=raq.getY()-1;
	directiony=0;
	directionx=0;
	ch=' ';
	
      }
      if ((y==raq.getY()) && (x>=raq.getX()+1) && (x<=raq.getX()+raq.getSize()-1)){
	       directiony*=-1;
         	y+=directiony;
      }

      //REBOND SUR LES ANGLES
      if ((y==raq.getY()) && (x>=raq.getX()) && (x<=raq.getX()+2)) {
	       directiony*=-1;
         directionx*-1;
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
      if ((y==raq.getY()) && x>=raq.getX()+6 && x<raq.getX()+7){
        directionx*=1;
        directiony*=-1;
        x+=directionx;
        y+=directiony;
      }


      //BRIQUE
      // int i=0;
      // 	if(y==T.getBriqueY(i)-1 && (x>=T.getBriqueX(i)) && (x<=T.getBriqueX(i))){
      // 	directiony*=-1;
      // 	T[i].print(w);
      //    	y+=directiony;
      // }
      // if(next_x==T.getBriqueX(i) && next_y==T.getBriqueY(i)+7){
      //     directionx*=-1;

      //   }
      //  if (next_x==T.getBriqueX(i) && next_y==T.getBriqueY(i)){
      //  	directionx*=-1;
      //  }
   
      

        switch (ch) {
     case KEY_LEFT:
       
       raq.erase(w);
       if(!(raq.getX()-1<0)){
         raq.setX(raq.getX()-1);
       }
       raq.print(w);
	break;
      case KEY_RIGHT:
	
	     raq.erase(w);
       if(!(raq.getX()+raq.getSize()>60-1)){
        raq.setX(raq.getX()+1);
       }
       raq.print(w);


	break;

	if (next_y>=max_y){
	ch=' ';
      }


    }

  }

  }
