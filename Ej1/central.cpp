#include "entidades.h"
#include "personal.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor
CentralRegional::CentralRegional(string unNombre, GerenteAlto::GerenteAlto& g_alto, GerenteMedio::GerenteMedio& g_medio)
    ::EntidadOrganizativa(unNombre){
        if (gerentesAlto.size() == 5){
            throw runtime_error("No hay mas lugar para gerentes alto");
        }
        if (gerenyesMedio.size() == 20){
            throw runtime_error("No hay mas lugar para gerentes medio");
        }
        gerentesAlto.push_back(g_alto);
        gerentesMedio.push_back(g_medio);
    } 


//métodos a sobreescribir
string CentralRegional::getNombre() const{
    return nombre;
}

void CentralRegional::agrgarSubentidad(unique_ptr<EntidadOrganizativa> subentidad){
    subentidades.push_back(subentidad);
    cout<<"Subentidad agergada con exito"<<endl;
    return;
}


int CentralRegional::contarSubentidades() const{
    return subentidades.size();
}

//métodos propios

int getCantEmpleados() const{
    return gerentesAlto.size() + gerentesMedio.size();
}

vector<string> getEmpNames() const{
    vector<string> nombre_empleados;
    
    for (GerenteAlto g_alto : gerentesAlto) {
        nombre_empleados.push_back(g_alto.nombre);
    }
    for (GerenteMedio g_medio : gerentesMedio) {
        nombre_empleados.push_back(g_medio.nombre);
    }

    return nombre_empleados;
} 

std::vector<GerenteAlto> getGerenteAlto() const{
    return gerentesAlto;
}

std::vector<GerenteMedio> getGerenteMedio() const{
    return gerentesMedio;
}
