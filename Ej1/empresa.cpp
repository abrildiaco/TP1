#include "entidades.h"
#include "departamento.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor clase abstracta

EntidadOrganizativa::EntidadOrganizativa(string unNombre) //VER DONDE PONER EL CONSTRUCTOR
    :nombre(unNombre){}

//constructor Empresa

Empresa::Empresa(string unNombre, string unaDireccion, class Departamento unDept)
    :EntidadOrganizativa(unNombre), direccion(unaDireccion), ocupada(false) {
        departamentos.push_back(unDept);
    }

//constructor de copia

// Empresa::Empresa(const Empresa& otra)
// : EntidadOrganizativa(otra.nombre), direccion(otra.direccion), ocupada(otra), departamentos(otra.departamentos) {}


//metodos a sobreescribir

string Empresa::getNombre()const {return nombre;}

void Empresa::agregarSubentidad(shared_ptr<EntidadOrganizativa> subentidad){
    subentidades.push_back(move(subentidad));
    cout<<"Subentidad agregada con exito"<<endl;
    return;
}


int Empresa::contarSubentidades() const{
    return subentidades.size();
}

//sobrecarga de operador <

bool Empresa::operator<(const Empresa& otra)const {
    return this->nombre < otra.getNombre();
}

//metodos propios
void Empresa::cambiarOcupada(bool cambio){
    ocupada = cambio;
    return;
}


void Empresa::agregarDep(Departamento& dept){
    if(dept.ocupado == true)
        throw invalid_argument("El departamaneto ya pertenece a otra empresa");
    
    departamentos.push_back(dept);
    dept.cambiarOcupado(true);
    cout<<"Departamento "<<dept.nombre<<" agregado con exito"<<endl;
    return;
}


Departamento Empresa::getDepByName(string nombreDep)const{

    for(Departamento dep: departamentos){
        if (dep.nombre == nombreDep) return dep;
    }

    throw invalid_argument("No se encontro el departamento");
}

vector<string> Empresa::getDepNames() const{
    vector<string> deptNames;
    for(Departamento dep: departamentos){
        deptNames.push_back(dep.nombre);
    }
    return deptNames;
}




