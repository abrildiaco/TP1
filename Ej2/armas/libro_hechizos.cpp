#include"armas.h"
#include "LibroHechizos.h"
#include <iostream>
#include <string>
#include <stdexcept>


//constructor
LibroHechizos::LibroHechizos(std::string nombre_, int durabilidad_, float auto_daño_, float daño_)
    :ItemMagico(nombre_, durabilidad_, auto_daño_, daño_) {
        if(auto_daño_ >= daño_)
            throw invalid_argument("El daño no puede ser menor o igual al auto daño");
        
    }

//metodos
void LibroHechizos::getInfo()const{
    cout<<"== Libro de Hechizos =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;

}

std::string LibroHechizos::getNombre()const{return nombre;}

int LibroHechizos::getDurabilidad()const{return durabilidad;}

float LibroHechizos::getDano() const{return daño;}

void LibroHechizos::Usar(){ 
    if(durabilidad >0 ){
        if(tipo == "veneno")
            cout<<"LibroHechizos de veneno lanzada"<<endl;
        
        if(tipo == "congelamiento")
            cout<<"LibroHechizos de Inmunidad usada.\nNo puedo recibir daño"<<endl;

        uso = true;
        durabilidad--;
    }

    if(durabilidad == 0){
        uso = false;
        cout<<"Ya no tienes mas LibroHechizos"<<endl;
    }
}
