#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/caballero.hpp"

using namespace std;

//constructor
Caballero::Caballero(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Guerrero(nombre_,fuerza_, arma1_, arma2_), afinidad("Espada"), armadura(10){}

//metodos
void Caballero::getInfo()const{
    cout<<"\n== Caballero =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    cout<<"Afinidad: "<<afinidad<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    cout<<"Vida Armadura: "<<armadura<<endl;
    
    return;
}

void Caballero::Curar(){
    if(hp < 1) cout<<"\nEl Caballero ya esta muerto"<<endl;
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Caballero se curo"<<endl;
        return;
    }

    cout<<"\nEl Caballero no necesita curarse"<<endl;
    return;
}


float Caballero::Atacar(shared_ptr<Arma> arma = nullptr){
    int daño_generado = 0;
    if(arma){
        arma->Usar();

        if(arma->getDurabilidad() > 0){
            if(arma->getNombre() == afinidad){
                //daño extra causado por afinidad
                daño_generado += 4;
            }

            daño_generado += fuerza + arma->getDano();
        }
    }else{
        //si no tiene arma, ataca con la fuerza
        daño_generado += fuerza;
    }
    ataco = true;
    cout<<"\nEl Caballero atacó"<<endl;
    return daño_generado;
}

bool Caballero::recibirDano(float daño_recibido, shared_ptr<ItemMagico> arma = nullptr){
    //si el personaje no tiene proteccion y usa un arma magica recibe daño 
    if(arma && !proteccion) hp -= arma->getAutoDano();
    
    //recibe el daño de ataque y le sumo la proteccion de la armadura
    hp -= daño_recibido + armadura;
    
    armadura--;
    if(armadura<= 0) cout<<"\nEl Caballero no tiene armadura"<<endl;

    return hp <= 0; //si esta vivo o muerto
}

//destructor
Caballero::~Caballero(){
    cout<<"\nEl Caballero fue destruido"<<endl;
}