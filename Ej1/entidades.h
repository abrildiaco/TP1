#pragma once

#include <string>
#include <vector>
#include <memory>
#include "personal.h"
#include "departamento.h"

//CLASE ABSTRACTA
class EntidadOrganizativa{
    protected: //PREGUNTAR
        std::string nombre;
        std::vector<std::unique_ptr<EntidadOrganizativa>> subentidades;
    
    public:
        EntidadOrganizativa(std::string);
        virtual std::string getNombre() const = 0;
        virtual void agrgarSubentidad(std::unique_ptr<EntidadOrganizativa>) = 0;
        virtual int contarSubentidades()const = 0;
        virtual ~EntidadOrganizativa();    
};       

//CLASES DERIVADAS

class Empresa: public EntidadOrganizativa{
    private:
        std::vector<std::Departamento> departamentos;
    
    public:
        //constructor
        Empresa(std::string, std::string, Departamento::Departamento);//falta algo

        //métodos a sobreescribir
        std::string getNombre() const override;
        void agrgarSubentidad(std::unique_ptr<EntidadOrganizativa>) override;
        int contarSubentidades() const override;

        //métodos/atributos propios
        std::string direccion;
        Departamento::Departamento getDepByName(std::string) const;
        std::vector<Departamento> getDepNames() const;

        ~Empresa();
};


class CentralRegional: public EntidadOrganizativa{
    private:
    int cantEmpleados;
    std::vector<std::GerenteAlto> gerentesAlto; //[1, 5]
    std::vector<std::GerenteMedio> gerentesMedio; //[1, 20]
    std::vector<Empresa> empresas; //unique y ordenado
    
    public:
        //constructor
        CentralRegional(std::string); //falta algo
        
        //métodos a sobreescribir
        std::string getNombre() const override;
        void agrgarSubentidad(std::unique_ptr<EntidadOrganizativa>)const override;
        int contarSubentidades() const override;
        
        //métodos/atributos propios
        //std::string nombre; no hace falta esta en la general
        std::vector<std::string> pais; //unique y ordenado
        int getCantEmpleados() const;
        std::vector<string> getEmpNames() const;
        std::vector<GerenteAlto> getGerentesAlto() const;
        std::vector<GerenteMedio> getGerentesMedio() const;

        ~CentralRegional();
};
    
//RELACION DE COMPOSICION ENTRE EMPRESA Y CENTRAL REGIONAL
/*
La central regional puede tener de una a infinitas empresas, pero una empresa
puede estar en una sola entidad regional
*/

    
    