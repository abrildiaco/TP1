#include "armas.h"
#include "Amuleto.h"
#include "libro_hechizos.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//constructor
Amuleto::Amuleto(string nombre_, int durabilidad_, bool suerte_)
    :ItemMagico(nombre_, durabilidad_), suerte(suerte_) {
        daño = 10;
        auto_daño = 6;
        if(suerte){daño = 15; auto_daño = 3;}
    }

//metodos
void Amuleto::getInfo()const{
    cout<<"== Amuleto magico =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;
    cout<<"Duerte: "<<suerte<<endl;

}

std::string Amuleto::getNombre()const{return nombre;}

int Amuleto::getDurabilidad()const{return durabilidad;}

float Amuleto::getDano() const{return daño;}

void Amuleto::Usar(){ 
    if(durabilidad >0 ){
        uso = true;
        durabilidad--;
    }

    if(durabilidad == 0){
        cout<<"Ya no tienes mas Amuleto"<<endl;
    }
}

float Amuleto::getAutoDano()const{return auto_daño;}

bool Amuleto::hasSuerte()const{return suerte;}

//destructor
Amuleto::~Amuleto(){
    cout<<"El amuleto se ha destruido"<<endl;
}