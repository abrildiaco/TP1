#include <string>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../armas/armas.hpp"
#include "../headers/gladiador.hpp"

using namespace std;

//constructor
Gladiador::Gladiador(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Guerrero(nombre_,fuerza_, arma1_, arma2_){
        srand(time(0)); // Inicializa la semilla
        //se le asigna un nivel de intimidacion aleatorio al gladiador
        nivelIntimidante = rand() % 10 + 1; //nivel de intimidacion entre 1 y 10
    }  

//metodos
void Gladiador::getInfo()const{
    cout<<"\n== Gladiador =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    cout<<"Nivel de Intimidacion: "<<nivelIntimidante<<endl;
    
    return;
}

void Gladiador::Curar(){
    if(hp < 1) cout<<"\nEl Gladiador ya esta muerto"<<endl;
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Gladiador se curo"<<endl;
        return;
    }

    cout<<"\nEl Gladiador no necesita curarse"<<endl;
    return;
}


float Gladiador::Atacar(shared_ptr<Arma> arma = nullptr){
    int daño_generado = 0;
    if(arma){
        arma->Usar();

        if(arma->getDurabilidad() > 0){
            daño_generado += fuerza + arma->getDano();
        }
    }else{
        //si no tiene arma, ataca con la fuerza
        daño_generado += fuerza;
    }
    ataco = true;
    cout<<"\nEl Gladiador atacó"<<endl;
    return daño_generado;
}

bool Gladiador::recibirDano(float daño_recibido, shared_ptr<ItemMagico> arma = nullptr){
    //si el personaje no tiene proteccion y usa un arma magica recibe daño 
    if(arma && !proteccion) hp -= arma->getAutoDano();
    
    //al daño recibido le sumo el nivel de intimidacion
    hp -= daño_recibido + nivelIntimidante;

    return hp <= 0; //si esta vivo o muerto
}

//destructor
Gladiador::~Gladiador(){
    cout<<"\nEl Gladiador fue destruido"<<endl;
}