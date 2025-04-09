#include "armas.h"
#include "hacha_simple.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


//constructor
HachaSimaple::HachaSimaple(string nombre_, int durabilidad_, float peso_)
    :ArmaCombate(nombre_, durabilidad_, peso_), filo(10) {
        daño = 15;
        cout<<"Hacha simple creada"<<endl;
    }

//metodos
void HachaSimaple::getInfo()const{
    cout<<"== Hacha simple =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Peso: "<<peso<<endl;
    cout<<"Filo: "<<filo<<endl;

}

string HachaSimaple::getNombre()const{return nombre;}

int HachaSimaple::getDurabilidad()const{return durabilidad;}

float HachaSimaple::getDano() const{return daño;}

string HachaSimaple::getTipo() {return tipo_arma;}

void HachaSimaple::Usar(){ 
    if(durabilidad >0 ){
        filo--;
        durabilidad--;
        uso = true;
    }

    if(durabilidad == 0){
        cout<<"El Hacha simple ya no sirve"<<endl;
    }
}

float HachaSimaple::getPeso()const{return peso;}

void HachaSimaple::Afilar(){
    filo = 10;
    cout<<"Hacha afilada"<<endl;
    return;
}

//destructor
HachaSimaple::~HachaSimaple(){
    cout<<"El hacha simple ha sido destruida"<<endl;
}
