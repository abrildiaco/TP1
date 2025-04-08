#pragma once

#include <string>

//Declaración de superclase Empleado

class Empleado{
    protected:
        int antiguedad;
        float salario;
        
    public:
        //atributos
        bool contratado; //atributo para cumplir con la composicion
        std::string nombre;
        std::string puesto;
        
        //constructor
        Empleado(std::string, std::string, int, float); //nombre, puesto, antiguedad, salario
        
        //metodos
        void cambiarContratado(bool);
        int getAntiguedad() const;
        float getSalario() const;
        bool updateSalario(float);

        //destructor
        virtual ~Empleado() = default;

};
/*
RELACION DE COMPOSICIÓN CON DEPARTAMENTO
los departamentos pueden tener muchos empleados, pero los empleados solo
pueden pertenecer a un departamento
*/

//Declaración de sub-superclase Manager

class Manager: public Empleado{
    protected:
        float bono;
        std::string level;
    
    public:
        //constructor
        Manager(std::string, std::string, int, float, float);
        
        //metodos
        bool updateBono(float);
        float getBono() const;
        bool setLevel(std::string);

        //destructor
        virtual ~Manager() = default;
};

//Declaracion de subclases

class GerenteAlto: public Manager{
    public:
        //constructor/destructor
        GerenteAlto(std::string, std::string, int, float, float);
        ~GerenteAlto() = default;
};

class GerenteMedio: public Manager{
    public:
        //constructor/destructor
        GerenteMedio(std::string, std::string, int, float, float);
        ~GerenteMedio() = default;

};

/*
los gerentes alto y gerentes medio tienen una RELACION DE COMPOSICION
con la central regional. 
cada uno puede pertenecer a tan solo una sentral regional
*/

class GerenteBajo: public Manager{
    public:
        //constructor/destructor
        GerenteBajo(std::string, std::string, int, float, float);
        ~GerenteBajo() = default;
};

class LiderEquipo: public Manager{
    public:
        //constructor/destructor
        LiderEquipo(std::string, std::string, int, float, float);
        ~LiderEquipo() = default;

};