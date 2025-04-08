#pragma once

#include <string>
#include <vector>
#include "personal.h"

//Definicion de clase Departamento

class Departamento{
    private:
        static int cantEmpleadosDepts; //STATIC -instanciar afuera
        std::vector<Empleado> empleados; //[1, inf]
    
    public:
        //atributos
        bool ocupado; //atributo para cumplir con la composicion
        std::string nombre;
        std::string ubicacion;
        
        //constructor
        Departamento(std::string, std::string); //nombre, ubi

        //metodos
        void cambiarOcupado(bool);
        static int contarEmpleados(); //STATIC - se instancia afuera
        std::vector<Empleado> getEmployees() const;
        bool contratarEmpleado(Empleado&);
        bool despedirEmpleado(Empleado&);

        //destructor
        ~Departamento() = default;
};

/*

EL DEPARTAMNETO PUEDE PERTENECER A UNA SOLA EMPRESA*/