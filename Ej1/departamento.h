#pragma once

#include <string>
#include <vector>
#include "personal.h"

//Definicion de clase Departamento

class Departamento{
    private:
        std::vector<Empleado> empleados;
    
    public:
        std::string nombre;
        std::string ubicacion;
        static int contarEmpleados() const;
        std::vector<Empleado> getEmployees() const;
        bool contratarEmpleado(Empleado);
        bool despedirEmpleado(Empleado);
}

/*

EL DEPARTAMNETO PUEDE PERTENECER A UNA SOLA EMPRESA*/