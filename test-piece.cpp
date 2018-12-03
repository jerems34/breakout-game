#include "window.h"
#include "raquette.h"
#include "balle.h"
#include "brique.h"
#include <stdlib.h>
#include <unistd.h>
#define DELAY 3000
void myprogram(){
  int dir=1;
  int ch;Color c=WRED;
  int h=35,w=100;
  Window menu(3,30,1,0);
  Window plateau(h,w,1,6);

    Balle ball(h/2,w-3,0,'O',1);
   Raquette raq(w/2,h-5,8,' ');
   Brique br(10,10,7,' ');
      raq.print(plateau.getwin());
      menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  menu.print(1,1,"Tapez q pour quitter !!!",WRED);
  //  while (br.getX()!=w && br.getY()!=20){
    
    
      // }
      br.print(plateau.getwin());
     ball.setX(raq.getX()+2.5);
     ball.setY(raq.getY()-1);
    ball.print(plateau.getwin(),ball.getX(),ball.getY());
  
  
  

    while( (ch = getch())!='q')
    {
      
      switch (ch) {
      case '1':
      	c=BMAGENTA;
	raq.setColors(plateau.getwin(),c);
      	break;
      case '2':
      	c=WCYAN;
	raq.setColors(plateau.getwin(),c);
      	break;
      case 'c':
	raq.erase(plateau.getwin());
	break;
	
      case ' ':
	  usleep(DELAY);
	   ball.moveBally(plateau.getwin(),raq,br);	   
     
	break;
      case KEY_LEFT:
	 
	raq.erase(plateau.getwin());
	if(!(raq.getX()-1<0))
	  raq.setX(raq.getX()-1);
	raq.print(plateau.getwin());
    	
	break;
      case KEY_RIGHT:

	raq.erase(plateau.getwin());
	if(!(raq.getX()+raq.getSize()>w-1))
	  raq.setX(raq.getX()+1);
	raq.print(plateau.getwin());
	
	break;
      
      }
    }

}     

int main(){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
