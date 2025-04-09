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