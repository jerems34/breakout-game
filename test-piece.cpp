#include "window.h"
#include "raquette.h"
#include "balle.h"
#include "brique.h"
#include "utilisateur.h"
#include "tabBriques.h"
#include "message.h"
#include "Bscore.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

void myprogram(string n, int sc, string niveau){ //fonction pour les levels
  fstream f("fichier.txt", ios::out|ios::in|ios::app); //j'ouvre le fichier pour mettrre dedans les données de l'utili
  fstream brq(niveau,ios::out|ios::in|ios::app);//pour avoir le fichier du niveau
  //fstream BestScore("score.txt",ios::out|ios::in|ios::app);

  int h,w;
  
  getmaxyx(stdscr,w,h);
  int ch, touche, dir=1, cha;
  
  Color c=BWHITE;
  int br0 =0;
  //hauteur et largeur de la fenetre de jeux
  string Level = niveau; //on range dans la variable Level le niveau
  Tableaubriques T; //tableau ou on va ranger toutes les briques
  // Bscore T1;

  Utilisateur pseudo(n, sc, 3); //je créé la classe utilisateur pour ranger les info tel que nom et setCouleurBordure
  string s = pseudo.getN(); //on dépose le pseudo dans un string
  //création des objets message ou window :
  Window zoneM(w-12,30,h-40,6);
  Message quitter(0,0);
  Message level(30, 0);
  Message utilisateur(71,9);
  Message score(71,11);
  Window plateau(w-6,h-70,0,2);
  Message vie(71, 13);
  Message pause(71,15);
  Message bsc(71, 18);

  // string Bests; int length1; int zz = 0;
  // while(getline(BestScore, Bests)){
  //   // length1 = BestScore.tellp();
  //   // BestScore.seekg(length1);
  //   Utilisateur pseudo1(Bests, 0);
  //   // T1.addScore(pseudo1, zz);
  //   // zz++;
  // }
  // BestScore.close();


  Balle ball(0,0,0,'O',1); //la Balle
  Raquette raq((h-70)/2,w-9,14,' ');// la raquette

  //création de l'objet brique
  string no; int i=0; int length;
  while(getline(brq, no)){
    int x = atoi(no.c_str());
    Brique br(x,0, 7, ' ');
    T.addBrique(br);
    length = brq.tellp();
    brq.seekg(length);
    getline(brq,no);
    int y = atoi(no.c_str());
    T.setBriqueY(i, y);
    length = brq.tellp();
    brq.seekg(length);
  }
  brq.close();


  zoneM.setCouleurBordure(BWHITE); //couleur de la bordure du bouton quitter
  plateau.setCouleurBordure(BWHITE);//bordure de la zone de jeu
  plateau.setCouleurFenetre(WBLACK); //couleur de la fenetre

  //on affiche tous les objets avec les méthodes print de chaque objet
  raq.print(plateau.getwin());
  T.print(plateau.getwin());
  quitter.print(zoneM.getwin(), 1,10,"Tapez q pour quitter",  WBLACK);
  utilisateur.print(zoneM.getwin(),1,2, pseudo.getN(),  WBLACK);
  score.print(zoneM.getwin(),1,4,sc, WBLACK);
  vie.print(zoneM.getwin(), 1,6, pseudo.getVie(), WBLACK);
  level.print(zoneM.getwin(),1,8, Level,  WBLACK);
  pause.print(zoneM.getwin(), 1,12,"Tapez p pour pause",WBLACK );
  //string top5;
  // for (size_t k = 0; k < 5; k++) {
  //   /* code */
  //   top5="2 :";
  //   top5.append(T1.getNom(k));
  //   top5.append(" = ");
  //   string str = to_string(T1.getScore(k));
  //   top5.append( str);
  //   //top5.append(T1.getScore(k));
  //   bsc.print(zoneM.getwin(), 1,14+k, top5, BWHITE);
  //
  // }

  ball.setX(raq.getX()+2.5);//on defini les coordonées de la balle
  ball.setY(raq.getY()-1);
  ball.print(plateau.getwin(),ball.getX(),ball.getY()); //ensuite on affiche la balle après avoir defini les coordonnées

  while((ch = getch()) != 'q') //tant que l'utilisateur n'a pas appuyé sur q on joue
    {
      switch (ch) {
      case 's': //cas ou l'utilisateur voudrait sauvegarder sont contenue
      //on enregistre donc sont pseudo, sont score, le niveau où il se trouve et le nombre de vie
      f<<"pseudo : "<<n<<'\n';
      f<<"score = "<<pseudo.getS()<<'\n';
      f<<"niveau : "<<Level<<'\n';
      f<<"vie = "<<pseudo.getVie()<<'\n';
      f<<"_____________"<<'\n';
      f.close(); //on ferme le fichier
      stopProgramX(); //on quitte le jeux
      return;

      break;

      case ' ': //cas où le joueur lance la balle
      br0=0;
       while(br0==0 && pseudo.getVie()>0){
         br0 = ball.moveBally(plateau.getwin(),raq, T, pseudo);//la balle se met en mouvement
         //à chaque fois que la balle sort du terrain on rafrachi les score et la vie
         score.setMessage(pseudo.getS());
         vie.setMessage(pseudo.getVie());
         score.print(zoneM.getwin(), 1, 4, pseudo.getS(), WBLACK);
         vie.print(zoneM.getwin(), 1, 6, pseudo.getVie(), WBLACK);
       }
       if(pseudo.getVie()==0){
         //si le nombre de vie est égal à  on efface tout ce qui se trouve dans le plateau et sur la zoneM et on affiche un message disant que nous avons perdu
         plateau.clear();
         zoneM.clear();
	 wclear(stdscr);
         stopProgramX();
         Message vie0(0,0);
         vie0.print(plateau.getwin(), 1,12, "GAME OVER\n, tapez sur 'q' pour quitter", WBLACK);
         break;
       }
       if(br0==1){
         //Si la fonction de mouvement de la balle renvoi 1 alors on passe au prochain niveau
         ball.erase(plateau.getwin(), ball.getX(), ball.getY());
         br0=0;
         Level = "level_2";
         ball.setX(h/2);
         ball.setY(w-3);
         ball.print(plateau.getwin(),ball.getX(),ball.getY());
         for (int i = 0; i < 3; i++) { //on supprime les brique actuel du tableau
           T.supbrique(i);
         }
         //on ouvre le fichier de configuration du niveau 2 et on affiche les briques
         fstream bbbrq("level_2",ios::out|ios::in|ios::app);
         string no; int i=0; int length;
         while(getline(bbbrq, no)){
           int x = atoi(no.c_str());
           Brique br(x,0, 7, ' ');
           T.addBrique(br);
           length = bbbrq.tellp();
           bbbrq.seekg(length);
           getline(bbbrq,no);
           int y = atoi(no.c_str());
           T.setBriqueY(i, y);
           length = bbbrq.tellp();
           bbbrq.seekg(length);
         }

         T.print(plateau.getwin()); // on affiche les briques dans le plateau
         break;
       }
       if(br0==-1){

         break;
       }
      break;

      case KEY_LEFT: //quand le joueur n'a pas encore lancé la balle mouvement à gauche
      raq.erase(plateau.getwin()); //on efface d'abord la raquette et la balle
      ball.erase(plateau.getwin(), ball.getX(), ball.getY());
      if((raq.getX()>0)){ //on change leur coordonnées pour qu'ils aillent à gauche
        raq.setX(raq.getX()-2);
        ball.setX(ball.getX()-2);
      }
      raq.print(plateau.getwin());//on les affiche après avoir changé les coordonnes
      ball.print(plateau.getwin(),ball.getX(), ball.getY());
    	    break;

      case KEY_RIGHT: //même choses que pour la gauche mais à droite
      raq.erase(plateau.getwin());
      ball.erase(plateau.getwin(), ball.getX(), ball.getY());
    	if((raq.getX()+raq.getSize()<h-75)){
        raq.setX(raq.getX()+2);
        ball.setX(raq.getX()+2);
      }
    	raq.print(plateau.getwin());
      ball.print(plateau.getwin(),ball.getX(), ball.getY());
    	    break;

      }
      
    }
    f.close(); //fermeture du fichier
     wclear(stdscr);
    
}

void menu(string N){ //le menu du jeux
  int yMax,xMax;
  string level;
  getmaxyx(stdscr,yMax,xMax);
  WINDOW* menu= newwin(6,xMax-12,yMax-25,1); //affiche les bares de selections
  Window titre(8,xMax,yMax,8); //on crée le class pour le titre
  Window version(3, 30, xMax-15, yMax-2);
  
  box(menu,0,0);
  refresh();
  wrefresh(menu);
  keypad(menu,true);
  string choices[4]={"1.Lancer une nouvelle partie","2.Charger une partie","3.Quitter le jeu", "4.Aide"};
  int choice;
  int highlight =0;
  string titre1="BREAKOUT";
  titre.print(1,0,"\t  :::::::::  :::::::::  ::::::::::     :::     :::    ::: ::::::::  :::    ::: :::::::::::\n",WBLACK);
  titre.print(1,1,"\t  :+:    :+: :+:    :+: :+:          :+: :+:   :+:   :+: :+:    :+: :+:    :+:     :+:    \n",WBLACK);
  titre.print(1,2,"\t  +:+    +:+ +:+    +:+ +:+         +:+   +:+  +:+  +:+  +:+    +:+ +:+    +:+     +:+    \n" ,WBLACK);
  titre.print(1,3,"\t  +#++:++#+  +#++:++#:  +#++:++#   +#++:++#++: +#++:++   +#+    +:+ +#+    +:+     +#+    \n" ,WBLACK);
  titre.print(1,4,"\t  +#+    +#+ +#+    +#+ +#+        +#+     +#+ +#+  +#+  +#+    +#+ +#+    +#+     +#+    \n" ,WBLACK);
  titre.print(1,5,"\t  #+#    #+# #+#    #+# #+#        #+#     #+# #+#   #+# #+#    #+# #+#    #+#     #+#    \n" ,WBLACK);
  titre.print(1,6,"\t  #########  ###    ### ########## ###     ### ###    ### ########   ########      ###    \n\n",WBLACK);
  version.print(0,0, "Version BV3",WBLACK);



   fstream f("fichier.txt", ios::out|ios::in|ios::app);

   int i=0, length;
   bool b=true;
   string nom = N, res = "pseudo : ", sc, Nom;
   res.append(N); //auqeulle j'ajoute le nom d'utilisateur pour avoir sont score si il existe déjà



  while(choice!=4) //tant que l'utilisateur ne quite pas la partie
    {
      for(int i=0;i<4;i++){
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
	if(highlight==4){
	  highlight=3;
	}
	break;
      case '\n':
	if(highlight==0){//si l'utilisateur choisi de commencer une nouvelle partie
	   clear();
	   myprogram(N, 0, "level_1");
	}
	if(highlight==1){//si l'utilisateur decide de charger une partie
    clear();
	  fstream f1("fichier.txt", ios::out|ios::in|ios::app); //on ouvre le fichier text
        while(getline(f1,Nom) && b){ //je prend tout les lignes et un bool pour areter quand on a trouvé
          if(Nom == res){ //si il existe affiche le score
            length = f1.tellp();//on recupére l'endroit où nous sommes
            b=false;
          }
        }

        if(b){//si on à pas trouvé d'utilisateur on commence une nouvelle partie
	  highlight=0;

  }else{//sinon on charge les donnéez
          f1.seekg(length+8); //on se postione pour récupérer le score
          getline(f1, sc);//on récupère le score dans un string
          int f = atoi(sc.c_str() );//on converti le string en int
          f1.seekg(length+18);//on récupère le Level où était le joueur
          getline(f1,level);//on le met dans un string
          myprogram(nom, f, level);//et on lance le programme
          f1.close();
        }
      }
	if(highlight==2){

	  choice=4;

    }

    if(highlight == 3){
      choice=4;
    }
}

    }

    }


int main(){

  string n;
  std::cout << "rentrer un nom d'utilisateur" << '\n';
  std::cin >> n;


  startProgramX();
  menu(n);
  stopProgramX();

  return 0;
}
