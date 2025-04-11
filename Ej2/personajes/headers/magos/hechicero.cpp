#include <string>
#include <memory>
#include <iostream>
#include "../armas/armas.hpp"
#include "hechicero.hpp"

using namespace std;

//constructor
Hechicero::Hechicero(string nombre_, float fuerza_, unique_ptr<Arma> arma_)
    :Mago(nombre_,fuerza_, arma_), afinidad("Libro de Hechizos"){}

//metodos
void Hechicero::getInfo()const{
    cout<<"\n== Hechicero =="<<endl;
    cout<<"Vida: "<<hp<<endl;
    cout<<"Fuerza: "<<fuerza<<endl;
    cout<<"Afinidad: "<<afinidad<<endl;
    cout<<"Arma: "<<arma<<endl;

    return;
}

void Hechicero::Curar(){
    //solo se pude curar si tiene menos de 40 de vida
    if(hp < 40){
        hp = 100;
        cout<<"\nEl Hechicero se curo"<<endl;
        return;
    }

    cout<<"\nEl Hechicero no necesita curarse"<<endl;
}

void Hechicero::Atacar()const{
    
}