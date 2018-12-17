#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main(){
  fstream f("fichier.txt", ios::app|ios::out|ios::in); //j'ouvre une première fois le fichier pour mettrre dedans le nom d'utilisateur
  if(f.is_open()){
    string n;
    int length;
    std::cout << "rentrer un nom d'utilisateur" << '\n';
    std::cin >> n;

    string Nom;
    int score;
    int i=0;
    bool b = true;
    string res = "pseudo = "; //je créer un string
    res.append(n);//auqeulle j'ajoute le nom d'utilisateur pour avoir sont score si il existe déjà

    while(getline(f, Nom) && b){ //je prend tout les lignes et un bool pour areter quand on a trouvé
      i++;
      if(Nom == res){ //si il existe affiche le score
        length = f.tellp();
        b=false;
      }
    }

    if(b){
      std::cout << "création utilisateur" << '\n';
      f<<res<<'\n';
    }else{
      std::cout << "utilisateur déja existant" << '\n';
      f.seekg(length+8);
      getline(f, Nom);
      std::cout << "score  = "<< Nom << '\n';
    }
  }
  f.close();


  return 0;

}
