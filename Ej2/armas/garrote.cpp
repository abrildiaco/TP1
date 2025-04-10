#include "armas.hpp"
#include "Garrote.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


//constructor
Garrote::Garrote(string nombre_, int durabilidad_, float peso_)
    :ArmaCombate(nombre_, durabilidad_, peso_){
        
        if(peso < 1 || peso > 5)
            throw invalid_argument("El peso va de 1 a 5");
        
        srand(time(0)); // Inicializa la semilla
        //genero si el garrote tiene clavos o no
        bool clavos_ = rand() % 2;//valores entre 0 y 1
        clavos = clavos_;

        //si es más pesada genera mas daño.
        if(clavos){
            if(peso < 3)
                daño = 16;
            else if(peso >= 3)
                daño = 20;
        }

        else{        
            if(peso < 3)
                daño = 14;
            else if(peso >= 3)
                daño = 17;
        }

        cout<<"\nGarrote creado"<<endl;
    }

//metodos
void Garrote::getInfo()const{
    cout<<"\n== Garrote =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Peso: "<<peso<<endl;
    cout<<"Clavos: "<<clavos<<endl;

}

void Garrote::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nEl Garrote ya no sirve"<<endl;
        return;
    }
    else{
        durabilidad--;
        uso = true;
        cout<<"\nEl Garrote ha sido usado"<<endl;
    }
    return;
}

float Garrote::getPeso()const{return peso;}

bool Garrote::hasClavos()const{return clavos;}

//destructor
Garrote::~Garrote(){
    cout<<"\nEl Garrote ha sido destruido"<<endl;
}
