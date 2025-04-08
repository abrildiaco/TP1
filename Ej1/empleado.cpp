#include "personal.h"
#include <string>
using namespace std;

//EMPLEADO

//constructor
Empleado::Empleado(string unNombre, string unPuesto, int unaAnt, float unSalario)
    :nombre(unNombre), puesto(unPuesto), antiguedad(unaAnt), salario(unSalario), contratado(false){}

//metodos
int Empleado::getAntiguedad() const {return antiguedad;}

void Empleado::cambiarContratado(bool cambio){
    contratado = cambio;
}


bool Empleado::updateSalario(float nuevo_salario){
    salario = nuevo_salario;
    return true;
}

float Empleado::getSalario() const{
    return salario;
}

//MANAGER

//constructor
Manager::Manager(string unNombre, string unPuesto, int unaAnt, float unSalario, float unBono)
    :Empleado(unNombre,unPuesto,unaAnt, unSalario), bono(unBono){}

//metodos
bool Manager::updateBono(float nuevo_bono){
    bono = nuevo_bono;
    return true;
}

float Manager::getBono() const{return bono;}

bool Manager::setLevel(string nivel){
    level = nivel;
    return true;
}

//NIVELES

GerenteAlto::GerenteAlto(string unNombre, string unPuesto, int unaAnt, float unSalario, float unBono)
    :Manager(unNombre,unPuesto,unaAnt, unSalario, unBono){}

GerenteMedio::GerenteMedio(string unNombre, string unPuesto, int unaAnt, float unSalario, float unBono)
    :Manager(unNombre,unPuesto,unaAnt, unSalario, unBono){}
    
GerenteBajo::GerenteBajo(string unNombre, string unPuesto, int unaAnt, float unSalario, float unBono)
    :Manager(unNombre,unPuesto,unaAnt, unSalario, unBono){}

LiderEquipo::LiderEquipo(string unNombre, string unPuesto, int unaAnt, float unSalario, float unBono)
    :Manager(unNombre,unPuesto,unaAnt, unSalario, unBono){}
