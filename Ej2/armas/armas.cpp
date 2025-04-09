#include"armas.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//constructores clases abstractas

ItemMagico::ItemMagico(string nombre_, int durabilidad_)
    :tipo_arma("magica"), nombre(nombre_), durabilidad(durabilidad_) {
        if(durabilidad_ <0)
            throw invalid_argument("La durabilidad no puede ser negativa");

        if(nombre_ != "Pocion" || nombre_ != "Baston" || nombre_ != "Libro de Hechizos" || nombre_ != "Amuleto")
            throw invalid_argument("No existe esa arma mágica");
}

ArmaCombate::ArmaCombate(string nombre_, int durabilidad_, float peso_);//nombre, durabilidad, peso
    :tipo_arma("combate"), nombre(nombre_), durabilidad(durabilidad_), peso(peso_){
        
        if(peso_ <1)
            throw invalid_argument("El peso debe ser mayor a uno");
        
        if(peso_ >5)
            throw invalid_argument("El peso debe ser menor a cinco");

        if(nombre_ != "Hacha Simple" || nombre_ != "Hacha Doble" || nombre_ != "Espada" || nombre_ != "Lanza", nombre_ != "Garrote")
            throw invalid_argument("No existe esa arma mágica");
    }
