#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/brujo.hpp"

using namespace std;

//constructor
Brujo::Brujo(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Mago(nombre_,fuerza_, arma1_, arma2_), afinidad("Pocion"){}

//metodos
void Brujo::getInfo()const{
    cout<<"\n== Brujo =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    cout<<"Afinidad: "<<afinidad<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    
    return;
}

void Brujo::Curar(){
    
    if(hp < 1) cout<<"\nEl Brujo ya esta muerto"<<endl;    
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Brujo se curo"<<endl;
        return;
    }

    cout<<"\nEl Brujo no necesita curarse"<<endl;
    return;
}

float Brujo::Atacar(shared_ptr<Arma> arma){
    int daño_generado = 0;
    arma->Usar();

    if(arma->getDurabilidad() > 0){
        if(arma->getNombre() == afinidad){
            //daño extra causado por afinidad
            daño_generado += 4;
        }
        daño_generado += fuerza + arma->getDano();
        ataco = true;
        cout<<"\nEl Brujo atacó"<<endl;
    }
    return daño_generado;
}

//destructor
Brujo::~Brujo(){
    cout<<"\nEl Brujo fue destruido"<<endl;
}