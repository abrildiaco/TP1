#include <string>
#include <memory>
#include <stdexcept>
#include "personajes.hpp"

using namespace  std;

//MAGO

//constructor
Mago::Mago(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr) //nombre, poder, fuerza, arma
    :tipo_personaje("Mago"), nombre(nombre_), hp(100), fuerza(fuerza_), arma1(arma1_), arma2(arma2_), ataco(false){
        
        if(nombre_ != "Hechicero" && nombre_ != "Conjurador" && nombre_ != "Brujo" && nombre_ != "Nigromante")
            throw invalid_argument("No existe ese Mago");

        if(fuerza < 0 || fuerza > 5)
            throw invalid_argument("La fuerza debe estar entre 0 y 5");

    }

//metodos 

string Mago::getNombre()const{return nombre;}

string Mago::getTipo()const{return tipo_personaje;}

float  Mago::getHp() const {return hp;}

shared_ptr<Arma> Mago::getArma1() {return arma1;}
shared_ptr<Arma> Mago::getArma2() {return arma2;}

bool Mago::recibirDano(float daño_recibido){
    hp -= daño_recibido;
    
    return hp<=0; //si esta vivo o muerto
}


//GUERRERO

//constructor
Guerrero::Guerrero(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr) //nombre, poder, fuerza, arma
    :tipo_personaje("Mago"), nombre(nombre_), hp(100), fuerza(fuerza_), arma1(arma1_), arma2(arma2_), ataco(false){
        
        srand(time(0)); // Inicializa la semilla
        //genero si el personaje tiene proteccion o no
        bool proteccion_ = rand() % 2; //valores entre 0 y 1
        proteccion = proteccion_;

        if(nombre_ != "Barbaro" && nombre_ != "Paladin" && nombre_ != "Caballero" && nombre_ != "Mercenario" && nombre_ != "Gladiador")
            throw invalid_argument("No existe ese Guerrero");

        if(fuerza < 0 || fuerza > 5)
            throw invalid_argument("La fuerza debe estar entre 0 y 5");

    }

//metodos 
string Guerrero::getNombre()const{return nombre;}

string Guerrero::getTipo()const{return tipo_personaje;}

float  Guerrero::getHp() const {return hp;}

shared_ptr<Arma> Guerrero::getArma1() {return arma1;}
shared_ptr<Arma> Guerrero::getArma2() {return arma2;}

bool Guerrero::recibirDano(float daño_recibido, shared_ptr<ItemMagico> arma = nullptr){
    //si el personaje no tiene proteccion y usa un arma magica recibe daño 
    if(arma && !proteccion) hp -= arma->getAutoDano();
    
    //recibe el daño de ataque
    hp -= daño_recibido;
    
    return hp <= 0; //si esta vivo o muerto
}

bool Guerrero::getProteccion()const{return proteccion;}