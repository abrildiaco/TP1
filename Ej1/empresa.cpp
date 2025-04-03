#include "entidades.h"
#include "departamento.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

//constructor clase abstracta

EntidadOrganizativa::EntidadOrganizativa(string unNombre) //VER DONDE PONER EL CONSTRUCTOR
    :nombre(unNombre){}

//constructor

Empresa::Empresa(string unNombre, Departamento unDep, string unaDireccion, Departamento::Departamento unDept)
    :EntidadOrganizativa(unNombre), direccion(unaDireccion) {
        departamentos.push_back(unDept);
    } //PREGUNTAR DEPARTAMENTO

string Empresa::getNombre(){return nombre;}

void Empresa::agrgarSubentidad(unique_ptr<EntidadOrganizativa> subentidad){
    subentidades.push_bach(subentidad);
    return;
}


int Empresa::contarSubentidades() const{
    return subentidades.size();
}

Departamento Empresa::getDepByName(string nombreDep){

    for(Departamento dep: departamentos){
        if (dep.nombre == nombreDep) return dep;
    }

    cout<<"No se encontro el departamento "<<nombreDep<<endl;
    return;
}

vector<Departamento> Empresa::getDepNames() const{
    return departamentos;
}




