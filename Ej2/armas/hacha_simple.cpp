#include "armas.hpp"
#include "hacha_simple.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


//constructor
HachaSimple::HachaSimple(string nombre_, int durabilidad_, float peso_)
    :ArmaCombate(nombre_, durabilidad_, peso_), filo(10) {
        
        if(peso < 1 || peso > 5)
            throw invalid_argument("El peso va de 1 a 5");

        //si es más pesada genera más daño
        if(peso < 3)
            daño = 12;
        else if(peso >= 3)
            daño = 16;
        
        cout<<"\nHacha simple creada"<<endl;
    }

//metodos
void HachaSimple::getInfo()const{
    cout<<"\n== Hacha simple =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Peso: "<<peso<<endl;
    cout<<"Filo: "<<filo<<endl;

}

void HachaSimple::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nEl Hacha Simple ya no sirve"<<endl;
        return;
    }
    else if(durabilidad >0 ){
        filo--;
        daño--;
        durabilidad--;
        uso = true;
    }

    cout<<"\nEl Hacha simple ha sido usada"<<endl;

    return;
}

float HachaSimple::getPeso()const{return peso;}

void HachaSimple::Afilar(){
    filo = 10; //restaura el filo
    //restauro el daño
    if(peso < 3)
        daño = 12;
    else if(peso >= 3)
        daño = 16;

    cout<<"\nEl Hacha fue afilada"<<endl;
    return;
}

//destructor
HachaSimple::~HachaSimple(){
    cout<<"\nEl hacha simple ha sido destruida"<<endl;
}
