#include "entidades.h"
#include "personal.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor
CentralRegional::CentralRegional(string unNombre, GerenteAlto& g_alto, GerenteMedio& g_medio)
    :EntidadOrganizativa(unNombre){
        if (gerentesAlto.size() == 5){
            throw runtime_error("No hay mas lugar para gerentes alto");
        }
        if (gerentesMedio.size() == 20){
            throw runtime_error("No hay mas lugar para gerentes medio");
        }
        gerentesAlto.push_back(g_alto);
        gerentesMedio.push_back(g_medio);
    } 


//métodos a sobreescribir
string CentralRegional::getNombre() const{
    return nombre;
}

void CentralRegional::agregarSubentidad(shared_ptr<EntidadOrganizativa> subentidad){ //CAMBIAR ESTO ED PUNTEROS ARREGLAR!!!!!!!!!!!!!!
    
    if (empresa.ocupada == true)
        throw invalid_argument("La empresa ya pertenece a otra central regional");
    
    empresas.insert(empresa);
    empresa.cambiarOcupada(true);
    cout<<"Empresa agregada con exito"<<endl;
    
    subentidades.push_back(move(subentidad));
    cout<<"Subentidad agregada con exito"<<endl;
    return;
}

int CentralRegional::contarSubentidades() const{
    return subentidades.size();
}


//métodos propios

int CentralRegional::getCantEmpleados() const{
    return gerentesAlto.size() + gerentesMedio.size();
}

vector<string> CentralRegional::getEmpNames() const{
    vector<string> nombre_empleados;
    
    for (GerenteAlto g_alto : gerentesAlto) {
        nombre_empleados.push_back(g_alto.nombre);
    }
    for (GerenteMedio g_medio : gerentesMedio) {
        nombre_empleados.push_back(g_medio.nombre);
    }

    return nombre_empleados;
}

void CentralRegional::contratarGerenteAlto(GerenteAlto& gerente_alto){
    if (gerente_alto.contratado == true)
        throw invalid_argument("La persona a contratar ya pertenece a una central regional");
    
    gerentesAlto.push_back(gerente_alto);
    gerente_alto.contratado = true;
    cout<<"gerente Alto "<<gerente_alto.nombre<<" fue contratado con exito"<<endl;
}


void CentralRegional::contratarGerenteMedio(GerenteMedio& gerente_medio){
    if (gerente_medio.contratado == true)
    throw invalid_argument("La persona a contratar ya pertenece a una central regional");

    gerentesMedio.push_back(gerente_medio);
    gerente_medio.contratado = true;
    cout<<"gerente Alto "<<gerente_medio.nombre<<" fue contratado con exito"<<endl;

}


vector<GerenteAlto> CentralRegional::getGerenteAlto() const{
    return gerentesAlto;
}

vector<GerenteMedio> CentralRegional::getGerenteMedio() const{
    return gerentesMedio;
}
