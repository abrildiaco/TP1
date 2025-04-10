#include "armas.hpp"
#include "Lanza.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


//constructor
Lanza::Lanza(string nombre_, int durabilidad_, float peso_)
    :ArmaCombate(nombre_, durabilidad_, peso_), filo(10) {
        
        if(peso < 1 || peso > 5)
            throw invalid_argument("El peso va de 0 a 5");

        srand(time(0)); // Inicializa la semilla
        //genero si las Lanza es de diamante
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
        cout<<"\nLanza creada"<<endl;
    }

//metodos
void Lanza::getInfo()const{
    cout<<"\n== Lanza =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Peso: "<<peso<<endl;
    cout<<"Filo: "<<filo<<endl;
    cout<<"Diamante: "<<diamante<<endl;


}

void Lanza::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nLa Lanza ya no sirve"<<endl;
        return;
    }
    else if(!diamante){
        filo--;
        daño--;
    }
    
    durabilidad--;
    uso = true;
    cout<<"\nLa Lanza ha sido usada"<<endl;

    return;
}

float Lanza::getPeso()const{return peso;}

void Lanza::Afilar(){
    
    if(!diamante){
        filo = 10; //restaura el filo
        //restauro el daño
            if(peso < 3)
                daño = 19;
            else if(peso >= 3)
                daño = 15;
        cout<<"\nLa Lanza fue afilada"<<endl;
        return;
    }
    cout<<"\nLa Lanza de diamante no necesita afilarse"<<endl;

    return;
}

bool Lanza::hasDiamante()const{return diamante;}

//destructor
Lanza::~Lanza(){
    cout<<"\nEl Lanza ha sido destruida"<<endl;
}
