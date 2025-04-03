#include "entidades.h"
#include "departamento.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

// //CLASE ABSTRACTA
// class EntidadOrganizativa{
//     protected: //PREGUNTAR
//         std::string nombre;
//         std::vector<unique_ptr<EntidadOrganizativa>> subentidades;
    
//     public:
//         EntidadOrganizativa(std::string, std::vector<unique_ptr<EntidadOrganizativa>>);
//         virtual std::string getNombre() const;
//         virtual void agrgarSubentidad(unique_ptr<EntidadOrganizativa>) = 0;
//         virtual int contarSubentidades()const;
//         virtual ~EntidadOrganizativa();    
// };       

// //CLASES DERIVADAS

// class Empresa: public EntidadOrganizativa{
//     private:
//         std::vector<std::Departamento> departamentos;
    
//     public:
//         //constructor
//         Empresa(std::string, std::string);//falta algo

//         //métodos a sobreescribir
//         std::string getNombre() const override;
//         void agrgarSubentidad(unique_ptr<EntidadOrganizativa>)const override;
//         int contarSubentidades() const override;

//         //métodos/atributos propios
//         //std::string nombre; no hace falta esta en la general
//         std::string direccion;
//         Departamento getDepByName(std::string) const;
//         std::vector<Departamento> getDepNames() const;
// };

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




