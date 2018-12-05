#include "balle.h"
#include "raquette.h"
#include <string>
#include "window.h"
#include <ncurses.h>
#include <unistd.h>
#include "brique.h"

Balle::Balle(int _x,int _y,int _velocity,char _b,int _size): x(_x),y(_y),velocity(_velocity),b(_b),size(_size) {}

int Balle::getX()const { return x; }
int Balle::getY()const { return y; }
int Balle::getVelocity()const{ return velocity;}
int Balle::getChB()const { return b;}


void Balle::setX(int i){  x=i; }
void Balle::setY(int i){  y=i; }
void Balle::setVelocity(int i) { velocity=i; }
void Balle::setChB(char c){ b=c; }
void Balle::erase(WINDOW *w,int x,int y){
   std::string s(2,' ');
   mvwprintw(w,y+2,x,s.c_str());
  wrefresh(w);
  refresh();
  
     mvwprintw(w,y-2,x,s.c_str());
  wrefresh(w);
  refresh();
 mvwprintw(w,y+1,x,s.c_str());
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
// void Balle::moveBallx(WINDOW *w,Raquette &raq){
int max_x=100;
     int next_x;
//   while(x!=raq.getX() || y!=30){
//     usleep(DELAY);

//     print(w,x,y);
   
    
// next_x =x+direction;
//  if(next_x>= max_x || next_x<0){
//    direction*=-1;
//    erase(w,next_x,y);
//  } else{
//    x+=direction;
//  }

//   }
//    wrefresh(w);
//     refresh();
// }

  
void Balle::moveBally(WINDOW *w,Raquette &raq,Brique &br ){
   int direction=-1;int max_y=35;
   int next_y;int ch;
   br.print(w);
    while( (ch = getch())!=' ')
    {
      erase(w,x,y);
      std::string s(size,b);
      mvwprintw(w,y,x,s.c_str());
      raq.print(w);
    
      wrefresh(w);
      refresh();
      next_y =y+direction;
      if( next_y<0 || next_y>max_y){
	direction*=-1;
      } else{
	y+=direction;
      }
      if ((y==raq.getY()-1) && (x>=raq.getX()) && (x<=raq.getX()+raq.getSize())){
	direction*=-1;
      }else{
	y+=direction;
      }

      
        switch (ch) {
     case KEY_LEFT:
	 
       raq.erase(w);
       if(!(raq.getX()-1<0)){
      // 	 if (31<=y){
      // 	direction*=-1;
      // }else{
      // 	y+=direction;
      // }
	 raq.setX(raq.getX()-1);
	 raq.print(w);
       }
	break;
      case KEY_RIGHT:

	raq.erase(w);
	
	 raq.setX(raq.getX()+1);
	if(!(raq.getX()+raq.getSize()>97)){
      // 	  if (31<=y){
      // 	direction*=-1;
      // }else{
      // 	y+=direction;
      // }
	raq.print(w);
	}
	break;
	
	if (next_y>=max_y){
	ch=' ';
      }

	
    }
  
  }
   
  }
    

