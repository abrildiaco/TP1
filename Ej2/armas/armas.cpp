#include"armas.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//constructores clases abstractas

ItemMagico::ItemMagico(string nombre_, int durabilidad_)
    :tipo_arma("Item Magico"), nombre(nombre_), durabilidad(durabilidad_), uso(false) {
        if(durabilidad_ <0)
            throw invalid_argument("La durabilidad no puede ser negativa");

        if(nombre_ != "Pocion" && nombre_ != "Baston" && nombre_ != "Libro de Hechizos" && nombre_ != "Amuleto")
            throw invalid_argument("No existe esa arma mágica");
}

string ItemMagico::getNombre()const{return nombre;}

int ItemMagico::getDurabilidad()const{return durabilidad;}

float ItemMagico::getDano() const{return daño;}

string ItemMagico::getTipo() {return tipo_arma;}


ArmaCombate::ArmaCombate(string nombre_, int durabilidad_, float peso_)//nombre, durabilidad, peso
    :tipo_arma("Combate"), nombre(nombre_), durabilidad(durabilidad_), peso(peso_), uso(false){
        
        if(durabilidad_ <0)
            throw invalid_argument("La durabilidad no puede ser negativa");

        if(peso_ <1 || peso_ >5)
            throw invalid_argument("El peso deeb estar entre 1 y 5");
        
        if(nombre_ != "Hacha Simple" && nombre_ != "Hacha Doble" && nombre_ != "Espada" && nombre_ != "Lanza" && nombre_ != "Garrote")
            throw invalid_argument("No existe esa arma mágica");
    }

string ArmaCombate::getNombre()const{return nombre;}

int ArmaCombate::getDurabilidad()const{return durabilidad;}

float ArmaCombate::getDano() const{return daño;}

string ArmaCombate::getTipo() {return tipo_arma;}