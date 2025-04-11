#include "../armas.hpp"
#include "../headers/pocion.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//constructor
Pocion::Pocion(string nombre_, int durabilidad_)
    :ItemMagico(nombre_, durabilidad_), tipo({"veneno", "inmunidad"}) {//, duracion_efecto(1) {
        
        //genero una pocion inicial
        int aleatorio = rand() % 2; //valores entre 0 y 1
        tipo_actual = tipo[aleatorio];

        if(tipo_actual == "veneno"){
            daño = 15;
            auto_daño = 1;
        }
        else if(tipo_actual == "inmunidad") {
            //la pocion no hace daño en sí. el daño dependerá
            //del golpe elegido en la batalla
            daño = 0;
            auto_daño = 0;
        }
        cout<<"\nPocion creada"<<endl;
    }

//metodos
void Pocion::getInfo()const{
    cout<<"\n== Pocion magica =="<<endl;
    cout<<"Tipo: "<<tipo_actual<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;
    //cout<<"Duracion de efecto: "<<duracion_efecto<<endl;

}


void Pocion::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nYa no tienes mas pocion"<<endl;
        return;
    }

    else if(durabilidad >0 ){
        //genero una pocion inicial
        int aleatorio = rand() % 2; //valores entre 0 y 1
        tipo_actual = tipo[aleatorio];

        if(tipo_actual == "veneno"){
            daño = 15;
            auto_daño = 1;
        }
        else if(tipo_actual == "inmunidad") {
            daño = 0;
            auto_daño = 0;
        }        
        
        cout<<"\nSe utilizo la Pocion"<<endl;
        uso = true;
        durabilidad--;
    }

    return;

}

float Pocion::getAutoDano()const{return auto_daño;}

string Pocion::getTipo() const{return tipo_actual;}

//int Pocion::getDuracionEfecto()const{return duracion_efecto;}


//destructor
Pocion::~Pocion(){
    cout<<"\nLa pocion se ha destruido"<<endl;
}