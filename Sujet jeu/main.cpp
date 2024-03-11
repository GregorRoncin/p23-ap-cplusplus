#include <iostream>
#include <vector>
#include <memory> //pour pouvoir utiliser shared_ptr
#include <string>
#include <fstream>

#include "internals.h"
#include "display.h"
#include "perso.h"


auto creer_personnage(const std::string& name, std::string classe,  std::shared_ptr<Arme> arme){
    std::shared_ptr<Personnage> perso;
    if (classe == "Chevalier"){
        perso = std::make_shared<Chevalier>(name, arme);
    }  
    else if (classe == "Mage"){
        perso = std::make_shared<Mage>(name, arme);
    }
    else if (classe == "Archer"){
        perso = std::make_shared<Archer>(name, arme);
    }
    else if (classe == "Assassin"){
        perso = std::make_shared<Assassin>(name, arme);
    }
    else if (classe == "Barbare"){
        perso = std::make_shared<Barbare>(name, arme);
    }
    else 
    {
        throw "Erreur : personnage non reconnu";
    }
    perso->print_info();
    return perso;
};

auto get_arme(const std::string& name){
    std::shared_ptr<Arme> arme;
    if (name == "Epee"){
        arme = std::make_shared<Epee>();
    }
    else if (name == "Hache"){
        arme = std::make_shared<Hache>();
    }
    else if (name == "Masse"){
        arme = std::make_shared<Masse>();
    }
    else if (name == "Arc"){
        arme = std::make_shared<Arc>();
    }
    else if (name == "Baton"){
        arme = std::make_shared<Baton>();
    }
    else if (name == "Sceptre"){
        arme = std::make_shared<Sceptre>();
    }
    else 
    {
        throw "Erreur : arme non reconnue";
    }
    arme->print_info();
    return arme;
};


int next_place(int piece_actuelle){
    std::cout << "Où souhaitez vous aller (D : Droite, G : Gauche, R: Revenir à la pièce précédente)" << std::endl;
    std::string diection;
    std::getline(std::cin, diection);
    if (diection == "D"){
        piece_actuelle = 2 * piece_actuelle ;
    }
    else if (diection == "G"){
        piece_actuelle = 2 * piece_actuelle + 1;
    }
    else if (diection == "R"){
        piece_actuelle = piece_actuelle / 2;
    }
    else 
    {
        throw "Erreur : piece non reconnue";
    }
    return piece_actuelle;
}




void startGame(const int &lap) 
{
    char key;
    std::cout<<"Donner le nom de votre personnage : "<<std::endl;
    std::string name;
    std::getline(std::cin, name);
    std::cout<<std::endl;
    std::cout<<"Donner la classe de votre personnage (parmis Chevalier, Mage, Archer, Assassin, Barbare): ";
    std::string classe;
    std::getline(std::cin, classe);
    // std::cout<<"Donner l'arme dont vous voulez équiper votre personnage (parmis Epee, Hache, Arc, Masse, Baton, Sceptre)"<<std::endl; 
    // std::string arme;
    // std::getline(std::cin, arme);
    // std::shared_ptr<Arme> arme_equipee = get_arme(arme);
    std::shared_ptr<Arme> arme_de_base;
    arme_de_base = std::make_shared<Poing>();
    std::shared_ptr<Personnage> perso = creer_personnage(name, classe, arme_de_base);

    std::vector piece_chateau = {0,1,2,3,4,5,6,7,8,9,10};
    int nb_piece_chateau = piece_chateau.size();
    int piece_actuelle = 0;

    std::cout << "Vous êtes dans un chateau, voici les différentes quêtes que vous devez compléter" << std::endl;
    std::cout << std::endl;
    std::shared_ptr<Quete> quete_principale = std::make_shared<Quete>("Trouver la sortie", "Vous devez trouver la sortie du chateau", 1, 0);
    quete_principale->print_info();
    std::shared_ptr<Quete> quete_secondaire_1 = std::make_shared<Quete>("Trouver l'arme", "Vous devez trouver l'arme de votre personnage", 1, 0);
    quete_secondaire_1->print_info();
    std::shared_ptr<Quete> quete_secondaire_2 = std::make_shared<Quete>("Tuer 5 monstres", "Vous devez tuer 5 monstres", 5, 0);
    quete_secondaire_2->print_info();
    std::shared_ptr<Quete> quete_secondaire_3 = std::make_shared<Quete>("Visite du chateau", "Vous devez visiter 10 pieces du chateau", 10, 0);
    quete_secondaire_3->print_info();



}

int main(){

    const int lap = 1000;

    startGame(lap);
    return 0; //end of the game
}