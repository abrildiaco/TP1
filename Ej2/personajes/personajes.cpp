#include <string>
#include <memory>
#include <stdexcept>
#include "personajes.hpp"

using namespace  std;

//MAGO

//constructor
Mago::Mago(string nombre_, float fuerza_, unique_ptr<Arma> arma_) //nombre, poder, fuerza, arma
    :tipo_personaje("Mago"), nombre(nombre_), hp(100), fuerza(fuerza_), arma(move(arma_)), ataco(false){
        
        if(nombre_ != "Hechicero" && nombre_ != "Conjurador" && nombre_ != "Brujo" && nombre_ != "Nigromante")
            throw invalid_argument("No existe ese Mago");

        if(fuerza < 0 || fuerza > 5)
            throw invalid_argument("La fuerza debe estar entre 0 y 5");

    }

//metodos 

string Mago::getNombre()const{return nombre;}

string Mago::getTipo()const{return tipo_personaje;}

float  Mago::getHp() const {return hp;}

Arma& Mago::getArma()const{return *arma;} //devuelvo una referencia al puntero, sin transferirle la 
                                        //propiedad a quien llama la funcion

//GUERRERO

//constructor
Guerrero::Guerrero(string nombre_, float fuerza_, unique_ptr<Arma> arma_) //nombre, poder, fuerza, arma
    :tipo_personaje("Mago"), nombre(nombre_), hp(100), fuerza(fuerza_), arma(move(arma_)), ataco(false){
        
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

Arma& Guerrero::getArma()const{return *arma;} //devuelvo una referencia al puntero, sin transferirle la 
                                        //propiedad a quien llama la funcion
bool Guerrero::getProteccion()const{return proteccion;}