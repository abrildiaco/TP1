#include "../armas.hpp"
#include "../headers/amuleto.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

//constructor
Amuleto::Amuleto(string nombre_, int durabilidad_)
    :ItemMagico(nombre_, durabilidad_){
        
        srand(time(0)); // Inicializa la semilla
        //genero si el amuleto tiene suerte o no
        bool suerte_ = rand() % 2; //valores entre 0 y 1
        suerte = suerte_;
        
        if(suerte){
            daño = 15;
            auto_daño = 3;}
        else{
            daño = 10;
            auto_daño = 6;
        }

        cout<<"\nEl amuleto fue creado"<<endl;
    }

//metodos
void Amuleto::getInfo()const{
    cout<<"\n== Amuleto magico =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;
    cout<<"Suerte: "<<(suerte ? "Si" : "No")<<endl;

}


void Amuleto::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nEl amuleto ya no sirve"<<endl;
        return;
    }
    else if(durabilidad >0 ){
        uso = true;
        durabilidad--;
    }

    cout<<"\nEl Amuleto fue usado"<<endl;
}

float Amuleto::getAutoDano()const{return auto_daño;}

bool Amuleto::hasSuerte()const{return suerte;}

//destructor
Amuleto::~Amuleto(){
    cout<<"\nEl amuleto se ha destruido"<<endl;
}