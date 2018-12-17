#include "window.h"
#include "raquette.h"
#include "balle.h"
#include "brique.h"
#include "utilisateur.h"
#include "tabBriques.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;


void myprogram(string n, int sc, string niveau){ //fonction pour les levels
  fstream f("fichier.txt", ios::out|ios::in|ios::app); //j'ouvre le fichier pour mettrre dedans le score
  f<<"pseudo : "<<n<<'\n';

  int ch, touche, nbrvie=3;
  int dir=1;
  Color c=BWHITE;
  int h=40,w=60;
  string Level = niveau;


  Utilisateur pseudo(n, sc); //je créé la classe utilisateur pour ranger les info tel que nom et setCouleurBordure
  Window quitter(40,30,115,6);//pour quitter la fenetre
  Window level(3, 10, 30, 1);
  Window utilisateur(3, 30, 115,9); //création de l'utilisateur dans le level
  Window score(3,30,115,11);//création du score dans le level
  Window plateau(45,100,0,0); //affichage de la base du niveau
  Window vie(3, 30, 115, 13);
  Balle ball(h/2,w-3,0,'O',1, nbrvie);
  Raquette raq(w/2,h-5,9,' ');
  Brique br(10,10,7,' ');
  Brique br1(40,10,7,' ');
  Brique br2(40,20,7,' ');
  Brique br3(10,20,7,' ');
  Brique br4(40,30,7,' ');
  Brique br5(10,30,7,' ');
  Brique br6(25,30,7,' ');
  Tableaubriques T;
  quitter.setCouleurBordure(BWHITE); //couleur de la bordure du bouton quitter
  plateau.setCouleurBordure(BWHITE);//bordure de la zone de jeu
  level.setCouleurBordure(WBLACK);
  plateau.setCouleurFenetre(WBLACK);
  raq.print(plateau.getwin());
  T.addBrique(br);
  T.addBrique(br1);
  T.addBrique(br2);
  T.addBrique(br3);
  T.addBrique(br4);
  T.addBrique(br5);
  T.addBrique(br6);
  T.print(plateau.getwin());
  string s = pseudo.getN(); //on range dans la variable s le nom de l'utilisateur


  quitter.print(1,1,"Tapez q pour quitter", BWHITE); //on affiche
  utilisateur.print(0,0, s, BWHITE);//on affiche l'utilisateur
  score.print(0,0,sc , BWHITE);//on affiche le score
  vie.print(0,0, ball.getNbrballe()+48, BWHITE);
  level.print(1,1, Level, BWHITE);
//  br.print(plateau.getwin());
  // br1.print(plateau.getwin());
  ball.setX(raq.getX()+2.5);
  ball.setY(raq.getY()-1);
  ball.print(plateau.getwin(),ball.getX(),ball.getY());
  

  while((ch = getch()) != 'q') //tant que l'utilisateur n'a pas appuyé sur q on joue
    {
      switch (ch) {
      case 's': //cas ou l'utilisateur voudrait sauvegarder sont contenue
      f<<"score : "<<sc<<'\n';
      f<<"niveau : "<<Level<<'\n';
      f<<"_____________"<<'\n';
      f.close(); //on ferme le fichier
      stopProgramX(); //on quitte le jeux
      return;
      break;

      case ' ':
	//	T.getCollisonbriqueX(ball);
	ball.moveBally(plateau.getwin(),raq);
          break;


      case KEY_LEFT:
      
      raq.erase(plateau.getwin());
      ball.erase(plateau.getwin(), ball.getX(), ball.getY());
      if(!(raq.getX()-1<0)){
        raq.setX(raq.getX()-1);
        ball.setX(ball.getX()-1);
      }
      raq.print(plateau.getwin());
      ball.print(plateau.getwin(),ball.getX(), ball.getY());
      sc+=1;//on incrémente le score
      score.print(0,0, sc + 48, BWHITE);//on update le score dans la case
    	    break;

      case KEY_RIGHT:
      raq.erase(plateau.getwin());
      ball.erase(plateau.getwin(), ball.getX(), ball.getY());
    	if(!(raq.getX()+raq.getSize()>165)){
        raq.setX(raq.getX()+1);
        ball.setX(raq.getX()+1);
      }
    	raq.print(plateau.getwin());
      ball.print(plateau.getwin(),ball.getX(), ball.getY());
    	    break;

   
      }
     }
 
    f<<"score = "<<sc<<'\n'; //à la fon du niveau on rentre le score dans le fichier
    f<<"level = "<<Level<<'\n';
    f<<"_____________"<<'\n';
    f.close(); //fermeture du fichier
    if(ch == 'q'){
 
      stopProgramX();
    }

}

void menu(string N){ //le menu du jeux
  int yMax,xMax;
  getmaxyx(stdscr,yMax,xMax);
  WINDOW* menu= newwin(5,xMax-12,yMax-8,5);
  Window titre(8,xMax,yMax,8);

  box(menu,0,0);
  refresh();
  wrefresh(menu);
  keypad(menu,true);
  string choices[3]={"1.Lancer une nouvelle partie","2.Charger une partie","3.Quitter le jeu"};
  int choice;
  int highlight =0;
  string titre1="BREAKOUT";
  titre.print(1,0,"\t  :::::::::  :::::::::  ::::::::::     :::     :::    ::: ::::::::  :::    ::: :::::::::::\n",BWHITE);
  titre.print(1,1,"\t  :+:    :+: :+:    :+: :+:          :+: :+:   :+:   :+: :+:    :+: :+:    :+:     :+:\n",BWHITE);     
  titre.print(1,2,"\t  +:+    +:+ +:+    +:+ +:+         +:+   +:+  +:+  +:+  +:+    +:+ +:+    +:+     +:+\n" ,BWHITE);    
  titre.print(1,3,"\t  +#++:++#+  +#++:++#:  +#++:++#   +#++:++#++: +#++:++   +#+    +:+ +#+    +:+     +#+\n" ,BWHITE);    
  titre.print(1,4,"\t  +#+    +#+ +#+    +#+ +#+        +#+     +#+ +#+  +#+  +#+    +#+ +#+    +#+     +#+\n" ,BWHITE);
  titre.print(1,5,"\t  #+#    #+# #+#    #+# #+#        #+#     #+# #+#   #+# #+#    #+# #+#    #+#     #+#\n" ,BWHITE);    
  titre.print(1,6,"\t  #########  ###    ### ########## ###     ### ###    ### ########   ########      ### \n\n",BWHITE);                                                              
            
	      
 
   fstream f("fichier.txt", ios::out|ios::in|ios::app);
    string Nom;//string qui va contenir chaque ligne du fichier
   int i=0;
   bool b=true;
   string nom = N;//string qui ne contient que le pseudo;
   string res = "pseudo : "; //je créer un string
   res.append(N); //auqeulle j'ajoute le nom d'utilisateur pour avoir sont score si il existe déjà
   int length;
   string sc;
       
       
  while(choice!=3) //tant que l'utilisateur ne quite pas la partie
    {
      for(int i=0;i<3;i++){
	if(i==highlight)
	  wattron(menu,A_REVERSE);
	mvwprintw(menu,i+1,1,choices[i].c_str());
	wattroff(menu,A_REVERSE);
      }
       choice=wgetch(menu);
      
      switch (choice) {
        case KEY_UP: //cas ou l'utiliszteur charge une nouvelle partie
	  highlight--;
	  if(highlight==-1){
	    highlight=0;
	  }
        break;
      case KEY_DOWN:
	highlight++;
	if(highlight==3){
	  highlight=2;
	}
	break;
      case '\n':
	if(highlight==0){
	  clear();
	   myprogram(N, 0, "level 1");
	}
	if(highlight==1){
	  fstream f1("fichier.txt", ios::out|ios::in|ios::app); //on ouvre le fichier text
        while(getline(f1,Nom) && b){ //je prend tout les lignes et un bool pour areter quand on a trouvé
          if(Nom == res){ //si il existe affiche le score
            length = f1.tellp();
            b=false;
          }
        }

        if(b){
	  choice=1;

        }else{
          f1.seekg(length+8);
          getline(f1, sc);
          int f = atoi(sc.c_str() );
       
          myprogram(nom, f, "level 2");
          f1.close();
        }
      }
	if(highlight==2){
	  
	  choice=3;
      
    }
}
      
    }
    }
int main(){
  fstream f("fichier.txt", ios::out|ios::in|ios::app); //j'ouvre une première fois le fichier pour mettrre dedans le nom d'utilisateur
  string n;
  if(f.is_open()){

    int length;
    std::cout << "rentrer un nom d'utilisateur" << '\n';
    std::cin >> n;
;
  }

  startProgramX();
  menu(n);
  stopProgramX();
  f.close();

  return 0;
}
