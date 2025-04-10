#include <string>
#include "armas.hpp"
#include "baston.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

//constructor
Baston::Baston(string nombre_, int durabilidad_)
    :ItemMagico(nombre_, durabilidad_), contador_daño(0), ulti(true) {   
        
        srand(time(0)); // Inicializa la semilla
        //genero si el baston tiene gema o no
        bool gema_ = rand() % 2; //valores entre 0 y 1
        tiene_gema = gema_;
        
        daño = tiene_gema ? 20 : 17;
        auto_daño = 4;
        cout<<"\nBaston creado"<<endl;
    }

//metodos
void Baston::getInfo()const{
    cout<<"\n== Baston magico =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Daño acumulado al oponente: "<<contador_daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;
    cout<<"Tiene gema: "<<tiene_gema<<endl;

}

void Baston::Usar(){ 
    if (durabilidad == 0) {
        cout << "\nYa no tienes más bastón." << endl;
        return;
    }

    if (contador_daño < 50) {
        cout << "\nEl bastón fue usado. Daño normal: " << daño << endl;
        contador_daño += daño;
    } 
    else if (ulti) {
        cout << "\n¡Ulti activada! Daño máximo: 50" << endl;
        daño = 50;
        ulti = false; //ya no se puede usar
    } 
    else {
        daño = tiene_gema ? 20 : 17; //si ya se uso la ulti, vuelvo a lo predeterminado
        cout << "\nEl bastón fue usado después de la ulti. Daño: " << daño << endl;
    }

    durabilidad--;
    uso = true;

    return;
}

float Baston::getAutoDano()const{return auto_daño;}

bool Baston::hasGema()const{return tiene_gema;}

Baston::~Baston(){
    cout<<"\nEl baston fue destruido"<<endl;
}
