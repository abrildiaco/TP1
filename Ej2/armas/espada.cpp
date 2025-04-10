#include "armas.hpp"
#include "espada.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


//constructor
Espada::Espada(string nombre_, int durabilidad_, float peso_)
    :ArmaCombate(nombre_, durabilidad_, peso_), filo(10) {
        
        if(peso < 1 || peso > 5)
            throw invalid_argument("El peso va de 0 a 5");

        srand(time(0)); // Inicializa la semilla
        //genero si las espada es de diamante
        bool diamante_ = rand() % 2; //valores entre 0 y 1
        diamante = diamante_;
    

        //si es más pesada genera menos daño. Se hace muy dificil de manejar
        if(diamante){
            if(peso < 3)
                daño = 20;
            else if(peso >= 3)
                daño = 17;
        }

        else{        
            if(peso < 3)
                daño = 16;
            else if(peso >= 3)
                daño = 13;
        }
        cout<<"\nEspada creada"<<endl;
    }

//metodos
void Espada::getInfo()const{
    cout<<"\n== Espada =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Peso: "<<peso<<endl;
    cout<<"Filo: "<<filo<<endl;
    cout<<"Diamante: "<<diamante<<endl;


}

void Espada::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nLa Espada ya no sirve"<<endl;
        return;
    }
    else if(!diamante){
        filo--;
        daño--;
    }
    
    durabilidad--;
    uso = true;
    cout<<"\nLa Espada ha sido usada"<<endl;

    return;
}

float Espada::getPeso()const{return peso;}

void Espada::Afilar(){
    
    if(!diamante){
        filo = 10; //restaura el filo
        //restauro el daño
            if(peso < 3)
                daño = 19;
            else if(peso >= 3)
                daño = 15;
        cout<<"\nLa espada fue afilada"<<endl;
        return;
    }
    cout<<"\nLa espada de diamante no necesita afilarse"<<endl;

    return;
}

bool Espada::hasDiamante()const{return diamante;}

//destructor
Espada::~Espada(){
    cout<<"\nEl Espada ha sido destruida"<<endl;
}
