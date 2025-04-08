#include "personal.h"
#include"departamento.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;
    
//constructor
Departamento::Departamento(string unNombre, string unaUbi)
    :nombre(unNombre), ubicacion(unaUbi), ocupado(false) {} //nombre, ubi

//metodos
int Departamento::contarEmpleados(){
    return cantEmpleadosDepts;
}

std::vector<Empleado> Departamento::getEmployees() const{
    return empleados;
}

void Departamento::cambiarOcupado(bool cambio){
    ocupado = cambio;
}

bool Departamento::contratarEmpleado(Empleado& empleado){
    if (empleado.contratado == true)
        throw invalid_argument("La persona a contratar ya tiene trabajo");
    
    empleados.push_back(empleado);
    empleado.cambiarContratado(true);
    cantEmpleadosDepts ++;
    cout<<"Empleado "<<empleado.nombre<<" fue contratado con exito"<<endl;

    return true;
}

bool Departamento::despedirEmpleado(Empleado& empleado){
    for(int i = 0; i < empleados.size(); i++){
        if (empleados[i].nombre == empleado.nombre){
            empleados.erase(empleados.begin() + i);
            empleado.cambiarContratado(false);
            cout<<"Empleado "<<empleado.nombre<<" due despedido con exito"<<endl;
            cantEmpleadosDepts --;
            return true;
        }
    }
    return false;
}
