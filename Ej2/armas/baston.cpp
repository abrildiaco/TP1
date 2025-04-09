#include <string>
#include "armas.h"
#include "baston.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor
Baston::Baston(string nombre_, int durabilidad_, bool gema_)
    :ItemMagico(nombre_, durabilidad_), tiene_gema(gema_), ulti(true) {   
        daño = 17;
        auto_daño = 4;
        if (gema_) daño = 20;
        cout<<"Baston creado"<<endl;
    }

//metodos
void Baston::getInfo()const{
    cout<<"== Baston magico =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;
    cout<<"Tiene gema: "<<tiene_gema<<endl;

}

std::string Baston::getNombre()const{return nombre;}

int Baston::getDurabilidad()const{return durabilidad;}

float Baston::getDano() const{return daño;}

void Baston::Usar(){ 
    if(durabilidad >0 ){
        if(contador_daño < 50){
            cout<<"El baston fue usado"<<endl;
            contador_daño += daño;
        }
        else if (contador_daño >= 50 && ulti){
            cout<<"Ulti activada!"<<endl;
            daño = 50;
            ulti = false; // ya no se puede usar la ulti
        }
        else if(contador_daño >= 50 && !ulti){
            daño = 17;
        }
        durabilidad--;
        uso = true;
    }

    if(durabilidad == 0){
        cout<<"Ya no tienes mas Baston"<<endl;
    }
    cout<<"El baston fue usado"<<endl;
}

float Baston::getAutoDano()const{return auto_daño;}

bool Baston::hasGema()const{return tiene_gema;}

Baston::~Baston(){
    cout<<"El baston fue destruido"<<endl;
}
