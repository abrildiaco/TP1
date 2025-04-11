#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/conjurador.hpp"

using namespace std;

//constructor
Conjurador::Conjurador(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Mago(nombre_,fuerza_, arma1_, arma2_), afinidad("Amuleto"){}

//metodos
void Conjurador::getInfo()const{
    cout<<"\n== Conjurador =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    cout<<"Afinidad: "<<afinidad<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    
    return;
}

void Conjurador::Curar(){
    if(hp < 1) cout<<"\nEl Conjurador ya esta muerto"<<endl;    
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Conjurador se curo"<<endl;
        return;
    }

    cout<<"\nEl Conjurador no necesita curarse"<<endl;
    return;
}

float Conjurador::Atacar(shared_ptr<Arma> arma){
    int daño_generado = 0;
    arma->Usar();

    if(arma->getDurabilidad() > 0){
        if(arma->getNombre() == afinidad){
            //daño extra causado por afinidad
            daño_generado += 4;
        }
        daño_generado += fuerza + arma->getDano();
        ataco = true;
        cout<<"\nEl Conjurador atacó"<<endl;
    }
    return daño_generado;
}

//destructor
Conjurador::~Conjurador(){
    cout<<"\nEl Conjurador fue destruido"<<endl;
}