#include <string>
#include <memory>
#include <iostream>
#include "../../armas/armas.hpp"
#include "../headers/hechicero.hpp"

using namespace std;

//constructor
Hechicero::Hechicero(string nombre_, float fuerza_, shared_ptr<Arma> arma1_ = nullptr, shared_ptr<Arma> arma2_ = nullptr)
    :Mago(nombre_,fuerza_, arma1_, arma2_), afinidad("Libro de Hechizos"){}

//metodos
void Hechicero::getInfo()const{
    cout<<"\n== Hechicero =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    cout<<"Afinidad: "<<afinidad<<endl;
    if(arma1) cout<<"Arma1: "<<arma1->getNombre()<<endl;
    if(arma2) cout<<"Arma2: "<<arma2->getNombre()<<endl;
    
    return;
}

void Hechicero::Curar(){
    if(hp < 1) cout<<"\nEl Hechicero ya esta muerto"<<endl;
    //solo se pude curar si tiene menos de 40 de vida
    else if(hp < 40){
        hp = 100;
        cout<<"\nEl Hechicero se curo"<<endl;
        return;
    }

    cout<<"\nEl Hechicero no necesita curarse"<<endl;
    return;
}

float Hechicero::Atacar(shared_ptr<Arma> arma){
    int daño_generado = 0;
    arma->Usar();

    if(arma->getDurabilidad() > 0){
        if(arma->getNombre() == afinidad){
            //daño extra causado por afinidad
            daño_generado += 4;
        }
        daño_generado += fuerza + arma->getDano();
        ataco = true;
        cout<<"\nEl Hechicero atacó"<<endl;
    }
    return daño_generado;
}

//destructor
Hechicero::~Hechicero(){
    cout<<"\nEl hechicero fue destruido"<<endl;
}