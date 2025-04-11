#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/nigromante.hpp"

using namespace std;

//constructor
Nigromante::Nigromante(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Mago(nombre_,fuerza_, arma1_, arma2_), revivir(false){}

//metodos
void Nigromante::getInfo()const{
    cout<<"\n== Nigromante =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    cout<<"Revivió: "<<(revivir ? "Si" : "No")<<endl;
    
    return;
}

void Nigromante::Curar(){
    if(hp < 1) cout<<"\nEl nigromante ya esta muerto"<<endl;
    
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Nigromante se curo"<<endl;
        return;
    } 

    cout<<"\nEl Nigromante no necesita curarse"<<endl;
    return;
}

float Nigromante::Atacar(shared_ptr<Arma> arma){
    int daño_generado = 0;
    arma->Usar();

    if(arma->getDurabilidad() > 0){

        daño_generado += fuerza + arma->getDano();
        ataco = true;
        cout<<"\nEl Nigromante atacó"<<endl;
    }
    return daño_generado;
}

void Nigromante::Revivir(){
    if(!revivir){
        revivir = true;
        hp = 50; //revive con 50 de vida
        cout<<"\nEl Nigromante revivió"<<endl;
    }else{
        cout<<"\nEl Nigromante ya revivió, no puede volver a hecrlo"<<endl;
    }
}

//destructor
Nigromante::~Nigromante(){
    cout<<"\nEl Nigromante fue destruido"<<endl;
}