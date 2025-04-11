#include "../armas.hpp"
#include "../headers/lanza.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


//constructor
Lanza::Lanza(string nombre_, int durabilidad_, float peso_)
    :ArmaCombate(nombre_, durabilidad_, peso_), filo(10), punteria(0) {
        
        if(peso < 1 || peso > 5)
            throw invalid_argument("El peso va de 1 a 5");

        //el daño se inicializa al usar
        cout<<"\nLanza creada"<<endl;
    }

//metodos
void Lanza::getInfo()const{
    cout<<"\n== Lanza =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño + punteria: "<<daño<<" + "<<punteria<<endl;
    cout<<"Peso: "<<peso<<endl;
    cout<<"Filo: "<<filo<<endl;

}

void Lanza::Usar(){ 
    if(durabilidad == 0){
        cout<<"\nLa Lanza ya no sirve"<<endl;
        return;
    }
    else{

        //restauro el daño para quitarle la puntería anterior
        //si la lanza es muy pesada hace menos daño
        if(peso < 3)
            daño = 13;
        else if(peso >= 3)
            daño = 10;

        //genero la punteria
        int punteria_ = rand() % 6;//valores entre 0 y 5
        punteria = punteria_;
    
        durabilidad--;
        filo--;
        daño += punteria;
        daño--;
        uso = true;
        cout<<"\nLa Lanza ha sido usada"<<endl;
    }
    return;
}

float Lanza::getPeso()const{return peso;}

void Lanza::Afilar(){
    
    filo = 10; //restaura el filo
    //restauro el daño
    if(peso < 3)
        daño = 13;
    else if(peso >= 3)
        daño = 10;
    
    cout<<"\nLa Lanza fue afilada"<<endl;

    return;
}

int Lanza::getPunteriaActual()const{return punteria;}

//destructor
Lanza::~Lanza(){
    cout<<"\nLa Lanza ha sido destruida"<<endl;
}
