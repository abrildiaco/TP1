#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "personal.h"
#include "departamento.h"

//CLASE ABSTRACTA
class EntidadOrganizativa{
    protected:
        std::string nombre;
        std::set<EntidadOrganizativa> subentidades; //[inf]
    
    public:
        //condtructor    
        EntidadOrganizativa(std::string);
        
        //metodos virtuales puros
        virtual std::string getNombre() const = 0;
        virtual void agrgarSubentidad(std::unique_ptr<EntidadOrganizativa>) = 0;
        virtual int contarSubentidades()const = 0;
        
        //destructor
        virtual ~EntidadOrganizativa() = default;    
};       

//CLASES DERIVADAS

class Empresa: public EntidadOrganizativa{
    private:
        std::vector<std::Departamento> departamentos; //[1, inf]
    
    public:
        //constructor
        Empresa(std::string, std::string, Departamento::Departamento);//falta algo

        //métodos a sobreescribir
        std::string getNombre() const override;
        void agrgarSubentidad(std::unique_ptr<EntidadOrganizativa>) override;
        int contarSubentidades() const override;

        //métodos/atributos propios
        std::string direccion;
        void agregarDep(const Departamento&);
        Departamento::Departamento getDepByName(std::string) const;
        std::string getDepNames() const;

        ~Empresa() = default;
};


class CentralRegional: public EntidadOrganizativa{
    private:
        int cantEmpleados;
        std::vector<std::GerenteAlto> gerentesAlto; //[1, 5]
        std::vector<std::GerenteMedio> gerentesMedio; //[1, 20]
        std::set<Empresa> empresas; //unique y ordenado [1, inf]
        
    public:
        //constructor
        CentralRegional(std::string, GerenteAlto&, GerenteMedio&);
        
        //métodos a sobreescribir
        std::string getNombre() const override;
        void agrgarSubentidad(EntidadOrganizativa&)const override;
        int contarSubentidades() const override;
        
        //métodos/atributos propios
        std::set<std::string> pais; //unique y ordenado
        
        void agregarEmpresa()const;
        int getCantEmpleados() const;
        std::vector<string> getEmpNames() const; //[1, inf]
        std::vector<GerenteAlto> getGerenteAlto() const;
        std::vector<GerenteMedio> getGerenteMedio() const;

        ~CentralRegional() = default;
};
    
//RELACION DE COMPOSICION ENTRE EMPRESA Y CENTRAL REGIONAL
/*
La central regional puede tener de una a infinitas empresas, pero una empresa
puede estar en una sola entidad regional
*/

    
    