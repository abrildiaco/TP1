#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/paladin.hpp"

using namespace std;

//constructor
Paladin::Paladin(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Guerrero(nombre_,fuerza_, arma1_, arma2_), juicio_solar(false){}

//metodos
void Paladin::getInfo()const{
    cout<<"\n== Paladin =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    cout<<"Juicio solar activado: "<<(juicio_solar ? "Si" : "No")<<endl;
    
    return;
}

void Paladin::Curar(){
    if(hp < 1) cout<<"\nEl Paladin ya esta muerto"<<endl;
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Paladin se curo"<<endl;
        return;
    }

    cout<<"\nEl Paladin no necesita curarse"<<endl;
    return;
}

//solo es llamado ante un nigromante o brujo
void Paladin::activarJuicioSolar(){
    if(!juicio_solar){
        juicio_solar = true;
        //le hace daño extra a estos personajes
        cout<<"\nEl Paladin activo el juicio solar"<<endl;
    }
    else{
        cout<<"\nEl Paladin ya tiene el juicio solar activado"<<endl;
    }
}

float Paladin::Atacar(shared_ptr<Arma> arma){
    int daño_generado = 0;
    arma->Usar();

    if(arma->getDurabilidad() > 0){
        if(juicio_solar){
            //si el Paladin se enfrenta a un nigromante o brujo
            daño_generado += (fuerza + arma->getDano()) +  (fuerza + arma->getDano())*(0.5); //50% mas de daño
        }
        else{
            //si no tiene ira, el daño es normal
            daño_generado += fuerza + arma->getDano();
        }
        ataco = true;
        cout<<"\nEl Paladin atacó"<<endl;
    }
    return daño_generado;
}


//destructor
Paladin::~Paladin(){
    cout<<"\nEl Paladin fue destruido"<<endl;
}