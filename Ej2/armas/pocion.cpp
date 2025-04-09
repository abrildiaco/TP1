#include"armas.h"
#include "pocion.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//constructor
Pocion::Pocion(std::string nombre_, int durabilidad_, float auto_daño_, float daño_, string tipo_, int duracion_efecto_)
    :ItemMagico(nombre_, durabilidad_, auto_daño_, daño_), tipo(tipo_), duracion_efecto(duracion_efecto_) {
        if(auto_daño_ >= daño_)
            throw invalid_argument("El daño no puede ser menor o igual al auto daño");
        
        if(tipo_ != "veneno" || tipo_ != "inmunidad")
            throw invalid_argument("No existe ese tipo de pocion");
    }

//metodos
void Pocion::getInfo()const{
    cout<<"== Pocion magica =="<<endl;
    cout<<"Tipo: "<<tipo<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;
    cout<<"Duracion de efecto: "<<duracion_efecto<<endl;

}

std::string Pocion::getNombre()const{return nombre;}

int Pocion::getDurabilidad()const{return durabilidad;}

float Pocion::getDano() const{return daño;}

void Pocion::Usar(){ 
    if(durabilidad >0 ){
        if(tipo == "veneno")
            cout<<"Pocion de veneno lanzada"<<endl;
        
        if(tipo == "congelamiento")
            cout<<"Pocion de Inmunidad usada.\nNo puedo recibir daño"<<endl;

        uso = true;
        durabilidad--;
    }

    if(durabilidad == 0){
        uso = false;
        cout<<"Ya no tienes mas pocion"<<endl;
    }
}

float Pocion::getAutoDano()const{return auto_daño;}

std::string Pocion::getTipo() const{return tipo;}

int Pocion::getDuracionEfecto()const{return duracion_efecto;}


//destructor
Pocion::~Pocion(){
    cout<<"La pocion se ha destruido"<<endl;
}