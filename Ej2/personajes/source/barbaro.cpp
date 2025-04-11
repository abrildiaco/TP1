#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/barbaro.hpp"

using namespace std;

//constructor
Barbaro::Barbaro(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Guerrero(nombre_,fuerza_, arma1_, arma2_), afinidad("Hacha Simple"), ira(false){}

//metodos
void Barbaro::getInfo()const{
    cout<<"\n== Barbaro =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    cout<<"Afinidad: "<<afinidad<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    cout<<"Ira activada: "<<(ira ? "Si" : "No")<<endl;
    
    return;
}

void Barbaro::Curar(){
    if(hp < 1) cout<<"\nEl Barbaro ya esta muerto"<<endl;
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Barbaro se curo"<<endl;
        return;
    }

    cout<<"\nEl Barbaro no necesita curarse"<<endl;
    return;
}

void Barbaro::activarIra(){
    if(!ira){
        ira = true;
        cout<<"\nEl Barbaro activo la ira"<<endl;
    }
    else{
        cout<<"\nEl Barbaro ya tiene ira activada"<<endl;
    }
}

float Barbaro::Atacar(shared_ptr<Arma> arma=nullptr){
    int daño_generado = 0;
    if(arma){
        arma->Usar();

        if(arma->getDurabilidad() > 0){
            if(arma->getNombre() == afinidad){
                //daño extra causado por afinidad
                daño_generado += 4;
            }
            if(ira){
                //si el barbaro tiene ira, el daño es mayor
                daño_generado += (fuerza + arma->getDano()) +  (fuerza + arma->getDano())*(0.5); //50% mas de daño
                ira = false; //desactivo la ira
            }
            else{
                //si no tiene ira, el daño es normal
                daño_generado += fuerza + arma->getDano();
            }
        }
    }else{
        //si no tiene arma, el daño es solo la fuerza
        daño_generado += fuerza;
    }
    ataco = true;
    cout<<"\nEl Barbaro atacó"<<endl;
    return daño_generado;
}

bool Barbaro::recibirDano(float daño_recibido, shared_ptr<ItemMagico> arma = nullptr){
    //si el personaje no tiene proteccion y usa un arma magica recibe daño 
    if(arma && !proteccion) hp -= arma->getAutoDano();
    
    //recibe el daño de ataque
    hp -= daño_recibido;
    
    //activo ira si eldaño recibido fue mayor a 20
    if(daño_recibido > 20 && !ira){
        this->activarIra();
    }
    return hp <= 0; //si esta vivo o muerto
}

//destructor
Barbaro::~Barbaro(){
    cout<<"\nEl Barbaro fue destruido"<<endl;
}