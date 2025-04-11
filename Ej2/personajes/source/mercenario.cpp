#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/mercenario.hpp"

using namespace std;

//constructor
Mercenario::Mercenario(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Guerrero(nombre_,fuerza_, arma1_, arma2_), comision(0){}

//metodos
void Mercenario::getInfo()const{
    cout<<"\n== Mercenario =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    cout<<"Comision actual: "<<comision<<endl;
    
    return;
}

void Mercenario::Curar(){
    if(hp < 1) cout<<"\nEl Mercenario ya esta muerto"<<endl;
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Mercenario se curo"<<endl;
        return;
    }

    cout<<"\nEl Mercenario no necesita curarse"<<endl;
    return;
}


float Mercenario::Atacar(shared_ptr<Arma> arma){
    int daño_generado = 0;
    arma->Usar();

    if(arma->getDurabilidad() > 0){
        
        if(comision >= 30){
            //si la comision es mayor a 30, se la suma al daño
            daño_generado += 30;
            comision = 0; //se reinicia la comision
        }
        daño_generado += fuerza + arma->getDano();
        ataco = true;
        cout<<"\nEl Mercenario atacó"<<endl;
    }
    return daño_generado;
}

bool Mercenario::recibirDano(float daño_recibido, shared_ptr<ItemMagico> arma = nullptr){
    //si el personaje no tiene proteccion y usa un arma magica recibe daño 
    if(arma && !proteccion) hp -= arma->getAutoDano();
    
    hp -= daño_recibido;

    //me guardo un 30% del daño recibido en comision
    comision += daño_recibido * 0.3;

    return hp <= 0; //si esta vivo o muerto
}

//destructor
Mercenario::~Mercenario(){
    cout<<"\nEl Mercenario fue destruido"<<endl;
}