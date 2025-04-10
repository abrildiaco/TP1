#include "armas.hpp"
#include "hacha_Doble.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


//constructor
HachaDoble::HachaDoble(string nombre_, int durabilidad_, float peso_)
    :ArmaCombate(nombre_, durabilidad_, peso_), filo(10) {
        
        if(peso < 1 || peso > 5)
            throw invalid_argument("El peso va de 0 a 5");

        //si es más pesada genera menos daño. Se hace muy dificil de manejar
        if(peso < 3)
            daño = 19;
        else if(peso >= 3)
            daño = 15;
        
        cout<<"\nHacha Doble creada"<<endl;
    }

//metodos
void HachaDoble::getInfo()const{
    cout<<"\n== Hacha Doble =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Peso: "<<peso<<endl;
    cout<<"Filo: "<<filo<<endl;

}

void HachaDoble::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nEl Hacha Doble ya no sirve"<<endl;
        return;
    }
    else if(durabilidad >0 ){
        filo--;
        daño--;
        durabilidad--;
        uso = true;
    }

    cout<<"\nEl Hacha Doble ha sido usada"<<endl;

    return;
}

float HachaDoble::getPeso()const{return peso;}

void HachaDoble::Afilar(){
    filo = 10; //restaura el filo
    //restauro el daño
        if(peso < 3)
            daño = 19;
        else if(peso >= 3)
            daño = 15;
    cout<<"\nEl Hacha fue afilada"<<endl;
    return;
}

//destructor
HachaDoble::~HachaDoble(){
    cout<<"\nEl hacha Doble ha sido destruida"<<endl;
}
