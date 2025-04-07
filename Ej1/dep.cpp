#include "personal.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;
    
//constructor
Departamento::Departamneto(string unNombre, string unaUbi)
    :nombre(unNombre), ubicacion(unaUbi) {} //nombre, ubi

//metodos
static int Departamneto::contarEmpleados() const{
    //???
    return 0;
}

std::vector<Empleado> getEmployees() const{
    return empleados;
}

bool contratarEmpleado(Empleado& empleado){
    empleados.push_back(empleado);
    cout<<"Empleado "<<empleado.nombre<<" contratado con exito"<<endl;

    return true;
}

bool despedirEmpleado(Empleado& empleado){
    for(int i = 0; i < empleados.size(); i++){
        if (empleados[i].nombre == empleado.nombre){
            empleados.erase(empleados.begin() + i);
            return true;
        }
    }
    return false;
}
