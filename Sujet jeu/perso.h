#include <iostream>
#include <string>
#include <vector>

class Arme{

public :
    std::string name_;
    int degats_;
    int portee_;
    int niveau_;
    Arme(const std::string& name, int degats, int portee, int niveau):name_(name), degats_(degats), portee_(portee), niveau_(niveau){};
    void print_info(){
        std::cout << "Arme : " << name_ << std::endl;
        std::cout<< "Degats : " << degats_ << std::endl;
        std::cout<< "Portée : " << portee_ << std::endl;
        std::cout<<std::endl;
    }

};

class Epee : public Arme{
    public :
    Epee():Arme("Epee", 35, 1, 1){}
};

class Hache : public Arme{
    public :
    Hache():Arme("Hache", 30, 2, 1){}
};

class Arc : public Arme{
    public :
    Arc():Arme("Arc", 20, 5, 1){}
};

class Masse : public Arme{
    public :
    Masse():Arme("Masse", 25, 10, 1){}
};

class Baton : public Arme{
    public:
    Baton():Arme("Baton", 10, 1, 1){}
};
 
class Sceptre : public Arme{
    public :
    Sceptre():Arme("Sceptre", 20, 20, 1){}
};

class Poing : public Arme{
    public :
    Poing():Arme("Poing", 5, 1, 1){}
};





class Personnage 
{
    std::string name_;
    std::shared_ptr<Arme> arme_{nullptr};
    int vie_;
    int defense_;
    int force_;
    int agilite_;
    int level_;
    int experience_;


public:
    Personnage(const std::string& name, std::shared_ptr<Arme> arme, int pv, int defense, int force, int agilite, int level, int experience):
         name_{name}, arme_{arme}, vie_{pv}, defense_{defense}, force_{force}, agilite_{agilite}, level_{level}, experience_{experience}{};
    void print_info(){
        std::cout << "Name : " << name_ << std::endl;
        std::cout << "Arme : " << arme_->name_<< std::endl;
        std::cout << "PV : " << vie_ << std::endl;
        std::cout << "Defense : " << defense_ << std::endl;
        std::cout << "Force : " << force_ << std::endl;
        std::cout << "Agilite : " << agilite_ << std::endl;
        std::cout << std::endl;
    };
    void update_lvl(){
        if ((experience_>= 100) and (level_ == 1)){
            level_++;
            experience_ = 0;
        }
        else if ((experience_>= 200) and (level_ == 2)){
            level_++;
            experience_ = 0;
        }
        else if ((experience_>= 400) and (level_ == 3)){
            level_++;
            experience_ = 0;
        }
        else if ((experience_>= 800) and (level_ == 4)){
            level_++;
            experience_ = 0;
        }
        else if ((experience_>= 1200) and (level_ == 5)){
            level_ ++;
            experience_ = 0;
        }
        else if ((experience_>= 1600) and (level_ == 6)){
            level_ ++;
            experience_ = 0;
        }
        else if ((experience_>= 2000) and (level_ == 7)){
            level_ ++;
            experience_ = 0;
        }
        else if ((experience_>= 2500) and (level_ == 8)){
            level_ ++;
            experience_ = 0;
        }
        else if ((experience_>= 3000) and (level_ == 9)){
            level_ ++;
            experience_ = 0;
        };   
     };
};




class Chevalier : public Personnage
{
    std::string name_;
    std::shared_ptr<Arme> arme_{nullptr};
    int vie_;
    int defense_;
    int force_;
    int agilite_;
    int level_;


public:
    Chevalier(const std::string& name, std::shared_ptr<Arme> arme):
        Personnage{name, arme, 100, 20, 30, 15, 1, 0}{};
    
};

class Mage : public Personnage
{
    std::string name_;
    std::shared_ptr<Arme> arme_{nullptr};
    int vie_;
    int defense_;
    int force_;
    int agilite_;
    int level_;

public:
    Mage(const std::string& name, std::shared_ptr<Arme> arme):
        Personnage{name, arme, 75, 15, 10, 25, 1, 0}{};
};




class Archer : public Personnage
{
    std::string name_;
    std::shared_ptr<Arme> arme_{nullptr};
    int vie_;
    int defense_;
    int force_;
    int agilite_;
    int level_;

public:
    Archer(const std::string& name, std::shared_ptr<Arme> arme):
        Personnage{name, arme, 75, 10, 20, 35, 1, 0}{};
};

class Assassin : public Personnage
{
    std::string name_;
    std::shared_ptr<Arme> arme_{nullptr};   
    int vie_;
    int defense_;
    int force_;
    int agilite_;
    int level_;

public:
    Assassin(const std::string& name, std::shared_ptr<Arme> arme):
        Personnage{name, arme, 50, 15, 25, 50, 1, 0}{};

};


class Barbare : public Personnage 
{
    std::string name_;
    std::shared_ptr<Arme> arme_{nullptr};
    int vie_;
    int defense_;
    int force_;
    int agilite_;
    int level_;

public:
    Barbare(const std::string& name, std::shared_ptr<Arme> arme):
        Personnage{name, arme, 100, 15, 35, 20, 1, 0}{};
};

class Monstre : public Personnage
{
    std::string name_;
    std::shared_ptr<Arme> arme_{nullptr};
    int vie_;
    int defense_;
    int force_;
    int agilite_;
    int level_;
    
public:
    Monstre(std::shared_ptr<Arme> arme, const int& level):
        Personnage{"Monstre", arme, 80, 10, 25, 10, level, 0}{};
    void update(){
        vie_ = vie_ + 12 * level_;
        defense_ = defense_ + 2 * level_;
        force_ = force_ + 5 * level_;
        agilite_ = agilite_ + 3 * level_;
        level_ = level_;
    }
    void print_ennemi(){
        std::cout << "Vous faites face à un monste niveau " << level_ << std::endl;
    }
};




class Quete{
    std::string name_;
    std::string description_;
    int element_requis_;
    int statut_;

    public :
    Quete(std::string name, std::string description, int element_requis, int statut){
        name_ = name;
        description_ = description;
        element_requis_ = element_requis;
        statut_ = statut;
    }
    void print_info(){
        std::cout <<  name_ << std::endl;
        std::cout <<  description_ << std::endl;
        std::cout << "Statut : " << statut_ <<" / " << element_requis_ << std::endl;
        std::cout << std::endl;
    }
};


class Piece{
    int numero_;
    std::string nom_;
    std::vector<std::shared_ptr<Arme>> armes_;
    std::vector<std::shared_ptr<Monstre>> monstre_;
    int experience_;

    public :
    Piece(int numero, std::string nom, std::vector<std::shared_ptr<Arme>> armes, std::vector<std::shared_ptr<Monstre>> monstre, int experience)


};