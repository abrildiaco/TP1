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

Empresa::Empresa(string unNombre, Departamento unDep, string unaDireccion, class Departamento unDept)
    :EntidadOrganizativa(unNombre), direccion(unaDireccion) {
        departamentos.push_back(unDept);
    }

//metodos a sobreescribir

string Empresa::getNombre(){return nombre;}

void Empresa::agrgarSubentidad(EntidadOrganizativa& subentidad){
    subentidades.push_back(subentidad);
    return;
}


int Empresa::contarSubentidades() const{
    return subentidades.size();
}

//metodos propios

void Empresa::agregarDep(const Departamento& dept){
    departamentos.push_back(dept);
    cout<<"Departamento "<<dept.nombre<<" agregado con exito"<<endl;
    return;
}


Departamento Empresa::getDepByName(string nombreDep){

    for(Departamento dep: departamentos){
        if (dep.nombre == nombreDep) return dep;
    }

    throw invalid_argument("No se encontro el departamento")
    return;
}

string Empresa::getDepNames() const{
    vector<string> deptNames;
    for(Departamento dep: departamentos){
        deptNames.push_back(dep.nombre)
    }
    return deptNames;
}




