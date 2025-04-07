#pragma once

#include <string>
#include <vector>
#include "personal.h"

//Definicion de clase Departamento

class Departamento{
    private:
        std::vector<Empleado> empleados; //[1, inf]
    
    public:
        //constructor
        Departamneto(std::string, std::string); //nombre, ubi

        //metodos/atributos
        std::string nombre;
        std::string ubicacion;
        
        static int contarEmpleados() const; //STATIC - se instancia afuera
        std::vector<Empleado> getEmployees() const;
        bool contratarEmpleado(Empleado&);
        bool despedirEmpleado(Empleado&);

        //destructor
        ~Departamento() = default;
}

/*

EL DEPARTAMNETO PUEDE PERTENECER A UNA SOLA EMPRESA*/