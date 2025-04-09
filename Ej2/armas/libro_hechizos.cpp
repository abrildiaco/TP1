#include "armas.h"
#include "libro_hechizos.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


//constructor
LibroHechizos::LibroHechizos(string nombre_, int durabilidad_)
    :ItemMagico(nombre_, durabilidad_), hechizos({"congelamiento", "daño por daño", "curacion"}) {
        
        srand(time(0)); // Inicializa la semilla
        //genero si el libro esta maldito o no
        bool maldi = rand() % 2; //valores entre 0 y 1
        maldito = maldi;

        //genero un hechizo actual-inicial random
        int aleatorio = rand() % 3; //valores entre o y 2
        string hechizo_actual = hechizos[aleatorio];

        if(hechizo_actual == "congelamiento"){
            daño = 5;
            auto_daño = 2;
        }
        else if(hechizo_actual == "daño por daño"){
            daño = 0; //el daño generado sera igual al daño que me genere el oponente
            auto_daño = 8;
        }
        else{
            //me puedo curar hasta 50 pts de vida
            daño = 0;
            auto_daño = 0;
        }
        cout<<"Libro de Hechizos creado"<<endl;
    }

//metodos
void LibroHechizos::getInfo()const{
    cout<<"== Libro de Hechizos =="<<endl;
    cout<<"Durabilidad: "<<durabilidad<<endl;
    cout<<"Daño: "<<daño<<endl;
    cout<<"Auto daño: "<<auto_daño<<endl;
    cout<<"Maldito: "<<maldito<<endl;
    cout<<"Hechizos: congelamiento, daño por daño, curacion"<<endl;
    cout<<"Hechizo actual: "<<hechizo_actual<<endl;


}

string LibroHechizos::getNombre()const{return nombre;}

int LibroHechizos::getDurabilidad()const{return durabilidad;}

float LibroHechizos::getDano() const{return daño;}

string LibroHechizos::getTipo() {return tipo_arma;}

void LibroHechizos::Usar(){ 
    if(durabilidad >0 ){
        int aleatorio = rand() % 3; //valores entre o y 2
        hechizo_actual = hechizos[aleatorio];

        if(hechizo_actual == "congelamiento"){
            daño = 5;
            auto_daño = 2;
        
        }else if(hechizo_actual == "daño por daño"){
            daño = 0; //el daño generado sera igual al daño que me genere el oponente
            auto_daño = 5;
        
        }else{
            //me puedo curar hasta 50 pts de vida
            daño = 0;
            auto_daño = 0;
        }
        if(maldito){
            //si esta maldito se reduce el daño y aumenta el autodaño
            daño = daño/2 ;
            auto_daño++;
        }
        durabilidad--;
        uso = true;
    }

    if(durabilidad == 0){
        cout<<"El Libro de Hechizos ya no sirve"<<endl;
    }
}

float LibroHechizos::getAutoDano()const{ return auto_daño;}

vector<string> LibroHechizos::getHechizos()const{return hechizos;}

string LibroHechizos::getHechizoActual()const{return hechizo_actual;}

bool LibroHechizos::isMaldito(){return maldito;}

//destructor
LibroHechizos::~LibroHechizos(){
    cout<<"El libro de hechizos se ha destruido"<<endl;
}