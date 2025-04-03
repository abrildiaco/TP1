#pragma once

#include <string>

//Declaración de superclase Empleado

class Empleado{
    private:
        int antiguedad;
        float salario;
        float getSalario() const;
    
    public:
        Empleado(std::string, std::string, int, int);
        std::string nombre;
        std::string puesto;
        int getAntiguedad() const;
        bool updateSalario(float);

        virtual ~Empleado();

}
/*
RELACION DE COMPOSICIÓN CON DEPARTAMENTO
los departamentos pueden tener muchos empleados, pero los empleados solo
pueden pertenecer a un departamento
*/

//Declaración de sub-superclase Manager

class Manager: public Empleado{
    private:
        float bono;
        std::string level;
    
    public:
        Manager(std::string, std::string, int, int, float);
        bool updateBono(float);
        float getBono() const;
        bool setLevel(std::string);

        virtual ~Manager();
};

//Declaracion de subclases

class GerenteAlto: public Manager{
    public:
        GerenteAlto(std::string, std::string, int, int, float);
        ~GerenteAlto();
};

class GerenteMedio: public Manager{
    public:
        GerenteMedio(std::string, std::string, int, int, float);
        ~GerenteMedio();

};

/*
los gerentes alto y gerentes medio tienen una RELACION DE COMPOSICION
con la central regional. 
cada uno puede pertenecer a tan solo una sentral regional
*/

class GerenteBajo: public Manager{
    public:
        GerenteBajo();
        ~GerenteBajo();
};

class LiderEquipo: public Manager{
    public:
        LiderEquipo();
        ~LiderEquipo();

};